#include "logging.h"

void init_syslog()
{
	openlog("rp_mb_rtu-tcp_route", LOG_CONS | LOG_NDELAY | LOG_PID, LOG_DAEMON);
	syslog(LOG_INFO, "The raspberry daemon ModBus rtu to tcp and router started");
}

void simple_syslog_info_mes(const char* mes)
{
	syslog(LOG_INFO, "%s", mes);
}

void syslog_info_mes(const char* mes1, const char* mes2)
{
	syslog(LOG_INFO, "%s %s", mes1, mes2);
}

void syslog_crit_mes(const char* mes, const char* err)
{
	syslog(LOG_CRIT, "%s %s", mes, err);
}