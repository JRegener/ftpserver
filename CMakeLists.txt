cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
project("ftpserver" CXX C)

set (SERVER_MAJOR 0)
set (SERVER_MINOR 0)
set (SERVER_PATCH 1)
set (SERVER_VERSION "${SERVER_MAJOR}.${SERVER_MINOR}.${SERVER_PATCH}")

set_property (GLOBAL PROPERTY USE_FOLDERS ON)


set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

if (MSVC)

	option(ENABLE_STATIC_LINK "Собирать проект с флагом /MT" ON)
	mark_as_advanced(ENABLE_STATIC_LINK)
	if (ENABLE_STATIC_LINK STREQUAL ON)
		set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
		set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELWITHDEBINFO} /MT")
		set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
		set(CMAKE_CXX_FLAGS_MINSIZEREL "${CMAKE_CXX_FLAGS_MINSIZEREL} /MT")
	endif ()

else ()

	option(ENABLE_STATIC_LINK "Линковать библиотеки статически" ON)
	mark_as_advanced(ENABLE_STATIC_LINK)

endif ()


set (LIBS "")
set (INCLUDES "")


set (Boost_USE_MULTITHREADED ON)
set (Boost_FIND_QUIETLY ON)
if ("${ENABLE_STATIC_LINK}" STREQUAL "ON")
	set (Boost_USE_STATIC_LIBS ON)
	set (Boost_USE_STATIC_RUNTIME ON)
endif()

find_package (Boost 1.67 REQUIRED COMPONENTS system filesystem thread regex timer)
if (Boost_FOUND)
	if (MSVC)
		# suppress messages about unknown compiler for MSVC, because
		# compiler updates occure faster than boost releases :-)
		add_definitions (-DBOOST_CONFIG_SUPPRESS_OUTDATED_MESSAGE)
	endif ()
	
	set (INCLUDES ${INCLUDES} ${Boost_INCLUDE_DIRS})
	set (LIBS ${LIBS} Boost::boost Boost::filesystem Boost::thread Boost::regex Boost::timer Boost::date_time)
endif ()


set (SRC_FILES
	src/Core.h
	src/main.cpp
	src/Server.h
	src/Server.cpp
	src/Session.h
	src/Session.cpp
	src/Commands.h
	src/Commands.cpp
	src/Reply.h
	src/Reply.cpp
)

add_executable (ftpserver ${SRC_FILES})
target_link_libraries (ftpserver PRIVATE ${LIBS})
target_include_directories (ftpserver PRIVATE ${INCLUDES})

