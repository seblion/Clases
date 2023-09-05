//#include <stdio.h>  
#include <iostream>
#include <string.h>
#include "../lib/patString.h"

using namespace std;

int main()
{
    //std::cout << "Hi pat_mic";
    //printf("\nhola en c");

    int a;
    char c;
    char palabra[12];
    string str;

    cout << "Hi pat_mic"<< endl;

    cout<< "Ingresa nro: ";
    cin >> a;
    //scanf("%i",&a);

    cout<< "Ingresa un caracter: ";
    cin >> c;

    //cout<< "Ingresa una frase: ";
    ppGetString("Ingresa una frase: ",str);
    //cin >> str;

    cout << "El nro ingresado es: " << a << endl;
    cout << "El caracter ingredado: " << c << endl;
    cout << "Tu frase es: " << ppToCapitalStr(ppTrim(str)) << endl;
    cout << endl;
    return 0;
}
