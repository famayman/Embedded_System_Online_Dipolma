#include "stdint.h"
extern int main();
extern uint32_t S_data;
extern uint32_t E_data;
extern uint32_t S_bss;
extern uint32_t E_bss;
extern uint32_t E_text;
extern uint32_t stack_top;


void Reset_Handler(void);
void Default_Handler(void)
{
    Reset_Handler();
}
void NMI(void) __attribute__((weak,alias("Default_Handler")));
void Hard_Fault(void)__attribute__((weak,alias("Default_Handler")));
void Mm_Fault(void)__attribute__((weak,alias("Default_Handler")));
void Bus_Fault(void)__attribute__((weak,alias("Default_Handler")));
void Usage_Fault(void)__attribute__((weak,alias("Default_Handler")));

uint32_t vectors[]__attribute__((section(".vectors")))=
{
    (uint32_t) &stack_top,
    (uint32_t) &Reset_Handler,
    (uint32_t) &NMI,
    (uint32_t)&Hard_Fault,    
    (uint32_t)&Mm_Fault,
    (uint32_t)&Bus_Fault,
    (uint32_t)&Usage_Fault
};

void Reset_Handler(void)
{
   unsigned int Data_size=(unsigned char *)&E_data - (unsigned char*)&S_data;
   unsigned char* P_src=(unsigned char*)&E_text;
   unsigned char* P_dis=(unsigned char*)&S_data;
   int i;
   for(i=0;i<Data_size;i++)
     {*((unsigned char*)P_dis++) = *((unsigned char*)P_src++);}
   uint32_t bss_size=(unsigned char*)&E_bss-(unsigned char*)&S_bss;
   for(i=0;i<bss_size;i++)
     {*((unsigned char*)P_dis++) = (unsigned char)0;}
    main(); 
}










