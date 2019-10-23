#ifndef COREZERO_CZSYSTEM_H__
#define COREZERO_CZSYSTEM_H__


#if		defined(WIN32)
/*	Windows 32 */
#include "pal/win32/UARTDevice.hpp"

#elif	defined(WINIOT)
/*	Windows IoT Core */

#elif	defined(ARDUINO)
/*	Arduino Framework */

#elif	defined(ATMELSAM)
/*	Atmel SAM Framework */

#elif	defined(RPI_X)
/*	Raspberry Pi Distros */

#endif // defined(PLATFORM)



#endif	// !COREZERO_CZSYSTEM_H__