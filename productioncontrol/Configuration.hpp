/*
 * Configuration.hpp
 *
 *  Created on: Nov 15, 2019
 *      Author: chester-debian
 */
#include <string>
#include <iostream>
#include <ostream>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>
#include "Machine.hpp"
#include <vector>

#ifndef PRODUCTIONCONTROL_CONFIGURATION_HPP_
#define PRODUCTIONCONTROL_CONFIGURATION_HPP_

class Configuration {

public:
	Configuration();
	virtual ~Configuration();

	std::string getName();
	std::string getStyle();
	std::string getMachineStyle();
	unsigned long getDuration();

	void setName(std::string aName);
	void setStyle(std::string aName);
	void setMachineStyle(std::string aName);
	void setDuration(unsigned long time);

	/**
	 * function to extract machine and system configuration from two different JSON files. The given parameter is the name of the JSON file.
	 * @param fileName
	 */
	void extractJson(std::string fileName);

	std::vector<Machine> machines;

private:

	unsigned long duration;
	std::string name;
	std::string style;
	std::string machineStyle;
};

#endif /* CONFIGURATION_HPP_ */

