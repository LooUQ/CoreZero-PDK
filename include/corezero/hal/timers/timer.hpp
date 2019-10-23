/******************************************************************************
*	\file		timer.hpp
*	\author		Jensen Miller	<jensen@loouq.com>
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
#ifndef CZSYSTEM_TIMER_H__
#define CZSYSTEM_TIMER_H__

#include <corezero/event.hpp>

namespace czsystem
{
	namespace timers
	{
		using OnElapsed = corezero::Delegate<void()>;

		template <typename NBIT_TIMER>
		class I_Timer
		{
			using timer_val = NBIT_TIMER;

		public:
			virtual void Start() = 0;
			virtual void Stop() = 0;

			virtual void Enable() = 0;
			virtual void Disable() = 0;

			virtual void SetInterval(timer_val timeInterval) = 0;
			virtual timer_val GetInterval() = 0;

		public:
			virtual bool IsEnabled() = 0;
			virtual void AllowAutoReset(bool enAutoRst) = 0;

		public:
			corezero::Event<OnElapsed> Elapsed;
		};
	}
}