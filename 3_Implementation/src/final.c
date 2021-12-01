/***********************************************
 * Name:
 *    main
 * In:
 *    --
 * Out:
 *    --
 * Description:
 *    Main function
 *
 *
 ************************************************/
int main(void)
{
	uint8_t pin, digit;
	uint16_t adc_value;
										  //Data Direction Register: 1 - output    0 - input
	DDRD = 0b11111100;                    //7 segments bus control: PORTB(2,3,4,5)
	DDRB = 0b00111111;					  //7 segments multiplexed leds: Arduino UNO pins 2 - 7: PORTD(2,3,4,5,6,7) and 8: PORTB0
										  //Arduino pin 9: PB1 --- white LED 
	PORTB |= (0<<PB2);
	PORTB |= (1<<PB3);
	PORTB |= (1<<PB4);
	PORTB |= (1<<PB5);
	
	InitADC();
	
	OCR1A = 0x3D08;							//Timer definitions
	TCCR1B |= (1 << WGM12); 				// Mode 4, CTC on OCR1A
	TIMSK1 |= (1 << OCIE1A);   				//Set interrupt on compare match
	TCCR1B |= (1 << CS12) | (1 << CS10);  	// set prescaler to 1024 and start the timer
	sei();									// enable interrupts
	
	PORT_OFF(PORTB,1);
	
    for(;;) 
    {	
		/*adc_value = ReadADC(0);
		if (adc_value > 750){
			cli();
			seconds += 1;
			if (seconds > 59){
				minutes += 1;
				seconds = 0;
			}
					
			if (minutes > 59){
				hour += 1;
				minutes = 0;
			}
					
			if (hour > 12){
				hour = 0;
			}
			
			//CalculateSeconds(1);
			CalculateMinutes(1);
			CalculateHours(1);
			sei();
		}*/
		
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

			//CalculateSeconds(1);
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
			
			//CalculateSeconds(1);
			CalculateMinutes(1);
			CalculateHours(1);
			sei();
		}
		
		//CalculateSeconds(0);
		CalculateMinutes(0);
		CalculateHours(0);
	}
}

ISR (TIMER1_COMPA_vect)
{
	//action to be done every 1 sec
	
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
}//~~ end of interruption
