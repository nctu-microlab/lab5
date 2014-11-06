#include<REG_MPC82G516.H>

sbit start_btn = P3 ^ 1;
sbit add_btn = P3 ^ 2;

void show_digit(char pos, char num);

void main(void)
{
	
	char num1 = 0, num2 = 0;
	char counter1 = 0, counter2 = 0;
	bit add_click = 0;
	
	P3 = 0xFF;
	TMOD = 1;
	TH0 = 60;
	TL0 = 176;
	TR0 = 0;
	
	while(1){
		if(!add_btn && !add_click) {
			add_click = 1;
			
			if(TR0) {
				TR0 = 0;
			} else {
				++num1;
				++num2;
			}
		}
		if(add_btn) {
			add_click = 0;
		}
		
		if(!start_btn) {
			TR0 = 1;
		}
		
		if(TF0) {
			TF0 = 0;
			
			if(++counter1 == 40) {
				++num1;
				counter1 = 0;
			}
			if(++counter2 == 60) {
				++num2;
				counter2 = 0;
			}
			
			TH0 = 60;
			TL0 = 176;
			TR0 = 1;
		}
		
		show_digit(1 << 5, num1);
		show_digit(1 << 1, num2);
	}
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
