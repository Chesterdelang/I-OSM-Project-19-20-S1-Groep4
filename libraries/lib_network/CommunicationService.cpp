/*
 * CommunicationService.cpp
 *
 *  Created on: Dec 3, 2019
 *      Author: chester-debian
 */

#include "CommunicationService.hpp"
#include "ServerMain.hpp"
#include <iostream>

namespace Messaging
{
	/**
	 *
	 */
	/* static */ CommunicationService& CommunicationService::getCommunicationService()
	{
		static CommunicationService communicationService;
		return communicationService;
	}
	/**
	 *
	 */
	boost::asio::io_service& CommunicationService::getIOService()
	{
		return io_service;
	}
	/**
	 *
	 */
	void CommunicationService::runRequestHandler( 	RequestHandlerPtr aRequestHandler,
													unsigned short aPort /* = 12345*/)
	{
		runRequestHandlerWorker(aRequestHandler, aPort);
	}
	/**
	 *
	 */
	CommunicationService::CommunicationService()
	{
	}
	/**
	 *
	 */
	CommunicationService::~CommunicationService()
	{
	}
	/**
	 *
	 */
	void CommunicationService::runRequestHandlerWorker(	RequestHandlerPtr aRequestHandler, unsigned short aPort)
	{
		try
		{
			// Create the server object. This must be alive while the program runs
			Messaging::ServerMain server(aPort, aRequestHandler);

			// Run the service until further notice
			getIOService().run();
		}

		catch (std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch (...)
		{
			std::cerr << "Unknown exception" << std::endl;
		}

	}
} // namespace Messaging



