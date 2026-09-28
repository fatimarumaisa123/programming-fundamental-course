/* PROGRAMMER: RUMAISA FATIMA 26K-0018
PROGRAM: Smart Campus Parking and Access Management System
PART B QUESTION 5*/
#include <stdio.h>
int main() 
{
    int reg,n=1,va=20,vb=40,vc=15,car=0,bike=0,van=0,r=0;
    // reg is number of registrations, car bike and van is number of each of them,va vb and vc are the capacities in zone a b and c respectively
   
    printf("input the number of registrations:");
    scanf("%d",&reg);
    getchar();
    while(n<=reg)
    {
      char   vtyp='a',cat='a',per='a',em='a';
        while(vtyp!='C'&&vtyp!='B'&& vtyp!='V')
        {
            printf("input vehicle type  (C for car V for van B for bike) of regitration no %d: ",n);
            scanf(" %c",&vtyp);

        }
         while(cat!='F'&&cat!='S'&& cat!='G')
        {
            printf("\ninput user category (F for faculty S for student and G for visitor) of registration no %d: ",n);
            scanf(" %c",&cat);


        }
         while(per!='Y'&&per!='N')
        {
            printf("\ninput valid parking permit Y or N of registration %d: ",n);
            scanf(" %c",&per);


        }
        if(per=='N')
        {
            printf("\nemergency?");
            scanf(" %c",&em);

        }
        if(per=='N'&&em=='N')
        {
            printf("\nnot allowed as permit in not available and no emergency");
            r=r+1;
        }
        else if(cat=='F')
        {
            if(vtyp=='C'||vtyp=='B')
            {
              if(va>0)
              {
                printf("\nallow parking in zone a");
                va--;
                printf("\nnumber of spaces left in zone a %d",va);
                if(vtyp=='C')
                {
                    car=car+1;
                }
                else
                bike=bike+1;
              }
              else
              {printf("\nno space in zone a ");
                r++;}
            }
            else
            {
                if(va>1)
               { printf("\nallow parking in zone a");
                va=va-2;
                printf("\nno of spaces left in zone a %d",va);
                van++;
               }
                else
               { printf("\nno space in zone a");
                r++;
               }

            }
        }
             else if(cat=='S')
        {
            if(vtyp=='C'||vtyp=='B')
            {
              if(vb>0)
              {
                printf("\nallow parking in zone b");
                vb--;
                printf("\nnum of spaces left in zone b %d",vb);
                if(vtyp=='C')
                {
                    car=car+1;
                }
                else
                bike=bike+1;
              }
              else
              {printf("\nno space in zone b");
                r++;}
            }
            else
            {
                if(vc>1)
               { printf("\nallow parking in zone c");
                vc=vc-2;
                printf("\nnum of spaces left in zone c %d",vc);
                van++;
               }
                else
                {
                printf("\nvehicle is rejected no space available");
                r++;}

            }
        }
             else if(cat=='G')
        {
            if(vtyp=='C'||vtyp=='B')
            {
              if(vc>0)
              {
                printf("\nallow parking in zone c");
                vc--;
                printf("\nnum of spaces left in zone c %d",vc);
                if(vtyp=='C')
                {
                    car=car+1;
                }
                else
                bike=bike+1;
              }
              else
              {printf("\nno space");
                r++;
              }
            }
            else
            {
                if(vc>1)
               { printf("\nallow parking in zone c");
                printf("\nnum of spaces left in zone c %d",vc);
                vc=vc-2;
                van++;
               }
                else
                {
                    printf("\nvehicle is rejected no space");
                    r++;
                }

            }
            
        }
        


        n++;
    }
   printf("\nPARKING SUMMARY:\n");
   printf("total number of vehicles processed: %d\n",reg);
   printf("total number of accepted vehicles: %d\ntotal number of rejected vehicles: %d\n",car+van+bike,r);
   printf("number of bikes: %d\nnumber of cars: %d",bike,car);
   printf("\nnumber of vans: %d\nfinal occupancy: %d\n",van,((20-va)+(40-vb)+(15-vc)));
   
   float oa = (20 - va) / 20.0, ob = (40 - vb) / 40.0, oc = (15 - vc) / 15.0; //PERECENT OCCUPANCY CALCULATION
   if (oa > ob && oa > oc)
    printf("zone a has the highest occupancy  ");
   else if (ob > oa && ob > oc)
    printf("zone b has the highest occupancy ");
   else if (oc > oa && oc > ob)
    printf("zone c has the highest occupancy  ");
   else
    printf("some occupancies equal");
   if(va==0&&vb==0&&vc==0)
   printf("\nparking is full");




return 0;
}