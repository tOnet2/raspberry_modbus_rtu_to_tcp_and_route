#ifndef LOGGING_H_SENTRY
#define LOGGING_H_SENTRY

#include <syslog.h>

class Logging {
public:
	static void InitSyslog();
	static void SyslogInfo(const char* mes);
	static void SyslogInfo2(const char* mes1, const char* mes2);
	static void SyslogCrit(const char* mes, const char* err);
};

#endif