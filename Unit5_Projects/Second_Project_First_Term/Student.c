/*****************************************************************
 * Student.c
 *
 *  Created on: Jul 20, 2022
 *      Author: Fam Ayman
 ****************************************************************/
#include "Student.h"

/***************************************************************
 * APIS Implementation
 **************************************************************/
FIFO_Buf_Status IS_FIFO_Full(FIFO_Buf_t * FIFO_Buf)
{
	if(!FIFO_Buf->base || !FIFO_Buf->head || !FIFO_Buf->tail )//Checking if FIFO already exists..
		return FIFO_Null;
	if(FIFO_Buf->count == FIFO_Buf->length )
		return FIFO_IS_Full;
	else
		return FIFO_NO_Error;
}
FIFO_Buf_Status IS_FIFO_Empty(FIFO_Buf_t * FIFO_Buf)
{
	if(!FIFO_Buf->base || !FIFO_Buf->head || !FIFO_Buf->tail)
		return FIFO_Null;
	if(FIFO_Buf->count == 0)
		return FIFO_IS_Empty;
	else
		return FIFO_NO_Error;
}
int Check_Roll_Num(FIFO_Buf_t * FIFO_Buf,Sinfo * Buf,int Num)
{
	int i, flag=0;
	for(i = 0 ; i<FIFO_Buf->count;i++)
	{
		if(Buf->roll == Num)
		{
			flag = 1;
			break;
		}
		Buf++;
	}
	return flag;
}
void FIFO_Init(FIFO_Buf_t * FIFO_Buf,Sinfo * Buf,uint32_t Length)
{
	if(Buf == Null)//Checking if there is a struct
	{Dprint("\n[Error] FIFO Does not exist");}
	else
	{
		FIFO_Buf->base =  Buf;//Let base has address of Buf
		FIFO_Buf->head =  Buf;//Let head has address of buf then increasing it with data added
		FIFO_Buf->tail =  Buf;//Let head has address of buf and increasing it with data removed
		FIFO_Buf->length = Length;//Length of FIFO
		FIFO_Buf->count = 0;//increasing it untill reaching to FIFO top
	}
}
void Add_Student_Details_From_File(FIFO_Buf_t * FIFO_Buf)
{
	if(FIFO_Buf->base == Null || FIFO_Buf->head == Null || FIFO_Buf->tail == Null)
	{
		Dprint("\n[Error]FIFO does not exist");
	}
	//Checking if FIFO IS FULL
	else if(IS_FIFO_Full(FIFO_Buf) == FIFO_IS_Full )
	{
		Dprint("FIFO IS FUll\n");
	}
	else
	{
		FILE * ptr=fopen("Students.txt","r");
		char Line[50];//to store Line
		const char * Taken;//points to parts of line
		int Line_Number = 0,Line_Parts = 0, Student_Duplicated_Roll= 0;
		while(fgets(Line,sizeof (Line),ptr))//Looping till end of file
		{
			Line_Number++; //increasing Line Number
			Line_Parts = 0;
			Taken = strtok(Line," ");
			while(Taken != Null)//Looping till end of line
			{
				Line_Parts++;
				if(Line_Parts == 1)
				{
					if(Check_Roll_Num(FIFO_Buf,FIFO_Buf->base,atoi(Taken)) == 1) //Checking for duplicating Roll Num
					{
						Student_Duplicated_Roll++;//increasing duplicated student roll indicator
						Dprint("\n [Error] Roll Number %d  is already Taken ",atoi(Taken));
						break;

					}
					else
					{
						//since it is not duplicated it will be added successfully
						Dprint("\n[Info] Roll Number %d  saved successfully ",atoi(Taken));
						FIFO_Buf->head->roll = atoi(Taken);
					}
				}
				else if (Line_Parts == 2)
					strcpy(FIFO_Buf->head->fname,Taken);
				else if (Line_Parts == 3)
					strcpy(FIFO_Buf->head->lname,Taken);
				else if(Line_Parts == 4)
					FIFO_Buf->head->GPA = atof(Taken);
				else if(Line_Parts == 5)
					FIFO_Buf->head->cid[0] = atoi(Taken);
				else if(Line_Parts == 6)
					FIFO_Buf->head->cid[1] = atoi(Taken);
				else if(Line_Parts == 7)
					FIFO_Buf->head->cid[2] = atoi(Taken);
				else if(Line_Parts == 8)
					FIFO_Buf->head->cid[3] = atoi(Taken);
				else
					FIFO_Buf->head->cid[4] = atoi(Taken);
				Taken = strtok(Null," \n");//points to null so we end this line....

			}
			if(Check_Roll_Num(FIFO_Buf,FIFO_Buf->base,atoi(Taken)) == 1)//No change in head
			{

				continue;
			}
			FIFO_Buf->count++;
			if(FIFO_Buf->head == (Sinfo*)(FIFO_Buf->length*sizeof(Sinfo)))//check if head reached its max
			{
				FIFO_Buf->head = FIFO_Buf->base;
			}
			else
			{
				FIFO_Buf->head++;
			}
		}
		fclose(ptr);
		Dprint("\n[Info] students Details is added successfully");
		Dprint("\n---------------------------------------------");
		Dprint("\n[Info] the total number of student is %d ",FIFO_Buf->count);
		Dprint("\n[Info] you can add up to 50 Students ");
		Dprint("\n[Info] you can add %d more students ",50-(FIFO_Buf->count));
	}
}
void Add_Student_Manually(FIFO_Buf_t * FIFO_Buf)
{
	char Temp[50];
	//Checking if Queue already exists
	if(FIFO_Buf->base == Null || FIFO_Buf->head == Null || FIFO_Buf->tail == Null)
	{
		Dprint("\nFIFO does not exist ");
	}
	//Checking if FIFO IS FULL
	else if(IS_FIFO_Full(FIFO_Buf) == FIFO_IS_Full )
	{Dprint("FIFO IS FUll\n");}
	else
	{
		//asking user for roll number
		Dprint("\nPlease enter roll Number : ");
		gets(Temp);
		if(Check_Roll_Num(FIFO_Buf,FIFO_Buf->base,atoi(Temp))  == 1)
		{
			Dprint("\n[Error] The Roll Number %d is already Taken ",atoi(Temp));
			Dprint("\n----------------->OUT");
		}
		else
		{
			FIFO_Buf->head->roll = atoi(Temp);
			Dprint("\nPlease Enter your First name : ");
			gets(FIFO_Buf->head->fname);
			Dprint("\nPlease Enter your Last name  :  ");
			gets(FIFO_Buf->head->lname);
			Dprint("\nPlease Enter your GPA  : ");
			gets(Temp);
			FIFO_Buf->head->GPA = atof(Temp);
			Dprint("\nPlease Enter your Courses ID :  ");
			for(int i = 0;i<5;i++)
			{
				Dprint("\nEnter ID for Course Number %d  :  ",i+1);
				gets(Temp);
				FIFO_Buf->head->cid[i] = atoi(Temp);
			}
			FIFO_Buf->count++;
			if(FIFO_Buf->head == (Sinfo*)(FIFO_Buf->length * sizeof(Sinfo)))
			{
				FIFO_Buf->head = FIFO_Buf->base;
			}
			else
			{
				FIFO_Buf->head++;
			}
			Dprint("\n[info] students Details is added successfully  ");
			Dprint("\n-----------------------------------------------");
			Dprint("\n[info] The total Number of students is %d ",FIFO_Buf->count);
			Dprint("\n[info] you can add up to 50 students ");
			Dprint("\n[info] you can add %d more students ",50-FIFO_Buf->count);
		}
	}
}
void Find_Student_By_Roll(FIFO_Buf_t * FIFO_Buf)
{
	//Checking if Queue already exists
	if(FIFO_Buf->base == Null || FIFO_Buf->head == Null || FIFO_Buf->tail == Null)
	{
		Dprint("\nFIFO does not exist ");
	}
	//Checking if FIFO IS FULL
	else if(IS_FIFO_Full(FIFO_Buf) == FIFO_IS_Full )
	{Dprint("FIFO IS FUll\n");}
	else
	{
		int User_Roll,i,j=0,indicator=0;
		Sinfo * ptr = FIFO_Buf->base;
		Dprint("\nPlease Enter Student Roll that you are looking for ");
		scanf("%d",&User_Roll);
		for(i=0;i<FIFO_Buf->count;i++)
		{
			if(ptr->roll == User_Roll)
			{
				Dprint("\nStudent Details are ");
				Dprint("\nStudent Roll is : %d",ptr->roll);
				Dprint("\nStudent First name is : %s",ptr->fname);
				Dprint("\nStudent Last name is : %s",ptr->lname);
				Dprint("\nStudent GPA is : %0.2f ",ptr->GPA);
				Dprint("\nStudent Courses ID \n");
				for(j=0;j<5;j++)
				{
					Dprint("\nCourse %d ID number is %d  ",j+1,ptr->cid[j]);
				}
				indicator =1;
				break;
			}
			ptr++;
		}
		if(!indicator)
		{
			Dprint("\n[Error]Roll Not found ......Please Try again Sir");
		}
	}
}
void Find_Student_By_First_Name(FIFO_Buf_t * FIFO_Buf)
{
	//Checking if Queue already exists
	if(FIFO_Buf->base == Null || FIFO_Buf->head == Null || FIFO_Buf->tail == Null)
	{
		Dprint("\nFIFO does not exist ");
	}
	//Checking if FIFO IS FULL
	else if(IS_FIFO_Full(FIFO_Buf) == FIFO_IS_Full )
	{Dprint("FIFO IS FUll\n");}
	else {
		int i,j,indicator = 0;
		char Temp[50];
		Sinfo* ptr = FIFO_Buf->base;
		Dprint("\nPlease Enter First Name of Student you are looking for ");
		gets(Temp);
		for(i=0;i<FIFO_Buf->count;i++)
		{
			if(!strcmp(ptr->fname,Temp))
			{
				Dprint("\nStudent Details are ");
				Dprint("\nStudent Roll is : %d",ptr->roll);
				Dprint("\nStudent First name is : %s",ptr->fname);
				Dprint("\nStudent Last name is : %s",ptr->lname);
				Dprint("\nStudent GPA is : %0.2f ",ptr->GPA);
				Dprint("\nStudent Courses ID \n");
				for(j=0;j<FIFO_Buf->count;j++)
				{
					Dprint("\n Course %d ID number is %d  ",j+1,ptr->cid[j]);
				}
				indicator = 1;
			}
			ptr++;
		}
		if(!indicator)
			Dprint("\n[Error] Student Not Found");
	}

}
void Find_NO_OF_Students_IN_Course(FIFO_Buf_t * FIFO_Buf)
{
	//Checking if Queue already exists
	if(FIFO_Buf->base == Null || FIFO_Buf->head == Null || FIFO_Buf->tail == Null)
	{
		Dprint("\nFIFO does not exist ");
	}
	//Checking if FIFO IS FULL
	else if(IS_FIFO_Full(FIFO_Buf) == FIFO_IS_Full )
	{Dprint("FIFO IS FUll\n");}
	else{


		int Course_ID,i,j,indicator = 0;
		Dprint("\nPlease Sir Enter Course ID : ");
		scanf("%d",&Course_ID);
		Sinfo * ptr = FIFO_Buf->base;
		for(i=0;i<FIFO_Buf->count;i++)
		{
			for(j=0;j<5 ;j++)
			{
				if(Course_ID == ptr->cid[j])
				{
					Dprint("\nStudent Details are ");
					Dprint("\nStudent Roll is : %d",ptr->roll);
					Dprint("\nStudent First name is : %s",ptr->fname);
					Dprint("\nStudent Last name is : %s",ptr->lname);
					Dprint("\nStudent GPA is : %0.2f ",ptr->GPA);
					indicator = 1;
					break;
				}

			}
			ptr++;
		}
		if(!indicator)
			Dprint("\n[Error] None Enrolled for this course ");
	}
}
void Count_Students(FIFO_Buf_t * FIFO_Buf)
{
	//Checking if Queue already exists
	if(FIFO_Buf->base == Null || FIFO_Buf->head == Null || FIFO_Buf->tail == Null)
	{
		Dprint("\nFIFO does not exist ");
	}
	//Checking if FIFO IS FULL
	else if(IS_FIFO_Full(FIFO_Buf) == FIFO_IS_Full )
	{Dprint("FIFO IS FUll\n");}
	else
	{
		Dprint("\n[info] The Total Number of students is : %d",FIFO_Buf->count);
		Dprint("\n[info] you can add up to 50 student ");
		Dprint("\n[info] you can add %d more students ",50-FIFO_Buf->count);
	}
}
void  Delete_Student(FIFO_Buf_t * FIFO_Buf)
{
	//Checking if Queue already exists
	if(FIFO_Buf->base == Null || FIFO_Buf->head == Null || FIFO_Buf->tail == Null)
	{
		Dprint("\nFIFO does not exist ");
	}
	//Checking if FIFO IS FULL
	else if(IS_FIFO_Full(FIFO_Buf) == FIFO_IS_Full )
	{Dprint("FIFO IS FUll\n");}
	else {
		int User_Roll,i,flag = 0;
		Sinfo * ptr = FIFO_Buf->base;
		Dprint("Please Enter Roll Number of student you want to delete : ");
		scanf("%d",&User_Roll);
		for(i=0;i<FIFO_Buf->count;i++)
		{
			if(ptr->roll == User_Roll)
			{
				flag = 1;
				break;
			}
			ptr++;
		}
		if(flag)
		{
			Switch(FIFO_Buf,ptr);
			FIFO_Dequeue(FIFO_Buf);
			Dprint("\n[info] Delete Done Successfully");
		}
		else
		{
			Dprint("\n[Error] cannot Find Roll Number ");
		}
	}
}
void Update_Student(FIFO_Buf_t * FIFO_Buf)
{
	//Checking if Queue already exists
	if(FIFO_Buf->base == Null || FIFO_Buf->head == Null || FIFO_Buf->tail == Null)
	{
		Dprint("\nFIFO does not exist ");
	}
	//Checking if FIFO IS FULL
	else if(IS_FIFO_Full(FIFO_Buf) == FIFO_IS_Full )
	{Dprint("FIFO IS FUll\n");}
	else{
		int User_Roll,i,j,Selected,User_ID;
		Sinfo * ptr = FIFO_Buf->base;
		char Temp[50];
		Dprint("Please Enter Roll of Student you want to update : ");
		scanf("%d",&User_Roll);
		for(i=0;i<FIFO_Buf->count;++i)
		{
			if(ptr->roll == User_Roll)
			{
				Dprint("\nChoose Option that you want to update ");
				Dprint("\n1.first name ");
				Dprint("\n2.last name");
				Dprint("\n3.roll no ");
				Dprint("\n4.GPA");
				Dprint("\n5.Courses \n");
				scanf("%d",&Selected);
				switch(Selected)
				{
				case 1:
					Dprint("\nEnter New First Name : ");
					gets(ptr->fname);
					break;
				case 2:
					Dprint("\nEnter New Last Name : ");
					gets(ptr->lname);
					break;
				case 3:
					Dprint("\nEnter New Roll Number");
					gets(Temp);
					ptr->roll = atoi(Temp);
					break;
				case 4:
					Dprint("\nEnter New GPA");
					gets(Temp);
					ptr->GPA = atof(Temp);
					break;
				case 5:
					Dprint("\nEnter ID of Course you want to update : ");
					scanf("%d",&User_ID);
					for(j=0;j<5;j++)
						if(ptr->cid[i] == User_ID)
						{
							Dprint("\nPlease Enter New ID Course ");
							gets(Temp);
							ptr->cid[j] = atoi(Temp);
							break;
						}
				}
			}
			ptr++;
		}
	}
}
void show_Students(FIFO_Buf_t * FIFO_Buf)
{
	//Checking if Queue already exists
	if(FIFO_Buf->base == Null || FIFO_Buf->head == Null || FIFO_Buf->tail == Null)
	{
		Dprint("\nFIFO does not exist ");
	}
	//Checking if FIFO IS FULL
	else if(IS_FIFO_Full(FIFO_Buf) == FIFO_IS_Full )
	{Dprint("FIFO IS FUll\n");}
	else
	{
		int i,j;
		Sinfo* ptr = FIFO_Buf->tail;
		for(i=0;i<FIFO_Buf->count;i++)
		{
			Dprint("\nStudent Details are ");
			Dprint("\nStudent Roll is : %d",ptr->roll);
			Dprint("\nStudent First name is : %s",ptr->fname);
			Dprint("\nStudent Last name is : %s",ptr->lname);
			Dprint("\nStudent GPA is : %0.2f ",ptr->GPA);
			Dprint("\nStudent Courses ID \n");
			for(j=0;j<5;j++)
			{
				Dprint("\nCourse %d ID number is %d  ",j+1,ptr->cid[j]);
			}
			ptr++;
		}
		Dprint("\n[Info] the total number of student is %d ",FIFO_Buf->count);
		Dprint("\n[Info] you can add up to 50 Students ");
		Dprint("\n[Info] you can add %d more students ",50-(FIFO_Buf->count));
	}
}
void Switch(FIFO_Buf_t * FIFO_Buf,Sinfo *ptr)
{
	Sinfo  Temp;
	while(ptr != FIFO_Buf->tail)
	{
		Temp = *ptr;
		*ptr = *(ptr-1);
		*(ptr-1)= Temp;
		ptr=ptr-1;
	}

}
void FIFO_Dequeue(FIFO_Buf_t * FIFO_Buf)
{
	if (!FIFO_Buf->base || !FIFO_Buf->head || !FIFO_Buf->tail)
		Dprint("FIFO does not exist");
	if(FIFO_Buf->count == 0)
		Dprint("FIFO Is Empty");
	if((FIFO_Buf->tail)==(FIFO_Buf->base+FIFO_Buf->length*sizeof(Sinfo)))
		FIFO_Buf->tail=FIFO_Buf->base;
	else
		FIFO_Buf->tail++;
	FIFO_Buf->count--;
}
