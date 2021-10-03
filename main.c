/*  test the UART for 89c52rc(12T)

*/
#include <STC89C5xRC.H>
#include <intrins.h>
#include <stdio.h>
unsigned char flag;



void Delayms(unsigned char tm)		//@11.0592MHz
{
	unsigned char i, j;
	
	while(tm--)
	{
		_nop_();
		i = 2;
		j = 199;
		do
		{
			while (--j);
		} while (--i);
		
	}	
}

void InitUART(void)
{
	SCON=0x50;
	TMOD=0x20;
	TH1=0xfd;
	TR1=1;
	PCON=0x00;
	EA=1;
	ES=1;
	
	// for printf() use 
	RI=TI=1;
}

void SendByte(unsigned char dat)
{
	SBUF=dat;
	while(TI==0);
	
	TI=0;
}


void main(void)
{
	int a;
	a=0xFE;
	InitUART();
	while(1)
	{
		//SendByte('K');
		//printf("enter one charcter:");
	  //printf("===");
		printf("test:%x\n",a);


		Delayms(250);
		Delayms(250);
		//
	
	}
}

