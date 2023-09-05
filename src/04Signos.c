/*
*  date: 30.may.2k23
*  author: Pat_mic
*  description: Imprime signos
*/
#include <stdio.h>

/**
 * secuenciaSigno: procedimiento de sisgnos 
 * numeroSigno: catidad de signs a generar
 * caracter: caracter a presetar
*/
void secuenciaSigno(int numeroSigno, char caracter)
{
    for (int i = 0; i < numeroSigno; i++)
        printf("%c ", caracter);
    printf("\n");
}

/**
 * secuenciaSignoAlernada: procedimiento de sisgnos alternos
 * numeroSigno: catidad de signs a generar
*/
void secuenciaSignoAlernada(int numeroSigno)
{
     for (int i = 0; i < numeroSigno; i++)
        if (i%2==0)        
            printf("+ ");
        else
            printf("- ");

    printf("\n");
}

int suma(int a, int b)
{   
    int c = a + b;
    return c;
}
int sumaPares(int a, int b)
{   
    if((a%2==0) && (b%2==0))
        return a + b;
    return 0;
}
int main()
{
    char caracter='+';
    int cantidaSigno=0;
    int a=0, b=0,c=0;
    printf("Ingresa un numero de signos que deseas: ");
    scanf("%i",&cantidaSigno);
    
    secuenciaSigno( cantidaSigno,  caracter);
    secuenciaSignoAlernada(cantidaSigno);
    //-----------------------------------

    
    printf("Ingresa a: ");
    scanf("%i",&a);
    printf("Ingresa b: ");
    scanf("%i",&b);

    c=sumaPares(a,b);
    printf("La suma es: %i",c);
    printf("\n");

    return 0;
}
