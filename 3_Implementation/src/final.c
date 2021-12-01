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
}
