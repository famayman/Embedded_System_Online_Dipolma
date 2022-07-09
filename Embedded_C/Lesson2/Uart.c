#include "Uart.h"
//Uart registers
#define UART0DR   *((volatile unsigned int * const)((unsigned int *)0x101f1000))
void Uart_Send_String(unsigned char * P_Tx_String)
{
 while(* P_Tx_String != '\0')
    {
      UART0DR = (unsigned int)(*P_Tx_String);          
      P_Tx_String++;
    }    

}