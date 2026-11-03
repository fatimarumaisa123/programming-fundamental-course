/**
 * Programmer: Rumaisa fatima
 * Program: Greenhouse Temperature Monitoring System
 * Desc: finding descriptions of all the sensors
 */
#include <stdio.h>
void input (int x ,int y,int arr[x][y]);//takes readings in the sensors
void calc (int x ,int y,int arr[x][y]);//to calculate several things of a perticular sensor
int highestAverage(int x, int y, int arr[x][y]);//to determine the senspr with the highest average
int main() 
{
  int sens,temp,total=0;//sens-->sensors temp-->number of temepratures or reading of one sensor
  float avg=0;
  printf("input the number of sensors: ");
  scanf("%d",&sens);
  printf("input the number of temperatres: ");
  scanf("%d",&temp);
  int arr[sens][temp];
  input(sens,temp,arr);//to take input of readings in each sensor
  calc(sens,temp,arr); // to calculate several things
 
  int sensor = highestAverage(sens,temp,arr);//returning the sensor with highest avg 
    for (int j = 0; j < temp; j++)//start for to calculate the total of the sensor number returned
    {
        total+=arr[sensor][j];
    }//end for
    avg=total/temp;//calculating the highes avg
    printf("\nSensor with highest average: %d\n", sensor+1);
    printf("Highest average temperature: %.2f\n", avg);


return 0;
}
void input (int x,int y,int arr[x][y]) //takes input in each sensor
{
   for(int i=0;i<x;i++)//start for for taking number of readings in each sensor
   {
    printf("input temperature readings in sensor %d:\n",i+1);
    for(int j=0;j<y;j++)//start for to take each reading
    {
        printf("input reading number %d: ",j+1);
        scanf("%d",&arr[i][j]);
    }//end for 
   }//end for

}
void calc(int x,int y,int arr[x][y])//calculating several things
{
    int total=0,high=0,low=0,critical=0,warning=0,streak=0,longest=0;
    int c;
    float avg=0;
    for(int i=0;i<x;i++)//for for calculating for each sensor
    {
        // resetting everything to 0 to reset everything for each sensor 
        total=0;
        avg=0;
        critical=0;
        warning=0;
        high=arr[i][0];
        low=arr[i][0];
        streak=0;
        longest=0;
        for(int j=0;j<y;j++)//for for calculating each reading
        {
            total=total+arr[i][j];//calculating the total for the sensor
            if(high<arr[i][j])//calculating the highest reading for the sensor
            {
             high=arr[i][j];
            }
            if(low>arr[i][j])//calculating the lowest reading for the sensor
            low=arr[i][j];
            if(arr[i][j]>=40)//calculating the critical readings in a sensor
            critical++;
            if(arr[i][j]>=35&&arr[i][j]<=39)//calculating warnings in a sensor
            warning++;
            if (arr[i][j] >= 35)//calculating streak
            {
            streak++;
            if (streak>longest)
            longest = streak;
            }
            else
            {
            streak = 0;
            }

        }
        avg=total/y;
        printf("\nsensor %d: total: %d  average: %.2f  max: %d  min: %d ",i+1,total,avg,high,low);
        printf("\n           critical: %d  warning: %d  longest streak: %d",critical,warning,longest);

        
    }
}
    int highestAverage(int x, int y, int arr[x][y])//calculating the highest average
{
    int sens=0;
    float havg=0;

    for (int i=0;i<x;i++)//start for to caculate the highest average among all the sensors
    {
        int total=0;
        for (int j=0;j<y;j++)//start for to caculate the total in that loop
        {
            total+=arr[i][j];
        }//end for
        float avg=total/y; // calcuating the average for the surrent sensor
        if (avg>havg) // if the avg is higher than the highest average
        {
            havg = avg;
            sens = i;
        }
    }//end for
        return sens;
}
    


