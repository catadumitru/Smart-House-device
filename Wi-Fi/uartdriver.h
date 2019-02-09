/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef XC_HEADER_TEMPLATE_H
#define	XC_HEADER_TEMPLATE_H

#define USART_TX_INT_OFF  0b01111111  // Transmit interrupt off
#define USART_RX_INT_OFF  0b10111111  // Receive interrupt off
#define USART_ASYNCH_MODE 0b11111110  // Asynchronous mode
#define USART_EIGHT_BIT   0b11111101  // 8-bit data
#define USART_BRGH_HIGH   0b11111111  // High baud rate
#define EUSART_DataReady  (PIR1bits.RC1IF)
#define _XTAL_FREQ  8000000
#define BusyUSART( ) (!TXSTAbits.TRMT)
#define putcUSART WriteUSART
#define getcUSART ReadUSART

#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>


#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code.
    void putsUSART ( char *data);
    void EUSART_Initialize(void);
    uint8_t EUSART_Read(void);
    void EUSART_Write(uint8_t txData);
    void uart_init(void);
    void clock_init(void);
    void pin_init();
    void getsUSART(char *buffer, unsigned char len);
    char ReadUSART(void);
    void WriteUSART(char data);
    char DataRdyUSART(void);
#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */

