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
