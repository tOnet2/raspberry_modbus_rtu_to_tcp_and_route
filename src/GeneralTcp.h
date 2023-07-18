#ifndef GENERALTCP_H_SENTRY
#define GENERALTCP_H_SENTRY

#include "config/open_tcp.h"
#include "Logging.h"
#include "CheckErrors.h"
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
	inline uint8_t* GetBuf() { return buf; }
	inline ssize_t GetTcpLen() { return tcp_len; }
	void ConvertUartToTcp(const char* uart, ssize_t uart_len);
private:
	MainTcp(const MainTcp&) {}
	void operator = (const MainTcp&) {}
};

#endif