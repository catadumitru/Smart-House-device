#include "dht11driver.h"

void StartSignal(){
    //Configure RD2 as output
    TRISCbits.TRISC2 =0;
    //RD2 sends 0 to the sensor
    PORTCbits.RC2 =0;
    __delay_ms(20);
    PORTCbits.RC2 =1;   //RC2 sends 1 to the sensor
    __delay_us(30);
    TRISCbits.TRISC2 = 1;    //Configure RC2 as input
  }
  void CheckResponse(){
    a = 0;
    __delay_us(40);
    if (PORTCbits.RC2 == 0){

      __delay_us(80);
    }
        if (PORTCbits.RC2 == 1) {
            a = 1;    
           __delay_us(40);
        }
 }
  void ReadData(){  
    for(b=0;b<8;b++)
    {
       while(!PORTCbits.RC2); //Wait until RC2 goes HIGH
       __delay_us(30); 
       if(PORTCbits.RC2 == 0){
           i&=~(1<<(7-b));  //Clear bit (7-b)
       }    
       else{
           i|= (1<<(7-b));       
       }        //Set bit (7-b)
       while(PORTCbits.RC2);  //Wait until RC2 goes LOW
        }
    }