#include <iostream>
#include <cstring>
#include <string>
using namespace std;

#define FIL 3
#define COL 3
#define COLD 6

void showMatriz(int m[][COL])
{
    for (int f = 0; f < FIL; f++)
    {
        for (int c = 0; c < COL; c++)
            cout << " " << m[f][c];
        cout << endl;
    }
}

void showMatrizP(int tam)
{
    char mc[tam][tam];

    for (int f = 0; f < tam; f++)
    {
        for (int c = 0; c < tam; c++)
            if ((f==0) || (c==0) || (tam/2==f) || ((tam -1 == c) && (f <= tam/2  ) ) )
                mc[f][c] = '*';
            else
                mc[f][c] = ' ';
    }
     
    for (int f = 0; f < tam; f++)
    {
        for (int c = 0; c < tam; c++)
             cout << mc[f][c];
        cout <<"   ";
        for (int c = 0; c < tam; c++)
             cout << mc[f][c];
        cout <<endl;
    }

}

void showMatrizInt()
{
    int edades[3][2] = {{1,2},{9,8},{14,21}};
    int filas = (sizeof(edades)/sizeof(edades[0]));
    int colum = (sizeof(edades[0])/sizeof(edades[0][0]));

    cout <<"filas: " <<  filas <<endl;
    cout <<"colum: " <<  colum <<endl;

    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < colum; j++)
            cout << edades[i][j] << "  ";
        cout << endl;
    }
}

void showArrayString()
{
    string titulos[5];
    string autores[5];
    
    cout<< "Ingrese información de los Libros: \n";
    for(int i = 0; i < 5; i++)
    {
        cout << "\n******* Libro " << i + 1 << "********:\n";
        cout << "Titulo: ";
        //scanf("%s",tixcvx);
        //cin >> titulos[i]; //No funciona con espacios
        getline(cin, titulos[i]);
        cout << "Autor: ";
        //cin >> autores[i]; //No funciona con espacios
        getline(cin, autores[i]);
    }

    cout<< "\n******* Libros Ingresados ********:\n";
    for(int i = 0; i < 5; i++)
    {
        cout<< "  Titulo: " << titulos[i];
        cout<< "  Autor : " << autores[i];
        cout<<endl;
    }

}

void showMatrizString()
{
    string libros[5][2];
    cout << "Por favor ingrese la siguiente información de los Libros: \n";
    string titulo ,autor;
    for(int i = 0; i < 5; i++)
    {
        cout << "\n******* Libro " << i + 1 << "********:\n";
        cout << "Titulo: ";
        getline(cin,titulo);
        cout << "Autor: ";
        getline(cin,autor);
        libros[i][0] = titulo;
        libros[i][1] = autor;
    }

    cout<< "\n******* Libros Ingresados ********:\n";
    for(int i = 0; i < 5; i++)
    {
        cout<< "  Titulo: " << libros[i][0];
        cout<< "  Autor : " << libros[i][1];
        cout<<endl;
    }

}

void showMatrizDinamica(char matriz[][COLD])
{
    int fila = (sizeof(matriz) / 2);  // sizeof(matriz) = sizeof(matriz[0]) = sizeof(matriz[0][0])
    //int columna = (sizeof(matriz[0])/sizeof(matriz[0][0]));
    for(int f= 0; f < fila; f++){
        for( int c=0; c < COLD; c++){
            cout<<matriz[f][c]<<" ";
        }
        cout<<endl;
    }
}

void MatrizDinamica(int fila)
{
    char matriz[fila][COLD];
 
    for(int f= 0; f < fila; f++){
        for( int c=0; c < COLD; c++){
            matriz[f][c]='+';
        }
    }
    showMatrizDinamica(matriz);
}

int main()
{
    int a[10][5];
    float b[3][2][4];

    int m[FIL][COL] = { {1, 0, 0},
                        {0, 1, 0},
                        {0, 0, 1} };
     
    // showMatriz(m);
    // showMatrizP(9);
    // showMatrizInt();
    // showArrayString();
    //showMatrizString();
    MatrizDinamica(4);
    return 0;
}