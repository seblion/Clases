#include <iostream>

using namespace std;

void showArray(char *arr, int len){
    for (int i = 0; i < len; i++)
        cout << arr[i] << " ";
}
void showArray(int *arr, int len){
    for (int i = 0; i < len; i++)
        cout << arr[i] << " ";
}
void fillArrayPares(int *arr, int len)
{
    for (int i = 0; i < len; i++)
        arr[i] = i*2;
}
void fillArrayImpares(int *arr, int len)
{
    for (int i = 0; i < len; i++)
        arr[i] = i*2 +1;
}

int main()
{   
    int size = 10;
    int pares[size];
    int impares[size];
    char alfabeto[] = {'a','b','c','d','e','f','g','h','i','j'};

    fillArrayPares(pares, size);
    fillArrayImpares(impares, size);
    cout << endl << "Pares: " ;
    showArray(pares, size);

    cout << endl << "Impares: " ;
    showArray(impares, size);

    cout << endl << "alfabeto: " ;
    showArray(alfabeto, size);

    cout << endl;
    return 0;
}


//https://www2.eii.uva.es/fund_inf/cpp/temas/9_vectores/vectores_c.html