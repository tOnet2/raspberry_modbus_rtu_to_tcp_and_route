#ifndef TTYSETTINGS_H_SENTRY
#define TTYSETTINGS_H_SENTRY

#include <termios.h>
#include <unistd.h>
#include <inttypes.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

class TtySettings {
public:
	static void SetTtyAsUart(int32_t fd, speed_t baud);
};

#endif
