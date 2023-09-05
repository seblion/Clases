#include <stdio.h>

void swap(int *a , int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

void swapValor(int a , int b)
{
    int c = a;
    a = b;
    b = c;
}


int main()
{
    int a = 10 , b= 20;
    // int c=a;
    // a = b;
    // b = c;
    swapValor(a,b);
    swap(&a, &b);
    printf("\n a=%i b=%i",a,b);

    printf("\n");
    return 0;
}
