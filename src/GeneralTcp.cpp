#include "GeneralTcp.h"

GeneralTcp::GeneralTcp()
{
	/* new socket */
	sock = socket(AF_INET, SOCK_STREAM, 0);
	check_less_zero_crit_error(sock, "Main Tcp socket: ");

	/* setting address */
	sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons((uint16_t)PORT);
	int32_t ipr = inet_pton(AF_INET, IP, &addr.sin_addr);
	check_zero_crit_error(ipr, "Inet Pton: ");

	/* connection */
	int32_t is_connected = -1;
	while (is_connected < 0) {
		is_connected = connect(sock, (const sockaddr*) & addr, sizeof(addr));
		check_less_zero_crit_error(is_connected, "Main Tcp Connect: ");
	}
	simple_syslog_info_mes("Connection to the ModBus TCP is established");
}

GeneralTcp::~GeneralTcp()
{
	close(sock);
}

void GeneralTcp::ConvertUartToTcp(const char* uart, ssize_t uart_len)
{
	if (tcp_len >= 0 && tcp_len <= 200)
		memset(buf, 0, tcp_len);
	else
		syslog_crit_mes("Big Tcp len: ", "In convert function");

	ssize_t tcp_len = uart_len + 4;
	uint8_t bytes = uart_len - 2;
	buf[5] = bytes;

	if (bytes <= 200 - 6)
		memcpy(buf + 6, uart, buf[5]);
	else
		simple_syslog_info_mes("Big pocket from uart!");
}