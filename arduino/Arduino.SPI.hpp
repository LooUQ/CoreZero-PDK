/******************************************************************************
*	\file Arduino.SPI.hpp
*
*	\author		Jensen Miller
*	\date		Jan 31, 2018
*
*	Copyright (c) 2018 LooUQ Incorporated
*
*	\details	Arduino adaptation for SPI functionality.
*
*	License: The GNU Licence(GNU)
*
*	This file is part of the CoreZero library.
*
*	CoreZero is free software: you can redistribute it and/or modify it under
*	the terms of the GNU General Public License as published by the
*	Free Software Foundation, either version 3 of the License, or (at
*	your option) any later version.
*
*	CoreZero is distributed in the hope that it will be useful, but WITHOUT
*	ANY WARRANTY; without even the implied warranty of
*	MERCHANTABILITY or FITNESS FOR A PARTICULAR
*	PURPOSE.  See the GNU General Public License for more details.
*
*	You should have received a copy of the GNU General Public
*	License along with CoreZero.
*	If not, see <http://www.gnu.org/licenses/>.
******************************************************************************/
#if defined(ARDUINO)
#ifndef ARDUINO_SPI_H_
#define ARDUINO_SPI_H_

#include "../CZSystem.Communication.Serial.SPI.hpp"
#include <Arduino.h>
#include <SPI.h>


namespace CZSystem
{
	namespace Communication
	{
		namespace Serial
		{
			class SerialPeripheral
				: public I_SerialPeripheral
			{
			public:
				constexpr SerialPeripheral(SPIClass * spiClass, IO::I_GPIO_PIN* slaveSelectPin, uint32_t clockSpeed)
					: I_SerialPeripheral(slaveSelectPin)
					, m_spiSettings(SPISettings())
					, m_spi(nullptr)
				{}

				virtual ~I_SerialPeripheral()
				{}

			public:
				void	Initialize();
				void	Disconnect();

				void	Receive(void* destBuffer, size_t len);
				void	Transmit(const void* srcBuffer, size_t len);
				void	FullDuplex(const void* srcBuffer, void* destBuffer, size_t len);

			private:
				SPISettings m_spiSettings;
				SPIClass* m_spi;
			};
		}
	}
}


#endif // !ARDUINO_SPI_H_
#endif // defined(ARDUINO)
