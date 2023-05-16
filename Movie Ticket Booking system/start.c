#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "adminFuncs.h"
#include "userFuncs.h"


int main()
{
	unsigned char choice1,choice2,choice3,compare,retry,numMovie,numTicket;
	char attempPass[25];
	char realPass[]="cinema";
	loop1:
	printf("\t\t\t    ****************************\n");
	printf("\t\t\t Welcome to our Movie ticket system!\n");
	printf("\t\t\t    ****************************\n");
	printf("Press:\n1 for Admin\n2 for User\n0 to Exit the program\n");
	
	fflush(stdin);
	scanf("%c", &choice1); 
	
	switch(choice1)
	{
		case '1':
			loop2:
			printf("Enter the password: ");
			fflush(stdin);
			scanf("%s", &attempPass);                 //gets the pass from the user
			compare= strcmp(attempPass, realPass);    // compare it with the real one
			if(compare)								// incase of wrong pass
			{
				printf("SORRY, WRONG PASSWORD!\n");
				printf("Press\n1 to re enter the password\n2 to exit\n"); // the option to either retry of leave
				fflush(stdin);
				scanf("%d", &retry);
				if(retry ==1)
				{
					printf("\n");
					goto loop2;  // if he choosed to retry it starts over from entering the pass
				}
				else if( retry == 2)
				{
					printf("\n");
					goto loop1; // incase of leaving it starts from the beginning
				}
			}
			else   // incase of right pass
			{
				// admin functions
				loop3:    
				printf("Press <1> to add movie\n");
				printf("Press <2> to show movie you added\n");
				printf("Press <3> to delete movie\n");
				printf("Press <4> to edit movie details\n");
				printf("Press <0> to exit\n");
				printf("Enter your choise:");
				fflush(stdin);
				scanf("%c",&choice2);
				switch (choice2)
				{
					case '1':
					{
						printf("Enter the number of movies you would like to add: ");
						scanf("%d",&numMovie);
						getchar();
						addMovie(numMovie);  // calling the function
						printf("\n");
					}goto loop3;
					break;
					case '2':
					{
						showMovie();  // calling the show movie function
						char a;
						printf("Enter any number to continue:");
						scanf("%i",&a);
						printf("\n");
						goto loop3;
					}
					break;
					case '3':
					{
						delMovie();   // calling the delete movie function
						goto loop3;
					}
					break;
					case '4':
					{
						editMovie();   // calling the edit movie function
						goto loop3;
					}
					break;
					case '0':
					{
						printf("\n");
						goto loop1;
					}
					break;
					default:
					{
						printf("Choice not available\n");
						goto loop3;
					}
					break;
				} 
			}
			
		break;
		case '2':  // user functions
		{
			loop4:
			printf("Press <1> to book your ticket\n");
			printf("Press <2> to show booked tickets\n");
			printf("Press <3> to cancel ticket\n");
			printf("Press <4> to exit\n");
			fflush(stdin);
			scanf("%c",&choice3);
			
			switch (choice3)
			{
				case '1':   				// show movies list and book your ticket
				{
					printf("Enter the number of tickets you would like to book:");
					scanf("%d",&numTicket);
					getchar();
					showMovie();
					book_ticket(numTicket);
					goto loop4;
				}
				break;
				case '2':     				// show booked tickets
				{
					showTicket_Booked();
					goto loop4;
				}
				break;
				case '3':           // cancel ticket
				{
					delTicket();
					goto loop4;
				}
				break;
				case '4':           // exit				
					goto loop1;
				break;
				default:
					printf("Invalid .. please enter a valid choise");
					goto loop4;
				break;
			}
		}	
		break;
		
		case '0':
			printf("Exiting the program...");
			return 0;
		break;
		
		default:
			printf("Invalid .. please enter a valid choise");
			goto loop1;
		break;
	}	
}