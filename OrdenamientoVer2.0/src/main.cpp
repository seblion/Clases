#include <iostream>
#include <unistd.h>
#include <vector>
#include <windows.h>
#include <random>
#define TIME 1000000

using namespace std;

enum color { azul = 1, verde, turqueza, rojo, rosa, amarillo};
string setColor(color c)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
    return "";
}

vector <int> num = {1,8,5,2,7,4,9,6,3};

void showVector(const vector<int>& vec) {
    
    cout << "\r [";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i];
        if (i < vec.size() - 1) {
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
    for (int k = 0; k < size; ++k) {
        cout <<espacio[k] << " ";
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
                presentaIJ(largo, i, r);
                cout << "\x1b[2K";
                showVector(vectorshell);
                usleep(TIME / 2);
                cout << "   swap( " << setColor(turqueza) << val << " < " << setColor(verde) << vectorshell[j - distancia] << " )";
                getchar();
                cout << "\x1b[A\x1b[2K";
                cout << "\x1b[A\x1b[2K";

                vectorshell[j] = vectorshell[j - distancia];
                j -= distancia;

            }

            presentaIJ(largo, i, r);
            showVector(vectorshell);
            cout << "   Val. memoria:" << val << "  Distancia comp:" << distancia;
            usleep(TIME / 2);
            cout << "\x1b[A\x1b[2K";

            vectorshell[j] = val;

            presentaIJ(largo, i, r);
            showVector(vectorshell);
            cout << "\x1b[A\x1b[2K";


        }
        distancia = distancia/2;
    }
    // cout << endl;
    // showVector(num);
    // cout << "\x1b[A\x1b[2K";

}

int main()
{
    shellsort(num);
}



// "\x1b[A\x1b[2K"