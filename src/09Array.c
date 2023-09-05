#include <stdio.h>

int main()
{
    int fila=3, columna = 5, sec=1;
    int matriz[fila][columna];

    for (int f = 0; f < fila; f++)
        for (int c = 0; c < columna; c++)
            matriz[f][c] = sec++;
    
    for (int f = 0; f < fila; f++)
    {
        for (int c = 0; c < columna; c++)
            printf("%3d ",  matriz[f][c] ) ;
        printf("\n");
    }
    printf("\n");
}

int buffers(  )
{
    int len=10;
    char letra[len];   ///  '1','2',...'9',/0
    //char *frutas ="coco";   //  frutas[] 

    printf("Ingrese letra: ");
    fgets(letra, len, stdin);   

    // printf("Ingrese frutas: ");
    // fgets(frutas, len, stdin);   

    printf("\n la letra: %s", letra);
    //printf("\n la fruta: %s", frutas);
}

void array(  )
{
    //            0     1   2
    // arr ->  { [10] [20] [30] ... }
    int lenCar = 4;
    int edad[3];
    int notas[]= {1,2,3,4,5};
    char caracteres[] ={'h','o','l','a'};
    char saludo[] ="hola";
    char palabras[] = "coco babana como estas pepe";

    edad[0]=10;
    edad[1]=20;
    edad[2]=30;
    edad[30]=300;

    printf("La edad del 1er alumno es: %d\n", edad[0]);
    printf("La edad del 2do alumno es: %d\n", edad[1]);
    printf("La edad del 3er alumno es: %d\n", edad[2]);
    printf("La edad del error alumno es: %d\n", edad[30]);

    printf("\n---------------\n");
    printf("Nota 1er: %d\n", edad[0]);
    printf("Nota 2do: %d\n", edad[1]);
    printf("Nota 3er: %d\n", edad[2]);
    printf("Nota err: %d\n", edad[10]);

    printf("\n---------------\n");
    printf("Caracteres : ");
    for (int i = 0; i < lenCar; i++)
        printf("%c\t", caracteres[i]);
    
     printf("\n---------------\n");
    printf("saludo : ");
    for (int i = 0; i < lenCar; i++)
        printf("%c\t", saludo[i]);
}
void arrarDeArrays()
{
    //char palabrasInicializadas[] = {"hola","como","estas"};
	char caracterVector[3];  // vector, array,    ['h']['o']['l'] =	"hol"	....
	char *palabrasVector[3];  // vector, array,    ["hola"]["como"]["estas hoy"]  		....
							//						  0	      1	      2 			3 ......
	palabrasVector[0] = "hola";
	palabrasVector[1] = "como";
	palabrasVector[2] = "estas";

	palabrasVector[12] = "20"; 	// *warning

	printf("\npalabrasVector[0]: %s", palabrasVector[0]);
	printf("\npalabrasVector[1]: %s", palabrasVector[1]);
	printf("\npalabrasVector[2]: %s", palabrasVector[2]);

	printf("\npalabrasVector[12]: %s", palabrasVector[12]);
}