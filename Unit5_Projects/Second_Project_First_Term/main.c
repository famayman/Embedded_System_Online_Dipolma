/*
 * main.c
 *
 *  Created on: Jul 20, 2022
 *      Author: Fam Ayman
 */
#include "Student.h"
int main()
{
	FIFO_Buf_t Data_Base;
	int Option;
	FIFO_Init(&Data_Base,ST,50);
	Dprint("Welcome to the Student Management System\n");
	while(1)
	{
		Dprint("Choose The Task that you want to perform\n");
		Dprint("1. Add the Student Details Manually\n");
		Dprint("2. Add the Student Details From Text File\n");
		Dprint("3. Find the Student Details by Roll Number\n");
		Dprint("4. Find the Student Details by First Name\n");
		Dprint("5. Find the Student Details by Course Id\n");
		Dprint("6. Find the Total number of Students\n");
		Dprint("7. Delete the Students Details by Roll Number\n");
		Dprint("8. Update the Students Details by Roll Number\n");
		Dprint("9. Show all information\n");
		Dprint("10. To Exit\n");
		Dprint("Enter your choice to perform the task :  ");
		scanf("%d",&Option);
		switch(Option)
		{
		case 1 :
			Dprint("====================================\n");
			Add_Student_Manually(&Data_Base);
			Dprint("\n====================================\n");
			break;
		case 2 :
			Dprint("====================================\n");
			Add_Student_Details_From_File(&Data_Base);
			Dprint("\n=====================================\n");
			break;
		case 3 :
			Dprint("======================================\n");
			Find_Student_By_Roll(&Data_Base);
			Dprint("\n======================================\n");
			break;
		case 4 :
			Dprint("=======================================\n");
			Find_Student_By_First_Name(&Data_Base);
			Dprint("\n=======================================\n");
			break;
		case 5 :
			Dprint("=======================================\n");
			Find_NO_OF_Students_IN_Course(&Data_Base);
			Dprint("\n=======================================\n");
			break;
		case 6 :
			Dprint("========================================\n");
			Count_Students(&Data_Base);
			Dprint("\n========================================\n");
			break;
		case 7 :
			Dprint("=========================================\n");
			Delete_Student(&Data_Base);
			Dprint("\n=========================================\n");
			break;
		case 8 :
			Dprint("==========================================\n");
			Update_Student(&Data_Base);
			Dprint("\n==========================================\n");
			break;
		case 9 :
			Dprint("===========================================\n");
			show_Students(&Data_Base);
			Dprint("\n===========================================\n");
			break;
		case 10 :
			Dprint("===========================================\n");
			exit(1);
			Dprint("\n===========================================\n");
			break;
		}
	}
	return 0;
}
