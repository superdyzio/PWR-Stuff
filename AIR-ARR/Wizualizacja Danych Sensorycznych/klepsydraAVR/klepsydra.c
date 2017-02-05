//#define F_CPU 7372800
//#define USART_BAUDRATE 9600 
//#define BAUD_PRESCALE (((F_CPU / (USART_BAUDRATE * 16UL))) - 1) 
/*
#define CZAS 200
#define D1_ON PORTD|=0x80
#define D1_OFF PORTD&=~(0x80)
#define D2_ON PORTC|=0x01
#define D2_OFF PORTC&=~(0x01)
#define D3_ON PORTC|=0x02
#define D3_OFF PORTC&=~(0x02)
#define D33_ON PORTC|=0x04
#define D33_OFF PORTC&=~(0x04)
#define D4_ON PORTC|=0x08
#define D4_OFF PORTC&=~(0x08)
#define D44_ON PORTC|=0x10
#define D44_OFF PORTC&=~(0x10)
#define D5_ON PORTC|=0x20
#define D5_OFF PORTC&=~(0x20)
#define D55_ON PORTC|=0x40
#define D55_OFF PORTC&=~(0x40)
#define G1_ON PORTB|=0x01
#define G1_OFF PORTB&=~(0x01)
#define G2_ON PORTB|=0x02
#define G2_OFF PORTB&=~(0x02)
#define G3_ON PORTB|=0x04
#define G3_OFF PORTB&=~(0x04)
#define G33_ON PORTB|=0x08
#define G33_OFF PORTB&=~(0x08)
#define G4_ON PORTB|=0x10
#define G4_OFF PORTB&=~(0x10)
#define G44_ON PORTD|=0x10
#define G44_OFF PORTD&=~(0x10)
#define G5_ON PORTD|=0x20
#define G5_OFF PORTD&=~(0x20)
#define G55_ON PORTD|=0x40
#define G55_OFF PORTD&=~(0x40)
#define DIODA1_ON PORTC|=0x80
#define DIODA1_OFF PORTC&=~(0x80)
#define DIODA2_ON PORTD|=0x04
#define DIODA2_OFF PORTD&=~(0x04)

#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>
/*
void uartPrintChar(char data) {
    // Wait for empty transmit buffer
    while ( !(UCSRA & (_BV(UDRE))) );
    // Start transmission
    UDR = data; 
}

void uartPrintString(char *s) {
    while (*s) { 
        uartPrintChar(*s);
        s++;
    }
	uartPrintChar('\n');
	//uartPrintChar('\r');
}
 
int wartoscAdc (void) {
    while (!(ADCSRA & (1<<ADIF)));
		ADCSRA|=(1<<ADIF);
    return ADCH;
} 

void czekaj(int ms)	{
	int i;
	for (i=0;i<=ms;i++)
		_delay_ms(1);
}

int main(void) { 
	char buffer[10]; 
	int x, y, kat, gora, dol, kierunek, poziom, tryb, ms;
//	poziom = CZAS/5;
	ms = 100;
	tryb = 0;	// 0 - klepsydra, 1 - poziomica
	gora = 0;
//	dol = CZAS;
	kierunek = 1;
//	UCSRA &= ~(1 << U2X);
//	UCSRC &= ~(1 << UMSEL); //setting the UMSEL bit to 0 for asynchronous mode
//	UBRRH = (unsigned char)(BAUD_PRESCALE >> 8);
//	UBRRL = (unsigned char)BAUD_PRESCALE;
//	UCSRB =(1<< TXEN);//transmitter
//	UCSRC = (1<<USBS) | (3<< UCSZ0); // 2 stopy 8 bitów
	ADCSRA = 0b11000110;//ADC 
//	UBRRH = (BAUD_PRESCALE >> 8);
//	UBRRL = BAUD_PRESCALE;// Load lower 8-bits into the low byte of the UBRR register
	UCSRB = ((1<<TXEN)|(1<<RXEN) | (1<<RXCIE));// Enable receiver and transmitter and receive complete interrupt 
	uint8_t low;
	uint16_t w10b;
	DDRC = 0x00;
	DDRB = 0x00;
	DDRD = 0x00;
	ADMUX = 0XE1; 
	DDRC = 0xFF;
	DDRD |= 0xF4;
	DDRB |= 0x1F;
	//ADCSRA |= 1<<ADSC; // START conversion
	while(1) {/*
		if (!bit_is_clear(PIND,PD3)) {
			tryb = 1;
			DIODA1_ON;
			DIODA2_OFF;
			ms = 10;
		}
		else {
			tryb = 0;
			DIODA2_ON;
			DIODA1_OFF;
			ms = 100;
		}	
		while((UCSRA &(1<<UDRE)) == 0); //czekam na uarta		
			ADCSRA |= 1<<ADSC; // START conversion
			ADMUX = 0XE0;   // x  wybieram kana³ adc i sczytujê dane
			x = wartoscAdc();
			x = x - 80;
			x = (x*180)/145;
			ADCSRA |= 1<<ADSC; // START conversion
			ADMUX = 0XE1;
			y = wartoscAdc();
			y = y - 140; //wysrodkowanie 
			if (y < 0)
				kat = x;
			else
				kat = -x;
			if (tryb == 0) {
				if (kat > -75 && kat < 75) {
					if (dol < CZAS) {
						dol++;
						if (kat > -15 && kat < 15)
							dol++;
					}
					else
						dol = CZAS;
					gora = CZAS - dol;
					if (kierunek <= 0)
						kierunek = 1;
				}
				if (kierunek > 0) {
					if (kierunek % 4 == 1) {
						D1_ON;
						D2_OFF;
						D3_OFF;
						D4_OFF;
					}
					if (kierunek % 4 == 2) {
						D1_OFF;
						D2_ON;
						D3_OFF;
						D4_OFF;
					}
					if (kierunek % 4 == 3) {
						D1_OFF;
						D2_OFF;
						D3_ON;
						D4_OFF;
					}
					if (kierunek % 4 == 0) {
						D1_OFF;
						D2_OFF;
						D3_OFF;
						D4_ON;
					}
					kierunek++;
					if (dol >= poziom) {
						D5_ON;
						D55_ON;
						G1_ON;
						G2_ON;
						G3_ON;
						G33_ON;
						G4_ON;
						G44_ON;
						G55_OFF;
						G5_OFF;
						if (dol >= 2*poziom) {
							D4_ON;
							D44_ON;
							G44_OFF;
							G4_OFF;
							if (dol >= 3*poziom) {
								D3_ON;
								D33_ON;
								G33_OFF;
								G3_OFF;
								if (dol >= 4*poziom) {
									D2_ON;
									G2_OFF;
									if (dol == 5*poziom) {
										D1_ON;
										G1_OFF;
									}
								}
							}
						}
					}
				}
				if (kat < -105 || kat > 105) {
					if (gora < CZAS) {
						gora++;
						if (kat < -150 || kat > 150)
							gora++;
					}
					else
						gora = CZAS;
					dol = CZAS - gora;
					if (kierunek >= 0)
						kierunek = -1;
				}
				if (kierunek < 0) {
					if (-kierunek % 4 == 1) {
						G1_ON;
						G2_OFF;
						G3_OFF;
						G4_OFF;
					}
					if (-kierunek % 4 == 2) {
						G1_OFF;
						G2_ON;
						G3_OFF;
						G4_OFF;
					}
					if (-kierunek % 4 == 3) {
						G1_OFF;
						G2_OFF;
						G3_ON;
						G4_OFF;
					}
					if (-kierunek % 4 == 0) {
						G1_OFF;
						G2_OFF;
						G3_OFF;
						G4_ON;
					}
					kierunek--;
					if (gora >= poziom) {
						G5_ON;
						G55_ON;
						D1_ON;
						D2_ON;
						D3_ON;
						D33_ON;
						D4_ON;
						D44_ON;
						D55_OFF;
						D5_OFF;
						if (gora >= 2*poziom) {
							G4_ON;
							G44_ON;
							D44_OFF;
							D4_OFF;
							if (gora >= 3*poziom) {
								G3_ON;
								G33_ON;
								D33_OFF;
								D3_OFF;
								if (gora >= 4*poziom) {
									G2_ON;
									D2_OFF;
									if (gora == 5*poziom) {
										G1_ON;
										D1_OFF;
									}	
								}
							}
						}
					}
				}
				if (dol == CZAS) {
					PORTC |= 0x7F;
					PORTD |= 0x80;
					PORTD &= 0x8F;
					PORTB &= 0xE0;
				}
				if (gora == CZAS) {
					PORTC &= 0x80;
					PORTD &= 0x7F;
					PORTD |= 0x70;
					PORTB |= 0x1F;
				}
				if ((kat < -75 && kat > -105) || (kat > 75 && kat < 105)) {
					if (kierunek > 0 && dol < CZAS) {
						PORTC &= 0x80;
						PORTD &= 0x7F;
						PORTD |= 0x70;
						PORTB |= 0x1F;
						if (dol > poziom) {
							G1_OFF;
							D55_ON;
							D5_ON;
							if (dol > 2*poziom) {
								G2_OFF;
								D44_ON;
								D4_ON;
								if (dol > 3*poziom) {
									G3_OFF;
									G33_OFF;
									D33_ON;
									D3_ON;
									if (dol > 4*poziom) {
										G2_OFF;
										D2_ON;
										if (dol == CZAS) {
											G1_OFF;
											D1_ON;
										}
									}
								}
							}
						}
					}
					if (kierunek < 0 && gora < CZAS) {
						PORTC |= 0x7F;
						PORTD |= 0x80;
						PORTD &= 0x8F;
						PORTB &= 0xE0;
						if (gora > poziom) {
							D1_OFF;
							G55_ON;
							G5_ON;
							if (gora > 2*poziom) {
								D2_OFF;
								G44_ON;
								G4_ON;
								if (gora > 3*poziom) {
									D3_OFF;
									D33_OFF;
									G33_ON;
									G3_ON;
									if (gora > 4*poziom) {
										D2_OFF;
										G2_ON;
										if (gora == CZAS) {
											D1_OFF;
											G1_ON;
										}
									}
								}
							}
						}
					}
					kierunek = 0;
				}
			}
			if (tryb == 1) {
				if ((kat < -75 && kat > -105) || (kat > 75 && kat < 105)) {
					PORTC &= 0x80;
					PORTD &= 0x0F;
					PORTB &= 0xE0;
				}
				if ((kat > -75 && kat < -60) || (kat > 60 && kat < 75)) {
					PORTC &= 0x80;
					PORTD &= 0x0F;
					PORTB &= 0xE0;
					D1_ON;
				}
				if ((kat < -45 && kat > -60) || (kat > 45 && kat < 60)) {
					PORTC &= 0x80;
					PORTD &= 0x0F;
					PORTB &= 0xE0;
					D1_ON;
					D2_ON; 
				}
				if ((kat < -30 && kat > -45) || (kat > 30 && kat < 45)) {
					PORTC &= 0x80;
					PORTD &= 0x0F;
					PORTB &= 0xE0;
					D1_ON;
					D2_ON;
					D3_ON;
				}
				if ((kat < -15 && kat > -30) || (kat > 15 && kat < 30)) {
					PORTC &= 0x80;
					PORTD &= 0x0F;
					PORTB &= 0xE0;
					D1_ON;
					D2_ON;
					D3_ON;
					D4_ON;
				}
				if (kat < 15 && kat > -15) {
					PORTC &= 0x80;
					PORTD &= 0x0F;
					PORTB &= 0xE0;
					D1_ON;
					D2_ON;
					D3_ON;
					D4_ON;
					D5_ON;
				}
				if ((kat > 105 && kat < 120) || (kat < -105 && kat > -120)) {
					PORTC &= 0x80;
					PORTD &= 0x0F;
					PORTB &= 0xE0;
					G1_ON;
				}
				if ((kat > 120 && kat < 135) || (kat < -120 && kat > -135)) {
					PORTC &= 0x80;
					PORTD &= 0x0F;
					PORTB &= 0xE0;
					G1_ON;
					G2_ON;
				}
				if ((kat > 135 && kat < 150) || (kat < -135 && kat > -150)) {
					PORTC &= 0x80;
					PORTD &= 0x0F;
					PORTB &= 0xE0;
					G1_ON;
					G2_ON;
					G3_ON;
				}
				if ((kat > 150 && kat < 165) || (kat < -150 && kat > -165)) {
					PORTC &= 0x80;
					PORTD &= 0x0F;
					PORTB &= 0xE0;
					G1_ON;
					G2_ON;
					G3_ON;
					G4_ON;
				}
				if ((kat > 165 && kat < 180) || (kat < -165 && kat > -180)) {
					PORTC &= 0x80;
					PORTD &= 0x0F;
					PORTB &= 0xE0;
					G1_ON;
					G2_ON;
					G3_ON;
					G4_ON;
					G5_ON;
				}
			}
			itoa(kat,buffer,10);                  // convert numerals into string
			uartPrintString(buffer);                   // display the received value on LCD	
			_delay_ms(ms);
	}
	return(0);
}*/

#define F_CPU 4000000
#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>

#define CZAS 200
#define D1_ON PORTC|=0x01
#define D1_OFF PORTC&=~(0x01)
#define D2_ON PORTC|=0x02
#define D2_OFF PORTC&=~(0x02)
#define D3_ON PORTC|=0x04
#define D3_OFF PORTC&=~(0x04)
#define D33_ON PORTC|=0x08
#define D33_OFF PORTC&=~(0x08)
#define D4_ON PORTA|=0x80
#define D4_OFF PORTA&=~(0x80)
#define D44_ON PORTA|=0x20
#define D44_OFF PORTA&=~(0x20)
#define D5_ON PORTA|=0x08
#define D5_OFF PORTA&=~(0x08)
#define D55_ON PORTB|=0x01
#define D55_OFF PORTB&=~(0x01)
#define G1_ON PORTC|=0x10
#define G1_OFF PORTC&=~(0x10)
#define G2_ON PORTC|=0x20
#define G2_OFF PORTC&=~(0x20)
#define G3_ON PORTC|=0x40
#define G3_OFF PORTC&=~(0x40)
#define G33_ON PORTC|=0X80
#define G33_OFF PORTC&=~(0x80)
#define G4_ON PORTA|=0x40
#define G4_OFF PORTA&=~(0x40)
#define G44_ON PORTA|=0x10
#define G44_OFF PORTA&=~(0x10)
#define G5_ON PORTA|=0x04
#define G5_OFF PORTA&=~(0x04)
#define G55_ON PORTB|=0x10
#define G55_OFF PORTB&=~(0x10)
#define DIODA1_ON PORTC|=0x80
#define DIODA1_OFF PORTC&=~(0x80)
#define DIODA2_ON PORTD|=0x04
#define DIODA2_OFF PORTD&=~(0x04)
#define RGB_RON PORTD|=0x80
#define RGB_ROFF PORTD&=~(0x80)
#define RGB_GON PORTD|=0x40
#define RGB_GOFF PORTD&=~(0x40)
#define RGB_BON PORTD|=0x20
#define RGB_BOFF PORTD&=~(0x20)

int wartoscAdc (void) {
    while (!(ADCSRA & (1<<ADIF)));
		ADCSRA|=(1<<ADIF);
    return ADCH;
} 

int main() {
	DDRA = 0xFC;
	DDRB |= 0x11;
	DDRC = 0xFF;
	DDRD = 0xE0;
	int x, y, kat, gora, dol, kierunek, poziom, tryb, ms;
	poziom = CZAS/5;
	ms = 100;
	tryb = 0;	// 0 - klepsydra, 1 - poziomica
	gora = 0;
	dol = CZAS;
	kierunek = 1;
	UCSRA &= ~(1 << U2X);
	UCSRC &= ~(1 << UMSEL); //setting the UMSEL bit to 0 for asynchronous mode
	ADCSRA = 0b11000110;//ADC  
	uint8_t low;
	uint16_t w10b;
	while(1) {
		if (!bit_is_clear(PINB,PD3)) {
			tryb = 1;
			RGB_BON;
			RGB_GOFF;
			RGB_ROFF;
			ms = 10;
		}
		else {
			tryb = 0;
			RGB_GON;
			RGB_BOFF;
			RGB_ROFF;
			ms = 100;
		}	
		while((UCSRA &(1<<UDRE)) == 0); //czekam na uarta		
			ADCSRA |= 1<<ADSC; // START conversion
			ADMUX = 0XE0;   // x  wybieram kana³ adc i sczytujê dane
			x = wartoscAdc();
			x = x - 80;
			x = (x*180)/145;
			ADCSRA |= 1<<ADSC; // START conversion
			ADMUX = 0XE1;
			y = wartoscAdc();
			y = y - 140; //wysrodkowanie 
			if (y < 0)
				kat = x;
			else
				kat = -x;
			kat -= 30;
			if (tryb == 0) {
				if (kat > -75 && kat < 75) {
					if (dol < CZAS) {
						dol++;
						if (kat > -15 && kat < 15)
							dol++;
					}
					else
						dol = CZAS;
					gora = CZAS - dol;
					if (kierunek <= 0)
						kierunek = 1;
				}
				if (kierunek > 0) {
					if (kierunek % 4 == 1) {
						D1_ON;
						D2_OFF;
						D3_OFF;
						D4_OFF;
					}
					if (kierunek % 4 == 2) {
						D1_OFF;
						D2_ON;
						D3_OFF;
						D4_OFF;
					}
					if (kierunek % 4 == 3) {
						D1_OFF;
						D2_OFF;
						D3_ON;
						D4_OFF;
					}
					if (kierunek % 4 == 0) {
						D1_OFF;
						D2_OFF;
						D3_OFF;
						D4_ON;
					}
					kierunek++;
					if (dol >= poziom) {
						D5_ON;
						D55_ON;
						G1_ON;
						G2_ON;
						G3_ON;
						G33_ON;
						G4_ON;
						G44_ON;
						G55_OFF;
						G5_OFF;
						if (dol >= 2*poziom) {
							D4_ON;
							D44_ON;
							G44_OFF;
							G4_OFF;
							if (dol >= 3*poziom) {
								D3_ON;
								D33_ON;
								G33_OFF;
								G3_OFF;
								if (dol >= 4*poziom) {
									D2_ON;
									G2_OFF;
									if (dol == 5*poziom) {
										D1_ON;
										G1_OFF;
									}
								}
							}
						}
					}
				}
				if (kat < -105 || kat > 105) {
					if (gora < CZAS) {
						gora++;
						if (kat < -150 || kat > 150)
							gora++;
					}
					else
						gora = CZAS;
					dol = CZAS - gora;
					if (kierunek >= 0)
						kierunek = -1;
				}
				if (kierunek < 0) {
					if (-kierunek % 4 == 1) {
						G1_ON;
						G2_OFF;
						G3_OFF;
						G4_OFF;
					}
					if (-kierunek % 4 == 2) {
						G1_OFF;
						G2_ON;
						G3_OFF;
						G4_OFF;
					}
					if (-kierunek % 4 == 3) {
						G1_OFF;
						G2_OFF;
						G3_ON;
						G4_OFF;
					}
					if (-kierunek % 4 == 0) {
						G1_OFF;
						G2_OFF;
						G3_OFF;
						G4_ON;
					}
					kierunek--;
					if (gora >= poziom) {
						G5_ON;
						G55_ON;
						D1_ON;
						D2_ON;
						D3_ON;
						D33_ON;
						D4_ON;
						D44_ON;
						D55_OFF;
						D5_OFF;
						if (gora >= 2*poziom) {
							G4_ON;
							G44_ON;
							D44_OFF;
							D4_OFF;
							if (gora >= 3*poziom) {
								G3_ON;
								G33_ON;
								D33_OFF;
								D3_OFF;
								if (gora >= 4*poziom) {
									G2_ON;
									D2_OFF;
									if (gora == 5*poziom) {
										G1_ON;
										D1_OFF;
									}	
								}
							}
						}
					}
				}
				if (dol == CZAS) {
					PORTC &= 0x00;
					PORTC |= 0x0F;
					PORTA &= ~(0xFC);
					PORTA |= 0xA8;
					PORTB &= ~(0x11);
					PORTB |= 0x01;
				}
				if (gora == CZAS) {
					PORTC &= 0x00;
					PORTC |= 0xF0;
					PORTA &= ~(0xFC);
					PORTA |= 0x54;
					PORTB &= ~(0x11);
					PORTA |= 0x10;
				}
				if ((kat < -75 && kat > -105) || (kat > 75 && kat < 105)) {
					if (kierunek > 0 && dol < CZAS) {
						PORTC &= 0x00;
						PORTC |= 0xF0;
						PORTA &= ~(0xFC);
						PORTA |= 0x54;
						PORTB &= ~(0x11);
						PORTA |= 0x10;
						if (dol > poziom) {
							G1_OFF;
							D55_ON;
							D5_ON;
							if (dol > 2*poziom) {
								G2_OFF;
								D44_ON;
								D4_ON;
								if (dol > 3*poziom) {
									G3_OFF;
									G33_OFF;
									D33_ON;
									D3_ON;
									if (dol > 4*poziom) {
										G2_OFF;
										D2_ON;
										if (dol == CZAS) {
											G1_OFF;
											D1_ON;
										}
									}
								}
							}
						}
					}
					if (kierunek < 0 && gora < CZAS) {
						PORTC &= 0x00;
						PORTC |= 0x0F;
						PORTA &= ~(0xFC);
						PORTA |= 0xA8;
						PORTB &= ~(0x11);
						PORTB |= 0x01;
						if (gora > poziom) {
							D1_OFF;
							G55_ON;
							G5_ON;
							if (gora > 2*poziom) {
								D2_OFF;
								G44_ON;
								G4_ON;
								if (gora > 3*poziom) {
									D3_OFF;
									D33_OFF;
									G33_ON;
									G3_ON;
									if (gora > 4*poziom) {
										D2_OFF;
										G2_ON;
										if (gora == CZAS) {
											D1_OFF;
											G1_ON;
										}
									}
								}
							}
						}
					}
					kierunek = 0;
				}
			}
			if (tryb == 1) {
				if ((kat < -75 && kat > -105) || (kat > 75 && kat < 105)) {
					PORTC &= 0x00;
					PORTA &= ~(0xFC);
					PORTB &= ~(0x11);
				}
				if ((kat > -75 && kat < -60) || (kat > 60 && kat < 75)) {
					PORTC &= 0x00;
					PORTA &= ~(0xFC);
					PORTB &= ~(0x11);
					D1_ON;
				}
				if ((kat < -45 && kat > -60) || (kat > 45 && kat < 60)) {
					PORTC &= 0x00;
					PORTA &= ~(0xFC);
					PORTB &= ~(0x11);
					D1_ON;
					D2_ON; 
				}
				if ((kat < -30 && kat > -45) || (kat > 30 && kat < 45)) {
					PORTC &= 0x00;
					PORTA &= ~(0xFC);
					PORTB &= ~(0x11);
					D1_ON;
					D2_ON;
					D3_ON;
				}
				if ((kat < -15 && kat > -30) || (kat > 15 && kat < 30)) {
					PORTC &= 0x00;
					PORTA &= ~(0xFC);
					PORTB &= ~(0x11);
					D1_ON;
					D2_ON;
					D3_ON;
					D4_ON;
				}
				if (kat < 15 && kat > -15) {
					PORTC &= 0x00;
					PORTA &= ~(0xFC);
					PORTB &= ~(0x11);
					D1_ON;
					D2_ON;
					D3_ON;
					D4_ON;
					D5_ON;
				}
				if ((kat > 105 && kat < 120) || (kat < -105 && kat > -120)) {
					PORTC &= 0x00;
					PORTA &= ~(0xFC);
					PORTB &= ~(0x11);
					G1_ON;
				}
				if ((kat > 120 && kat < 135) || (kat < -120 && kat > -135)) {
					PORTC &= 0x00;
					PORTA &= ~(0xFC);
					PORTB &= ~(0x11);
					G1_ON;
					G2_ON;
				}
				if ((kat > 135 && kat < 150) || (kat < -135 && kat > -150)) {
					PORTC &= 0x00;
					PORTA &= ~(0xFC);
					PORTB &= ~(0x11);
					G1_ON;
					G2_ON;
					G3_ON;
				}
				if ((kat > 150 && kat < 165) || (kat < -150 && kat > -165)) {
					PORTC &= 0x00;
					PORTA &= ~(0xFC);
					PORTB &= ~(0x11);
					G1_ON;
					G2_ON;
					G3_ON;
					G4_ON;
				}
				if ((kat > 165 && kat < 180) || (kat < -165 && kat > -180)) {
					PORTC &= 0x00;
					PORTA &= ~(0xFC);
					PORTB &= ~(0x11);
					G1_ON;
					G2_ON;
					G3_ON;
					G4_ON;
					G5_ON;
				}
			}
			_delay_ms(ms);
	}
	return 0;
}