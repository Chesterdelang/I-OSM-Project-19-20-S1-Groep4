/*
 * ProductionControl.hpp
 *
 *  Created on: Nov 15, 2019
 *      Author: chester-debian
 */
#ifndef PRODUCTIONCONTROL_PRODUCTIONCONTROL_HPP_
#define PRODUCTIONCONTROL_PRODUCTIONCONTROL_HPP_

#include <boost/property_tree/ptree.hpp>
#include <boost/filesystem.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/optional.hpp>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <ostream>
#include <vector>
#include <chrono>
#include <thread>
#include <map>
#include <set>
#include <algorithm>
#include <functional>
#include "Configuration.hpp"
#include "Machine.hpp"
#include <boost/date_time.hpp>
#include <algorithm>

class ProductionControl {
public:

	ProductionControl();

	virtual ~ProductionControl();

	/**
	 *
	 * function for writing collected data to a text file
	 */
	void write_text();

	double calculateRunningTime(double aTime);

	double runningTime();

	void machineSortingAlgorithm(
			std::map<unsigned short, double> aMachineTimeMap);

	void runtimeAlgorithm();

	void runMachine();

	double timeDifference(std::map<unsigned short, double> &aMachineTimeMap);

	void subtractTime(double aTimeDifference);

	void stateSimulation(Machine &aMachine);

	void initiateMapList();

	void machineBroken(Machine &bMachine);

	void checkBuffers(Machine &aMachine);

	void dryer();

	Configuration config;

	std::map<unsigned short, double> machineTimeMap;

	std::map<signed short, double> machineBrokenMap;

	std::map<signed short, double> dryerMap;

	std::vector<double> firstDryer;

	std::vector<double> secondDryer;

	unsigned long long countdays;



private:

	unsigned long timer;
	const unsigned long INTERVAL = 28800;
	const unsigned short HOURPAST = 3600;
	const unsigned short RANDOMNUMBER = 42;

	double totalRunTime;
	std::string style;
	std::string machineStyle;
	unsigned long long totalMachineDowntime;
	unsigned long long numberOfProducts;

	unsigned long productday = 0;
	std::vector<unsigned long long> productPerDay;

	unsigned long reparationTime = 0;

	unsigned long long brokenDay;
	std::string brokenDayString;
	std::vector<std::string> brokenDays;

	bool firstMachine = false;

	//compare the second values
	struct compare {
		template<typename T>
		bool operator()(const T &l, const T &r) const {
			if (l.second != r.second)
				return l.second < r.second;

			return l.first < r.first;
		}
	};

};

#endif /* PRODUCTIONCONTROL_PRODUCTIONCONTROL_HPP_ */
