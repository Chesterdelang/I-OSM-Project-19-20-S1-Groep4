/*
 * RequestHandler.hpp
 *
 *  Created on: Dec 4, 2019
 *      Author: chester
 */
#include "Message.hpp"

#ifndef LIBRARIES_LIB_NETWORK_REQUESTHANDLER_HPP_
#define LIBRARIES_LIB_NETWORK_REQUESTHANDLER_HPP_

namespace Messaging {
//	class ServerSession;

	class RequestHandler
	{
		public:
			virtual ~RequestHandler(){}
			/**
			 * After this function is called aMessage is returned as response to the requesting client,
			 * i.e. it should contain the result/response of/to the request.
			 *
			 * @param aMessage
			 */
			virtual void handleRequest( Messaging::Message& aMessage) = 0;

			virtual void attachServer(void* pServerSession) = 0;

			/**
			 * The given argument contains the result/response of/to a previous request.
			 *
			 * @param aMessage
			 */
			virtual void handleResponse(const Messaging::Message &aMessage) = 0;


	}; // class RequestHandler
	typedef std::shared_ptr<RequestHandler> RequestHandlerPtr;

}

#endif /* LIBRARIES_LIB_NETWORK_REQUESTHANDLER_HPP_ */
