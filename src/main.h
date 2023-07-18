#include <signal.h>
#include "GeneralUart.h"
#include "GeneralTcp.h"
#ifdef DAEMON
#include "Daemon.h"
#else
#include "Logging.h"
#endif
#ifdef ROUTER
#include "config/route_rules.h"
#endif