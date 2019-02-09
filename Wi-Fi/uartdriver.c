#pragma config FOSC = INTIO67    // Oscillator Selection bits->Internal oscillator block, port function on RA6 and RA7
#pragma config FCMEN = OFF    // Fail-Safe Clock Monitor Enable bit->Fail-Safe Clock Monitor disabled
#pragma config IESO = OFF    // Internal/External Oscillator Switchover bit->Oscillator Switchover mode disabled

// CONFIG2L
#pragma config PWRT = OFF    // Power-up Timer Enable bit->PWRT disabled
#pragma config BOREN = SBORDIS    // Brown-out Reset Enable bits->Brown-out Reset enabled in hardware only (SBOREN is disabled)
#pragma config BORV = 18    // Brown Out Reset Voltage bits->VBOR set to 1.8 V nominal

// CONFIG2H
#pragma config WDTEN = OFF    // Watchdog Timer Enable bit->WDT is controlled by SWDTEN bit of the WDTCON register
#pragma config WDTPS = 32768    // Watchdog Timer Postscale Select bits->1:32768

// CONFIG3H
#pragma config CCP2MX = PORTC    // CCP2 MUX bit->CCP2 input/output is multiplexed with RC1
#pragma config PBADEN = ON    // PORTB A/D Enable bit->PORTB<4:0> pins are configured as analog input channels on Reset
#pragma config LPT1OSC = OFF    // Low-Power Timer1 Oscillator Enable bit->Timer1 configured for higher power operation
#pragma config HFOFST = ON    // HFINTOSC Fast Start-up->HFINTOSC starts clocking the CPU without waiting for the oscillator to stablize.
#pragma config MCLRE = ON    // MCLR Pin Enable bit->MCLR pin enabled; RE3 input pin disabled

// CONFIG4L
#pragma config STVREN = ON    // Stack Full/Underflow Reset Enable bit->Stack full/underflow will cause Reset
#pragma config LVP = ON    // Single-Supply ICSP Enable bit->Single-Supply ICSP enabled
#pragma config XINST = OFF    // Extended Instruction Set Enable bit->Instruction set extension and Indexed Addressing mode disabled (Legacy mode)
#pragma config DEBUG = OFF    // Background Debugger Enable bit->Background debugger disabled, RB6 and RB7 configured as general purpose I/O pins

// CONFIG5L
#pragma config CP0 = OFF    // Code Protection Block 0->Block 0 (000800-001FFFh) not code-protected
#pragma config CP1 = OFF    // Code Protection Block 1->Block 1 (002000-003FFFh) not code-protected
#pragma config CP2 = OFF    // Code Protection Block 2->Block 2 (004000-005FFFh) not code-protected
#pragma config CP3 = OFF    // Code Protection Block 3->Block 3 (006000-007FFFh) not code-protected

// CONFIG5H
#pragma config CPB = OFF    // Boot Block Code Protection bit->Boot block (000000-0007FFh) not code-protected
#pragma config CPD = OFF    // Data EEPROM Code Protection bit->Data EEPROM not code-protected

// CONFIG6L
#pragma config WRT0 = OFF    // Write Protection Block 0->Block 0 (000800-001FFFh) not write-protected
#pragma config WRT1 = OFF    // Write Protection Block 1->Block 1 (002000-003FFFh) not write-protected
#pragma config WRT2 = OFF    // Write Protection Block 2->Block 2 (004000-005FFFh) not write-protected
#pragma config WRT3 = OFF    // Write Protection Block 3->Block 3 (006000-007FFFh) not write-protected

// CONFIG6H
#pragma config WRTC = OFF    // Configuration Register Write Protection bit->Configuration registers (300000-3000FFh) not write-protected
#pragma config WRTB = OFF    // Boot Block Write Protection bit->Boot Block (000000-0007FFh) not write-protected
#pragma config WRTD = OFF    // Data EEPROM Write Protection bit->Data EEPROM not write-protected

// CONFIG7L
#pragma config EBTR0 = OFF    // Table Read Protection Block 0->Block 0 (000800-001FFFh) not protected from table reads executed in other blocks
#pragma config EBTR1 = OFF    // Table Read Protection Block 1->Block 1 (002000-003FFFh) not protected from table reads executed in other blocks
#pragma config EBTR2 = OFF    // Table Read Protection Block 2->Block 2 (004000-005FFFh) not protected from table reads executed in other blocks
#pragma config EBTR3 = OFF    // Table Read Protection Block 3->Block 3 (006000-007FFFh) not protected from table reads executed in other blocks

// CONFIG7H
#pragma config EBTRB = OFF    // Boot Block Table Read Protection bit->Boot Block (000000-0007FFh) not protected from table reads executed in other blocks
unsigned char UART1Config = 0, baud = 0;

#include <p18f45k20.h>
#include "uartdriver.h"

void WriteUSART(char data)
{
  TXREG = data;      // Write the data byte to the USART
}


char DataRdyUSART(void)
{
  if(PIR1bits.RC1IF)  // If RCIF is set
    return 1;  // Data is available, return TRUE
  return 0;  // Data not available, return FALSE
}
void getsUSART(char *buffer, unsigned char len)
{
  char i;    // Length counter
  unsigned char data;

  for(i=0;i<len;i++)  // Only retrieve len characters
  {
    while(!DataRdyUSART());// Wait for data to be received

    data = getcUSART();    // Get a character from the USART
                           // and save in the string
    *buffer = data;
    buffer++;              // Increment the string pointer
  }
}


char ReadUSART(void)		//this function can be removed by macro #define ReadUSART RCREG
{
  char data;   // Holds received data

  //USART_Status.val &= 0xf2;          // Clear previous status flags

 
  data = RCREG;                      // Read data

  return (data);                     // Return the received data
}

void putsUSART( char *data)
{
  do
  {  // Transmit a byte
    while(BusyUSART());
    putcUSART(*data);
  } while( *data++ );
}

void clock_init(void){
    
    // INTSRC disabled; PLLEN disabled; TUN 0; 
    OSCCON = 0x60;
    // Set the secondary oscillator
    OSCTUNE = 0x00;
}

void OpenUSART( unsigned char config, unsigned int spbrg)
{
  TXSTA1 = 0;          // Reset USART registers to POR state
  RCSTA1 = 0;
 
  if(config&0x01)      // Sync or async operation
    TXSTA1bits.SYNC = 1;

  if(config&0x02)      // 8- or 9-bit mode
  {
    TXSTA1bits.TX9 = 1;	
    RCSTA1bits.RX9 = 1;
  }

  if(config&0x04)      // Master or Slave (sync only)
    TXSTA1bits.CSRC = 1;

  if(config&0x08)      // Continuous or single reception
    RCSTA1bits.CREN = 1;
  else
    RCSTA1bits.SREN = 1;

  if(config&0x10)      // Baud rate select (asychronous mode only)
    TXSTA1bits.BRGH = 1;
  else
    TXSTA1bits.BRGH = 0;

  if(config&0x40)      // Interrupt on receipt
    PIE1bits.RC1IE = 1;
  else
    PIE1bits.RC1IE = 0;

  if(config&0x80)      // Interrupt on transmission
    PIE1bits.TX1IE = 1;
  else
    PIE1bits.TX1IE = 0;

  SPBRG1 = spbrg;       // Write baudrate to SPBRG
  
  TXSTA1bits.TXEN = 1;  // Enable transmitter
  RCSTA1bits.SPEN = 1;  // Enable receiver
	TRISCbits.TRISC6 = 0;TRISCbits.TRISC7 = 1; 
	if(TXSTA1bits.SYNC && !TXSTA1bits.CSRC)	//synchronous  slave mode
		TRISCbits.TRISC6 = 1;
}




void pin_init(){
    TRISCbits.RC6 = 0; //TX pin set as output
    TRISCbits.RC7 = 1; //RX pin set as input
     WPUB = 0xFF;
    INTCON2bits.nRBPU = 0;
    TRISE = 0x07;
    ANSELH = 0x1F;
    ANSEL = 0xFF;
}

void uart_init(void){
    UART1Config = USART_TX_INT_OFF & USART_RX_INT_OFF & USART_ASYNCH_MODE & USART_EIGHT_BIT & USART_BRGH_HIGH ;
    baud = 51;
    OpenUSART(UART1Config,baud);
}
