/*
 * Client.hpp
 *
 *  Created on: Nov 19, 2019
 *      Author: chester-debian
 */

#include <memory>
#include <deque>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <cstdlib>
#include <cstring>
#include "Message.hpp"
#include "CommunicationService.hpp"
#include "ClientSession.hpp"
#include "Session.hpp"
#include "MessageHandler.hpp"
#include <iostream>

#ifndef LIBRARIES_LIB_NETWORK_CLIENTHANDLER_HPP_
#define LIBRARIES_LIB_NETWORK_CLIENTHANDLER_HPP_

namespace Messaging {
class ClientHandler {
public:
	/**
	 *
	 */
	ClientHandler(const std::string &aHost, const std::string &aPort,
			ResponseHandlerPtr aResponseHandler) :
			io_service(
					CommunicationService::getCommunicationService().getIOService()), host(
					aHost), port(aPort), responseHandler(aResponseHandler) {
		std::cout << "Client started" << std::endl;
	}
	/**
	 *
	 */
	~ClientHandler() {
	}
	void dispatchMessage(Message &aMessage) {
		// Create the session that will handle the next outgoing connection
		ClientSession *session = new ClientSession(aMessage, io_service, responseHandler);

		// Build up the remote address to which we will connect
		boost::asio::ip::tcp::resolver resolver(io_service);
		boost::asio::ip::tcp::resolver::query query(boost::asio::ip::tcp::v4(),
				host, port);
		boost::asio::ip::tcp::resolver::iterator endpoint_iterator =
				resolver.resolve(query);
		boost::asio::ip::tcp::endpoint endpoint = *endpoint_iterator;
		// Let the session handle any outgoing messages
		session->getSocket().async_connect(endpoint,
				boost::bind(&ClientHandler::handleConnect, this, session,
						boost::asio::placeholders::error));
		io_service.run();
	}
	/**
	 *
	 */
	void handleConnect(ClientSession *aSession,
			const boost::system::error_code &error) {
		if (!error) {
			aSession->start();
		} else {
			std::cout << "A error occured, you were trying to connect to:  " << std::endl;
			std::cout << "Host = " + host << std::endl;
			std::cout << "Port = " + port << std::endl;
			std::string sessionDestination = "host = " + host + ", port =  "
					+ port;
			delete aSession;
			throw std::runtime_error(
					__PRETTY_FUNCTION__ + std::string(": ") + error.message()
							+ ", " + sessionDestination);
		}
	}

private:
	boost::asio::io_service &io_service;
	std::string host;
	std::string port;
	ResponseHandlerPtr responseHandler;
};
} // namespace Messaging

#endif /*_LIBRARIES_LIB_NETWORK_CLIENTHANDLER_HPP_ */
