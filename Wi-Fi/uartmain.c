 
#include "uartdriver.h"
#include <p18f45k20.h>
#include <stdlib.h>
#include "tmr0.h"
#include "interrupt_manager.h"

char createMeasurement(char temp, char humidity, char light, char status);
int i = 50;
unsigned char measurements_array[];
unsigned char MsgFromPIC[] = "hk";
unsigned char measurement[4];
unsigned char meas[4];
unsigned char MsgToPIC[2];
uint8_t data = 10;
uint8_t count= 0;


void main(void)
{  
    INTERRUPT_GlobalInterruptEnable();
    
    pin_init();
    clock_init();
    uart_init();
    INTERRUPT_Initialize();
    TMR0_Initialize();

      while (1)
    {
        //__delay_ms(1000);
     
//        if(getCount() == 2){
//           putsUSART(MsgFromPIC);
//        }
        getsUSART(MsgToPIC,2);
        
       // __delay_ms(1000);
        // Add your application code
       
    }
}

