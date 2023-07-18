#include "SysCalls.h"

int32_t SysCalls::Open_tty(const char * tty, speed_t baud)
{
	int32_t tty_fd = open(tty, O_RDWR | O_NOCTTY | O_ASYNC);
	CheckErrors::CheckZeroCritError(tty_fd, "Open tty: ");
	Logging::SyslogInfo("Tty is opened");
	TtySettings::SetTtyAsUart(tty_fd, baud);
	Logging::SyslogInfo("Tty is configured");
	return tty_fd;
}

int32_t SysCalls::Inet_stream_socket()
{
	int s = socket(AF_INET, SOCK_STREAM, 0);
	CheckErrors::CheckLessZeroCritError(s, "Socket: ");
	Logging::SyslogInfo("Socket inited");
	return s;
}

void SysCalls::Connect(int32_t sock, const char * ip, uint16_t port)
{
	sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);
	int32_t ipr = inet_pton(AF_INET, ip, &addr.sin_addr);
	CheckErrors::CheckLessZeroCritError(ipr, "Ipr: ");
	CheckErrors::CheckZeroCritError(ipr, "Bad IP: ");
	int32_t cr = 0;
	while (1) {
		cr = connect(sock, (const struct sockaddr*) & addr, sizeof(addr));
		if (cr < 0) {
			if (errno == ECONNREFUSED) {
				Logging::SyslogInfo("Cant connect to the ModBus TCP (is runtime not running?)");
				sleep(5);
			}
			else
				CheckErrors::CheckLessZeroCritError(cr, "Connect: ");
		} else break;
	}
	Logging::SyslogInfo("Connection to the ModBus TCP is established");
}

ssize_t SysCalls::Read(int32_t fd, uint8_t* buf, ssize_t buf_len)
{
	ssize_t rr = read(fd, buf, (size_t)buf_len);
	CheckErrors::CheckLessZeroCritError(rr, "Read: ");
	return rr;
}

void SysCalls::Write(int32_t fd, const char *buf, ssize_t len)
{
	ssize_t wr = write(fd, buf, (size_t)len);
	CheckErrors::CheckLessZeroCritError(wr, "Write: ");
}

void SysCalls::Send(int32_t s, const uint8_t* buf, ssize_t len)
{
	ssize_t sr = send(s, (const uint8_t*)buf, (size_t)len, 0);
	CheckErrors::CheckLessZeroCritError(sr, "Send: ");
}

ssize_t SysCalls::Recv(int32_t s, uint8_t* buf, ssize_t buf_len)
{
	ssize_t rr = recv(s, buf, (size_t)buf_len, 0);
	CheckErrors::CheckLessZeroCritError(rr, "Recv: ");
	return rr;
}
