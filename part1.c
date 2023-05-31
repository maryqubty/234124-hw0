#include <stdio.h>
#include <stdlib.h>



/*=========================================================================
  Constants and definitions:
==========================================================================*/

/* put your #defines and typedefs here*/



/*-------------------------------------------------------------------------
  The main program. (describe what your program does here)
 -------------------------------------------------------------------------*/
#define NOT_FOUND -1

int power_num(int num)
{  int counter =0;
    if(num<=0) return NOT_FOUND;
    while(num>=2)
    {
        if(num%2) return NOT_FOUND;
        counter++;
        num/=2;
    }
    return counter;
}

int main()
{
    printf("Enter size of input:\n");
    int size=0;
    int check=0;
    check= scanf("%d",&size);
    if(size<=0 || check!=1)
    {
        printf("Invalid size\n");
        return 0;
    }
    int * array=(int*)malloc(sizeof(int)*size);
    int size2=size;
    printf("Enter numbers:\n");
    int num=0;
    int sum=0;

    while(size>0)
    {
        check = scanf("%d",&num);
        if(check!=1)
        {
            printf("Invalid number\n");
            free(array);
            return 0;
        }
        array[size-1]=num;
        size--;
    }
    while(size2>0)
    {
        check = power_num(array[size2-1]);

        if(check!= NOT_FOUND)
        {
            sum+=check;
            printf("The number %d is a power of 2: %d = 2^%d\n",array[size2-1] ,array[size2-1], check);

        }
        size2--;
    }
    printf("Total exponent sum is %d\n",sum);
    free(array);
    return 0;

}
