#include "Uart.h"
unsigned char string_buffer[100] = "Learn-in-depth-fam";
unsigned char const stirng_buffer2[100] = "Learn-in-depth-fam";
void main(void)
{
    Uart_Send_String(&string_buffer[0]);
}