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
#ifndef ARDUINO_GPIO_H_
#define ARDUINO_GPIO_H_
#include <Arduino.h>

#include <corezero/hal/IO/GPIOPin.hpp>

namespace czsystem
{
	namespace io
	{
		class GPIOPin
			: public I_GPIOPin
		{
		public:
			constexpr GPIOPin(unsigned pinName)
				: m_pinName(pinName)
				, m_opened(false)
				, m_eventLinker(nullptr)
			{}

			int Open();
			int Close();

			int Write(LogicValue logicVal);
			LogicValue Read();

			int SetPinMode(DriveMode driveMode);
			int EnableInterrupt(InterruptTrigger intTrig);
			int DisableInterrupt();

			unsigned GetName() const { return m_pinName; }

		private:
			void interrupt_to_event();

		private:
			bool m_opened;
			const unsigned m_pinName;
			corezero::Delegate<void()>* m_eventLinker;
		};
	}
}


#endif // !ARDUINO_GPIO_H_
#endif // defined(ARDUINO)