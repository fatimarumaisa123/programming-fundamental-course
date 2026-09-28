/* PROGRAMMER: RUMAISA FATIMA 26K-0018
PROGRAM: Class Result Processing
PART B QUESTION 3*/
#include <stdio.h>
int main() 
{
    int n,i=0,j=0,sum=0; // n is the number of students, i and j are the loop counters and sum is the sum of marks
    float avg; // avg is the average marks
    printf("number of students ");
    scanf("%d",&n);
    int std[n],sub[5]; // std[n] is the array for number of students and sub[5] is the array for marks of each subject
    while(i<n) // loop running for each student
    {
        
            while(j<5) // loop running for each subject for marks
            { 
                printf("input marks of sub %d of student %d ",j+1,i+1);
                scanf("%d",&sub[j]);
                j++;
             }
       
         j=0; 
             
    
      
        while(j<5)
        {
             sum=sum+sub[j]; // calculating the sum of marks of each student
             avg=sum/5; // calculating average marks of each student
            
             j++;
        
        }
        
         printf("details of student %d",i+1);
         printf("\naverage= %.2f \nremarks: ",avg);
             
         if(sub[0]<33||sub[1]<33||sub[2]<33||sub[3]<33||sub[4]<33)
         //printing statements according to conditions provided
             {
                printf("fail-- subject definciency\n");
             }
             else if(avg>=80)
             {
                printf("distinction\n");

             }
             else if(avg>=60)
             {
                printf("pass\n");
             }
             else
               { printf("fail\n");}
             i++;
             sum=0;
      avg=0;
      j=0;
             
      
        
    }
    
    \

return 0;
}