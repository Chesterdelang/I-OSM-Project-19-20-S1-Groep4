/*
 * ProductionControl.cpp
 *
 *  Created on: Nov 15, 2019
 *      Author: chester-debian
 */

#include "ProductionControl.hpp"

ProductionControl::ProductionControl() :
		totalRunTime(0), totalMachineDowntime(0), numberOfProducts(0) {
	config.extractJson("machineconfiguration");
	config.extractJson("systemconfiguration");
	std::cout << "Running Simulation" << std::endl;

	totalRunTime = config.getDuration();
	style = config.getStyle();
	timer = config.getDuration();

	for (Machine aMachine : config.machines) {
		aMachine.machineBrokenCalculate();
		aMachine.setInBuffer(0);

		machineBrokenMap.insert(
				{ std::make_pair(aMachine.getId(), aMachine.timeUntilBroken) });
	}

}

ProductionControl::~ProductionControl() {

}

void ProductionControl::write_text() {
	boost::posix_time::ptime timeLocal =
			boost::posix_time::second_clock::local_time();

	std::cout << "Current System Time = " << timeLocal << std::endl;

	// Get Date object from ptime object
	boost::gregorian::date dateObj = timeLocal.date();

	// Get Time object from ptime object
	boost::posix_time::time_duration durObj = timeLocal.time_of_day();
	std::ofstream productionFile("results.json", std::ofstream::out);
	std::string newFileResults;
	std::string rpdFile = "resultsPerDay.csv";
	std::string newFileBroken;
	std::string bpmFile = "brokenPerMachine.csv";

	std::string input;
	std::string newFileReparation;
	std::string rFile = "reparationPerMachine.csv";

	std::string newFileProducts;
	std::string pFile = "ProductsPerMachine.csv";

	if (boost::filesystem::exists(rpdFile) || boost::filesystem::exists(bpmFile) || boost::filesystem::exists(rFile) || boost::filesystem::exists(pFile)) {
		std::cout << "Some files already exist, give a prefix for new files: " << std::endl;
		std::cin >> input;

		std::ostringstream nfr;
		nfr << "resultsPerDay" << input << ".csv";
		newFileResults = nfr.str();

		std::ostringstream nfb;
		nfb << "brokenPerMachine" << input << ".csv";
		newFileBroken = nfb.str();

		std::ostringstream nfrep;
		nfrep << "reparationPerMachine" << input << ".csv";
		newFileReparation = nfrep.str();

		std::ostringstream rpm;
		rpm << "ProductsPerMachine" << input << ".csv";
		newFileProducts = rpm.str();

	} else {
		newFileResults = "resultsPerDay.csv";
		newFileBroken = "brokenPerMachine.csv";
		newFileReparation = "reparationPerMachine.csv";
		newFileProducts = "ProductsPerMachine.csv";
	}


	boost::property_tree::ptree pt;
	std::ofstream newFileProductsPerMachine(newFileProducts);
	std::ofstream newFileReparationPerMachine(newFileReparation);
	std::ofstream newFileBrokenPerMachine(newFileBroken);
	std::ofstream newOutFilePerDay(newFileResults);
	pt.put("Results.TotalDuration", totalRunTime);
	pt.put("Results.TotalMachineDowntime", totalMachineDowntime);
	pt.put("Results.ProductsFabricated", numberOfProducts);
	unsigned long long xproductPerDay = 0;
	unsigned long long xproduct = 0;
	boost::property_tree::ptree fruits_node;
	for (auto &fruit : productPerDay) {
		// Create an unnamed node containing the value
		boost::property_tree::ptree fruit_node;
		fruit_node.put("", fruit);
		newOutFilePerDay << xproductPerDay << ",";
		newOutFilePerDay << fruit << std::endl;

		// Add this node to the list.
		fruits_node.push_back(std::make_pair("", fruit_node));
		xproductPerDay++;
	}

	for (auto &machine : config.machines) {
		// Create an unnamed node containing the value
		for (unsigned long product : machine.machineMadeDay) {
			newFileProductsPerMachine << xproduct << ",";
			newFileProductsPerMachine << machine.getId() << ",";
			newFileProductsPerMachine << product << std::endl;
			xproduct++;
		}
	}

	for (auto &aMachine : config.machines) {
		// Create an unnamed node containing the value
		newFileReparationPerMachine << aMachine.getId() << ",";
		newFileReparationPerMachine << " " << aMachine.getRepairTimeTotal()
				<< std::endl;
	}

	for (auto &aMachine : config.machines) {
		newFileBrokenPerMachine << aMachine.getId() << ",";
		newFileBrokenPerMachine << aMachine.getTimesBroken()
				<< std::endl;

	}

	newFileProductsPerMachine.close();
	newFileReparationPerMachine.close();
	newFileBrokenPerMachine.close();
	newOutFilePerDay.close();
}

void ProductionControl::initiateMapList() {
	machineTimeMap.clear();
	for (Machine aMachine : config.machines) {
		machineTimeMap.insert(
				{ std::make_pair(aMachine.getId(), aMachine.getRebuildTime()) });
	}
}

double ProductionControl::calculateRunningTime(double aTime) {
	return totalRunTime = (5 * 8 * 52 * aTime) * 60;
}

double ProductionControl::runningTime() {
	return totalRunTime = totalRunTime - timeDifference(machineTimeMap);
}

void ProductionControl::machineSortingAlgorithm(
		std::map<unsigned short, double> aMachineTimeMap) {
	std::set<std::pair<unsigned short, double>, compare> orderedMachines(
			aMachineTimeMap.begin(), aMachineTimeMap.end());

}

double ProductionControl::timeDifference(
		std::map<unsigned short, double> &aMachineTimeMap) {

	std::set<std::pair<unsigned short, double>, compare> orderedMachines(
			aMachineTimeMap.begin(), aMachineTimeMap.end());

	for (auto const &pair : orderedMachines) {
		if (pair.second > 0) {
			return pair.second;
		}
	}
	return 0;
}

void ProductionControl::subtractTime(double aTimeDifference) {
	for (auto const& [key, val] : machineTimeMap) {
		if (val > 0) {
			machineTimeMap[key] = val - aTimeDifference;

		}
	}
	for (auto const& [key, val] : machineBrokenMap) {
		if (val > 0) {
			machineBrokenMap[key] = val - aTimeDifference;
		}
	}
	for (unsigned short i=0; i<firstDryer.size(); ++i){
		firstDryer[i] = firstDryer[i] - aTimeDifference;
	}
	for (unsigned short i=0; i<secondDryer.size(); ++i){
		secondDryer[i] = secondDryer[i] - aTimeDifference;
	}
}

void ProductionControl::dryer(){
	if(config.getStyle() == "Basic"){
		for (unsigned short i=0; i<firstDryer.size(); ++i){
			if (firstDryer[i] <= 0) {
				firstDryer.erase (firstDryer.begin()+i);
				for (Machine &aMachine : config.machines) {
					if (aMachine.getId() == 5) {
						aMachine.setInBuffer((aMachine.getInBuffer() + 1));

					}

				}
			}
		}

	}else if(config.getStyle() == "Deluxe"){
		for (unsigned short i=0; i<firstDryer.size(); ++i){
			if (firstDryer[i] <= 0) {
				firstDryer.erase (firstDryer.begin()+i);
				for (Machine &aMachine : config.machines) {
					if (aMachine.getId() == 3) {
						aMachine.setInBuffer((aMachine.getInBuffer() + 1));

					}

				}
			}
		}
		for (unsigned short i=0; i<secondDryer.size(); ++i){
			if (secondDryer[i] <= 0) {
				secondDryer.erase (secondDryer.begin()+i);
				for (Machine &aMachine : config.machines) {
					if (aMachine.getId() == 8) {
						aMachine.setInBuffer((aMachine.getInBuffer() + 1));

					}

				}
			}
		}

	}

}

void ProductionControl::machineBroken(Machine &aMachine) {

	if (aMachine.getDroogband() == 0) {

		for (auto const& [key, val] : machineBrokenMap) {
			if (val <= 0 && key == aMachine.getId()) {

				aMachine.machineBrokenCalculate();

				reparationTime = aMachine.calculateRepairTime();

				machineBrokenMap[key] = (aMachine.timeUntilBroken
						+ reparationTime);

				aMachine.setTimesBroken(aMachine.getTimesBroken() + 1);

				brokenDayString = std::to_string(brokenDay)
						+ std::to_string(aMachine.getId());
				aMachine.setMachineBroken(true);
			}
		}

	} else if (aMachine.getDroogband() == 1) {
		aMachine.setRepairTimeTotal(0);
	}

}

void ProductionControl::runMachine() {

	for (auto const& [key, val] : machineTimeMap) {

		if (val == 0) {
			for (Machine &aMachine : config.machines) {
				if (aMachine.getId() == key) {
					machineBroken(aMachine);
					if (aMachine.getMachineBroken()) {

						aMachine.setInBuffer(0);

						aMachine.setRepairTimeTotal(
								aMachine.getRepairTimeTotal() + reparationTime);

						machineTimeMap[key] = reparationTime;
						aMachine.setMachineBroken(false);
					} else {
						checkBuffers(aMachine);
						if (aMachine.getRun()) {
							if(aMachine.getDroogband() == 1){
								machineTimeMap[key] = aMachine.getProductionTime();
								aMachine.productMade++;
								aMachine.setRun(false);
								if(config.getMachineStyle() == "Basic"){
								if(aMachine.getId() == 5){
									firstDryer.push_back(60/0.05);
								}else if(aMachine.getId() == 3){
									firstDryer.push_back(60/0.0333);
								}else if(aMachine.getId() == 8){
									secondDryer.push_back(60/0.05);
								}
								}else if(config.getMachineStyle() == "Deluxe"){
									if(aMachine.getId() == 5){
										firstDryer.push_back(60/0.04);
									}else if(aMachine.getId() == 3){
										firstDryer.push_back(60/0.04);
									}else if(aMachine.getId() == 8){
										secondDryer.push_back(60/0.0666);
									}
								}
							}else{

							machineTimeMap[key] = aMachine.getProductionTime();

							aMachine.setInBuffer((aMachine.getInBuffer() + 1));

							aMachine.productMade++;
							aMachine.setRun(false);
							if (aMachine.getEnd() == true) {
								productday++;
							}
							}
						}
					}
				}
			}
		}
	}
}

void ProductionControl::checkBuffers(Machine &aMachine) {

	if(config.getStyle() == "Basic"){
	if (aMachine.getEnd() == 1) {
		for (Machine &prevMachine : config.machines) {
			if ((prevMachine.getLast() == 1 && prevMachine.getInBuffer() > 0)
					|| (prevMachine.getLast() == 1
							&& prevMachine.getDroogband() == 1
							&& prevMachine.getInBuffer() > 0)) {
				for (Machine &secondPrevMachine : config.machines) {

					if ((prevMachine.getId() != secondPrevMachine.getId()
							&& secondPrevMachine.getLast() == 1
							&& secondPrevMachine.getInBuffer() > 0)
							|| (secondPrevMachine.getId() != prevMachine.getId()
									&& secondPrevMachine.getLast() == 1
									&& secondPrevMachine.getDroogband() == 1
									&& secondPrevMachine.getInBuffer() > 0)) {

						prevMachine.setInBuffer(prevMachine.getInBuffer() - 1);
						secondPrevMachine.setInBuffer(
								secondPrevMachine.getInBuffer() - 1);
						aMachine.setRun(true);
					}
				}
			}
		}
	} else if (aMachine.getFirst() == 0) {
		for (Machine &prevMachine : config.machines) {
			if (prevMachine.getId() == aMachine.getPrev()
					&& prevMachine.getInBuffer() > 0
					&& aMachine.getInBuffer() <= aMachine.getBufferSize()) {
				prevMachine.setInBuffer(prevMachine.getInBuffer() - 1);
				aMachine.setRun(true);
			}
		}
	}else if (aMachine.getFirst() == 1
			&& aMachine.getInBuffer() <= aMachine.getBufferSize()) {
		aMachine.setRun(true);
	}
	}else if(config.getStyle() == "Deluxe"){
		if (aMachine.getEnd() == 1) {
				for (Machine &prevMachine : config.machines) {
					if ((prevMachine.getLast() == 1 && prevMachine.getInBuffer() > 0)
										|| (prevMachine.getLast() == 1
												&& prevMachine.getDroogband() == 1
												&& prevMachine.getInBuffer() > 0)) {
						for (Machine &secondPrevMachine : config.machines) {

							if ((prevMachine.getId() != secondPrevMachine.getId()
									&& secondPrevMachine.getLast() == 1
									&& secondPrevMachine.getInBuffer() > 0)
									|| (secondPrevMachine.getId() != prevMachine.getId()
											&& secondPrevMachine.getLast() == 1
											&& secondPrevMachine.getDroogband() == 1
											&& secondPrevMachine.getInBuffer() > 0)) {

								prevMachine.setInBuffer(prevMachine.getInBuffer() - 1);
								secondPrevMachine.setInBuffer(
										secondPrevMachine.getInBuffer() - 1);
								aMachine.setRun(true);
							}
						}
					}
				}
			} else if (aMachine.getFirst() == 0) {
				for (Machine &prevMachine : config.machines) {

					if (prevMachine.getId() == aMachine.getPrev()
							&& aMachine.getPrev() == 1
							&& prevMachine.getInBuffer() > 7
							&& aMachine.getInBuffer() < aMachine.getBufferSize()) {

						prevMachine.setInBuffer(prevMachine.getInBuffer() - 8);
						aMachine.setRun(true);
					}else if(prevMachine.getId() == aMachine.getPrev()
							&& prevMachine.getInBuffer() > 0
							&& aMachine.getInBuffer() < aMachine.getBufferSize()){

							prevMachine.setInBuffer(prevMachine.getInBuffer() - 1);
							aMachine.setRun(true);

					}
				}
			}else if (aMachine.getFirst() == 1
					&& aMachine.getInBuffer() <= aMachine.getBufferSize()) {
				aMachine.setRun(true);
				if(aMachine.getId() == 1){
				}

			}

	}
}

void ProductionControl::runtimeAlgorithm() {

	initiateMapList();

	unsigned short day = 1;

	while (runningTime() >= 0) {

		if ((timer - totalRunTime) >= INTERVAL) {
			productPerDay.push_back(productday);
			brokenDays.push_back(brokenDayString);
			for (Machine &aMachine : config.machines) {
				aMachine.machineMadeDay.push_back(aMachine.productMade);
				aMachine.productMade = 0;
			}
			brokenDay = 0;
			productday = 0;
			countdays++;
			initiateMapList();
			//std::cout << "Day " << day << " past" << std::endl;
			day++;
			timer = totalRunTime;
		}

		runMachine();

		dryer();

		machineSortingAlgorithm(machineTimeMap);

		subtractTime(timeDifference(machineTimeMap));
	}

	std::cout << "Simulation finished" << std::endl;

}

