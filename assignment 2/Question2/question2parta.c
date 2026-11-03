/**
 * Programmer: Rumaisa fatima
 * Program: amicable pair 
 */
#include <stdio.h>
int sumOfDivisors(int x)// returns the sum of the proper divisors of x
{
    int i;
    int sum = 0;
    for (i = 1; i <= x/2; i++)// proper divisor is not bigger than x/2 calculating the sum of proper divisiors
    {
        if (x % i == 0) // if i divides x exactly 
            sum = sum + i;   
    }//end for
    return sum;
}

int main()
{
    int n; //till which the pairs are to be found 
    int a; //first pair
    int b; 
    int count = 0; //number of pairs found

    printf("Enter n: ");
    scanf("%d", &n);
    printf("amicable pairs up to %d:\n", n);
    for (a = 2; a <= n; a++)// for to test every number a from 2 to n 
    {
        b = sumOfDivisors(a);
        /* b > a  : smaller number first, so each pair prints only once(this also removes perfect numbers like 6 and 28,
            because for them b is equal to a)*/
        if ( b>a  &&sumOfDivisors(b) == a)
        {
            printf("(%d, %d)\n", a, b);
            count++;// amicabel pair found
        }
    }//end for

    if (count == 0)
        printf("no amicable pairs found.\n");
    else
        printf("total pairs: %d\n", count);

    return 0;
}