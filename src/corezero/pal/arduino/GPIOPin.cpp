#if defined(ARDUINO)

#include "../../../include/platform/arduino/GPIOPin.hpp"

namespace CZSystem
{
	namespace IO
	{
		int GPIOPin::Open()
		{
			m_opened = true;
			return 0;
		}

		int GPIOPin::Close()
		{
			m_opened = false;
			return 0;
		}

		int GPIOPin::Write(LogicValue logicVal)
		{
			digitalWrite(m_pinName, logicVal);
			return 0;
		}

		LogicValue GPIOPin::Read()
		{
			return (LogicValue)digitalRead(gpioPin);
		}

		int GPIOPin::SetPinMode(DriveMode driveMode)
		{
			pinMode(m_pinName, driveMode);
			return 0;
		}

		int GPIOPin::EnableInterrupt(InterruptTrigger intTrig)
		{
			if (m_eventLinker != nullptr) return;
			m_eventLinker = CoreZero::Create_MemberDelegate(this, &interrupt_to_event);
			attachInterrupt(digitalPinToInterrupt(m_pinName), m_eventLinker, intTrig);
			return 0;
		}

		int GPIOPin::DisableInterrupt()
		{
			if (m_eventLinker == nullptr) return;
			detachInterrupt(m_pinName);
			delete m_eventLinker; m_eventLinker = nullptr;
			return 0;
		}


		void GPIOPin::interrupt_to_event()
		{
			Triggered(this);
		}
	}
}

#endif	// ARDUINO