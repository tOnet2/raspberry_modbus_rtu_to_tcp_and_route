#ifndef DAEMON_H_SENTRY
#define DAEMON_H_SENTRY

#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include "Logging.h"

class Daemon {
public:
	static void InitProcessAsDaemonAndOpenLog();
};

#endif