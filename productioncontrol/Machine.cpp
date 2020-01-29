/*
 * Machine.cpp
 *
 *  Created on: Nov 18, 2019
 *      Author: chester-debian
 */

#include "Machine.hpp"

Machine::Machine(std::string aName, unsigned short aId,
		double aProductionTime, unsigned short aBufferSize,
		unsigned short aRebuildTime, unsigned short aMeantime,
		unsigned short aRepartionTime, unsigned short stdev, unsigned short prev, bool first, bool last, bool end, bool droogband) :
name(aName), id(aId), productionTime(aProductionTime), bufferSize(aBufferSize), rebuildTime(aRebuildTime),
meantime(aMeantime), reparationTime(aRepartionTime), stdev(stdev), inBuffer(0), prev(prev), first(first), last(last), end(end), droogband(droogband){

}

unsigned short Machine::getBufferSize() const {
	return bufferSize;
}

unsigned short Machine::getId() const {
	return id;
}

unsigned short Machine::getMeantime() const {
	return meantime;
}

std::string Machine::getName() const {
	return name;
}

double Machine::getProductionTime() const {
	//products per minute
	return productionTime;
}

unsigned short Machine::getRebuildTime() const {
	return rebuildTime;
}

unsigned short Machine::getReparationTime() const {
	return reparationTime;
}

unsigned short Machine::getStdev() const {
	return stdev;
}

signed long Machine::getInBuffer() const {
	return inBuffer;
}

bool Machine::getMachineBroken() const {
	return machineBroken;
}

bool Machine::getMachineBusy() const {
	return machineBusy;
}

double Machine::getRemainingTime() const {
	return remainingTime;
}

bool Machine::getPreviousBufferEmpty() const {
	return previousBufferEmpty;
}

unsigned short Machine::getRandBrokenTime() const {
	return randBrokenTime;
}

unsigned long Machine::getTimesBroken() const {
	return timesBroken;
}

unsigned short Machine::getPrev() const{
	return prev;
}
bool Machine::getFirst() const{
	return first;
}
bool Machine::getLast() const{
	return last;
}
bool Machine::getEnd() const{
	return end;
}

bool Machine::getRun() const{
	return run;
}

void Machine::setRun(bool run) {
	this->run = run;
}

bool Machine::getDroogband() const{
	return droogband;
}

unsigned long long Machine::getRepairTimeTotal() const{
	return repairTimeTotal;
}

void Machine::setBufferSize(unsigned short bufferSize) {
	this->bufferSize = bufferSize;
}

void Machine::setId(unsigned short id) {
	this->id = id;
}

void Machine::setMeantime(unsigned short meantime) {
	this->meantime = meantime;
}

void Machine::setName(const std::string &name) {
	this->name = name;
}

void Machine::setProductionTime(double productionTime) {
	this->productionTime = productionTime;
}

void Machine::setRebuildTime(unsigned short rebuildTime) {
	this->rebuildTime = rebuildTime;
}

void Machine::setReparationTime(unsigned short reparationTime) {
	this->reparationTime = reparationTime;
}

void Machine::setStdev(unsigned short stdev) {
	this->stdev = stdev;
}

void Machine::setInBuffer(signed long inBuffer) {
	this->inBuffer = inBuffer;
}

void Machine::setMachineBroken(bool machineBroken) {
	this->machineBroken = machineBroken;
}

void Machine::setRemainingTime(double remainingTime) {
	this->remainingTime = remainingTime;
}

void Machine::setMachineBusy(bool machineBusy) {
	this->machineBusy = machineBusy;
}

void Machine::setPreviousBufferEmpty(bool previousBufferEmpty) {
	this->previousBufferEmpty = previousBufferEmpty;
}

void Machine::setTimesBroken(unsigned long timesBroken) {
	this->timesBroken = timesBroken;
}

void Machine::setRandBrokenTime(unsigned short randBrokenTime) {
	this->randBrokenTime = randBrokenTime;
}

void Machine::setRepairTimeTotal(unsigned long long repairTimeTotal){
	this->repairTimeTotal = repairTimeTotal;
}

unsigned short Machine::calculateRepairTime() {
	std::random_device dev;
	std::mt19937 rng(dev());
	std::normal_distribution<double> distribution(getReparationTime(), getStdev());
	unsigned short number = distribution(rng);
	return number;
}

void Machine::machineBrokenCalculate() {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> rand(0,
            ((getMeantime() * 2)));
    timeUntilBroken = rand(rng)*60*60;
}

