#include "Session.h"

#include "Commands.h"

#include <boost/bind/bind.hpp>
#include <iostream>


namespace ftp::server {

	Session::Session (boost::asio::io_context& ioc) : 
		socket(ioc),
		strand(ioc)
	{ }

	Session::~Session () {

	}

	bool Session::start () {
		
	}

	void Session::readRequest () {
		boost::asio::async_read_until (socket, command_buffer, "\n",
			boost::asio::bind_executor (
				strand,
				boost::bind (&Session::processRequest, shared_from_this (), 
					boost::asio::placeholders::error,
					boost::asio::placeholders::bytes_transferred)));
	}

	void Session::processRequest (boost::system::error_code ec, size_t length) {
		using isiter = std::istreambuf_iterator<char>;
		
		if (ec) {

		}

		std::string message ((isiter (&command_buffer)), isiter ());
		size_t pos = message.find_first_of (' ');

		handleCommand (message.substr(0, pos), message.substr (pos + 1));
	}

	void Session::handleCommand (const std::string& command, const std::string& body) {

	}



	void Session::sendResponse () {

	}

}