#ifndef LOGGING_H_SENTRY
#define LOGGING_H_SENTRY

#include <syslog.h>

void init_syslog();
void simple_syslog_info_mes(const char* mes);
void syslog_info_mes(const char* mes1, const char* mes2);
void syslog_crit_mes(const char* mes, const char* err);

#endif