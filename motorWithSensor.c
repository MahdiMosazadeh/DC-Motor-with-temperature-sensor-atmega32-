#include <mega32.h>
#include <delay.h>
#include <io.h>
int first,second;
int a,b;
void main(void)
{
DDRA=0b00000000;
DDRD=0b01110111;
while (1)
    {   
        ADMUX=0b11000000;
        ADCSRA=0b11000110;
        while(ADCSRA & 0b00010000==0);
        ADCSRA=0b10010110;
        first=ADCW;
        a=first/4;
        
        ADMUX=0b11000001;
        ADCSRA=0b11000110;
        while(ADCSRA & 0b00010000==0);
        ADCSRA=0b10010110;
        second=ADCW;
        b=second/4;
        
        if(a>30)
        {
            PORTD.2=1;
            PORTD.0=1;
            PORTD.1=0;       
        }
        if(a<30)
        {
            PORTD.2=1;
            PORTD.0=0;
            PORTD.1=0;       
        }
        
        if(b>30)
        {
            PORTD.4=1;
            PORTD.5=1;
            PORTD.6=0;       
        }
        if(b<30)
        {
            PORTD.4=1;
            PORTD.5=0;
            PORTD.6=0;       
        }
    }    
    
}
