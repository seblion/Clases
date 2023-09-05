#include <iostream>
#include "../lib/patColor.h"
using namespace std;

void deficionPuntero()
{
    int a  = 10;
    int b  = 20;
    int *pi= NULL;

    pi = &a;
    cout<< endl << endl << COLOR_BLUE
        << "valor de   a: " << a  << endl
        << "referencia a: " << &a << endl
        << "----------------------------" << endl
        << "refer  pi_a: " << pi << endl
        << "valor *pi_a: " << *pi << endl;
    *pi =0;     //a=0;
    cout<< "cambio    a: " << a << endl;
    
    pi = &b;
    cout<< endl << endl << COLOR_RED
        << "valor de   b: " << b  << endl
        << "referencia b: " << &b << endl
        << "----------------------------" << endl
        << "refer  pi_b: " << pi << endl
        << "valor *pi_b: " << *pi << endl;
    *pi =0;     //b=0;
    cout<< "cambio    b: " << b << endl;
}

int funcionPorValor(int valor)       //parametro por valor
{
    valor = valor + 10;             //Se le suma 10
    return valor;
}

int funcionPunteros(int *valor)    //parametro por referencia
{
    *valor = *valor + 10;          //Se le suma 10 a la posici�n en memoria
    return *valor;
}

void tipoParametrosPunteros()
{
    int numero = 10;
    int *pi  = NULL;

    cout<<  "----------------------------"<< COLOR_RESET <<endl<<endl;
    cout<< "Antes de funcionPorValor, numero   = " << numero <<endl;      // 10
    funcionPorValor(numero);
    cout << "Despues de funcionPorValor, numero = " << numero <<endl;      // 10

    pi = &numero;
    cout<<  "----------------------------"<< COLOR_BLUE <<endl<<endl;
    cout << "Antes de funcionPunteros, numero   = " << numero <<endl;      // 10
    funcionPunteros(pi);
    cout << "Despues de funcionPunteros, numero = " << numero <<endl;      // ?

    cout<<  "----------------------------"<< COLOR_CYAN <<endl<<endl;
    cout << "Antes de funcionPunteros, numero   = " << numero <<endl;      // 10
    funcionPunteros(&numero);
    cout << "Despues de funcionPunteros, numero = " << numero <<endl;      // ?

}

void ArrayPunteros()
{
    // string titulos[] ==> string* titulos
    string* titulos = NULL; //Se inicializa el puntero (inicia en null) 
    string* autores = NULL; //Se inicializa el puntero (inicia en null)
    int tamanio ;           //Se inicializa la variable
    string entrada;

    //punteros dobles
    string** libros; 
    int cols = 2;              //    |autores|titulos|

    cout << "Cuantos libros desea ingresar?";
    getline(cin, entrada);      //Se asigna el valor ingresado
    tamanio = stoi(entrada);    //Se transforma la entrada en n�mero

    //dimensionar los arrays
    titulos = new string[tamanio];
    autores = new string[tamanio];

    //dimensionar arrays doble
    libros = new string*[tamanio];//Se asigna el n�mero de filas  


    cout <<endl<< "Por favor ingrese la siguiente informaci�n de los Libros: "<<endl;
    for(int i = 0; i < tamanio; i++)
    {
        string titulo, autor;
        cout << "\n******* Libro " << i + 1 << "********:\n";
        cout << "Titulo: ";
        //cin >> titulos[i]; //No funciona con espacios
        getline(cin, titulo);
        titulos[i]=titulo;
       
        cout << "Autor: ";
        //cin >> autores[i]; //No funciona con espacios
        getline(cin, autor);
        autores[i]=autor;

        //con el array doble
        libros[i] = new string[cols]; //Cada fila contendr� dos columnas  //    |<titulos>|<autores>|
        libros[i][0] = titulo;
        libros[i][1] = autor;
    }

    cout<<"titulo \t autor"<<endl;
    for (int i = 0; i < tamanio; i++)
        cout<<libros[i][0]<<"\t"<<libros[i][1]<<endl;

    //Liberamos la memoria de ambos punteros
    delete [] titulos;
    delete [] autores;
    titulos = NULL;
    autores = NULL;

    //punteros dobles,...
    //Para liberar la memoria debemos recorrer fila por fila primero.
    for (int i = 0; i < tamanio; ++i)
        delete [] libros[i]; //Cada fila de libros es otro array de punteros //Por eso son punteros a punteros

    //Luego de limpiar las columnas, quitamos la fila �nica que qued�
    delete [] libros;
}

int main()
{
    // deficionPuntero();
    // tipoParametrosPunteros();
    ArrayPunteros();

    cout << endl;
    return 0;
}