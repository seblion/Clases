/*
�recursi�n?
La recursividad es una t�cnica de programaci�n que busca resolver un problema sustituy�ndolo por otros problemas
de la misma categor�a, pero m�s simples implementando un algoritmo recursivo.

Una funci�n recursiva es una funci�n que se llama a s� misma.
La funci�n recursiva tienen similitud con los bucles, pero no est�n basados en una declaraci�n condicional. 
La funci�n se llama siempre que se requiere el mismo c�digo para ejecutarse de forma reiterada.
La funci�n recursiva ofrecen soluciones estructuradas, modulares y elegantemente simples

Para escribir una funci�n recursiva, se deben satisfacer 3 condiciones:
- Debe haber al menos un caso base de parada o salida
- Inducci�n: Paso recursivo que provoca una llamada recursiva Debe ser correcto para distintos par�metros de entrada
- Convergencia: Cada paso recursivo debe acercar a un caso base. Se describe el problema en t�rminos de problemas m�s sencillos
La funci�n recursiva debe tener un �caso base� (paso 1), el caso base es cualquier expresi�n donde le dice a la funci�n
cu�ndo dejar de llamarse a s� misma. Si no tiene un caso base, la recursi�n producir� un bucle infinito.

Uso de funciones recursivas:
- Cuando los problemas son mas cercanos a la descripci�n matem�tica.
- Cuando su lectura es mas f�cil de analizar
- En estructuras que se adaptan mejor a estructuras de datos recursivas. Como la b�squeda binaria, listas recursivas, particiones, �rboles, series de Fibonacci, etc.
- Un ejemplo t�pico de programaci�n recursiva consiste en la terea de eliminar un directorio. La funci�n eliminar� todos los archivos en un directorio y cuando encuentre un subdirectorio se llamar� a s� mismo para eliminar el subdirectorio y todos sus archivos y subdirectorios.

*/

#include <iostream>
using namespace std;


// 0! = 1    ** base
// 1! = 1    ** base
// 2! = 2 * 1!  -> 2 * 1 -> 2
// 3! = 3 * 2!  -> 
// 5! = 5 � 4 � 3 � 2 � 1 = 120
// 10! = 10 � 9 � 8 � 7 � 6 � 5 � 4 � 3 � 2 � 1
int factorial(int n)
{
    if(n==1 || n==0)           // condici�n de parada
        return 1; 
    return n*factorial(n-1);   // Llamada recursiva a la funci�n que lleva a la condici�n de parada
    //     factorial(5) 
    //-> 5*factorial(4) 
    //-> 4*factorial(3)
    //-> 3*factorial(2)     .... -> 1
}

// siempre busca una forma de memorizar y hacer que sea recursivo.
// Este c�digo elimina la necesidad de que el sistema operativo mantenga el marco de la pila para
// cada llamada de funci�n recursiva en la memoria, en lugar de pasar los valores que deben ser �recordados� 
// en cada paso como un argumento a la funci�n. Esto mejora dram�ticamente el rendimiento a medida que n crece.
int factorial(int n, int r) 
{
      if (n == 0) 
          return r;
      else 
          return factorial (n - 1, n * r);      //memoria
      //   factorial (5, 1) 
      //-> factorial (4, 5*1) 
      //-> factorial (3, 4*5) 
      //-> factorial (2, 3*20) --> ....
 }

 //Ejemplos: a   b 
 //          3 + 4  => 
 //     suma(4 , 3) ->
 //     suma(5 , 2) -> 
 //     suma(6 , 1) -> 
 //     suma(7 , 0) -> 7
 int suma(int a, int b)
 {
    if(b==0)
       return a;
    else
       return suma(++a,--b);   
 }

 int multiplicacion(int a, int b)
 {
    if(a==0 || b==0)
       return 0;
    else
       return multiplicacion(a,b-1) + a;   
 }

int potencia(int a, int b)
{
    if(b==0)
       return 1;
    else
       return potencia(a,b-1) * a;   
}

int fibonacci(int n)
{
     if(n==1 || n==2)
        return n-1;
     else
        return fibonacci(n-1) + fibonacci(n-2);   
 }

//"10-9-8-7-6-5 ... 1"  : Ruth
string conteoRegresivo(int n)
{ 
   if(n==1)
      return to_string(n);
   return to_string(n) + "-"+ conteoRegresivo(n-1); // --n
}

string conteoRegresivoMemoria(int n, string memoria)
{ 
   if(n==1)
      return memoria + to_string(n);
   memoria += to_string(n) + "-" ;
   return conteoRegresivoMemoria(n-1, memoria); // --n
}

// Claudia
string conteoProgresivo10(int numero)
{
   if(numero==10)
      return to_string(numero);   
   return to_string(numero) + " "+ conteoProgresivo10(numero+1);
}

int main()
{
    int a, b, n = 15; 
    cout<< "Factorial de  "<< n <<" es " << factorial(n) << endl;
    cout<< "Factorial de  "<< n <<" es " << factorial(n,1) << endl;

    cout << "Operaciones:" <<endl; 
    cout << "Ingrese valor de a : ";    cin >> a;
    cout << "Ingrese valor de b : ";    cin >> b;
    cout << a << " + " << b << " = " << suma(a,b) << endl;
    cout << a << " * " << b << " = " << multiplicacion(a,b) << endl;
    cout << a << " elevado a " << b << " = " << potencia(a,b) << endl;

    cout << "Conteo: "              << conteoRegresivo(10) << endl;
    cout << "Conteo progresivo: "     <<conteoProgresivo10(5) << endl;
    cout << "conteoRegresivoMemoria: "<<conteoRegresivoMemoria(10, "");

   cout << endl;
    return 0;
}


