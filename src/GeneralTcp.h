#ifndef GENERALTCP_H_SENTRY
#define GENERALTCP_H_SENTRY

#define GENERALTCP_BUF_LEN 250

#include <inttypes.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include "config/open_tcp.h"

class GeneralTcp {
	int32_t sock;
	uint8_t buf[GENERALTCP_BUF_LEN];
	ssize_t r_return;
public:
	GeneralTcp();
	~GeneralTcp();
	inline uint8_t* GetGeneralTcpBuf() { return buf; }
	ssize_t SendGeneralTcp(uint8_t *data, ssize_t data_len);
	ssize_t RecvGeneralTcp();
	inline void ZeroBuf() { memset(buf, 0, r_return); }
	uint8_t* ConvertTcpToRtu();
private:
	GeneralTcp(const GeneralTcp&) {}
	void operator = (const GeneralTcp&) {}
};

#endif