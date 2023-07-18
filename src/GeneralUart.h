#ifndef GENERALUART_H_SENTRY
#define GENERALUART_H_SENTRY

#define GENERAL_UART_BUF_LEN 250

#include <inttypes.h>
#include "SysCalls.h"
#include "config/open_uart.h"

class GeneralUart {
	int32_t ud;
	uint8_t buf[GENERAL_UART_BUF_LEN];
	size_t rw_return;
public:
	GeneralUart();
	~GeneralUart();
	inline uint8_t* GetGeneralUartBuf() { return buf; };
	inline void ZeroBuf() { memset(buf, 0, rw_return); }
	void ReadGeneralUart();
	void WriteGeneralUart(const uint8_t* data, ssize_t data_len);
	uint8_t* ConvertRtuToTcp();
private:
	GeneralUart(const GeneralUart&) {}
	GeneralUart operator = (const GeneralUart&) {}
};

#endif