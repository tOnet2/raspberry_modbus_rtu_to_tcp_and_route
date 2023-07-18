#include "Crc.h"

uint16_t Crc::ModbusCrc16(const unsigned char * buf, ssize_t len)
{
	uint8_t crc_hi = 0xFF;
    uint8_t crc_lo = 0xFF;
    unsigned int i;
    while (len--) {
        i = crc_lo ^ *buf++;
        crc_lo = crc_hi ^ table_crc_hi[i];
        crc_hi = table_crc_lo[i];
    }
    return (crc_hi << 8 | crc_lo);
}

bool Crc::CheckCrc(const unsigned char * buf, ssize_t len)
{
	uint16_t crc = ModbusCrc16(buf, len - 2);
	uint8_t lo = *(buf + len - 2);
	uint8_t hi = *(buf + len - 1);
    uint8_t crc_from_buf = (hi << 8) + lo;
	if (crc_from_buf != crc)
		return false;
	return true;
}
