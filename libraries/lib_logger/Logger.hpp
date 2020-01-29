/*
 * Logger.hpp
 *
 *  Created on: Nov 19, 2019
 *      Author: chester-debian
 */

#ifndef LIBRARIES_LOGGER_HPP_
#define LIBRARIES_LOGGER_HPP_

#include <string>
#include <vector>
#include <algorithm>

class Logger
{
public:
    static Logger& getLogger();
    void Log(const std::string &s);
    void printLog();
    virtual ~Logger();

private:
    Logger();
    std::vector<std::string> logs;
    static Logger logger;



};

#endif /* LIBRARIES_LOGGER_HPP_ */
