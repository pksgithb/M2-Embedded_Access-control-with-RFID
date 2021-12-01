

#define F_CPU 16000000UL
#define PORT_ON(port,pin) port |= (1<<pin)
#define PORT_OFF(port,pin) port &= ~(1<<pin)
#define true 1
#define false 0

#include <avr/io.h>
#include <avr/interrupt.h>
#include "util/delay.h"
#include <stdbool.h>

void CalculateSeconds (bool time_display);
void CalculateMinutes (bool time_display);
void CalculateHours (bool time_display);
void WriteDisplays(uint8_t digit, uint8_t displaynum);
void InitADC();
uint16_t ReadADC(uint8_t channel);

uint8_t hour = 0;
uint8_t minutes = 0;
uint8_t seconds = 0;
uint8_t seven_seg_digits[10][7] = {						
								{ 1,1,1,1,1,1,0 },  // = 0
								{ 0,1,1,0,0,0,0 },  // = 1
								{ 1,1,0,1,1,0,1 },  // = 2
								{ 1,1,1,1,0,0,1 },  // = 3
								{ 0,1,1,0,0,1,1 },  // = 4
								{ 1,0,1,1,0,1,1 },  // = 5
								{ 1,0,1,1,1,1,1 },  // = 6
								{ 1,1,1,0,0,0,0 },  // = 7
								{ 1,1,1,1,1,1,1 },  // = 8
								{ 1,1,1,0,0,1,1 }   // = 9
}
void CalculateSeconds (bool time_display)
{
	switch (time_display){
		case 0:
				if (seconds/10 == 0 && seconds < 10){
					WriteDisplays(0,1);
					WriteDisplays(seconds,0);
				}

				else if (seconds%10 != 0){
					WriteDisplays(seconds/10,1);
					WriteDisplays(seconds%10,0);
				}
	
				else if (seconds%10 == 0){
					WriteDisplays(seconds/10,1);
					WriteDisplays(0,0);
				}
		break;
		
		case 1:
				if (seconds/10 == 0 && seconds < 10){
					WriteDisplays(0,1);
					_delay_ms(25);
					WriteDisplays(seconds,0);
					_delay_ms(25);
				}

				else if (seconds%10 != 0){
					WriteDisplays(seconds/10,1);
					_delay_ms(25);
					WriteDisplays(seconds%10,0);
					_delay_ms(25);
				}
				
				else if (seconds%10 == 0){
					WriteDisplays(seconds/10,1);
					_delay_ms(25);
					WriteDisplays(0,0);
					_delay_ms(25);
				}
		break;
	}
}
void CalculateMinutes (bool time_display)
{
	switch (time_display){
		case 0:
				if (minutes/10 == 0 && minutes < 10){
					WriteDisplays(0,1);
					WriteDisplays(minutes, 0);
				}
	
				else if (minutes%10 == 0){
					WriteDisplays(minutes/10, 1);
					WriteDisplays(0,0);
				}
	
				else if (minutes%10 != 0){
					WriteDisplays(minutes/10, 1);
					WriteDisplays(minutes%10,0);
				}
		break;
		
		case 1:
				if (minutes/10 == 0 && minutes < 10){
					WriteDisplays(0,1);
					_delay_ms(25);
					WriteDisplays(minutes, 0);
					_delay_ms(25);
				}
				
				else if (minutes%10 == 0){
					WriteDisplays(minutes/10, 1);
					_delay_ms(25);
					WriteDisplays(0,0);
					_delay_ms(25);
				}
				
				else if (minutes%10 != 0){
					WriteDisplays(minutes/10, 1);
					_delay_ms(25);
					WriteDisplays(minutes%10,0);
					_delay_ms(25);
				}
		break;
	}	
}
void CalculateHours (bool time_display)
{
	switch (time_display){
		case 0:
				if (hour/10 == 0){
					WriteDisplays(0,3);
					WriteDisplays(hour,2);
				}
	
				else{
					WriteDisplays(1,3);	
					WriteDisplays(hour%10,2);	
				}
		break;
		
		case 1:
				if (hour/10 == 0){
					WriteDisplays(0,3);
					_delay_ms(50);
					WriteDisplays(hour,2);
					_delay_ms(50);
				}
				
				else{
					WriteDisplays(1,3);
					_delay_ms(50);
					WriteDisplays(hour%10,2);
					_delay_ms(50);
				}
				break;	
	}
}
void WriteDisplays(uint8_t digit, uint8_t display_num) 
{
	uint8_t pin = 2;
	PORTD &= 0b00000000;
	PORTB &= (0<<PB0);
	PORTB &= (0<<PB1);
		
	if (display_num == 0){							
		PORTB &= (0<<PB2);
		PORTB |= (1<<PB3);
		PORTB |= (1<<PB4);
		PORTB |= (1<<PB5);
	}
	
	else if (display_num == 1){
		PORTB &= (0<<PB3);
		PORTB |= (1<<PB2);
		PORTB |= (1<<PB4);
		PORTB |= (1<<PB5);
	}
	
	else if (display_num == 2){
		PORTB &= (0<<PB4);
		PORTB |= (1<<PB2);
		PORTB |= (1<<PB3);
		PORTB |= (1<<PB5);
	}
	
	else if (display_num == 3){
		PORTB &= (0<<PB5);		
		PORTB |= (1<<PB2);
		PORTB |= (1<<PB3);
		PORTB |= (1<<PB4);
	}
	
	for (int segCount = 0; segCount < 7; ++segCount){
		if (pin < 8)
			PORTD |= (seven_seg_digits[digit][segCount]<<pin);
		else
			PORTB |= (seven_seg_digits[digit][segCount]<<0);
		++pin;
	}
}
void InitADC ()
{
	ADCSRA = (1<<ADEN) | (1<<ADPS2) | (1<<ADPS0);		
	ADMUX = 0x00 | (1<<REFS0);							
														
}
uint16_t ReadADC (uint8_t channel)
{
	uint16_t adc_value;

	ADMUX &= 0xF0;                    			
	ADMUX = channel | (1<<REFS0);				
	ADCSRA |= (1<<ADSC);						
	while (ADCSRA & (1<<ADSC));					
	
	adc_value = ADCW;							
	return adc_value;
}
int main(void)
{
	uint8_t pin, digit;
	uint16_t adc_value;
										 
	DDRD = 0b11111100;                    
	DDRB = 0b00111111;					  
										 
	PORTB |= (0<<PB2);
	PORTB |= (1<<PB3);
	PORTB |= (1<<PB4);
	PORTB |= (1<<PB5);
	
	InitADC();
	
	OCR1A = 0x3D08;							
	TCCR1B |= (1 << WGM12); 				
	TIMSK1 |= (1 << OCIE1A);   				
	TCCR1B |= (1 << CS12) | (1 << CS10);  	
	sei();								
	
	PORT_OFF(PORTB,1);
	
    for(;;) 
    {	
		adc_value = ReadADC(1);
		if (adc_value > 750) {
			cli();
			minutes += 1;
			
			if (minutes > 59){
				hour += 1;
				minutes = 0;
			}
					
			if (hour > 11){
				hour = 0;
			}
			CalculateMinutes(1);
			CalculateHours(1);
			sei();
		}
		
		adc_value = ReadADC(2);
		if (adc_value > 750) {
			cli();	
			hour += 1;
							
			if (hour > 11){
				hour = 0;
			}
			CalculateMinutes(1);
			CalculateHours(1);
			sei();
		}
		
	    CalculateMinutes(0);
		CalculateHours(0);
	}
}
ISR (TIMER1_COMPA_vect)
{	
		if (seconds > 59){
			minutes += 1;
			seconds = 0;
		}
		
		if (minutes > 59){
			hour += 1;
			minutes = 0;
		}
		
		if (hour > 11){
			hour = 0;
		}
		seconds += 1;
}
