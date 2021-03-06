/*
 * CommunicationService.hpp
 *
 *  Created on: Dec 3, 2019
 *      Author: chester-debian
 */

#ifndef LIBRARIES_LIB_NETWORK_COMMUNICATIONSERVICE_HPP_
#define LIBRARIES_LIB_NETWORK_COMMUNICATIONSERVICE_HPP_

#include <boost/asio.hpp>

#include "MessageHandler.hpp"

namespace Messaging
{
	/*
	 *
	 */
	class CommunicationService
	{
		public:
			/**
			 *
			 */
			static CommunicationService& getCommunicationService();
			/**
			 * This function is public because otherwise it the classes Session, Server and Client
			 * have to be friends
			 */
			boost::asio::io_service& getIOService();
			/**
			 * Runs the given aRequestHandler at the given port until boost::asio::io_service::io_service.run()
			 * returns. In the limited context of RobotWorld this is done by sending a "stop"-message.
			 * @see ServerSession::handleMessageRead( Message& aMessage) for the implementation.
			 */
			void runRequestHandler(	RequestHandlerPtr aRequestHandler,
									unsigned short aPort = 1234);
			/**
			 * Uses std::stoi for string to *int* conversion. Throws the exceptions that std::stoi may throw.
			 * If int > max short you lose...
			 */
			void runRequestHandler(	RequestHandlerPtr aRequestHandler,
									const std::string& aPort)
			{
				runRequestHandler(aRequestHandler, static_cast<unsigned short>(std::stoi(aPort)));
			}
		private:
			/**
			 *
			 */
			CommunicationService();
			/**
			 *
			 */
			virtual ~CommunicationService();
			/**
			 *
			 */
			void runRequestHandlerWorker( 	RequestHandlerPtr aRequestHandler,
											unsigned short aPort);
			/**
			 *
			 */
			std::thread requestHandlerThread;
			/**
			 *
			 */
			boost::asio::io_service io_service;
	};
	// class CommunicationService
} // namespace Messaging




#endif /* LIBRARIES_LIB_NETWORK_COMMUNICATIONSERVICE_HPP_ */
