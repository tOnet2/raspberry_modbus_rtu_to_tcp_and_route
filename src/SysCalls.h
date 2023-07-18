#ifndef SYSCALLS_H_SENTRY
#define SYSCALLS_H_SENTRY

#include <inttypes.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <termios.h>
#include "Logging.h"
#include "CheckErrors.h"
#include "TtySettings.h"

class SysCalls {
public:
	static int32_t Open_tty(const char* tty, speed_t baud);
	static int32_t Inet_stream_socket();
	static void Connect(int32_t sock, const char* ip, uint16_t port);
	static ssize_t Read(int32_t fd, uint8_t* buf, ssize_t buf_len);
	static void Write(int32_t fd, const char* buf, ssize_t len);
	static void Send(int32_t s, const uint8_t* buf, ssize_t len);
	static ssize_t Recv(int32_t s, uint8_t* buf, ssize_t buf_len);
};

#endif
