/*
 * main.c
 *
 *  Created on: Jul 13, 2022
 *      Author: Fam Ayman
 */


#include "Linked_List.h"
int main()
{
	char Temp_Text[40];
		while(1)
		{
		     Dprint("\n ==============================");
		     Dprint("\n Choose on the following Options \n");
		     Dprint("\n 1: AddStudent ");
		     Dprint("\n 2: Delete_Student ");
		     Dprint("\n 3: view_students ");
		     Dprint("\n 4: DeleteAll ");
		     Dprint("\n 5: Get Nth Node From Start ");
		     Dprint("\n 6: Get Nth from End");
		     Dprint("\n 7: Get List Length with recursive");
		     Dprint("\n 8: Get Length without recursive");
		     Dprint("\n 9: Get Middle ");
		     Dprint("\n 10:  Reverse List");
		     Dprint("\n Enter Option Number : ");
		     gets(Temp_Text);
		     Dprint("\n =======================");
		     switch(atoi(Temp_Text))
		    		 {
		     case 1:
		    	 Add_Student();break;
		     case 2:
		    	 Delete_Student();break;
		     case 3:
		    	 View_Students();break;
		     case 4:
		    	 Delete_All();break;
		     case 5:
		    	 Get_Nth();break;
		     case 6:
		    	 Get_Nth_From_End_Two_Pointer_Method();break;
		     case 7:
		    	 Calling_Get_Length_Recursive();break;
		     case 8:
		    	 Get_Length();break;
		     case 9:
		    	 Get_Middle();break;
		     case 10:
		    	 Reverse_List();break;
		     default:
		    	 Dprint("Wrong Option");break;
		    		 }
		}
		     return 0;
}

