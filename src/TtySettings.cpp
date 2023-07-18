#include "TtySettings.h"

void TtySettings::SetTtyAsUart(int32_t fd, speed_t baud)
{
	struct termios old_p;
	struct termios new_p;
	if (tcgetattr(fd, &old_p) < 0) {
		fprintf(stderr, "Termios: %s", strerror(errno));
		exit(EXIT_FAILURE);
	}
	memcpy(&new_p, &old_p, sizeof(old_p));

	/* set the local flags of the terminal
	 * close all echo and canon style
	 */
	new_p.c_lflag &= ~(ICANON | ISIG | ECHO | ECHOE | ECHONL);

	/* set the input flags of the terminal
	 * ignore special symbols
	 */
	new_p.c_iflag &= ~(IXON | IXOFF | IXANY | IGNBRK | BRKINT
		| PARMRK | ISTRIP | INLCR | IGNCR | ICRNL);

	/* set the output flags of the terminal
	 * prevent interp of output bytes 
	 */
	new_p.c_oflag &= ~(OPOST | ONLCR);

	/* set the control modes of the terminal
	 * prevent parity bit, set one stop bit, disable rts/cts
	 * set 8 bit size of byte
	 * turn on read and ignore ctrl lines
	 */
	new_p.c_cflag &= ~(CRTSCTS | PARENB | CSTOPB | CSIZE);
	new_p.c_cflag |= CS8 | CREAD | CLOCAL;


	/* set blocking via setting wait 1 symbol minimum */
	new_p.c_cc[VMIN] = 1;
	new_p.c_cc[VTIME] = 0;

	/* set speed baud */
	cfsetispeed(&new_p, baud);
	cfsetospeed(&new_p, baud);

	if (tcsetattr(fd, TCSANOW, &new_p) < 0) {
		fprintf(stderr, "Termios: %s", strerror(errno));
		exit(EXIT_FAILURE);
	}
}