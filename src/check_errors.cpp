#include "check_errors.h"

void check_zero_crit_error(int32_t value, const char* mes)
{
	if (!value) {
		if (errno == ECONNREFUSED) {
			simple_syslog_info_mes("Cant connect to the ModBus TCP (is runtime not running?)");
			sleep(5);
		} else {
			syslog_crit_mes(mes, strerror(errno));
			exit(EXIT_FAILURE);
		}
	}
}

void check_less_zero_crit_error(int32_t value, const char* mes)
{
	if (value < 0) {
		syslog_crit_mes(mes, strerror(errno));
		exit(EXIT_FAILURE);
	}
}