/**************************************/
/*              ARE 2008              */
/*      e-mail: biuro@are.net.pl      */
/*      www   : are.net.pl            */
/**************************************/

#define F_CPU 8000000UL  // 8 MHz
//#define F_CPU 14.7456E6
#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#include <string.h>
#include <math.h>

void delay_ms(int ms)
	{
	volatile long unsigned int i;
	for(i=0;i<ms;i++)
		_delay_ms(1);
	}
	
void delay_us(int us)
	{
	volatile long unsigned int i;
	for(i=0;i<us;i++)
		_delay_us(1);
	}

//RS PA0
//RW PA1
//E  PA2
//DATA PD

#define RS 0
#define RW 1
#define E  2

void LCD2x16_init(void)
{
PORTA &= ~(1<<RS);
PORTA &= ~(1<<RW);

PORTA |= (1<<E);
PORTD = 0x38;   // dwie linie, 5x7 punktow
PORTA &=~(1<<E);
_delay_us(120);

PORTA |= (1<<E);
PORTD = 0x0e;   // wlacz wyswietlacz, kursor, miganie
PORTA &=~(1<<E);
_delay_us(120);

PORTA |= (1<<E);
PORTD = 0x06;
PORTA &=~(1<<E);
_delay_us(120);
}

void LCD2x16_clear(void){
PORTA &= ~(1<<RS);
PORTA &= ~(1<<RW);

PORTA |= (1<<E);
PORTD = 0x01;
PORTA &=~(1<<E);
delay_ms(120);
}

void LCD2x16_putchar(int data)
{
PORTA |= (1<<RS);
PORTA &= ~(1<<RW);

PORTA |= (1<<E);
PORTD = data;
PORTA &=~(1<<E);
_delay_us(120);
}

void LCD2x16_pos(int wiersz, int kolumna)
{
PORTA &= ~(1<<RS);
PORTA &= ~(1<<RW);

PORTA |= (1<<E);
delay_ms(1);
PORTD = 0x80+(wiersz-1)*0x40+(kolumna-1);
delay_ms(1);
PORTA &=~(1<<E);
_delay_us(120);
}



int main(void){
char www[16] = "Dawid Perdek     ";
char email[16] = "B. Zychal      ";
char tmp[16] = "                  ";

int i;
int j=4;
float _sp=60;
float _h=8;
float _hf=_h*1024/100;
float _spf=_sp*1024/100;
float _pvf=0, _pv, _e, _ef;
DDRD = 0xff;
PORTD = 0x00;
DDRA = 0b11110111;
PORTA = 0b00000000;
DDRC = 0x00;
PORTC = 0xff;

ADMUX=0x43;
ADCSRA=0xe0;

_delay_ms(200);

LCD2x16_init();
LCD2x16_clear();


    for(i=0;i < 16;i++)
		LCD2x16_putchar(www[i]);
	LCD2x16_pos(2,1);
	for(i=0;i < 16;i++)
		LCD2x16_putchar(email[i]);

delay_ms(3000);
LCD2x16_clear();
for(i=0;i < 16;i++)
	LCD2x16_putchar(www[i]);

LCD2x16_clear();
while(1)
	{
	switch (127-PINC){
		case 1:{
			_sp=50;
			break;
			}
		case 2:{
			_sp=80;
			break;
			}
		case 4:{
			_h=10;
			break;
			}
		case 8:{
			_h=4;
			break;
			}
		}
	
	
	/*	_pvf = (float)ADC;
	_hf=_h*1024/100;
	_spf = _sp*1024/100;
	_pv = _pvf*100/1024;
	_ef = _spf-_pvf;
	_e = _ef*100/1024;			//wersja z procentami
	LCD2x16_pos(1,1);
	sprintf(tmp,"SP=%2i%%  PV=%2i,%1i%% ",(int)_sp,(int)_pv,(int)((_pv-(int)_pv)*10));
	for(i=0;i < 16;i++)
		LCD2x16_putchar(tmp[i]);
	LCD2x16_pos(2,1);
	sprintf(tmp,"h=%2i%%   E=%3i,%1i%% ",(int)_h,(int)(_e),abs((int)((_e-(int)_e)*10)));*/
	
	
	_pvf = (float)ADC;
	_pv = _pvf*400/1024;
	_e = _sp-_pv;
	LCD2x16_pos(1,1); 			// wersja ze stopniami
	sprintf(tmp,"SP=%3iC  PV=%3iC ",(int)_sp*4,(int)_pv);
	for(i=0;i < 16;i++)
		LCD2x16_putchar(tmp[i]);
	LCD2x16_pos(2,1);
	sprintf(tmp,"h=%2iC  E=%4i,%1iC ",(int)_h*4,(int)(_e),abs((int)((_e-(int)_e)*10)));
	
	/*if (_e>(_h/2))
		PORTA = PORTA & 0b11101111;
	if (_e<(-_h/2))
		PORTA = PORTA | 0b00010000;*/ //zapalanie i gaszenie-nie dziala	
		
	j++;
	for(i=0;i < 16;i++)
		LCD2x16_putchar(tmp[i]);
	delay_ms(10);   
	}

return 0;
}