#include "main.h"

int main()
{
#ifdef DAEMON
	Daemon::InitProcessAsDaemonAndOpenLog();
#else
	Logging::InitSyslog();
#endif
	GeneralUart* general_uart = new GeneralUart();
	GeneralTcp*	 general_tcp  = new GeneralTcp();
	uint8_t run = 1;
	uint8_t* rtu_converted = 0;
	uint8_t* tcp_converted = 0;
	while (run)
	{
		general_uart->ReadGeneralUart();
#ifdef ROUTER
		if (general_uart->GetGeneralUartBuf()[0] < OWN_ADDRESS) {
#endif
			tcp_converted = general_uart->ConvertRtuToTcp();
			general_tcp->SendGeneralTcp(tcp_converted, strlen((const char*)tcp_converted));
			general_tcp->RecvGeneralTcp();
			rtu_converted = general_tcp->ConvertTcpToRtu();
			general_uart->WriteGeneralUart(rtu_converted, strlen((const char*)rtu_converted));
			if (rtu_converted) {
				delete rtu_converted;
				rtu_converted = 0;
			}
			if (tcp_converted) {
				delete tcp_converted;
				tcp_converted = 0;
			}
			general_uart->ZeroBuf();
			general_tcp->ZeroBuf();
#ifdef ROUTER
		}
		else {
			;
		}
#endif

	}
	return 0;
}