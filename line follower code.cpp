/*
 * line_follower_code.cpp
 *
 * Created: 8/11/2019 11:54:34 PM
 *  Author: sachin.
 */ 


#include <avr/io.h>
#define F_CPU 12000000UL
void wait();

int main(void)
{
	DDRD = 0b11111111;
	DDRB = 0b00000000;
	 int ls,rs;
	 
    while(1)
    {
     ls = PINB & 0b00000001;
	 rs = PINB & 0b00000010;
	  if((ls== 0b00000001) && (rs == 0b00000010)){
		  
		  PORTD = 0b00000101;//foreward
	  }
	  if((ls == 0b00000000) && (rs == 0b00000010)){
		  PORTD = 0b00000100;//left
	  }		  
	  	 if((ls == 0b00000001) &&(rs == 0b00000000)){
		   
		   PORTD = 0b00000001;//right
		   }
		   if((ls == 0b00000000) && (rs == 0b00000000)){
			   //stop
		   }
		   //else wait();
		   
}
	}
	void wait(){
		PORTD=0b00000000;
	}