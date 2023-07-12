#include "daemon.h"
#define DAEMON 1
int main()
{
#if DAEMON
	init_process_as_daemon_and_openlog();
#endif

	return 0;
}