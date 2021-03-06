#pragma once

#include "Core.h"

#include "Session.h"

#include <boost/asio.hpp>

namespace ftp::server {

	using tcp = boost::asio::ip::tcp;


	class Server {
	public:
		Server (const std::string & address, uint16_t port);

		~Server ();

		Server (const Server&) = delete;
		Server& operator=(const Server&) = delete;

	public:
		bool start ();

		void stop ();
	
		
	private:
		void acceptConnection ();

		void startSession (Ref<Session> session, boost::system::error_code ec);
	private:
		
		const std::string address;
		const uint16_t port;

		boost::asio::io_context ioc;
		tcp::acceptor acceptor;
	};
}