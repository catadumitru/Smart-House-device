 
#ifndef XC_HEADER_TEMPLATE_H
#define	XC_HEADER_TEMPLATE_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include <p18f45k20.h>

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

  
#define CE			PORTCbits.RC0
#define TRIS_CE		TRISCbits.TRISC0
#define CSN			PORTCbits.RC1
#define TRIS_CSN	TRISCbits.TRISC1
#define IRQ			PORTCbits.RC2
#define TRIS_IRQ	TRISCbits.TRISC2

#define TRIS_SCK	TRISCbits.TRISC3
#define TRIS_MISO	TRISCbits.TRISC4
#define TRIS_MOSI	TRISCbits.TRISC5


#define SPI_BUFFER_FULL_STAT    SSPSTATbits.BF
#define SPI_BUFFER              SSPBUF

#define SPI_STATUS				SSPSTAT
#define SPI_CLK_EDGE			SSPSTATbits.CKE //clock edge
#define SPI_CLK_POL				SSPCON1bits.CKP //clock polarity
#define SPI_CONFIG_1			SSPCON1
#define SPI_ENABLE				SSPCON1bits.SSPEN

#define SPI_CONFIG_1_VALUE  0b00100010
#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */

