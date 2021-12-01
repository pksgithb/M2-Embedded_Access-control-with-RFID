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
};
