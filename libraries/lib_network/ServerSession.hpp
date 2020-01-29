/*
 * ServerSession.hpp
 *
 *  Created on: Dec 4, 2019
 *      Author: chester
 */

#include "Session.hpp"

#include <string>
#include <iostream>
#include <sstream>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <functional>

#include "Message.hpp"
#include "RequestHandler.hpp"
#include "MessageHandler.hpp"

#ifndef LIBRARIES_LIB_NETWORK_SERVERSESSION_HPP_
#define LIBRARIES_LIB_NETWORK_SERVERSESSION_HPP_

namespace Messaging {
class ServerSession: virtual public Session {
public:
	/**
	 *
	 * @param io_service
	 * @param aRequestHandler
	 */
	ServerSession(boost::asio::io_service &io_service,
			RequestHandlerPtr aRequestHandler) :
			Session(io_service), requestHandler(aRequestHandler) {
		std::cout << "ServerSession called" << std::endl;
	}
	/**
	 *
	 */
	~ServerSession() {
	}
	/**
	 * @see Session::start()
	 */
	virtual void start() {
		readMessage();

//		requestHandler->attachServer(this);
	}

	void sendMsgTest() {
		Messaging::Message msg;
		msg.setBody("TEST from ProductionControl");
		writeMessage(msg);
	}
	/**
	 * @see Session::handleMessageRead( Message& aMessage)
	 */
	void handleMessageRead(Messaging::Message &aMessage) {
		requestHandler->handleRequest( aMessage);
		std::cout << aMessage.asString() << std::endl;

		switch (aMessage.getMessageType()) {

		case InitMachineMessage: {
			requestHandler->handleRequest( aMessage);
			writeMessage(aMessage);

			std::cout << "Binnen InitMachineMessage ServerSession" << aMessage.asString() << std::endl;

			break;
			//wait for X time (maybe in the main of machinecontrol?)
			//start init function
//			if (broken) {
//				Message newMessage;
//				newMessage.setBody("Machine is broken");
//				writeMessage(newMessage);
//				break;
//			} else {
//				Message newMessage;
//				newMessage.setBody("Machine initiated");
//				writeMessage(newMessage);
//				break;
//			}
		}

		case IdleMessage: {
			Message newMessage;
			newMessage.setBody("Machine is idle... waiting for product");
			writeMessage(newMessage);
			break;
		}

		case BusyMessage: {
			Message newMessage;
			newMessage.setBody("Machine is making a product");
			writeMessage(newMessage);
			break;
		}

		case RepairMessage: {
			Message newMessage;
			newMessage.setBody("Machine is broken");
			writeMessage(newMessage);
			break;
		}

		default :{
			Message newMessage;
			newMessage.setBody("FaultyMessage");
			writeMessage(newMessage);
			break;
		}
		}
//				writeMessage( aMessage);

// This is part of the original application. If one wants a stop message
// just leave this here. Otherwise think something up yourself.
		if (aMessage.getBody() == "stop") {

		}
	}
	/**
	 * @see Session::handleMessageWritten( Message& aMessage)
	 */
	void handleMessageWritten(Message &aMessage) {
		delete this; // why?????????
	}


private:
	RequestHandlerPtr requestHandler;
};
}
// class ServerSession
/**
 *
 */

#endif /* LIBRARIES_LIB_NETWORK_SERVERSESSION_HPP_ */
