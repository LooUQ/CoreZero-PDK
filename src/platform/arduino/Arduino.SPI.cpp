#if defined(ARDUINO)
#include "Arduino.SPI.hpp"


namespace CZSystem
{
	namespace Communication
	{
		namespace Serial
		{
			void SerialPeripheral::Initialize()
			{
				m_slaveSelectPin->Open();
				m_slaveSelectPin->SetPinMode(IO::DriveMode::Output)
				m_slaveSelectPin->Write(IO::LogicValue::High);

				m_spi->begin();
				m_spi->setDataMode(GetMode());
			}

			void SerialPeripheral::Disconnect()
			{
				m_spi->end();
			}

			void SerialPeripheral::Receive(void* destBuffer, size_t len)
			{
				FullDuplex(destBuffer, destBuffer, len);
			}

			void SerialPeripheral::Transmit(const void* srcBuffer, size_t len)
			{
				if (len < 1) return;
				m_slaveSelectPin->Write(IO::Low);
				m_spi->beginTransaction(m_spiSettings);

				for (unsigned idx = 0; idx < len; idx++) {
					(void)m_spi->transfer(((uint8_t*)(srcBuffer))[idx]);
				}

				m_spi->endTransaction();
				m_slaveSelectPin->Write(IO::HIGH);
			}



			/******************************************************************
			 *	Full duplex transfer.
			 *
			 *	\param[in] srcBuffer The source of data to send.
			 *	\param[out] destBuffer The destination of data to receive.
			 *	\param[in] len The number of bytes to transcieve.
			 */
			void SerialPeripheral::FullDuplex(const void* srcBuffer, void* destBuffer, size_t len)
			{
				if (len < 1) return;
				m_slaveSelectPin->Write(IO::Low);
				m_spi->beginTransaction(m_spiSettings);
				for (unsigned idx = 0; idx < len; idx++) {
					((uint8_t*)(destBuffer)) = m_spi->transfer(((uint8_t*)(srcBuffer))[idx]);
				}
				m_spi->endTransaction();
				m_slaveSelectPin->Write(IO::HIGH);
			}
		}
	}
}

#endif