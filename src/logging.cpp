#include "logging.h"

void init_syslog()
{
	openlog("rp_mb_rtu-tcp_route", LOG_CONS | LOG_NDELAY | LOG_PID, LOG_DAEMON);
	syslog(LOG_INFO, "The raspberry daemon ModBus rtu to tcp and router started");
}