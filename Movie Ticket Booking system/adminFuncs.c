#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"

static int count1=0;
char postion1=0;


/* ******* add movie ********* */

void addMovie(int numMovie)
{
		
		postion1= numMovie+1 ;
		while(postion1>(count1))
		{
			postion1--;
		}
				count1=count1 + numMovie;
			for (postion1; postion1 <= (count1-1); postion1++)
			{
				printf("\t Data of movie number %d\n", postion1+1);
				printf("Enter the name of the movie: ");
				fflush(stdin);
				gets(movie[postion1].newMovie);
				
				
				printf("Enter the type of the movie (2D or 3D): ");
				fflush(stdin);
				gets(movie[postion1].type);
				
				printf("Enter the price of the ticket: ");
				fflush(stdin);
				gets(movie[postion1].price);
				
				printf("Enter the time of the movie: ");
				fflush(stdin);
				gets( movie[postion1].time);
			
			}
		

		
}
/* ******* show movie ********* */

void showMovie()
{
	
	if(count1==0)
	{
		printf("There are NO MOVIES!\n");
	}
	else
	{
		for ( int i=0; i<count1; i++)
		{
			printf("\n   Movie number %d\n", i+1);
			printf("Name: %s, ", movie[i].newMovie);	
			printf("Type: %s, ", movie[i].type);
			printf("price: %s L.E, ", movie[i].price);
			printf("Time: %s \n", movie[i].time);
				
		}
	}
}

/* ******* delete movie ********* */
int delMovie()
{
    char delNum, choice3;
    loop:
	if (count1 == 0)
    {
        printf("There are NO MOVIES to be deleted!\n");
        return 0;
    }
    else
    {
        for(int i=0; i<count1; i++)
        {
            printf("%d.%s\n",i+1, movie[i].newMovie);	
        }
        
        printf("Enter the number of the movie you would like to delete: ");
		fflush(stdin);
        scanf("%d", &delNum);
        //checking whether this number exists or not
        if(delNum<1 || delNum>count1)
        {
            printf("Invalid INPUT!\n retry a valid number\n");
            return 0;
        }
        else
        {
            delNum--;
            // deleting the selected movie by shifting the other movies up
            for(int i=delNum; i<count1-1; i++)
            {
                strcpy(movie[i].newMovie, movie[i+1].newMovie);
                strcpy(movie[i].type, movie[i+1].type);
                strcpy(movie[i].price, movie[i+1].price);
                strcpy(movie[i].time, movie[i+1].time);
            }
            // resetting the last movie in the array
            strcpy(movie[count1-1].newMovie,"");
            strcpy(movie[count1-1].type,"");
            strcpy(movie[count1-1].price,"");
            strcpy(movie[count1-1].time,"");
            count1--;
            printf("Movie deleted successfully.\n");
        }
    }


		loop2:
		printf("\nPress:\n1 to delete another movie\n0 to exit\n");
		fflush(stdin);
		scanf("%c",&choice3);
		switch(choice3)
		{
			case '1':
				goto loop;
			break;
			
			case '0':
				return 0;
			break;
			default:
				printf("Invalid INPUT!");
				goto loop2;
			break;
		}
}		
	
	
/* ******* edit movie ********* */

int editMovie()
{
	char editNum, choice1, choice2;
    
	if (count1 == 0)
    {
        printf("There are NO MOVIES to be edited!\n");
        return 0;
    }
    else
    {
        for(int i=0; i<count1; i++)
        {
            printf("%d.%s\n",i+1, movie[i].newMovie);	
        }
		printf("Enter the number of the movie you would like to edit: ");
		fflush(stdin);
		scanf("%d", &editNum); //get the number of the movie
		
		loop:
		printf("Press:\n 1 to edit the name\n 2 to edit the type\n 3 to edit the price\n 4 to edit the time\n 0 to exit the edit\n");
		fflush(stdin);
		scanf("%c", &choice1);
		
		switch(choice1)  // A switch statment to choose which member to edit
		{
			case '1':  // editing the name
			{
				printf("Enter the new name: ");
				fflush(stdin);
				gets(movie[editNum-1].newMovie);
			}
			break;
			
			case '2':     // editing the name
			{
				printf("Enter the new type: ");
				fflush(stdin);
				gets(movie[editNum-1].type);
			}
			break;
			
			case '3':    // editing the type
			{
				printf("Enter the new price: ");
				fflush(stdin);
				gets(movie[editNum-1].price);
			}
			break;
			
			case '4':    // editing the price
			{
				printf("Enter the new time: ");
				fflush(stdin);
				gets(movie[editNum-1].time);
			}
			break;
			
			case '0':   // exiting
			{
				return 0;
			}
			break;
			default:
			{
				printf("Enter a valid choice!\n");
				goto loop;
			}
			break;
		}	
			loop2:
			printf("Press:\n1 to edit another thing\n0 to exit\n");
			fflush(stdin);
			scanf("%c",&choice2);
			
			switch(choice2)
			{
				case '1':
					goto loop;
				break;
				case '0':
					return 0;
				break;
				default:
				{
					printf("Enter a valid choice!\n");
					goto loop2;
				}
				break;
			}
		
	}
}
