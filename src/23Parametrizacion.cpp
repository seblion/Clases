#include <iostream>	
using namespace std;

void parametrosPorValor(int a, int b, int c)
{
    c= a + b;
    a = 0;
    b = 0;
    cout << "parametrosPorValor c: " << c << endl;
}

void parametrosPorReferencia(int a, int b, int &c)
{
    c= a + b;
    a = 0;
    b = 0;
    cout << "parametrosPorReferencia c: " << c << endl;
}


int suma(int a , int b)  // solo retorna un valor
{
    return a+b;
}

void encerar(int &a , int &b, int &c)  // solo retorna un valor
{
    a= 0;
    b= 0;
    c= 0;
}

int main()
{ // ver diagrama : desing/paramatro
    int a= 1,  b=2,  c=0;
   
    cout << "parametrosPorValor" <<endl;
    parametrosPorValor(a,b,c);  // parametros por valor
    cout << "main a: " << a <<endl;
    cout << "main b: " << b <<endl;
    cout << "main c: " << c <<endl;
    
    cout << "parametrosPorReferencia" <<endl;
    parametrosPorReferencia(a,b,c);  // parametros por referencia
    cout << "main a: " << a <<endl;
    cout << "main b: " << b <<endl;
    cout << "main c: " << c <<endl;


    cout << "suma" <<endl;
    c= suma(a,b);
    cout << "main c: " << c <<endl;

    cout << "encerar" <<endl;
    encerar(a,b,c);
    cout << "main a: " << a <<endl;
    cout << "main b: " << b <<endl;
    cout << "main c: " << c <<endl;

    int x=12 , y=34 , z=12;
    cout << "encerar" <<endl;
    encerar(x,y,z);
    cout << "main x: " << x <<endl;
    cout << "main y: " << y <<endl;
    cout << "main z: " << z <<endl;
}