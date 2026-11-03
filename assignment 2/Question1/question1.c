/**
 * Programmer: Rumaisa fatima
 * Program: Cinema hall
 * Desc: Finding consequtive seats near the mid 
 */
#include <stdio.h>
int main() 
{
    /*row is the number of seats in the hall while col is the number of 
     seat in each row*/
    int row,col;
    printf("inout number of rows and colums respectively:");
    scanf("%d %d",&row,&col);
    int seats [row][col];
    printf("input seating arrangements:\n");
    for(int i=0;i<row;i++) //start for loop for rows (loop to take input for seating arrangement)
    {
        for(int j=0;j<col;j++) //start for loop for seats
        {
            printf("input (1 for filled 0 for not filled) for row[%d]col[%d]: ",i,j); //1 indicates filled 0 empty
            scanf("%d",&seats[i][j]);
        }//end for loop
    }//end for loop
    printf("\nseating arrangemnet:\n");
    printf("  ");
    for(int j=0;j<col;j++)///start for loop(loop for printing the seat numbers)
    {
        printf(" %d ",j);
    }//end for loop
    printf("\n");
    for(int i=0;i<row;i++)//start for loop (loop for printing the seating arrangement enetered)
    {
         printf("R%d",i); // printing the row numbers
        for (int j=0;j<col;j++)//start for loop
        {
            if(seats[i][j]==0) // prints _ for empty
            printf(" _ ");
            else
            {printf(" X "); // prints X for filled
            }
        }//end for loop
        printf("\n");
    }//end for loop
    int totalAvailable =0;
    for (int i=0;i<row;i++)//start for loop(loop for counting the available seats)
    {
        int available =0;
        for (int j=0;j<col;j++)//start for loop
        {
            if (seats[i][j] == 0)
                available++;
        }//end for loop
        totalAvailable += available;
    }//end for loop
    printf("Total available seats: %d\n", totalAvailable);//printing available seats
    int k;//num of req seats
    printf("input the number of seats required: ");
    scanf("%d",&k);
    if(k<=0||k>col)//checking input validity
    printf("invalid input");
    else{
    int m = row/2;//as middle is prioritized 
    int SbookedRow = 0; // number of row if booked from middle to 0
    int EbookedRow = 0; // number of row if booked from middle to the max seats 
    int EstartSeat = 0; // the starting seat no from middle to 0
    int SstartSeat = 0; // the starting seat no from middle to max seats
    int Sdone=0 , Edone=0; // acting as a boolean if booked S for start and E for end
    for (int i=0; i<row&&(!Sdone||!Edone);i++)//start for loop(checking if all rows are checked and either of
    //the booleans are done  )
    {
        int m1 = m-i;//checking the starting rows from the mid to  0
        int m2 = m+i;// checking the neding rows from the mid to max seats
        if (m1>=0) //as seats are from 0 to col so anything less than 0 is ommitted
        {
            int count = 0;
            for (int j=0;j<col;j++)//start for loop for checking consequtive seats from mid to 0
            {
                if (seats[m1][j] == 0)//if seat is available
                    count++;
                else//when seat is not available
                    count = 0;

                if (count == k)// when consequtive seats equals the number of seats we require
                {
                    SbookedRow = m1; //booked row from mid to 0
                    SstartSeat = j-k+1; // starting booked seat from mid to 0
                    Sdone=1; // booking done
                    break; // iterates outside the loop as bookinug done 
                }
            }//end for loop
        }
        if (m2<row) // omitting the rows more than the actual ones
        {
            int count = 0;
            for (int j = 0; j<col; j++)//start for loop for checking consequtive seats from mid to end
            {
                if (seats[m2][j] == 0)//when seat is available
                    count++;
                else// when not available
                    count = 0;
                if (count == k)
                {
                    EbookedRow = m2;//booked row from mid to end
                    EstartSeat = j-k+1;// starting booked seat from mid to end
                    Edone = 1;//booking done
                    break;// iterates outside the loop as bookinug done
                }
            }
        }
    }//end for loop
    int bookedRow;//actual row that will be boked
    int startSeat;// actual starting seat
    if(!Edone&&!Sdone) // if no booking found
    printf("no available seats");
    else // if booking found
    {
        if(EbookedRow-m==m-SbookedRow) // if same distance prioritize starting ones
        {
            bookedRow=SbookedRow;
            startSeat= SstartSeat;
        } 
        else if(EbookedRow-m>m-SbookedRow) // prioritze the less distance one
        {
            bookedRow= SbookedRow;
            startSeat= SstartSeat;

        }
        else if(EbookedRow-m<m-SbookedRow)// prioritze the less distance one
        {
            bookedRow=EbookedRow;
            startSeat= EstartSeat;

        }
        printf("Booking successful");
        printf("Allocated row: %d\nAllocated seats: ", bookedRow);
         for (int j = startSeat; j<startSeat+k; j++)//start for loop(printing the allocated seats)
        {
            printf("%d ", j);
            seats[bookedRow][j] = 1; // assigning the booked row 1 as filled
        }//end for loop
        printf("\nupdated arrangemnts:\n");
        printf("  ");
    for(int j=0;j<col;j++)///start for loop(printing seat numbers)
    {
        printf(" %d ",j);
    }//end for loop
    printf("\n");
    for(int i=0;i<row;i++)//start for loop(printing updated arrangemnts) iteratinf the rows
    {
         printf("R%d",i);// printing row numbers
        for (int j=0;j<col;j++)//start for loop printing the seats 
        {
            if(seats[i][j]==0)
            printf(" _ "); // _ for empty
            else
            {printf(" X ");// X for filled
            }
        }//end for loop
        printf("\n");
    }//end for loop
}
}
        
    
return 0;
}