#include<REG_MPC82G516.H>

void	display(char HH, char MM, char SS);

void main(void)
{
	char HH = 23, MM = 59, SS = 58;
	TMOD=1;
	while(1){
		char run20 = 20;
		
		while(run20--) {
			TH0=60;
			TL0=176;
			TR0=1;
			while(1){
				display(HH, MM, SS);
				
				if(TF0==1){
					TF0=0;
					break;
				}
			}
		}
		
		++SS;
		if(SS >= 60) {
			SS = 0;
			++MM;
		}
		if(MM >= 60) {
			MM = 0;
			++HH;
		}
		if(HH >= 24) {
			HH = 0;
		}
	}


}

void display(char HH, char MM, char SS)
{
	void show_digit(char pos, char num);
	
	show_digit(1 << 5, HH);
	show_digit(1 << 3, MM);
	show_digit(1 << 1, SS);
}

void show_digit(char pos, char num) {
	unsigned char i;
	
	P1 = ~pos;
	P2 = num / 10;
	
	for(i=0; i<250; i++);
	
	P1 = ~(pos >> 1);
	P2 = num % 10;
	
	for(i=0; i<250; i++);
}
