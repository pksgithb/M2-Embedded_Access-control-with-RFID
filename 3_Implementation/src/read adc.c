/***********************************************
 * Name:
 *    ReadADC
 * In:
 *    uint8_t channel
 * Out:
 *    adc_value
 * Description:
 *    Function to Read ADC Value
 *	  The channel to be read is entered as input
 *
 ************************************************/
uint16_t ReadADC (uint8_t channel)
{
	uint16_t adc_value;

	ADMUX &= 0xF0;                    			//Clear the older channel that was read
	ADMUX = channel | (1<<REFS0);				// ADC input channel set to channel and Vref <- AVcc
	ADCSRA |= (1<<ADSC);						// Start conversion
	while (ADCSRA & (1<<ADSC));					// wait for conversion to complete
	
	adc_value = ADCW;							//Store ADC value
	return adc_value;
}//~~ end of ReadADC
