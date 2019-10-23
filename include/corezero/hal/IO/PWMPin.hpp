/******************************************************************************
*	@file		PWM_Pin.hpp
*
*	@author		Jensen Miller
*	@date		Aug 22, 2019
*
*	Copyright (c) 2019 LooUQ Incorporated
*
*	@details	An interface for deriving platform specific Pwm implementations.
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
#ifndef COREZERO_HDK_PWMPIN_H_
#define COREZERO_HDK_PWMPIN_H_

#include "GPIOPin.hpp"



namespace czsystem
{
	namespace io
	{
		class I_PWMPin
		{
		public:
			constexpr I_PWMPin(unsigned pinNum) {}
			virtual ~I_PWMPin() {}

			//
			//	Methods
			//
		public:
			virtual int Open() = 0;
			virtual int Close() = 0;

			virtual int Write(float pwmValue) = 0;
			virtual float Read() = 0;

			virtual int SetPinMode(DriveMode driveMode) = 0;
		};

	}
}


#endif	// !COREZERO_HDK_PWMPIN_H_