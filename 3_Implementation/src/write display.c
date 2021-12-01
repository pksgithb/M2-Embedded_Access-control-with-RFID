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
