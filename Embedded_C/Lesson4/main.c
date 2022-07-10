/*Perpared BY
ENG FAM
*/
//Registers
#define SYSCTL_RCGC2_R       (*((volatile unsigned long * )0x400FE108))  //Enable GPIO PORT
#define GPIO_PORTF_DATA_R    (*((volatile unsigned long * )0x400253FC))  //Writing on PORT    
#define GPIO_PORTF_DIR_R     (*((volatile unsigned long * )0x40025400))  //setuping pin for input or output
#define GPIO_PORTF_DEN_R     (*((volatile unsigned long * )0x4002551C))  //Enabling Pin
int main(void)
{
   volatile unsigned long delay_count; //For making delay
   SYSCTL_RCGC2_R = 0x00000020;        //To enable GPIO module
   for(delay_count = 0;delay_count<200;delay_count++); //Taking time to initialise
   GPIO_PORTF_DIR_R |= (1<<3);         //Setting pin as output 
   GPIO_PORTF_DEN_R |= (1<<3);         //Enabling pin
   while(1)
   {
    GPIO_PORTF_DATA_R |= 1<<3;                            //LED ON
    for(delay_count = 0;delay_count < 200 ;delay_count++);      //Delay
    GPIO_PORTF_DATA_R &= ~(1<<3);                         //LED OFF
    for(delay_count = 0;delay_count < 200 ;delay_count++);      //Delay
    }
    return 0 ;
}