#pragma once

#include "Core.h"

#include <boost/asio.hpp>


namespace ftp::server {

	using tcp = boost::asio::ip::tcp;

	class Session : public std::enable_shared_from_this<Session> {
	public:
		explicit Session (boost::asio::io_context & ioc);

		~Session ();


	public:
		bool start ();


		tcp::socket& getSocket () { return socket; }

	private:
		void readRequest ();

		void processRequest (boost::system::error_code, size_t length);

		void handleCommand (const std::string& command, const std::string& body);

		void sendResponse ();

	private:
		boost::asio::io_context::strand strand;
		tcp::socket socket;


		boost::asio::streambuf command_buffer;
	};

}