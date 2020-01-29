/*
 * Copyright (c) 2015-2016 Joost Kraaijeveld. See license.txt for details.
 * For information, bug reports and additions send an e-mail to ProjectTemplate@Askesis.nl.
 *
 * Author: jkr
 */

#include <iostream>
#include <MachineControl.hpp>
#include <thread>
#include <chrono>

#include "../Config/ProjectTemplateConfig.h"

int main(int argc, char **argv) {

	Machine aMachine("", 0, 2, 0, 0, 500, 0, 0);
	std::shared_ptr<MachineControl> machineControl = std::make_shared<
			MachineControl>(aMachine);
	std::shared_ptr<MachineControl> gp2 = machineControl;
	//std::string string = "|startMachine=|id=1,|name=Zagen,|bufferSize=10,|productionTime=0,|rebuildTime=12,|meantime=15,|reparationTime=17,|stdev=10";

	std::string input;
	std::cout << "Type 'start' to start machine: ";

	std::cin >> input;
	if (input == "start") {
		//machineControl.readMachineMessage(string);
		//machineControl.checkRestrerendeTijd(120.0);
	} else if (input == "stop") {
		std::cout << "Stopping program" << std::endl;
		return 0;
	}
//	} else if (input == "kaas") {
//		Messaging::Message aMessage;
//		aMessage.setMessageType(Messaging::ServerMessage);
//		aMessage.setBody("Server");
//		machineControl->startClient(aMessage);
//	} else if (input == "s") {
//		Messaging::Message aMessage;
//		aMessage.setMessageType(Messaging::ProductMessage);
//		aMessage.setBody("Ik wil kaas");
//		machineControl->startClient(aMessage);
//	} else if (input == "TestServer") {
//		Messaging::Message aMessage;
//		aMessage.setMessageType(Messaging::TestServerMessage);
//		aMessage.setBody("Dit is vanuit de Client de test");
//		machineControl->startClient(aMessage);
//	} else if (input == "init") {
////		state = initMachine;
//	} else {
//		Messaging::Message aMessage;
//		aMessage.setBody(input);
//		machineControl->startClient(aMessage);
//	}


//
//switch(state) {
//	case 1: {
//	Messaging::Message aMessage;
//	aMessage.setMessageType(Messaging::InitMachineMessage);
//	aMessage.setBody("Initiate Machine");
//	machineControl->startClient(aMessage);
//		break;
//	}
//	case 2: {
//
//		Messaging::Message aMessage;
//		aMessage.setMessageType(Messaging::IdleMessage);
//		aMessage.setBody("Idle");
//		machineControl->startClient(aMessage);
//		break;
//	}
//	case 3: {
//
//		Messaging::Message aMessage;
//		aMessage.setMessageType(Messaging::BusyMessage);
//		aMessage.setBody("Busy");
//		machineControl->startClient(aMessage);
//		break;
//	}
//	case 4: {
//
//		Messaging::Message aMessage;
//		aMessage.setMessageType(Messaging::RepairMessage);
//		aMessage.setBody("Repair Machine");
//		machineControl->startClient(aMessage);
//		break;
//	}
//	//	default;
//}

	while(1);

}
