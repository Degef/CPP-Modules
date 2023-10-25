#ifndef BitcoinExchange_hpp
#define BitcoinExchange_hpp

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <ctime>
#include <math.h>
#include <limits>

//colors
#define RESET		"\033[0m"
#define R			"\033[31m"
#define G			"\033[32m"
#define Y			"\033[33m"
#define B			"\033[34m"


time_t			dateToEpoch(const std::string& dateStr);
int				getData(std::map<time_t, double> &dataMap);
std::string		epochToDateString(time_t epochTime);
void			findValue(std::map<time_t, double> &dataMap, time_t my_time, double amount);
int				getInputValues(std::map<time_t, double> &dataMap, char **argv);

#endif