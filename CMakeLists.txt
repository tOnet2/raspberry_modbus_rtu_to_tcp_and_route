# CMakeList.txt: проект CMake для raspberry_modbus_rtu_to_tcp_and_route; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.0)

set (CMAKE_CXX_STANDARD 98)

project (rspberry_modbus_rtu_to_tcp_and_route
	VERSION 1.0.0
	DESCRIPTION "Daemon to make routung or additional acces to the modbus TCP master via uart on the board"
	LANGUAGES CXX)

set (SRC
	src/config/open_uart.h
	src/config/open_tcp.h
	src/config/route_rules.h
	src/main.cpp
	src/main.h
	src/Daemon.h
	src/Daemon.cpp
	src/Logging.h
	src/Logging.cpp
	src/TtySettings.cpp
	src/TtySettings.h
	src/Crc.cpp
	src/Crc.h
	src/GeneralTcp.cpp
	src/GeneralTcp.h
	src/GeneralUart.cpp
	src/GeneralUart.h
	src/SysCalls.cpp
	src/SysCalls.h
	src/TtySettings.cpp
	src/TtySettings.h
	src/CheckErrors.cpp
	src/CheckErrors.h
)

add_executable (exe ${SRC})