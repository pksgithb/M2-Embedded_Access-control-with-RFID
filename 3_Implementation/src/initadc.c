/***********************************************
 * Name:
 *    InitADC
 * In:
 *    int digit, int display_num
 * Out:
 *    --
 * Description:
 *	  Function to initialized ADC conversion
 * 
 *
 ************************************************/
void InitADC ()
{
	ADCSRA = (1<<ADEN) | (1<<ADPS2) | (1<<ADPS0);		// ADEN: Set to turn on ADC , by default it is turned off
	ADMUX = 0x00 | (1<<REFS0);							//ADPS2: ADPS2 and ADPS0 set to make division factor 32
														// ADC input set to channel 0 and Vref <- AVcc
}//~~ end of InitADC
