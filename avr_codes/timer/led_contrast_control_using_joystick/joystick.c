#include<avr/io.h>
#include<avr/interrupt.h>
#include<util/delay.h>

int main(void)
{
	ADMUX=0XE2;	//MUX1=1, RFES1=1, REFS0=1 for internal 2.6v ADLAR=1 for left adjust y axix on chnl 2  x axis on chnl 1 
	ADCSRA=0XEF;	//ADPS2:0=111 for 128 prescalar, ADIE=1 interrupt enable, ADATE=1 auto trigger enable, ADSC=1 to start conversion, ADEN=1 to 						enable the ADC
	sei();
	DDRC=0XFF;
	while(1)
	{
	
	}
	return 0;
}

ISR(ADC_vect)
{	
	int a;
	a=ADCH;
	PORTC=0X00;
	_delay_us(a);
	PORTC=0XFF;
	_delay_us(255-a);
}
