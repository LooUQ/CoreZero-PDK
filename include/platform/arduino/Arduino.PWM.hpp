/******************************************************************************
*	\file Arduino.GPIO.hpp
*
*	\author		Jensen Miller
*	\date		Aug 28, 2019
*
*	Copyright (c) 2019 LooUQ Incorporated
*
*	\details	Arduino adaptation for GPIO functionality.
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
#ifndef ARDUINO_PWM_H_
#define ARDUINO_PWM_H_

#include <CZSystem.IO.PWM_Pin.hpp>
#include "Arduino.GPIO.hpp"

namespace CZSystem
{
	namespace IO
	{
		class PWM_Pin
			: public I_PWM_Pin
		{
		public:
			constexpr PWM_Pin(unsigned pinName)
				: m_pin(pinName)
			{}

			virtual ~PWM_Pin();

		public:
			virtual int Open();
			virtual int Close();

			virtual int Write(float pwmValue);
			virtual float Read();

			virtual int SetPinMode(DriveMode driveMode);
			
		private:
			GPIO_Pin m_pin;
		};
	}
}

#endif	// !ARDUINO_PWM_H_
#endif	// ARDUINO