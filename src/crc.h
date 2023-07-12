#ifndef CRC_H_SENTRY
#define CRC_H_SENTRY

#include <inttypes.h>
#include <sys/types.h>

uint16_t modbus_crc16(const unsigned char * buf, ssize_t len);
bool check_crc(const unsigned char * buf, ssize_t len);

#endif
