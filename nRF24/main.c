/* 
 * File:   main.c
 * Author: Monster
 *
 * Created on May 28, 2017, 2:26 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "nrf24driver.h"

/*
 * 
 */
unsigned char temperature1;
unsigned char rxbuf;
void main() {

    temperature1 = 22;
   nrf_init();
   nrf_enablePipe(1);
   nrf_txmode(void);
   nrf_setTxAddr(temperature1);
   nrf_send(temperature1,rxbuf);
   
}

