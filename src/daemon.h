#ifndef DAEMON_H_SENTRY
#define DAEMON_H_SENTRY

#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include "logging.h"

void init_process_as_daemon_and_openlog();

#endif