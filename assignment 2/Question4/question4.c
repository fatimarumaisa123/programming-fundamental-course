/**
 * Programmer: Rumaisa fatima
 * Program: Daily Sales Bar Chart
 */
#include <stdio.h>
int getValidDays();//for validity check
float calculateDailySales(int dayNumber);//calculating daily sales
int findHighestSalesDay(int dailySales[], int days);//calculating highes sales day
void displayBarChart(int dailySales[],int days);//displaying the bar chart
int main() 
{
    int days;
    float total;
    days= getValidDays();
    int dailySales[days];
    for (int i = 0; i < days; i++)//calling the daily sales function for each day
    {
        dailySales[i] = calculateDailySales(i + 1);
        total+= dailySales[i];//calculating the total sales
    }//end for
    int hd=findHighestSalesDay(dailySales, days);

    printf("\nTotal festival sales: Rs. %.2f\n", total);
    printf("Day with highest sales: Day %d\n", hd);

    displayBarChart(dailySales, days);
return 0;
}
int getValidDays()//validity check
{
int days=0,customers;
    while(days>7||days<1)//start while greter than 7 and less than  1 not allowed
    {printf("input the number of days: ");
        scanf("%d",&days);
    }//end while
    return days;
}
float calculateDailySales(int dayNumber)//calculating daily sales
{
    int customer;
   printf("input the number of customer orders receivced on day %d: ",dayNumber);
    scanf("%d",&customer);
    int arr[customer];
    for(int i=0;i<customer;i++)//for to take customers order price
    {
            printf("input for day %d customer %d: ",dayNumber+1,i+1);
            scanf("%d",&arr[i]);
            
    } //end for
    int total=0,hod=0;
    float avg=0;
    for(int i=0;i<customer;i++)//for to calculate total sales for the day and finding highest sales 
        {
           total+=arr[i];
           if(hod<arr[i])
           hod=arr[i];
        }
        avg=total/customer;
        printf("\nsummary of  day %d",dayNumber);
        printf("\ntotal=%d average=%.2f highest order of the day=%d,total,avg,hod");
        return total;



    }
    int findHighestSalesDay(int dailySales[],int numberOfDays)//calculating the highest sales day
{
    int hod = 0;
    for (int i = 1; i < numberOfDays; i++)
    {
        if (dailySales[i] > dailySales[hod])
            hod = i;
    }

    return hod + 1;
}

    void displayBarChart(int dailySales[], int numberOfDays)//display bar chart
{
    printf("\nbar chart\n");
    for (int i=0;i<numberOfDays;i++)//display sales for each day
    {
        printf("Day %d: ", i + 1);
        for (int j = 0; j<(dailySales[i]/100); j++)//display 1 for each complete rs 100
            printf("*");
        printf("\n");
    }
}
