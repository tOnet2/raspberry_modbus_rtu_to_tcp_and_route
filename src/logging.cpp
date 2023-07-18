#include "Logging.h"

void Logging::InitSyslog()
{
#ifndef ROUTER
	openlog("modbus-rtu-to-tcp", LOG_CONS | LOG_NDELAY | LOG_PID, LOG_DAEMON);
#else
	openlog("modbus-rtu-to-tcp-plus-router", LOG_CONS | LOG_NDELAY | LOG_PID, LOG_DAEMON);
#endif
}

void Logging::SyslogInfo(const char* mes)
{
	syslog(LOG_INFO, "%s", mes);
}

void Logging::SyslogInfo2(const char* mes1, const char* mes2)
{
	syslog(LOG_INFO, "%s: %s", mes1, mes2);
}

void Logging::SyslogCrit(const char* mes1, const char* mes2)
{
	syslog(LOG_CRIT, "%s: %s", mes1, mes2);
}