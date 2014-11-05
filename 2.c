#include<REG_MPC82G516.H>

void	timer(void);
void	display();

void main(void)
{
	TMOD=6;
	while(1){
		display();
		timer();
	}


}

void timer(void)
{
	TH0=251;
	TL0=251;
	TR0=1;
	while(1){
		if(TF0==1){
			TF0=0;
			break;
		}
	}

}

void display()
{
	static char num = 0;
	P1 = 0xFE;
	P2 = num;
	
	if(++num > 9)
		num = 0;
}
