/* PROGRAMMER: RUMAISA FATIMA 26K-0018
PROGRAM: Elevator Simulation
PART B QUESTION 2*/
#include <stdio.h>
int main() 
{
    int n,i=0,pst=0; // n is the number of requests, i is the loop counter and pst is the position of elevator
    printf("enter number of requests"); 
    scanf("%d",&n);
    int req[n];
    while(i<n)
    {
        scanf("%d",&req[i]); // taking user input for position requests
        i++;
    }
    i=0; // resetting the loop counter for next itterations
    while(i<n)
    {
        if(req[i]>pst)
       { printf("moving up"); //Requested floor greater than current floor so Moving Up
       }
        else if(req[i]<pst){
        printf("moving down");//Requested floor greater than current floor so Moving down
        }
        else 
        {printf("doors opening"); // //Requested floor same as the current floor so doors opening
            
        }
        pst=req[i]; // changing the position of the floor to the request that was just executed
        printf("\n");
        i++; //incrementing the loop counter
       
      
    }


return 0;
}