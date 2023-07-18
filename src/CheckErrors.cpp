#include "CheckErrors.h"

void CheckErrors::CheckZeroCritError(int32_t value, const char* mes)
{
	if (!value) {
		if (errno == ECONNREFUSED) {
			Logging::SyslogInfo("Cant connect to the ModBus TCP (is runtime running?)");
			sleep(5);
		} else {
			Logging::SyslogCrit(mes, strerror(errno));
			exit(EXIT_FAILURE);
		}
	}
}

void CheckErrors::CheckLessZeroCritError(int32_t value, const char* mes)
{
	if (value < 0) {
		Logging::SyslogCrit(mes, strerror(errno));
		exit(EXIT_FAILURE);
	}
}