# CMakeList.txt: проект CMake для raspberry_modbus_rtu_to_tcp_and_route; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.0)

set (CMAKE_CXX_STANDARD 98)

project (rspberry_modbus_rtu_to_tcp_and_route
	VERSION 1.0.0
	DESCRIPTION "Daemon to make routung or additional acces to the maodbus TCP master via uart on the board"
	LANGUAGES CXX)

set (SRC
	src/config/open_uart.h
	src/config/open_tcp.h
	src/config/route_rules.h
	src/main.cpp
	src/main.h
	src/daemon.h
	src/daemon.cpp
	src/logging.h
	src/logging.cpp
	src/tty_settings.cpp
	src/tty_settings.h
	src/crc.cpp
	src/crc.h
	src/MainTcp.cpp
	src/MainTcp.h
	src/MainUart.cpp
	src/MainUart.h
)

add_executable (exe ${SRC} "src/check_errors.cpp")