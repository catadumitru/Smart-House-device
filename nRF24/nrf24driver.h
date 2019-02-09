

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef XC_HEADER_TEMPLATE_H
#define	XC_HEADER_TEMPLATE_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include "nrf24config.h"

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */



#define MAX_PAYLOAD 32

unsigned char nrf_getStatus(void);
unsigned char nrf_send(unsigned char * tx_buf, unsigned char * rx_buf);
void nrf_send_noack(unsigned char * tx_buf, unsigned char * rx_buf);
unsigned char nrf_receive(unsigned char * tx_buf, unsigned char * rx_buf);

void nrf_init(void);
void nrf_txmode(void);
void nrf_rxmode(void);
void nrf_powerdown(void);

void nrf_setTxAddr(char addr);
void nrf_setRxAddr(char pipe, char addr);
char nrf_enablePipe(char pipe);
char nrf_disablePipe(char pipe);


#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */

