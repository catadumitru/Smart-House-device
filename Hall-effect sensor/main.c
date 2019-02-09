/* 
 * File:   main.c
 * Author: Monster
 *
 * Created on April 12, 2017, 1:57 PM
 */



#include <stdio.h>
#include <stdlib.h>
#include <p18f45k20.h>
#include <xc.h>
#include "mcc_generated_files/adc.h"
#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/pin_manager.h"


/*
 * 
 */
uint16_t channel = 1;
uint16_t convertedValue;
void main() {
   SYSTEM_Initialize();
ADC_Initialize();


 TRISDbits.RD7 = 0;
 
 while(1){
     ADC_SelectChannel(channel);
      __delay_ms(10);
    ADC_StartConversion();
  
    while(ADC_IsConversionDone());
     
        convertedValue = ADC_GetConversionResult();

        if( convertedValue <765 ){
             LATDbits.LATD7 = 0;
    
        }
        else{
               LATDbits.LATD7 = 1;
        }
   
 }
}

