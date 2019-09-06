#if defined(ARDUINO)
#include "Arduino.PWM.hpp"


namespace CZSystem
{
	namespace IO
	{
		/**
		 *	\brief Destructor.
		 */
		PWM_Pin::~PWM_Pin()
		{
		}



		int PWM_Pin::Open()
		{			
			return m_pin.Open();
		}



		int PWM_Pin::Close()
		{
			return m_pin.Close();
		}



		int PWM_Pin::Write(float pwmValue)
		{
			analogWrite(m_pin.GetName(), pwmValue);
			return 0;
		}



		float PWM_Pin::Read()
		{
			return analogRead(m_pin.GetName());
		}



		int PWM_Pin::SetPinMode(DriveMode driveMode)
		{			
			return m_pin.SetPinMode(driveMode);
		}
	}
}

#endif