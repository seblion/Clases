#include <stdio.h>

int sumaValor(int a , int b)
{
    int suma = a+b;
    a =0;
    b =0;
    printf("\n sumaValor: a=%i b=%i",a,b);
    return suma;
}


void sumaRef(int *aa , int b, int *c)
{
    *c = *aa + b;
    *aa = 100;
    b =0;
    printf("\n sumaRef: aa=%i b=%i",*aa,b);
}

int main()
{
    int a=10, b=20, suma=0;
    printf("Parametros por valor");

    printf("\n main: a=%i",a);
    suma = sumaValor(a,b);
    printf("\n main: Suma por valor = %i",suma);
    printf("\n main: a=%i",a);

    printf("\n\nParametros por referencia");
    printf("\n main: a=%i",a);
    sumaRef(&a,b,&suma);   // & *
    printf("\n main: Suma por referencia = %i",suma);
    printf("\n main: a=%i",a);

    printf("\n");
    return 0;
}
