#include <iostream>
#include <unistd.h>
#include <vector>
#include <random>
#define TIME 1000000

using namespace std;

vector <int> num = {1,8,5,2,7,4,9,6,3};

void showVector(const vector<int>& vec) {
    
    cout << "\r[";
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
    cout <<"\r ";
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
    
    for (int num : vectorshell)
    {
        cout << num << " ";
    }
    
    largo = vectorshell.size();
    int distancia = largo / 2;

    while (distancia > 0)
        {
        for (int i = distancia; i < largo; ++i) 
        {
            int val = vectorshell[i];
            int j = i;
            while (j >= distancia && vectorshell[j - distancia] > val) 
            {
                vectorshell[j] = vectorshell[j - distancia];
                j -= distancia;

                cout << "\x1b[A\x1b[2K" << i<< j;
                presentaIJ(largo, i, j);
                showVector(vectorshell);
                usleep(TIME / 2);
            }

            vectorshell[j] = val;

            cout << "\x1b[A\x1b[2K" << i<< j;;
            presentaIJ(largo, i, j);
            showVector(vectorshell);
            cout << "   Val en memoria:" << val << "  Distancia de comparacion:" << distancia;

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
