#if defined(WIN32)
#ifndef WIN32_UART_H__
#define WIN32_UART_H__


#include <corezero/hal/communication/serial.UART.hpp>



namespace czsystem
{
	namespace communication
	{
		namespace serial
		{
			class SerialDevice
				: public I_UartDevice
			{

			};
		}
	}
}

#endif	// !WIN32_UART_H__
