#include <stdio.h>
#include "../lib/patSerie.h"
#include "../lib/patColor.h"
#include "../lib/patUtility.h"

void usoProcedimiento()
{
        int edad=0;
        edad = getNumeroPositivo("Ingresa tu edad:");
        printf(" la edad ingresada es : %i", edad );

        edad = getNumeroPositivo("Ingresa un num mayor a cero:");
        printf(" la edad ingresada es : %i", edad );
        
        char *menuOpc ="\n\tMENU OPERA \n1. Generar PARES \n2. Generar IMPARES \n3. Generar fibonaci \nIngresa tu opc: ";        
}

char menu()
{
    int opc=0;
    do{
        setTextColor(textColorBlue);
        printf("\n\t PATMIC_RETOS");
        setTextColor(textColorCyan);

        printf("\n1. Pares");
        printf("\n2. Impares");
        printf("\n3. Fibonaci");
        printf("\n4. Dibujar cuadrado");
        printf("\n5. Dibujar triangulo");
        printf("\n99.Salir");
        opc =  getNumeroPositivo("Ingresa opc: ");
    }while ( opc < 0 ) ;
    return opc;
}

int main()
{
        // crear la suma de dos mumeros? 

        //int opcMenu     = menu();
        // int num[] ={1,2,3,4,5};

        // num[0]=0;
        // num[2]=2;
        // num[1]=1;

        switch (getNumeroPositivo("Ingresa un numero de mes:"))
        {
            case ENE :  printf("%c Enero", ENTER);           
                        break;
            case FEB :  printf("%c Febrero", ENTER);         
                        break;
            case MAR :  printf("%c Marzo", ENTER);           
                        break;
            default:    printf("%c Mes no registrado", ENTER); 
                        break;
        }
        printf("%c", ENTER);
        //clearTerminal();
        //LoadingBar(30);
        //loadingShort();
        //int nroTermino  = getNumeroPositivo("Ingresa el nro. de términos: ");
        //showCuadrado(nroTermino);
        // switch (opcMenu)
        // {
        //         case 1 :showPares(nroTermino);
        //                 break;
        //         case 2 :showImpares(nroTermino);
        //                 break;
        //         case 3 :showSignoAlernadoFibonaci(nroTermino);
        //                 break;
        //         case 4 :showCuadrado(nroTermino);
        //                 break;
        //         case 99 :printf("Hasta la vista baby...!");
        //                 break;
        //         default:printf("\nOopcion no valida");
        //                 break;
        // }
        return 0;
}