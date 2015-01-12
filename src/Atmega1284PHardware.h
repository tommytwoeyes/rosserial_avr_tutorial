/**
 * Atmega1284PHardware.h
 *
 * Defines the hardware interface for the ROS NodeHandle object to use to 
 * communicate between the AVR node and ROS master via UART (thus the name,
 * of the package: rosserial_client).
 */

#ifndef _ATMEGA1284P_HARDWARE_H_
#define _ATMEGA1284P_HARDWARE_H_

extern "C"
{
	#include <avr/interrupt.h>
	#include <avr/wdt.h>
	#include "avr_time.h"
	#include "avr_uart.h"
}

class Atmega1284PHardware {
	public:
		Atmega1284PHardware() {}

		// Initialize the AVR
		void init()
		{
			wdt_diable();
			avr_time_init();
			avr_uart_init();
			sei();
		}

		// Read a byte of data fromn the ROS connection
		// If no data, returns -1
		int read()
		{
			return avr_uart_receive_byte();
		}

		// Send a byte of data to the ROS connection
		void write(uint8_t* data, int length)
		{
			for (int i = 0; i < length; i++) {
				avr_uart_send_bte(data[i]);
			}
		}

		// Returns millseconds since start of program
		unsigned long time()
		{
			return avr_time_now();
		}
}

#endif
