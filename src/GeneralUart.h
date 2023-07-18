#ifndef GENERALUART_H_SENTRY
#define GENERALUART_H_SENTRY

#include <inttypes.h>
#include "SysCalls.h"
#include "config/open_uart.h"
#include "Crc.h"

class GeneralUart {
	int32_t ud;
	uint8_t buf[GENERALUART_BUF_LEN];
	ssize_t r_return;
public:
	GeneralUart();
	~GeneralUart();
	inline uint8_t* GetGeneralUartBuf() { return buf; };
	inline void ZeroBuf() { memset(buf, 0, r_return); r_return = 0; }
	void ReadGeneralUart();
	void WriteGeneralUart(const uint8_t* data, ssize_t data_len);
	uint8_t* ConvertRtuToTcp();
private:
	GeneralUart(const GeneralUart&) {}
	void operator = (const GeneralUart&) {}
};

#endif