/*
*  date: 30.may.2k23
*  author: Pat_mic
*  description: Mayor de dos numeros
*/
#include <stdio.h>
#include <stdlib.h>

/**
 * description: rutina principal.
*/
int main()
{   // a y b son numeros enteros
    int numero1=0, numero2=0;

    printf("Ingresa 1er num: ");
    scanf("%i",&numero1);
    printf("Ingresa 2do num: ");
    scanf("%i",&numero2);

    if (numero1 == numero2)
    {
        printf("Son iguales \n");
        exit(0);
    }

    if(numero1 > numero2)
        printf("el mayor es: %i", numero1);
    else
        printf("el mayor es: %i", numero2);

    printf("\n");
    return 0;
}
