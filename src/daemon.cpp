#include "daemon.h"

void init_process_as_daemon_and_openlog()
{
	close(0);
	close(1);
	close(2);
	open("/dev/null", O_RDONLY);
	open("/dev/null", O_WRONLY);
	open("/dev/null", O_WRONLY);
	if (fork() > 0)
		exit(1);
	setsid();
	if (fork() > 0)
		exit(1);
	init_syslog();
}