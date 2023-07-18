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
	if (!Crc::CheckCrc((const unsigned char*)buf, r_return)) {
		ZeroBuf();
		SysCalls::Write(ud, "Invalid CRC", 11);
	}
}

void GeneralUart::WriteGeneralUart(const uint8_t* data, ssize_t data_len)
{
	SysCalls::Write(ud, data, data_len);
}

uint8_t* GeneralUart::ConvertRtuToTcp()
{
	ssize_t new_len = r_return + 2;
	uint8_t* b = new uint8_t[new_len]();
	b[5] = (size_t)r_return - 4;
	memcpy(b + 6, buf, b[5]);
	return b;
}