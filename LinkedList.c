#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "STD_TYPES.h"
 
 typedef struct Node 
{
	u8 Name[11];
    u8 Title[11];
	u32 Age;
	u32 ID;
	f32 Salary;
   struct Node* Next;
}node_t;

/* ***************************************************************************************************************/
/*  Function to insert a node at the front of the linked list.                                                   */
/*  Input : All the data from the user and it takes an pointer of type sturct to the beggeing of the linkedlist  */
/*  Returns the new front, pointer to the next struct                                   
/* ***************************************************************************************************************/

 node_t* CreateAnEmployee ( node_t *front ,u8 Name[], u8 Title[], u32 Age, u32 ID, f32 Salary);

 node_t* CreateAnEmployee ( node_t *front ,u8 Name[], u8 Title[], u32 Age, u32 ID, f32 Salary)
{
	 node_t* temp = (node_t*)malloc(sizeof(node_t)) ; // Allocating space in memory of the struct
 	 strcpy( temp->Name, Name);
	 temp->Age = Age;
	 temp->Salary = Salary ;
	 strcpy(temp->Title, Title);
	 temp->ID = ID ;
	
	temp->Next = front ; // making the next points to the new front that the user will assign later
	front = temp ; // making the front = the temp stuct that i allocate to save in it
    return(front); // a pointer to the new struct 
}

/*  Function to print a node of a linked list */ 

void  PrintNode (node_t* PtrNode) ;

void PrintNode (node_t* PtrNode) 
{
	 printf ("1. Name : %s \n", PtrNode->Name) ;
	 printf ("2. Age : %d \n", PtrNode->Age) ;
	 printf ("3. Salary : %0.2f \n", PtrNode->Salary) ;
	 printf ("4. Title : %s \n", PtrNode->Title) ;
	 printf ("5. ID : %d \n", PtrNode->ID) ;
	 printf ("-------------------------------------\n");
}


/* ***************************************************************************************************************/
/*  Function to print all nodes of a linked list                                                                 */
/* Another way to do is in the while loop just call the print node                                               */
/* ***************************************************************************************************************/

void  PrintList (node_t* PtrHead) ;

void PrintList (node_t* PtrHead) 
{
	// While the ptr never points to a list, it's not the end of the linked list
     while (PtrHead!= NULL) {
	printf ("1. Name : %s \n", PtrHead->Name) ;
	 printf ("2. Age : %d \n", PtrHead->Age) ;
	 printf ("3. Salary : %0.2f \n", PtrHead->Salary) ;
	 printf ("4. Title : %s \n", PtrHead->Title) ;
	 printf ("5. ID : %d \n", PtrHead->ID) ;
	 printf ("-------------------------------------\n");
	 //shifting to the next of the list 
     //PrintNode(PtrHead);
	 PtrHead = PtrHead->Next ;
 }
}

void Modify (node_t *front) ;

void Modify (node_t *front)
 {
	     printf ("The Employee Information : \n") ;
     	 PrintNode (front) ;
		 
		 printf ("Kindly choose the information you want to modify \n \
          1. Name. \n \
          2. Age. \n \
          3. Sallary.\n \
          4. Title. \n \
          5. ID. \n \
		  6. Return. \n"); 
		  
		  u8 Name[11];
          u8 Title[11];
          u32 Age;
          u32 ID;
          f32 Salary;
		  u8 Modify;
		  scanf("%d", &Modify);
		
		  switch (Modify) 
		  {
			  case 1:
			  printf (" Noice: Name Can Only Be 10 Digits, No Spaces Included. \n New Name is : \n " );
			  fflush(stdin);
              gets(Name);
			  strcpy(front->Name, Name);
			  break;
			  
			  case 2:
			  printf ("Happy Birthday! \n New Age is : \n " );
			  scanf ("%d", &Age) ;
			  front->Age = Age;
			  break;
			  
			  case 3:
			  printf ("Congratulation! \n New Salary is : \n " );
			  scanf ("%f", &Salary) ;
	          front->Salary = Salary ;
			  break;
			  
			  case 4:
			  printf ("Title Can Only Be 10 Digits, No Spaces Included. \n New Title is : \n");
	          fflush(stdin);
              gets(Title);
			  strcpy(front->Title, Title);
	          break;
			  
			  case 5:
	          printf (" Maximum Number Is 99. \n New ID is : \n");
              scanf ("%d", &ID) ;
		      front->ID = ID ;
			  break;
			  
			  case 6:
			  printf ("Nothing is changed.");
			  return;
		  }
		  
		  printf ("The New Employee Information : \n");
		  PrintNode (front) ;
}

u8 search (node_t *PtrToTheStruct, u8 Choose , u8 IDSearch) ;

u8 search (node_t *PtrToTheStruct, u8 Choose, u8 IDSearch) 
{
	u8 flag=0;
	switch (Choose) {
	     case 1 : //delete
		   for (int i = 0 ; i<= sizeof (struct Node)/sizeof (PtrToTheStruct) ; i++) 
		   {
			if (PtrToTheStruct->ID == IDSearch)
            {
				flag=1;
		         node_t* temp;
			     temp = PtrToTheStruct ;
			     free(PtrToTheStruct);
			     PtrToTheStruct = temp->Next ;
                 printf("Node deleted.\n");
			     return(flag);
            }
			PtrToTheStruct = PtrToTheStruct->Next;
		}
		break;
		
		case 2 : //modify
         for (int i = 0 ; i<= sizeof (struct Node)/sizeof (PtrToTheStruct) ; i++) 
		{
           if (PtrToTheStruct->ID == IDSearch)
            {
			flag=1;
            Modify(PtrToTheStruct);
		   return(flag);
            }
		  PtrToTheStruct = PtrToTheStruct->Next ;	
		}
        break;
		
		case 3 : //print a member
		for (int i = 0 ; i<= sizeof (struct Node)/sizeof (PtrToTheStruct) ; i++) 
		{
        if (PtrToTheStruct->ID == IDSearch)
        {
			flag=1;
            PrintNode(PtrToTheStruct);
			return(flag);
        }
		 PtrToTheStruct = PtrToTheStruct->Next ;		
		}
		break;
	}
	return(flag);
}
	
void main (void) 
{
	
 printf ("Welcome to Employees DataBase.\n");

 u32 ChossenOperation ;
 node_t* PtrToTheStruct = NULL;
 u8 Name[11];
 u8 Title[11];
 u32 Age;
 u32 ID;
 f32 Salary;
 u8 IDSearch;
u8 Flag;

while (1)
{
	
 printf ("Kindly choose the operation \n \
 1. Creating a new employee. \n \
 2. Deleting an Employee. \n \
 3. Modifing an Employee. \n \
 4. View the data of an Employee. \n \
 5. Print list of all Employess. \n \
 6. Exit. \n"); 
 
 scanf ("%d" , &ChossenOperation) ;
 
	switch(ChossenOperation)
        {
        case 1: 
		
		 printf ("Please Enter \n  1. Name. \n Noice: Name Can Only Be 10 Digits. \n") ;
		 fflush(stdin);
         gets(Name);
		 printf (" 2. Age. \n Notice: Age Is Just A Number. \n ") ;
	     scanf ("%d", &Age) ;
		 printf (" 3. Sallary.\n Notice : Sallary Can Include $$.$$.\n ");
	     scanf ("%f", &Salary) ;
	     printf (" 4. Title. \n Noice: Title Can Only Be 10 Digits.\n");
	     fflush(stdin);
         gets(Title);
	     printf (" 5. ID. \n Noice: Maximum Number Is 99. \n");
         scanf ("%d", &ID) ;
	     PtrToTheStruct = CreateAnEmployee (PtrToTheStruct, Name, Title, Age, ID, Salary) ;
		 printf ("-------------------------------------\n");
		break ;
		
		case 2:
		
		if (PtrToTheStruct == NULL) 
		{
			printf ("No Employees Found. \n");
			break;
	    }
		
		printf ("Kindly Enter The Employee ID. \n") ;
		scanf ("%d" , &IDSearch) ;
		
		//Flag = search (PtrToTheStruct , 1, IDSearch);
		
		/*if (Flag==0){
			printf ("ID NOT FOUND.");
			break;
		}*/

		for (int i = 0 ; i<= sizeof (struct Node)/sizeof (PtrToTheStruct) ; i++) 
		{
			if (PtrToTheStruct->ID == IDSearch)
            {
		     node_t* temp;
		     temp = PtrToTheStruct->Next ; 
		    free(PtrToTheStruct);
			//PtrToTheStruct->Next = NULL;
			//PtrToTheStruct = temp ;
			PtrToTheStruct =temp;
            printf("Node deleted.\n");
			break;
            }
			PtrToTheStruct = PtrToTheStruct->Next;
		}
		
		/*
		if (PtrToTheStruct == NULL) 
		{
		printf ("ID Not Found. \n");
		break;
		} */
		
		break ;
		
		case 3:
		
		if (PtrToTheStruct == NULL) 
		{
			printf ("No Employees Found. \n");
			break;
	    }
		
		printf ("Kindly Enter The Employee ID. \n") ;
		scanf ("%d" , &IDSearch) ;
		
		Flag = search (PtrToTheStruct , 2, IDSearch);
		
		if (Flag==0)
		{
			printf ("ID NOT FOUND.");
			break;
		}
		
		/* (int i = 0 ; i<= sizeof (struct Node)/sizeof (PtrToTheStruct) ; i++) 
		{
        if (PtrToTheStruct->ID == IDSearch)
        {
            Modify(PtrToTheStruct);
		   break;
        }
		  PtrToTheStruct = PtrToTheStruct->Next ;	
		}
		
		if (PtrToTheStruct == NULL) 
		{
		printf ("ID Not Found. \n");
		break;
		} */
		
		break;
		
		case 4:
		
		if (PtrToTheStruct == NULL) 
		{
			printf ("No Employees Found. \n");
			break;
	    }
		
		printf ("Kindly Enter The Employee ID. \n") ;
		scanf ("%d" , &IDSearch) ;
		
	    Flag= search (PtrToTheStruct , 3, IDSearch);
	   
	   if (Flag==0)
		{
			printf ("ID NOT FOUND.");
			break;
		} 
		
		/*for (int i = 0 ; i<= sizeof (struct Node)/sizeof (PtrToTheStruct) ; i++) 
		{
        if (PtrToTheStruct->ID == IDSearch)
        {
            PrintNode(PtrToTheStruct);
			break;
        }
		 PtrToTheStruct = PtrToTheStruct->Next ;		
		}
		
		if (PtrToTheStruct == NULL) 
		{
		printf ("ID Not Found. \n");
		break;
		} */

		break;
		
		case 5:
		
		if (PtrToTheStruct == NULL) 
		{
			printf ("No Employees Found. \n");
			break; 
	    }
		
		PrintList (PtrToTheStruct) ;
		
		break;
		
		 case 6 :
		printf ("Thank you for using. \n");
		return;
	}
   }
}
 