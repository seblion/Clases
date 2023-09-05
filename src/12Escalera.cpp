#include <iostream>
#include <string>
using namespace std;

void showEscalera(int nivel)
{
    string strEspacio ="", strGrada = "|_";
    
    for(int i=1; i<= nivel; i++)
    {
        cout << strEspacio << strGrada << endl;
        strEspacio += "  ";
    }
}

void showEscaleraSigno(int nivel)
{
    string strEspacio ="", strGradaPos = "|_+_", strGradaNeg = "|_-_";
    
    for(int i=1; i<= nivel; i++)
    {
        cout << strEspacio << ((i%2==0) ? strGradaNeg : strGradaPos )<< endl;
        strEspacio += "    ";  //  strEspacio= strEspacio+ "    ";
    }
}

string getEspacio(int nroEspacio)
{
    string str="";
    for (int i = 0; i < nroEspacio; i++)
        str += "  ";
    return str;
}

void showEscaleraDoble(int nivel)
{
    for (int i = 0; i < nivel; i++)
    {
        if(i==0)
            cout<< getEspacio( nivel ) << "  __" << endl;

        cout    << getEspacio( nivel-i ) << "_|"    // genera grada izq
                << "  "                             // esp del centro
                << getEspacio( i*2 ) << "|_"        // genera grada der
                << endl;
    }
}

int main()
{
    int nivel =10;
    showEscaleraDoble(nivel);
    cout << endl;
    return 0;
}

