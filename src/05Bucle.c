#include <stdio.h>

/**
 * 
*/
void  signoAlernadoFibonaci(int cantida)
{
    int a =0, b=1, c=1;
    for (int i = 0; i < cantida; i++)
    {
        //printf("%i",c);  // 1 1 2 
        for (int s = 0; s < c; s++)
            printf ( (i %2==0) ?  "+" : "-");

        printf("\t");
        c = a + b;
        a = b;
        b = c;
    }
    cantida =0;
    printf("\nsignoAlernadoFibonaci.cantida %i",cantida); 
}

void main()
{
    int cantida=0;
    printf("\nIngresa numero de terminos: ");
    scanf("%i",&cantida);
    signoAlernadoFibonaci(cantida);
    printf("\nmain.cantida %i",cantida); 
}
