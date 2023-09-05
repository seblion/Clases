/*
*  date: 30.may.2k23
*  author: Pat_mic
*  description: Determina si un numero es par o impar
*/
#include <stdio.h>

int main()
{
    int numero;

    printf("Ingresa un numero: ");
    scanf("%i",&numero);
    
    //% permite saber si existe un residuo en una division
    if (numero % 2 == 0)
        printf("El %i es PAR", numero);
    else
        printf("El %i es IMPAR", numero);

    printf("\n");
    return 0;
}
