/* PROGRAMMER: RUMAISA FATIMA 26K-0018
PROGRAM: Smart EV Charging and Parking Management System
PART B QUESTION 6*/
#include <stdio.h>
#include<stdlib.h>
int main() 
{
    char vtyp,pm,dis,avb,status; //vtyp is vehicle type, pm is parkimg membership, dis is disability, avb is availability, status is peak and off peak
    int soc,req,exp,ctime,cost,discount,pcharges; /* soc is battery charge level, req is required charging, exp is expected 
    parking duration, ctime is current time, pcharges is parking charges */
    printf("input vehicle type E for electric H for hybrid: ");
    scanf("%c",&vtyp);
    printf("input battery charge level: ");
    scanf("%d",&soc);
    printf("input required charge level: ");
    scanf("%d",&req);
    printf("input expected parking duration: ");
    scanf("%d",&exp);
    printf("input current time: ");
    scanf("%d",&ctime);
    getchar();
    printf("membership?(y/n): ");
    scanf("%c",&pm);
    getchar();
    printf("disabled?(y/n): ");
    scanf("%c",&dis);
    getchar();
    printf("station available?(y/n): ");
    scanf("%c",&avb);
    
    if(avb=='n') // n means no
   {
    if(vtyp=='H') 
    {
        printf("charging unavailable parking only");
        exit(0); // program ending function
    }
    else
    {printf("no charging slot available");
        exit(0); // program ending function
    }
   }
   else if(vtyp=='H'||vtyp=='E')
   {
    if(soc<40||vtyp=='E')
    printf("allow cahrging");
    else
    {
        printf("vehicle doesnt qualify for ev charging");
        exit(0); // program ending function
    }
   }
   int reqc=req-soc; // calculating required charging
   if(req<=soc)
   {
    printf("no charging required");
    exit(0); // program ending function
   }
   else
   {
    if(soc<=15&&reqc>=80)
    printf("emergency charging policy");
    else if (dis=='y'||(pm=='y'&&soc<=30))
    printf("priority charging");
    else
    printf("normal charging");
   }
   if(ctime>=17&&ctime<=22)
   { cost=50;
    discount=10;
     status='p'; // peak
   }
   else
   {
     cost=35;
     discount=20;
     status='o'; // off peak
        
   }
   if(exp<=2)
  {  pcharges=200;

  }
  else if(exp<=5)
  { pcharges=400;
    
  }
  else 
  {
    pcharges=700;
  }
  if(pm='y') // yes
  {
     discount=20;
  }
  if(dis='y') // yes
  {
    discount=100;
  }
  if(exp>8)
  printf("long stay warning please relocate your vehicle after cahrging");
  else
  printf("standard parking duration");
  printf("vehicle type: %c\nbattery level: %d\nrequired level: %d\nstatus: %c\ncost: %d\nparking charges: %d\ndiscount: %d",
        vtyp, soc, req, status, cost, pcharges, discount);




return 0;
}