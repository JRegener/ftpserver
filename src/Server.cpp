#include "Server.h"


namespace ftp::server {

	Server::Server (const std::string& address, uint16_t port) :
		address (address),
		port (port),
		acceptor (ioc)
	{}


	Server::~Server () {
		stop ();
	}

	bool Server::start () {

		try {
			tcp::endpoint endpoint (boost::asio::ip::make_address (address), port);
			acceptor.open (endpoint.protocol ());
			acceptor.bind (endpoint);
			acceptor.listen (boost::asio::socket_base::max_listen_connections);

			acceptConnection ();

			return true;
		}
		catch (const std::exception& ex) {

			std::cout << ex.what () << std::endl;

		}

		return false;
	}

	void Server::stop () {

	}


	void Server::acceptConnection () {
		Ref<Session> session = CreateRef<Session> (ioc);

		acceptor.async_accept (
			session->getSocket (),
			std::bind (&Server::startSession, this, session, std::placeholders::_1));
	}

	void Server::startSession (Ref<Session> session, boost::system::error_code ec) {
		if (!ec) {
			//TODO: log error for debug

			session->start ();
		}

		acceptConnection ();
	}
}