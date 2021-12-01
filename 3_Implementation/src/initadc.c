
void InitADC ()

	ADCSRA = (1<<ADEN) | (1<<ADPS2) | (1<<ADPS0);	
	ADMUX = 0x00 | (1<<REFS0);					
													
}
