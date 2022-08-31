/*
 * Key_Pad_Driver.c
 *
 * Created: 8/10/2022 10:46:03 AM
 *  Author: Fam Ayman
 */ 
#include "Key_Pad_Driver.h"
int Key_padRow[] = {R0,R1,R2,R3};
int Key_padCol[] = {C0,C1,C2,C3};
void keypad_init()
{ 
	//Setting Row as input........
	keypadDDR &= ~ ((1<<R0) | (1<<R1) | (1<<R2) | (1<<R3));
	//Setting Col as output
	keypadDDR |= ((1<<C0) | (1<<C1) | (1<<C2) | (1<<C3));
	//we need input as input with pull up resistor and output to be High
	keypadPORT = 0xFF ;
}	
char Keypad_getKey()
{
	//How it works .......
	//Firstly we will make all Rows as pull up input pins so the volt on those will be 5 volt and putting high on Col
	//Secondly putting zero on a particular Col 
	//Thirdly we will check if any Row is Low so we can determine the KeyPressed
	int i ,j ;
	for( i = 0; i<4;i++)
	{
		keypadPORT |= (1<<Key_padCol[0] | 1<<Key_padCol[1] | 1<<Key_padCol[2] | 1<<Key_padCol[3]); 
		keypadPORT &= ~(1<<Key_padCol[i]);//Setting a Particular Col with zero 
		for(j=0;j<4;j++)
		{
			if(!(keypadPIN & (1<<Key_padRow[j])))
			{
				while (!(keypadPIN & (1<<Key_padRow[j]))); //waiting until releasing his hand 
				switch (i)
				{
					case 0 :
					{
						if (j == 0) return '7';
						else if (j == 1) return '4';
						else if (j == 2) return '1';
						else if (j == 3) return '?';
						break;
					}
					case 1 :
					{
						if(j == 0) return '8';
						else if(j == 1) return '5';
						else if(j == 2) return '2';
						else if(j == 3) return '0';
						break;
					}
					case 2 :
					{
						if (j == 0) return '9';
						else if (j == 1) return '6';
						else if (j == 2) return '3';
						else if (j == 3) return '=';
						break;
					}
					case 3 :
					{
						if (j == 0) return '/';
						else if (j == 1) return '*';
						else if (j == 2) return '-';
						else if (j == 3) return '+';
						break;
					}
				}
			}
		}
	}
	return 'A' ;//As default No Key pressed..
}