/*
 * ResponseHandler.hpp
 *
 *  Created on: Dec 4, 2019
 *      Author: chester
 */

#include "Message.hpp"

#ifndef LIBRARIES_LIB_NETWORK_RESPONSEHANDLER_HPP_
#define LIBRARIES_LIB_NETWORK_RESPONSEHANDLER_HPP_

namespace Messaging {

class ResponseHandler {
public:
	virtual ~ResponseHandler() {
	}
	/**
	 * The given argument contains the result/response of/to a previous request.
	 *
	 * @param aMessage
	 */
	virtual void handleResponse(const Messaging::Message &aMessage) = 0;

	/**
	 * After this function is called aMessage is returned as response to the requesting client,
	 * i.e. it should contain the result/response of/to the request.
	 *
	 * @param aMessage
	 */
	virtual void handleRequest( Messaging::Message& aMessage) = 0;


};
typedef std::shared_ptr< ResponseHandler > ResponseHandlerPtr;
// class ResponseHandler

}
;

#endif /* LIBRARIES_LIB_NETWORK_RESPONSEHANDLER_HPP_ */
