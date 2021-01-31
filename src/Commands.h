#pragma once

#include "Core.h"
#include "Reply.h"

#include <map>

namespace ftp::server {

	enum class Command {
		ABOR, // - abort a file transfer
		CWD, // - change working directory
		DELE, // - delete a remote file
		LIST, // - list remote files
		MDTM, // - return the modification time of a file
		MKD, // - make a remote directory
		NLST, // - name list of remote directory
		PASS, // - send password
		PASV, // - enter passive mode
		PORT, // - open a data port
		PWD, // - print working directory
		QUIT, // - terminate the connection
		RETR, // - retrieve a remote file
		RMD, // - remove a remote directory
		RNFR, // - rename from
		RNTO, // - rename to
		SITE, // - site - specific commands
		SIZE, // - return the size of a file
		STOR, // - store a file on the remote host
		TYPE, // - set transfer type
		USER, // - send username

		ACCT, // - send account information
		APPE, // - append to a remote file
		CDUP, // - CWD to the parent of the current directory
		HELP, // - return help on using the server
		MODE, // - set transfer mode
		NOOP, // - do nothing
		REIN, // - reinitialize the connection
		STAT, // - return server status
		STOU, // - store a file uniquely
		STRU, // - set file transfer structure
		SYST  // - return system type
	};


	class Commands {
		using CommandHandler = std::function<Reply (const std::string & params)>;

	public:

		Commands ();

		~Commands () = default;


	public:

		Reply handle (const std::string& command, const std::string& params);

	private:
		
		Reply handlerHELP (const std::string& params);

	private:


		std::map<std::string, CommandHandler> commandsMapping;
	};


}