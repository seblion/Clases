#include <stdio.h>

int main()
{
    //Variables int:
    int a;       // declarando
    int b=10;    // inicializado
    int c;   
    
    //Variables char:
    float f1 = 1.01, f2 = 2.02, f3r;

    //Variables char:
    char caracter ='*';

    a=5;
    c= a + b;
    printf("la suma int es : %i  \n", c);

    f3r = f1 + f2;
    printf("la suma float es : %.3f  \n", f3r);

    printf("El caracter es: %c  \n", caracter);
    return 0;
}
