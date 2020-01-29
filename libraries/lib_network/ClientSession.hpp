/*
 * ClientSession.hpp
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
#include "ResponseHandler.hpp"
#include "Session.hpp"
#include <functional>

#include "Message.hpp"
#include "MessageHandler.hpp"

#ifndef LIBRARIES_LIB_NETWORK_CLIENTSESSION_HPP_
#define LIBRARIES_LIB_NETWORK_CLIENTSESSION_HPP_


namespace Messaging {
class ClientSession : virtual public Session
	{
		public:
			/**
			 *
			 * @param aMessage
			 * @param io_service
			 * @param aResponseHandler
			 */
			ClientSession( 	Message aMessage,
							boost::asio::io_service& io_service,
							ResponseHandlerPtr aResponseHandler) :
							Session( io_service),
							message( aMessage),
							responseHandler( aResponseHandler)
			{
			}
			/**
			 *
			 */
			~ClientSession()
			{
			}
			/**
			 * @see Session::start()
			 */
			virtual void start()
			{
				writeMessage( message);
			}
			/**
			 * @see Session::handleMessageRead( Message& aMessage)
			 */
			void handleMessageRead( Message& aMessage)
			{
				// This is the place where any reply message from the server should
				// be handled
				std::cout << "Printing message" << aMessage.asDebugString() << std::endl;
				responseHandler->handleResponse( aMessage);

				delete this;
			}
			/**
			 * @see Session::handleMessageWritten( Message& aMessage)
			 */
			virtual void handleMessageWritten(Message &aMessage)
			{
				// This *must* be the last function that is called after
				// sending a message because it will read the response...
				readMessage();
			}


		private:
			Message message;
			ResponseHandlerPtr responseHandler;
	};
}



#endif /* LIBRARIES_LIB_NETWORK_CLIENTSESSION_HPP_ */
