#include <iostream>
using namespace std;
enum ERRORES { E_DIV = 500, W_NUM_PAR, W_DEN_PAR};

int main()
{
    int a , b;

    cout << " -- division solo de pares -- "<<endl<<endl;
    cout << " ingresa numero par a: "; cin>>a;
    cout << " ingresa numero par b : "; cin>>b;

    try
    {
        if (b == 0)
            throw 500;  
        if (a%2 !=0)
            throw 501;  
        if (b%2 !=0)
            throw 502;
            
        cout << " division a/b : "<< a/b<<endl<<endl;
    }
    catch (const int e) 
    {
        switch (e)
        {
            case E_DIV :        cout<<"Error: Division por cero"<<endl<<endl;  
                                b=1;
                                cout << " Division arreglada a/b : "<< a/b<<endl<<endl;
                                b=0;
                                break;
            case W_NUM_PAR :    cout<<"Warning: Numerador no es par"<<endl<<endl;   break;
            case W_DEN_PAR :    cout<<"Warning: Denominador no es par"<<endl<<endl;   break;
        }
    }
    

    cout << " sumar a+b : "<< a+b<<endl<<endl;
    cout << " -- FIN -- ";
    /* do code */
}
