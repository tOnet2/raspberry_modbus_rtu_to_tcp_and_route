#include "main.h"

int main()
{
#ifdef DAEMON
	Daemon::InitProcessAsDaemonAndOpenLog();
#endif
	GeneralUart* general_uart = new GeneralUart();
	return 0;
}