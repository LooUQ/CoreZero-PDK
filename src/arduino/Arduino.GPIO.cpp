#if defined(ARDUINO)

#include "Arduino.GPIO.hpp"
#include <Arduino.h>

namespace CZSystem
{
	namespace IO
	{
		int GPIO_Pin::Open()
		{
			m_opened = true;
			return 0;
		}

		int GPIO_Pin::Close()
		{
			m_opened = false;
			return 0;
		}

		int GPIO_Pin::Write(LogicValue logicVal)
		{
			digitalWrite(m_pinName, logicVal);
			return 0;
		}

		LogicValue GPIO_Pin::Read()
		{
			return (LogicValue)digitalRead(gpioPin);
		}

		int GPIO_Pin::SetPinMode(DriveMode driveMode)
		{
			pinMode(m_pinName, driveMode);
			return 0;
		}

		int GPIO_Pin::EnableInterrupt(InterruptTrigger intTrig)
		{
			if (m_eventLinker != nullptr) return;
			m_eventLinker = CoreZero::Create_MemberDelegate(this, &interrupt_to_event);
			attachInterrupt(digitalPinToInterrupt(m_pinName), m_eventLinker, intTrig);
			return 0;
		}

		int GPIO_Pin::DisableInterrupt()
		{
			if (m_eventLinker == nullptr) return;
			detachInterrupt(m_pinName);
			delete m_eventLinker; m_eventLinker = nullptr;
			return 0;
		}


		void GPIO_Pin::interrupt_to_event()
		{
			Triggered(this);
		}
	}
}

#endif	// ARDUINO