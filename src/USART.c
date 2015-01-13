/**
 * Minimal USART comms library
 */

#include <avr/io .h>
#include "USART.h"
#include <util/setbaud.h>

void initializeUsart(void) {	/* requures BAUD */
	UBRR0H = UBRRH_VALUE;	/* defined in setbaud.h */
	UBRR0L = UBRRL_VALUE;
#if USE_2X
	UCSR0A |= (1 << U2X0);
#else
	UCSR0A &= ~(1 << U2X0);
#endif

	/*  Enable USART transmitter/receiver */
	UCSR0B = (1 << TXEN0) | (1 << RXEN0);
	UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);	/* 8 data bits / 1 stop bit */
}

void transmitByte(uint8_t tx_data) {
	/* Wait for empty transmit buffer */
	loop_until_bit_is_set(UCSR0A, UDRE0);
	UDR0 = tx_data;			/* Send data */
}

uint8_t receiveByte(void) {
	loop_until_bit_is_set(UCSR0A, RXC0);
	return UDR0;
}
/*  Convenience printing function */
void printString(const char myString[]) {
	uint8_t i = 0;
	while (myString[i]) {
		transmitByte( myString[i] );
		i++;
	}
}
