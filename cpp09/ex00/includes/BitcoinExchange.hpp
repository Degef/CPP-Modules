#ifndef BitcoinExchange_hpp
#define BitcoinExchange_hpp

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <ctime>

time_t			dateToTime(const std::string& dateStr);
int				getData(std::map<time_t, double> &dataMap);
std::string		epochToDateString(time_t epochTime);
void			findValue(std::map<time_t, double> &dataMap, time_t my_time, double amount);
int				getInputValues(std::map<time_t, double> &dataMap, char **argv);

#endif