#ifndef CHECK_ERRORS_H_SENTRY
#define CHECK_ERRORS_H_SENTRY

#include "logging.h"
#include <inttypes.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

void check_zero_crit_error(int32_t value, const char* mes);
void check_less_zero_crit_error(int32_t value, const char* mes);

#endif