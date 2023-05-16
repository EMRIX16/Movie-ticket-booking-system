#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"

static int count2=0;
char postion2=0;

/* ****** book ticket ****** */

void book_ticket(int numTicket)
{
    char accept,p;
    static int i=0;
	loop5:
    printf("\nDo you want to book a ticket ?\n");
    printf("If yes press 1 .. If no press 2\n");
	fflush(stdin);
    scanf("%c",&accept);
    switch (accept)
	{
        case '1':
		{
			postion2= numTicket+1 ;
			while(postion2>(count2))
			{
				postion2--;
			}
			count2=count2 + numTicket;
			for (postion2; postion2 <= (count2-1); postion2++)
			{
			printf("Your ID :%d\n", postion2+1);
			printf("Enter the number of movie : ");
			fflush(stdin);
			scanf("%s",&data[i].numberofmovice);
			printf("Enter your name : ");
			fflush(stdin);
			scanf("%s",&data[i].name);
			printf("Enter your phone number : ");
			fflush(stdin);
			scanf("%s",&data[i].phone_number);
			 printf("_______________________S\tC\tR\tE\tE\tN___________________________\n\n");
            int k,w=1,j=i;
            for (k=0; k<100; k++)
            {

                       if((w ==atoi(data[j-1].seat_number)) &&(atoi(data[j].numberofmovice) == atoi(data[j-1].numberofmovice) ))
                        {
                            printf("[__]\t");
                        }
                       else
                        {
                            printf("[%i]\t",w);
                        }

                if(w%10==0)
                    printf("\n\n");
                w++;
            }
			printf("\n\n");
	        printf("Seats from 1 to 30 (film price + 50)\n");
	        printf("Seats from 31 to 60 (film price + 30)\n");
	        printf("Seats from 61 to 100 (film price)\n\n");
            printf("\n");
            loop11:
            printf("Enter the seat number : ");
            fflush(stdin);
            scanf("%s",&data[i].seat_number);
            if((i>0)&&(atoi(data[i].seat_number)==atoi(data[i-1].seat_number)))
            {
                printf("the sear booked\n");
                goto loop11;
            }
            i++;
        }
        printf("Thank you ... \n");
		}
        break;
        case '2':
        break;
        default:
            printf("Invalid .. please enter a valid choise");
        goto loop5;
    }
}

/* ******* price of seats ******* */
int price(int n,int priceofmovie)
{
    if((n>=1) && (n<=30))
        return (50+priceofmovie);
    else if((n>=31)&&(n<=60))
        return (30+priceofmovie);
    else
        return priceofmovie ;

}





/* ****** show ticket ****** */
void showTicket_Booked()
{

	if(count2==0)
	{
		printf("There are NO Tickets booked!\n");
	}
	else
	{
		for ( int i=0; i<count2; i++)
		{
			 printf("_______________________________________________________________\n");
            printf("\t\tUser ID %d\n", i+1);
            printf("Name: %s \t\t\t", data[i].name);
            printf("Phone: %s\n", data[i].phone_number);
            printf("Movie: %s\t\t\t",movie[atoi(data[i].numberofmovice)-1].newMovie);
            printf("Seat: %s \n", data[i].seat_number);
           // data[i].prize =price(atoi(data[i].seat_number),atoi(movie[atoi(data[i].numberofmoveice)].price));
            printf("                price:%d\n",price(atoi(data[i].seat_number),atoi(movie[atoi(data[i].numberofmovice)-1].price)));
            printf("_______________________________________________________________\n");
        }
	}
}
/* *****  del ticket  ****** */
int delTicket()
{
    char delID;
    loop:
	if (count2 == 0)
    {
        printf("There are NO MOVIES to be deleted!\n");
        return 0;
    }
    else
    {
        for(int i=0; i<count2; i++)
        {
            printf("%d.%s\n",i+1, data[i].name);
        }

        printf("Enter your ID: ");
		fflush(stdin);
        scanf("%d", &delID);
        //checking whether this number exists or not
        if(delID<1 || delID>count2)
        {
            printf("Invalid INPUT!\n retry a valid number\n");
            return 0;
        }
        else
        {
            delID--;
            // deleting the selected movie by shifting the other movies up
            for(int i=delID; i<count2-1; i++)
            {
                strcpy(data[i].name, data[i+1].name);
                strcpy(data[i].phone_number, data[i+1].phone_number);
                strcpy(data[i].numberofmovice, data[i+1].numberofmovice);
				strcpy(data[i].seat_number, data[i+1].seat_number);
            }
            // resetting the last movie in the array
            strcpy(data[count2-1].name,"");
            strcpy(data[count2-1].phone_number,"");
            strcpy(data[count2-1].numberofmovice,"");
            strcpy(data[count2-1].seat_number,"");
            count2--;
			printf("Your ticket was deleted successfully.\n");
			return 0;
        }
    }
}

