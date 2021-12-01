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

