#ifndef CHECKERRORS_H_SENTRY
#define CHECKERRORS_H_SENTRY

#include <inttypes.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "Logging.h"

class CheckErrors {
public:
	static void CheckZeroCritError(int32_t value, const char* mes);
	static void CheckLessZeroCritError(int32_t value, const char* mes);
};

#endif