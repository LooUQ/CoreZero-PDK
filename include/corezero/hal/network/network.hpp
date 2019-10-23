/******************************************************************************
*	\file		network.hpp
*	\author		Jensen Miller
*	\date		Jul 15, 2018
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
#ifndef CZSYSTEM_NETWORKADAPTER_H_
#define CZSYSTEM_NETWORKADAPTER_H_

#include <corezero/event.hpp>
#include <corezero/network/network_def.hpp>

#include <stdint.h>
#include <stdio.h>

#ifdef NETWORKADAPTER_SUPPORTS_IPV6
#define IPV6_SUPPORTED
#endif

constexpr int NETWORK_NO_SSL_SUPPORT = 0x0;
constexpr int NETWORK_SUPPORTS_SSL = 0x1;

#include <corezero/network/network_def.hpp>

namespace czsystem
{	
	namespace network
	{
		using corezero::network::IPv4_Address;
		using corezero::network::PingSummary;
		using OnDataReceived = corezero::Delegate<void(void*,size_t)>;

		/**
		 *	\interface Network adapter interface.
		 */
		class I_NetworkAdapter
		{
		//
		//	Methods
		//
		public:		

			virtual PingSummary	Ping(const IPv4_Address& ipAddress, unsigned int timeout = 4000, unsigned int pingNum = 4) = 0;
			virtual PingSummary	Ping(const char hostName[], unsigned int timeout = 4000, unsigned int pingNum = 4) = 0;

			virtual IPv4_Address HostByName(const char* hostName) = 0;

			virtual int Connect(int &connectionId, uint32_t connectionFlags, IPv4_Address remoteAddress, uint16_t remotePort) = 0;
			virtual int ConnectSSL(int &connectionId, uint32_t connectionFlags, uint32_t securityFlags, IPv4_Address remoteAddress, uint16_t remotePort) = 0;			
			virtual int Listen(int &connectionId, uint32_t connecitonFlags, IPv4_Address localAddress, uint16_t localPort) = 0;
			virtual int Disconnect(int connectionId, int timeout = 0) = 0;

			virtual size_t Send(int connectionId, const uint8_t data[], size_t dataLength) = 0;
			virtual size_t SendTo(int connectId, const uint8_t data[], size_t dataLength, const IPv4_Address& remoteAddress, uint16_t remotePort) = 0;
			virtual size_t SendFile(int connectionId, FILE* fileToSend, fpos_t* filePos = NULL) = 0;
			virtual size_t Receive(int connectionId, uint8_t data[], size_t dataLength) = 0;
			virtual size_t ReceiveFrom(int connectionId, uint8_t data[], size_t dataLength, const IPv4_Address& remoteAddress, uint16_t remotePort) = 0;

			virtual int	ConfigureOptions(int connectionId, int options) = 0;
			virtual bool IsNetworkAvailable() = 0;
			virtual const char* GetNetworkInterfaceType() = 0;
		};
	}
}

#endif // !CZSYSTEM_NETWORKADAPTER_H_
