/* PROGRAMMER: RUMAISA FATIMA 26K-0018
PROGRAM: Online Shopping Bill Calculator
PART B QUESTION 4*/
#include <stdio.h>
int main() 
{
    int qnt; // qnt is quantity
    float price,disc,tax,subtotal,discountedamt,finalbill;
    // price is the price of the product, disc is the discount percentage, tax i sthe tax percentage, 
    // subtotal is the product of price and quantity, discountedamt is the discounted amount and final bill is the final bill
    printf("input the quatity of produxts purchased: ");
    scanf("%d",&qnt);
    printf("input the price of item: ");
    scanf("%f",&price);
    printf("input discount percentage: ");
    scanf("%f",&disc) ;
    printf("input tax percentage: ");  
    scanf("%f",&tax);
    // checking if any user input is invalid
    if(qnt<0||price<0||disc>100||disc<0||tax>100||tax<0)
   {
    printf("invalid data input");
   }
   else
   {
    subtotal=qnt*price; // calculating subtotal
    discountedamt=subtotal-((subtotal*disc)/100); // calculating discounted amount 
    finalbill=discountedamt+((discountedamt*tax)/100); // calculatimg final bill
    printf("CALCULATED BILL\nqunatity: %d\nprice: %.2f\ntax: %.2f\ndiscount %.2f\nsubtotal: %.2f\ndiscounted amount: %.2f\nfinal bill: %.2f",qnt,price,tax,disc,subtotal,discountedamt,finalbill);



   }
 



    
return 0;
}