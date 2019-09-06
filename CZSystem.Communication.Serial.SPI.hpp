/******************************************************************************
*	\file CZSystem.Communication.Serial.SPI.hpp
*
*	\author		Jensen Miller
*	\date		Jan 31, 2018
*
*	Copyright (c) 2018 LooUQ Incorporated
*
*	\details	An interface for deriving platform specific
*		Spi implementations.
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
#ifndef COREZERO_HDK_SPI_H_
#define COREZERO_HDK_SPI_H_

#include <CZSystem.IO.GPIO_Pin.hpp>

#include <stdint.h>
#include <stddef.h>

namespace CZSystem
{
	namespace Communication
	{
		namespace Serial
		{
			/// Spi Mode
			enum Mode
			{
				SpiMode_0,	///< Mode 0
				SpiMode_1,	///< Mode 1
				SpiMode_2,	///< Mode 2
				SpiMode_3	///< Mode 3
			};


			/******************************************************************
			 *	\interface I_SerialPeripheral I_SerialPeripheral.hpp "I_SerialPeripheral.hpp"
			 *  \brief An Spi Device interface for spidervations.
			 *
			 *	\details Allows for cross-platform implementations of Spi class
			 */
			class I_SerialPeripheral		
			{
			//
			//	Constructors
			//
			public:
				constexpr I_SerialPeripheral(IO::I_GPIO_Pin* slaveSelectPin, uint32_t clockSpeed = 4000000)
					: m_slaveSelectPin(slaveSelectPin)
					, m_clockSpeed(clockSpeed)
					, m_mode(0)					
				{}

				virtual ~I_SerialPeripheral()
				{}


			//
			//	Methods
			//
			public:
				virtual void	Initialize() = 0;
				virtual void	Disconnect() = 0;

				virtual void	Receive(void* destBuffer, size_t len) = 0;
				virtual void	Transmit(const void* srcBuffer, size_t len) = 0;
				virtual void	FullDuplex(const void* srcBuffer, void* destBuffer, size_t len) = 0;


			//
			//	Getters and Setters
			//
			public:

				virtual void SetMode(const Mode mode) { m_mode = mode; }
				virtual void SetClockSpeed(const uint32_t clockSpeed) { m_clockSpeed = clockSpeed; };

			protected:
				virtual Mode GetMode()	const { return m_mode; }
				IO::I_GPIO_Pin* GetSlaveSelect() { return m_slaveSelectPin; }
				uint32_t	GetClockSpeed() { return m_clockSpeed; }

			//
			//	Attributes
			//
			protected:
				///	Chip Select	(CS)
				IO::I_GPIO_Pin* m_slaveSelectPin;								

			private:
				///	SPI Data mode
				Mode m_mode;

				///	BaudRate (bit rate)
				uint32_t m_clockSpeed;
			};
		}
	}
}

#endif // !COREZERO_HDK_SPI_H_