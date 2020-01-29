/*
 * Configuration.cpp
 *
 *  Created on: Nov 15, 2019
 *      Author: jeremy
 */
#include "Configuration.hpp"

Configuration::Configuration() :
		name("NoNameSpecified"), style("NoStyleSpecified"), duration(0) {

}

Configuration::~Configuration() {

}

std::string Configuration::getName() {
	return name;
}

std::string Configuration::getStyle() {
	return style;
}

std::string Configuration::getMachineStyle(){
	return machineStyle;
}

unsigned long Configuration::getDuration() {
	return duration;
}

void Configuration::setName(std::string aName) {
	name = aName;
}

void Configuration::setStyle(std::string aStyle) {
	style = aStyle;
}

void Configuration::setDuration(unsigned long time) {
	duration = time;
}

void Configuration::setMachineStyle(std::string aName){
	machineStyle = aName;
}

void Configuration::extractJson(std::string fileName) {
	namespace pt = boost::property_tree;

	// Initialize property_tree object to store machine information.
	pt::ptree root;

	// Fill ptree with provided JSON file.
	pt::read_json(fileName + ".json", root);

	// Get machineconfiguration object from JSON file.
	pt::ptree systemlist = root.get_child(fileName);

	bool configModeMachine;

	// Get all machines from the machinelist and put them in a machinevector. It is worth mentioning that ERROR or 0 gets filled when the element can't be found.
	if (fileName == "machineconfiguration") {
		configModeMachine = true;
	}else {
		configModeMachine = false;
	}

	if (configModeMachine == true) {

		BOOST_FOREACH(pt::ptree::value_type const &v, systemlist) {

			pt::ptree tempList = systemlist.get_child(v.first);
			Machine tempMachine(tempList.get<std::string>("name", "ERROR"),
					tempList.get<short>("id", 1),
					(60 / tempList.get<double>("productionTime", 0)),
					tempList.get<short>("bufferSize", 0),
					tempList.get<short>("rebuildTime", 0)*60,
					tempList.get<short>("MTBF", 0),
					tempList.get<short>("reparationTime", 0)*60,
					tempList.get<short>("stdev", 0)*60,
					tempList.get<short>("prev", 0),
					tempList.get<bool>("first", 0),
					tempList.get<bool>("last", 0),
					tempList.get<short>("end", 0),
					tempList.get<bool>("droogband", 0));
			machines.push_back(tempMachine);
		}
	}

	if (configModeMachine == false) {
		BOOST_FOREACH(pt::ptree::value_type const &v, systemlist) {
			pt::ptree tempList = systemlist.get_child(v.first);

			setName(tempList.get<std::string>("name"));
			setStyle(tempList.get<std::string>("style"));
			setMachineStyle(tempList.get<std::string>("machine"));
			setDuration(tempList.get<unsigned long>("duration")*60);
		}
	}
}


