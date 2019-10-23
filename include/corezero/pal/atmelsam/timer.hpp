/******************************************************************************
*	\file ATSAM.Timers.Timer.h
*
*	\author Jensen Miller <jensen@loouq.com>
*
*	Copyright (c) 2019 LooUQ Incorporated
*
*	License: The GNU License
*
*	This file is part of CoreZero.
*
*   CoreZero is free software: you can redistribute it and/or modify
*   it under the terms of the GNU General Public License as published by
*   the Free Software Foundation, either version 3 of the License, or
*   (at your option) any later version.
*
*   CoreZero is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU General Public License for more details.
*
*   You should have received a copy of the GNU General Public License
*   along with CoreZero.  If not, see <https://www.gnu.org/licenses/>.
*
`*****************************************************************************/
#ifdef ATMELSAM
#ifndef ATSAM_TIMERS_TIMER_H_
#define ATSAM_TIMERS_TIMER_H_

namespace atsam
{
	namespace Timers
	{
		
		class Timer_8b;
		class Timer_16b;
		class Timer_32b;

		/*	Timer Factory
		 *		Due to the timer having variant implementations, there is
		 *		a timer factory that constructs a timer
		 */
		class TimerFactory;
	}
}

#endif	// ! ATSAM_TIMERS_TIMER_H_
#endif // ATMELSAM