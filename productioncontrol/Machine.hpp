/*
 * Machine.hpp
 *
 *  Created on: Nov 18, 2019
 *      Author: chester-debian
 */
#include <iostream>

#ifndef MACHINE_HPP_
#define MACHINE_HPP_

#include <random>

class Machine {
public:
	Machine(std::string aName, unsigned short aId,
			double aProductionTime, unsigned short aBufferSize,
			unsigned short aRebuildTime, unsigned short aMeantime,
			unsigned short aRepartionTime, unsigned short stdev, unsigned short prev, bool first, bool last, bool end, bool droogband);

	unsigned short getBufferSize() const;
	unsigned short getId() const;
	unsigned short getMeantime() const;
	std::string getName() const;
	double getProductionTime() const;
	unsigned short getRebuildTime() const;
	unsigned short getReparationTime() const;
	unsigned short getStdev() const;
	signed long getInBuffer() const;
	bool getMachineBroken() const;
	double getRemainingTime() const;
	bool getMachineBusy() const;
	unsigned short getDuration() const;
	bool getPreviousBufferEmpty() const;
	unsigned short getRandBrokenTime() const;
	unsigned long getTimesBroken() const;
	unsigned short getPrev() const;
	bool getFirst() const;
	bool getLast() const;
	bool getEnd() const;
	bool getRun() const;
	bool getDroogband() const;
	unsigned long long getRepairTimeTotal() const;


	void setBufferSize(unsigned short bufferSize);
	void setId(unsigned short id);
	void setMeantime(unsigned short meantime);
	void setName(const std::string &name);
	void setProductionTime(double produtionTime);
	void setRebuildTime(unsigned short rebuildTime);
	void setReparationTime(unsigned short reparationTime);
	void setStdev(unsigned short stdev);
	void setInBuffer(signed long inBuffer);
	void setMachineBroken(bool machineBroken);
	void setRemainingTime(double remainingTime);
	void setMachineBusy(bool machineBusy);
	void setPreviousBufferEmpty(bool previousBufferEmpty);
	void setRandBrokenTime(unsigned short setRandBrokenTime);
	void setTimesBroken(unsigned long timesBroken);
	void setRun(bool run);
	void setRepairTimeTotal(unsigned long long repairTimeTotal);

	void machineBrokenCalculate();

	/**
	 * Function for calculating reparation time using standard deviation
	 */
	unsigned short calculateRepairTime();

	std::vector<unsigned long> machineMadeDay;
	//unsigned long long repairTimeTotal =0;

	unsigned long productMade = 0;
	unsigned long long timeUntilBroken;

private:
	std::string name;
	unsigned short id;
	double productionTime;
	unsigned short bufferSize;
	unsigned short rebuildTime;
	long long meantime;
	unsigned short reparationTime;
	unsigned short stdev;
	double remainingTime;
	bool machineBusy;
	bool machineBroken = false;
	signed long inBuffer;
	bool previousBufferEmpty;
	unsigned short randBrokenTime;
	unsigned long timesBroken = 0;
	unsigned short prev;
	bool first;
	bool last;
	bool end;
	bool droogband;
	bool run = false;
	unsigned long long repairTimeTotal;
};

#endif /*_MACHINE_HPP_ */
