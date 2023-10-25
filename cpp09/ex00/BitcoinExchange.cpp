#include "includes/BitcoinExchange.hpp"

time_t dateToEpoch(const std::string& dateStr) {
    struct tm timeinfo = {};
    if (strptime(dateStr.c_str(), "%Y-%m-%d", &timeinfo) != NULL) {
        int day = atoi(dateStr.substr(8, 2).c_str());
        timeinfo.tm_mday = day;
        time_t my_time = mktime(&timeinfo);
        struct tm check_timeinfo = {};
        localtime_r(&my_time, &check_timeinfo);
        if (check_timeinfo.tm_mday != day) {
            return -1;
        }
        return my_time;
    }
    return -1;
}

std::string epochToDateString(time_t epochTime) {
    char buffer[11];
    std::tm* timeInfo = std::localtime(&epochTime);
    std::strftime(buffer, 11, "%Y-%m-%d", timeInfo);
    return std::string(buffer);
}

int getData(std::map<time_t, double> &dataMap)
{
	std::ifstream		inputFile("data.csv");
    std::string			dateStr;
    double				rate;
    std::string 		line;

    if (!inputFile.is_open()) {
        std::cerr << "Failed to open data.csv." << std::endl;
        return 1;
    }
	std::getline(inputFile, line);
    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);

        if (std::getline(iss, dateStr, ',') && iss >> rate && iss.get() == -1)
		{
            time_t timeValue = dateToEpoch(dateStr);
            if (timeValue != -1)
                dataMap[timeValue] = rate;
        	else
                std::cerr << "Invalid date format in CSV: " << dateStr << std::endl;
        } 
		else
            std::cerr << "Invalid line format in CSV: " << line << std::endl;
    }
	return 0;
}

void findValue(std::map<time_t, double> &dataMap, time_t my_time, double amount)
{
    double minTime = std::numeric_limits<double>::max();
    std::map<time_t, double>::const_iterator it = dataMap.begin();
    std::map<time_t, double>::const_iterator ite = dataMap.end();
    std::map<time_t, double>::const_iterator it2 = ite;

    while (it != ite) {
        double timeDiff = std::abs(my_time - it->first);
        if (timeDiff < minTime) {
            it2 = it;
            minTime = timeDiff;
        }
        ++it;
    }

    if (it2 != ite) {
        std::cout << epochToDateString(my_time) << " => " << amount << " = " 
		<< it2->second * amount << std::endl;
    } else {
        std::cerr << "No rate found for specified time" << std::endl;
    }
}

int getInputValues(std::map<time_t, double> &dataMap, char **argv)
{
	std::ifstream	inputFile(argv[1]);
	if (!inputFile.is_open()) {
        std::cerr << R << "Failed to open " << argv[1] << RESET << std::endl;
        return 1;
    }

	std::string		dateStr;
	double			amount;
	std::string 	line;
	int				i = 0;
	std::getline(inputFile, line);
	while (std::getline(inputFile, line)) {
		i++;
		std::istringstream iss(line);

		if (std::getline(iss, dateStr, '|') && iss >> amount && iss.get() == -1)
		{
			time_t timeValue = dateToEpoch(dateStr);
			if (timeValue == -1)
				std::cerr << R << "Error: bad input => " << dateStr << RESET << std::endl;
			else if (timeValue < 1229761829 || timeValue > 1649579429)
				std::cout << R << "Error: no data for date => " << dateStr << RESET << std::endl;
			else if (amount < 0)
				std::cerr << R << "Error: not a positive amount => "<< amount << RESET << std::endl;
			else if (amount > 1000)
				std::cerr << R << "Error: amount too high => " << amount << RESET << std::endl;
			else
				findValue(dataMap, timeValue, amount);
		} 
		else
			std::cerr << R << "Error: bad input => " << dateStr << RESET << std::endl;
    }
	if (i == 0)
		std::cerr << R << "Error: empty file" << RESET << std::endl;
	return 0;
}
