/*
 * MessageHandler.hpp
 *
 *  Created on: Dec 3, 2019
 *      Author: chester-debian
 */

#ifndef LIBRARIES_LIB_NETWORK_MESSAGEHANDLER_HPP_
#define LIBRARIES_LIB_NETWORK_MESSAGEHANDLER_HPP_

#include <memory>
#include <iostream>
#include "ResponseHandler.hpp"
#include "RequestHandler.hpp"

/**
 *
 */
namespace Messaging
{
	class Message;

	/**
	 * Base server interface for handling remote requests
	 * Classes derived from this interface can serve as server in the Messaging protocol
	 * by implementing this interface.
	 */
	typedef std::shared_ptr<RequestHandler> RequestHandlerPtr;
	/**
	 * Base client interface for handling remote responses
	 * Classes derived from this interface can serve as client in the Messaging protocol
	 * by implementing this interface.
	 */
	typedef std::shared_ptr< ResponseHandler > ResponseHandlerPtr;
	/**
	 * Convenience interface class for a class that acts both as server and client in the Messaging protocol
	 * @see RequestHandler::handleRequest( Message& aMessage)
	 * @see ResponseHandler::handleResponse( Message& aMessage)
	 */
	class MessageHandler : public RequestHandler, public ResponseHandler
	{
	}; // class MessageHandler

} // namespace Messaging

#endif /* LIBRARIES_LIB_NETWORK_MESSAGEHANDLER_HPP_ */
