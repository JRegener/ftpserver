#pragma once

#include "Core.h"


namespace ftp::server {
	
	// https://help.globalscape.com/help/cuteftpmacpro3/Numbered_FTP_status_and_error_codes.htm

	enum class ReplyCode {
		RESTART_MARKER_REPLY				= 110,
		SERVICE_READY_IN_NN_MINUTES			= 120,
		DATA_CONNECTION_ALREADY_OPEN		= 125,
		FILE_STATUS_OK						= 150,

		COMMAND_OK							= 200,
		COMMAND_NOT_IMPLEMENTED				= 202,
		SYSTEM_STATUS						= 211,
		DIRECTORY_STATUS					= 212,
		FILE_STATUS							= 213,
		HELP_MESSAGE						= 214,
		NAME_SYSTEM_TYPE					= 215,
		READY_FOR_NEW_USER					= 220,
		SERVICE_CLOSING_CONTROL_CONNECTION	= 221, 
		DATA_CONNECTION_OPEN				= 225,
		CLOSING_DATA_CONNECTION				= 226,
		ENTERING_PASSIVE_MODE				= 227,
		USER_LOGGED_IN						= 230,
		REQUESTED_FILE_ACTION_OK			= 250,
		PATHNAME_CREATED					= 257,

		USER_NAME_OK_NEED_PASSWORD			= 331,
		NEED_ACCOUNT_FOR_LOGIN				= 332,
		REQUESTED_FILE_ACTION_PENDING_FURTHER_INFORMATION = 350,


		SERVICE_NOT_AVAILABLE				= 421,
		CANT_OPEN_DATA_CONNECTION			= 425,
		CONNECTION_CLOSED_TRANSFER_ABORTED	= 426,
		FILE_UNAVAILABLE					= 450,
		REQESTED_ACTION_ABORTED				= 451,
		INSUFFICIENT_STORAGE_SPACE			= 452,

		SYNTAX_ERROR_COMMAND_UNRECOGNIZED	= 500,
		SYNTAX_ERROR_IN_PARAMETERS			= 501,
		BAD_SEQUENCE_OF_COMMANDS			= 503,
		COMMAND_NOT_IMPLEMENTED				= 504,
		USER_NOT_LOGGED_IN					= 530,
		NEED_ACCOUNT_FOR_STORING_FILES		= 532,
		FILE_NOT_FOUND_NO_ACCESS			= 550,
		EXCEEDED_STORAGE_ALLOCATION			= 552,
		FILE_NAME_NOT_ALLOWED				= 553
	};


	class Reply {
	public:
		Reply (ReplyCode code, const std::string & message) :
			code(code), message(message)
		{}

		~Reply () = default;

	public:

		inline ReplyCode getCode () { return code; }

		inline std::string getMessage () { return message; }

	private:

		ReplyCode code;
		std::string message;
	};
}