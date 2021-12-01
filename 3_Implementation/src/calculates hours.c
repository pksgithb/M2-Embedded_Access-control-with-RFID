/***********************************************
 * Name:
 *    CalculateHours
 * In:
 *    --
 * Out:
 *    --
 * Description:
 *    Function to write on 7 segments display
 *    It receives two arguments: the digit  
 *    and the display number to to be writed 
 *
 ************************************************/
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
}//~~ end of CalculateHours
