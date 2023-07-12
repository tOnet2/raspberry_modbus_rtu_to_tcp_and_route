#ifndef MAINTCP_H_SENTRY
#define MAINTCP_H_SENTRY

#include "config/open_tcp.h"
#include "logging.h"
#include "check_errors.h"
#include <inttypes.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

class MainTcp {
	int32_t sock;
	uint8_t buf[200];
	ssize_t tcp_len;
public:
	MainTcp();
	~MainTcp();
	ssize_t Send();
	ssize_t Recv();
	void ConvertUartToTcp(const char* uart, ssize_t uart_len);
private:
	MainTcp(const MainTcp&) {}
	MainTcp& operator=(const MainTcp&) {}
};

#endif