/*
 * Linked_List.c
 *
 *  Created on: Jul 13, 2022
 *      Author: Fam Ayman
 */
#include "Linked_List.h"
S_Student_t * gp_First_Student  ;
void Add_Student()
{
	S_Student_t * pNew_Student;
	S_Student_t * pLast_Student;
	if(gp_First_Student == Null)
	{
		//Creating block
		pNew_Student =(S_Student_t *) malloc(sizeof(S_Student_t));
		//let gp_First points to it instead of null
		gp_First_Student=pNew_Student;
	}
	else  //Not empty
	{
		pLast_Student=gp_First_Student;
		while(pLast_Student->Pnext_Student) //Looping till Null
			pLast_Student=(S_Student_t *)pLast_Student->Pnext_Student;
		pNew_Student =(S_Student_t *) malloc(sizeof(S_Student_t));
		pLast_Student->Pnext_Student=pNew_Student;
	}
	//Leaving loop with pLast_Student has address of the last block
	Fill_Block(pNew_Student);
	//Let last block points to Null
	pNew_Student->Pnext_Student=Null;

}
void View_Students()
{
	S_Student_t * pCurrent_Student = gp_First_Student;
	int Counter = 0;
	if(gp_First_Student == Null )
		printf("\n List is empty");
	else
	{
		while(pCurrent_Student)
		{
			Dprint("\n Block Number is %d : ",Counter+1);
			Dprint("\n ID is : %d",pCurrent_Student->Student_info.ID);
			Dprint("\n Name : %s ",pCurrent_Student->Student_info.name);
			Dprint("\n Height : %f",pCurrent_Student->Student_info.height);
			pCurrent_Student=(S_Student_t *)pCurrent_Student->Pnext_Student;
			Counter++;
		}
	}

}
int Delete_Student()
{
	unsigned int Selected_ID;
	Dprint("\nEnter the Student id to be deleted ");
	scanf("%d",&Selected_ID);
	if(gp_First_Student) //checking the the list already exists !!
	{
		S_Student_t *pPrevious_Student = Null;
		S_Student_t *pSelected_Student = gp_First_Student;
		while(pSelected_Student) //Looping unitll we find ID or pSelected  equal null
		{
			if(pSelected_Student->Student_info.ID == Selected_ID) //Checking if pSelected contains our ID
			{
				if(pPrevious_Student)
				{
					pPrevious_Student->Pnext_Student=pSelected_Student->Pnext_Student;

				}
				else    //entering else means gp_First_Student contains our ID
				{
					gp_First_Student = (S_Student_t * )pSelected_Student->Pnext_Student;

				}
				free(pSelected_Student);
				return 1 ;
			}
			pPrevious_Student=pSelected_Student;
			pSelected_Student=(S_Student_t *)pSelected_Student->Pnext_Student;
		}

	}
	Dprint("\n Not Found");
	return 0;

}
void Delete_All()
{
	S_Student_t * pCurrent_Student = gp_First_Student;
	if(gp_First_Student == Null )
		printf("\n List is empty");
	else
	{
		while(pCurrent_Student)
		{
			S_Student_t * temp=pCurrent_Student;
			pCurrent_Student=(S_Student_t *)pCurrent_Student->Pnext_Student;
			free(temp);
		}
		gp_First_Student =Null;
	}
}
void Fill_Block(S_Student_t*pNew_Student)
{
	char Temp_text[40];
	Dprint("\n Enter the ID: ");
	gets(Temp_text);
	pNew_Student->Student_info.ID = atoi(Temp_text);
	Dprint("\n Enter the Name: ");
	gets(pNew_Student->Student_info.name);
	Dprint("\n Enter the Height: ");
	gets(Temp_text);
	pNew_Student->Student_info.height = atof(Temp_text);
}
void Get_Nth()
{
	S_Student_t * pCurrent_Student = gp_First_Student;
	int Counter = 0,Index,flag = 1;
	if(gp_First_Student == Null )
	{Dprint("\n List is empty");}
	else
	{
		Dprint("\nPlease Enter the Index : ");
		scanf("%d",&Index);
		while(Counter != Index)
		{
			pCurrent_Student = (S_Student_t *)(pCurrent_Student->Pnext_Student);
			Counter++;
			flag = 0;
		}

	}
	if (flag && Counter != 0)
	{Dprint("Wrong Index");}
	else
	{
		Dprint("\n Block Number is %d : ",Counter+1);
		Dprint("\n ID is : %d",pCurrent_Student->Student_info.ID);
		Dprint("\n Name : %s ",pCurrent_Student->Student_info.name);
		Dprint("\n Height : %f ",pCurrent_Student->Student_info.height);
	}


}
void Get_Length()
{
	S_Student_t * pCurrent_Student = gp_First_Student;
	int Counter = 0;
	while(pCurrent_Student)
	{
		Counter++;
		pCurrent_Student=(S_Student_t *)pCurrent_Student->Pnext_Student;
	}
	Dprint("\n Length is %d ",Counter);
}
int Get_Length_Recursive(S_Student_t * pCurrent_Student)
{
	if(pCurrent_Student == Null)
		return 0;
	else
		return 1 + Get_Length_Recursive((S_Student_t *)pCurrent_Student->Pnext_Student);
}
void Calling_Get_Length_Recursive()
{
	int count;
	count = Get_Length_Recursive(gp_First_Student);
	Dprint("\nLength is %d",count);
}
void Get_Nth_From_End_Two_Pointer_Method()
{   //Algorithm letting the distance between  ref and main pointer equla to index then moving both untill ref->Next reaches Null
	//Then Pmain points to the wanted index
	int i,index;
	Dprint("\nPlease enter index : ");
	scanf("%d",&index);
	S_Student_t * Pmain = gp_First_Student;
	S_Student_t * P_ref = gp_First_Student;
	if(gp_First_Student == Null)
	{Dprint("List is Empty");}
	else
	{
		for(i=1;i<index;i++)
			P_ref=(S_Student_t *)P_ref->Pnext_Student;
		if(!P_ref)
		{Dprint("Error");}
		else
		{
			while(P_ref->Pnext_Student != Null)
			{
				P_ref =(S_Student_t *) P_ref->Pnext_Student;
				Pmain =(S_Student_t *) Pmain->Pnext_Student;
			}
			Dprint("\n ID is : %d",Pmain->Student_info.ID);
			Dprint("\n Name : %s ",Pmain->Student_info.name);
			Dprint("\n Height : %f",Pmain->Student_info.height);
		}

	}
}
void Get_Middle()
{
	S_Student_t * pfastStudent = gp_First_Student;
	S_Student_t * pslowStudent = gp_First_Student;


			if(!pslowStudent)
			{
				Dprint("\n Empty List \n");
			}
			else
			{



				while(pfastStudent->Pnext_Student)
				{
					pfastStudent = (S_Student_t *) pfastStudent->Pnext_Student;
					pfastStudent = (S_Student_t *) pfastStudent->Pnext_Student;
					pslowStudent =  (S_Student_t *)pslowStudent->Pnext_Student;
					if(!pfastStudent)
					{

						break;
					}


				}

				Dprint("\n \t ID : %d",pslowStudent->Student_info.ID);
				Dprint("\n \t Name  %s",pslowStudent->Student_info.name);
				Dprint("\n \t height  %f",pslowStudent->Student_info.height);



			}


}
void Reverse_List()
{
	S_Student_t * P_Current_Studenet = gp_First_Student;
	S_Student_t * P_Next = Null;
	S_Student_t * P_Previous = Null;
	if(! gp_First_Student)
	{Dprint("\n List is Empty");}
	else
	{
		while(P_Current_Studenet != Null)
		{
			P_Next=(S_Student_t *)(P_Current_Studenet->Pnext_Student);
			P_Current_Studenet->Pnext_Student = P_Previous;
			P_Previous=P_Current_Studenet;
			P_Current_Studenet=P_Next;
		}
		gp_First_Student=P_Previous;
	}
}
