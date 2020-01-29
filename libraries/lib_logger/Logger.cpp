/*
 * Logger.cpp
 *
 *  Created on: Nov 19, 2019
 *      Author: chester-debian
 */
#include "Logger.hpp"

#include <string>
#include <iostream>

Logger& Logger::getLogger(){
	static Logger logger;
	return logger;
}

void Logger::Log(const std::string &s){
    logs.push_back(s);
}

void Logger::printLog()
{
    for(unsigned short i = 0; i <= logs.size(); ++i){
        std::cout << logs[i] << std::endl;
    }

}

Logger::Logger()

{
	// TODO Auto-generated constructor stub

}

Logger::~Logger(){


}
