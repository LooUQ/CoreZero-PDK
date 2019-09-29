/******************************************************************************
*	\file		CZSystem.Communication.Serial.SPI.h
*	\author		Jensen Miller	<jensen@loouq.com>
*	\date		Jan 31, 2018
*
*	Copyright (c) 2018-2019 LooUQ Incorporated
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
#ifndef COREZERO_PDK_COM_H_
#define COREZERO_PDK_COM_H_

#include <stdint.h>
#include <CoreZero.Event.hpp>

namespace CZSystem
{
	namespace Communication
	{
		class I_Communicator;
		using OnDataReceived = CoreZero::Delegate<void(I_Communicator* const)>;

		class I_Communicator
		{
		public:
			virtual int Write(const void* _src, size_t srcSize) = 0;
			virtual int Read(void* _dest, size_t destSize) = 0;

		public:
			CoreZero::Event<OnDataReceived> DataReceived;
		};
	}
}

#endif	// !COREZERO_PDK_COM_H_