#include "Commands.h"

#include "Session.h"

namespace ftp::server {

#define STR(val) #val

	Commands::Commands () {
#if 0
		commandsMapping[STR (ABOR)] = ;
		commandsMapping[STR (CWD)] = ;
		commandsMapping[STR (DELE)] = ;
		commandsMapping[STR (LIST)] = ;
		commandsMapping[STR (MDTM)] = ;
		commandsMapping[STR (MKD)] = ;
		commandsMapping[STR (NLST)] = ;
		commandsMapping[STR (PASS)] = ;
		commandsMapping[STR (PASV)] = ;
		commandsMapping[STR (PORT)] = ;
		commandsMapping[STR (PWD)] = ;
		commandsMapping[STR (QUIT)] = ;
		commandsMapping[STR (RETR)] = ;
		commandsMapping[STR (RMD)] = ;
		commandsMapping[STR (RNFR)] = ;
		commandsMapping[STR (RNTO)] = ;
		commandsMapping[STR (SITE)] = ;
		commandsMapping[STR (SIZE)] = ;
		commandsMapping[STR (STOR)] = ;
		commandsMapping[STR (TYPE)] = ;
		commandsMapping[STR (USER)] = ;

		commandsMapping[STR (ACCT)] = ;
		commandsMapping[STR (APPE)] = ;
		commandsMapping[STR (CDUP)] = ;
#endif
		commandsMapping[STR (HELP)] = std::bind (&Commands::handlerHELP, this, std::placeholders::_1);

#if 0
		commandsMapping[STR (MODE)] = ;
		commandsMapping[STR (NOOP)] = ;
		commandsMapping[STR (REIN)] = ;
		commandsMapping[STR (STAT)] = ;
		commandsMapping[STR (STOU)] = ;
		commandsMapping[STR (STRU)] = ;
		commandsMapping[STR (SYST)] = ;

#endif
	}


	Reply Commands::handle (const std::string& command, const std::string& params) {
		auto handler = commandsMapping.find (command);
		
		if (handler != commandsMapping.end ()) {
			return handler->second (params);
		}

		return reply(...);
	}



	Reply Commands::handlerHELP (const std::string& params) {
		

	}
}


