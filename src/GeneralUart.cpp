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
	r_return = SysCalls::Read(ud, buf, GENERALUART_BUF_LEN);
}

void GeneralUart::WriteGeneralUart(const uint8_t* data, ssize_t data_len)
{
	SysCalls::Write(ud, data, data_len);
}