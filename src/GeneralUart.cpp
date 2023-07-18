#include "GeneralUart.h"

GeneralUart::GeneralUart()
{
	ud = SysCalls::Open_tty(TTY, BAUD);
}

GeneralUart::~GeneralUart()
{
	if (ud)
		close(ud);
}

void GeneralUart::ReadGeneralUart()
{
	SysCalls::Read(ud, buf, GENERAL_UART_BUF_LEN);
}

void GeneralUart::WriteGeneralUart(const uint8_t* data, ssize_t data_len)
{
	SysCalls::Write(ud, data, data_len);
}