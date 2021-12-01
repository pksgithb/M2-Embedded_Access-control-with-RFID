void CalculateSeconds (bool time_display)
{
	switch (time_display){
		case 0:
				if (seconds/10 == 0 && seconds < 10){
					WriteDisplays(0,1);
					WriteDisplays(seconds,0);
				}

				else if (seconds%10 != 0){
					WriteDisplays(seconds/10,1);
					WriteDisplays(seconds%10,0);
				}
	
				else if (seconds%10 == 0){
					WriteDisplays(seconds/10,1);
					WriteDisplays(0,0);
				}
		break;
		
		case 1:
				if (seconds/10 == 0 && seconds < 10){
					WriteDisplays(0,1);
					_delay_ms(25);
					WriteDisplays(seconds,0);
					_delay_ms(25);
				}

				else if (seconds%10 != 0){
					WriteDisplays(seconds/10,1);
					_delay_ms(25);
					WriteDisplays(seconds%10,0);
					_delay_ms(25);
				}
				
				else if (seconds%10 == 0){
					WriteDisplays(seconds/10,1);
					_delay_ms(25);
					WriteDisplays(0,0);
					_delay_ms(25);
				}
		break;
	}
