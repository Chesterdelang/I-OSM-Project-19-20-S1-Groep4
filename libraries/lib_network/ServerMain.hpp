/*
 * ServerMain.hpp
 *
 *  Created on: Nov 26, 2019
 *      Author: chester-debian
 */

#ifndef LIBRARIES_LIB_NETWORK_SERVERMAIN_HPP_
#define LIBRARIES_LIB_NETWORK_SERVERMAIN_HPP_

#include <memory>
#include <vector>
#include <thread>
#include <iostream>
#include <string>
#include "Session.hpp"
#include <boost/asio.hpp>
#include <system_error>
#include "ServerSession.hpp"
#include "MessageHandler.hpp"
#include "ResponseHandler.hpp"
#include "RequestHandler.hpp"
#include "ServerSession.hpp"
#include "CommunicationService.hpp"
#include <boost/thread/thread.hpp>
#include "Config.hpp"

namespace Messaging {
class ServerMain {
public:
	ServerMain(short port,
			RequestHandlerPtr aRequestHandler) :
			io_service(
					CommunicationService::getCommunicationService().getIOService()), acceptor(
					io_service,
					boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(),
							port)), requestHandler(aRequestHandler) {
		// start handling incoming connections
		handleAccept(nullptr, boost::system::error_code());
	}

	~ServerMain() {
	}

	/**
	 * Looks for a session that calls to this server. It accepts the incoming connection with async_accept.
	 * It will then open a new session where it can keep receiving messages.
	 * @param aSession
	 * @param error
	 */
	void handleAccept(ServerSession *aSession,
			const boost::system::error_code &error) {
		if (!error) {
			// Create the session that will handle the next incoming connection
			ServerSession *session = new ServerSession(io_service,
					requestHandler);
			// Let the acceptor wait for any new incoming connections
			// and let it call server::handle_accept on the happy occasion
			acceptor.async_accept(session->getSocket(),
					boost::bind(&ServerMain::handleAccept, this, session,
							boost::asio::placeholders::error));
			// If there is a session, start it up..
			if (aSession) {
				aSession->start();

			}
		} else {
			delete aSession;
			throw std::runtime_error(
					__PRETTY_FUNCTION__ + std::string(": ") + error.message());
		}
	}

private:

	boost::asio::io_service &io_service;
	boost::asio::ip::tcp::acceptor acceptor;
	RequestHandlerPtr requestHandler;
}
;
}
#endif /* LIBRARIES_LIB_NETWORK_SERVERMAIN_HPP_ */

