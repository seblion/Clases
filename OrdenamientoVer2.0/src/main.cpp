#include <iostream>
#include <unistd.h>
#include <vector>
#include <windows.h>
#include <random>
#define TIME 2000000

using namespace std;

enum color { azul = 1, verde, turqueza, rojo, rosa, amarillo};
string setColor(color c)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
    return "";
}

vector <int> num = {1,8,5,2,7,4,9,6,3};

void showVector(const vector<int>& vec) {
    
    cout << setColor(azul)<< "\r [";
    for (size_t k = 0; k < vec.size(); ++k) {
        cout << vec[k];
        if (k < vec.size() - 1) {
            cout << " ";
        }
    }
    cout << "]";
    usleep(TIME);
}

void presentaIJ(int size, int i, int j) 
{
    vector <char> espacio(size, ' ');
    espacio[i] = 'i';
    espacio[j] = 'j';
    cout <<"\r  ";
    for (int k = 0; k < size; ++k) 
    {
        if (k == i)               cout << setColor(verde) << espacio[k] << " ";
        if (k == j)               cout << setColor(rojo) << espacio[k] << " ";
        if (k != j && k!= i )     cout << espacio[k] << " ";
    }
    cout << endl;
    usleep(TIME/2);
}

void shellsort(vector <int> &vectorshell)
{
    cout << "----------------------------------------------------------------------" << endl
         << endl;
    int largo = 0;
    
    largo = vectorshell.size();
    int distancia = largo / 2;

    while (distancia > 0)
        {
        for (int i = distancia; i < largo; ++i) 
        {
            int val = vectorshell[i];
            int j = i;
            int r = j - distancia;
            while (j >= distancia && vectorshell[j - distancia] > val) 
            {
                presentaIJ(largo, r, i);
                cout << "\x1b[2K";
                showVector(vectorshell);
                usleep(TIME / 2);
                cout << "   swap( " << setColor(rojo) << val << setColor(azul) 
                     << " < " << setColor(verde) << vectorshell[j - distancia] << setColor(azul) << " )";
                getchar();
                cout << "\x1b[A\x1b[2K";
                cout << "\x1b[A\x1b[2K";
                vectorshell[j] = vectorshell[j - distancia];
                j -= distancia;
            }

            presentaIJ(largo, r, i);
            showVector(vectorshell);
            cout << setColor(turqueza)<<"   Val. memoria:" <<setColor(rojo)<< val 
                 << setColor(turqueza) <<"  Distancia comp:" <<setColor(rosa)<< distancia;
            usleep(TIME / 2);
            cout << "\x1b[A\x1b[2K";

            vectorshell[j] = val;

            presentaIJ(largo, r, i);
            showVector(vectorshell);
            cout << "\x1b[A\x1b[2K";


        }
        distancia = distancia/2;
    }
    cout << endl;
    cout << "Vector resultante:  ";
    showVector(vectorshell);

}

int main()
{
    cout << "SHELLSORT"<<endl << "Vector a ordenar: " <<endl;
    showVector(num);
    cout <<endl;
    shellsort(num);
}



