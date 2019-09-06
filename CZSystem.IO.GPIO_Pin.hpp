/******************************************************************************
*	\file	CZSystem.IO.GPIO_Pin.hpp
*	\author	Jensen Miller
*	\date	Jun 25, 2018
*	
*	Copyright (c) 2018 LooUQ Incorporated
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
#ifndef COREZERO_HDK_GPIOPIN_H_
#define COREZERO_HDK_GPIOPIN_H_

#include <stdint.h>
#include <CoreZero.Event.hpp>



namespace CZSystem
{
	namespace IO
	{
		//
		//	Enumerables
		//

		/// The possible digital logic values
		enum LogicValue
		{
			Low,	///< Logical Low
			High	///< Logical High
		};

		/// The possible drive modes of Gpio pins
		enum DriveMode
		{
			Input,			///< Configure pin as Input
			Output,			///< Configure pin as Output
			InputPullup,	///< Configure pin as Input with Pullup resistor
			InputPulldown	///< Configure pin as Input with Pulldown resistor
		};

		/// The possible triggeres for an interrupt
		enum InterruptTrigger
		{
			TriggerOnLow,		///< Trigger interrupt when pin is pulled Low
			TriggerOnHigh,		///< Trigger interrupt when pin is pulled High
			TriggerOnChange,	///< Trigger interrupt when pin value Changes
			TriggerOnFalling,	///< Trigger interrupt on Falling edge of signal
			TriggerOnRising		///< Trigger interrupt on Risging edge of signal
		};

		class I_GPIO_Pin;

		using OnTrigger = CoreZero::Delegate<void(I_GPIO_Pin*)>;

		/****************************************************************************
		 *	@interface I_GpioPin GpioController.hpp "GpioController.hpp"
		 *  @brief A Gpio controller interface class for platform dervations
		 *
		 *	@details Allows for cross-platform implementations of Gpio controllers
		 */
		class I_GPIO_Pin
		{
		public:
			constexpr I_GPIO_Pin(unsigned pinNum) {}
			virtual ~I_GPIO_Pin() {}

		//
		//	Methods
		//
		public:
			virtual	int	Open() = 0;
			virtual int Close() = 0;

			virtual	int	Write(LogicValue logicVal) = 0;
			virtual	LogicValue	Read() = 0;

			virtual int SetPinMode(DriveMode driveMode) = 0;

			virtual int EnableInterrupt(InterruptTrigger intTrig) = 0;
			virtual int DisableInterrupt() = 0;

		public:
			CoreZero::Event<OnTrigger> Triggered;
		};
	}
}
#endif // !COREZERO_HDK_GPIOPIN_H_
