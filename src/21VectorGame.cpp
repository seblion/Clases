/**
 * ©2023 pat_mic, All Rights Reserved.
 * juego : piedra papel o tijera
 * @version: 1.0
 * @author : pat_mic
 * @date   : 2023.07.30
 **/

#include <iostream>
#include <windows.h>
#include <vector>
using namespace std;

const string CLS ="\x1B[2J\x1B[H";
enum color { azul = 1, verde, turqueza, rojo, rosa, amarillo };
string setColor(color c)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
    return "";
}

int main()
{
    int jugador=-1, compu;
    vector<string> menu = { "Piedra", "Papel", "Tijera", "Salir" };
    do
    {
        cout<<CLS << endl << setColor(rojo)
        <<" -- JUGEMOS A QUE PIERDES --"
        <<setColor(azul);
        for (string m : menu)
            cout<<endl<<++jugador <<". "<<  m;
        try
        {
            string s="";
            jugador=-1;
            cout<<setColor(azul) <<endl<<  "(?) Elige: ";
            cin>>s;
            jugador= stoi(s);
            if(jugador == 3)  exit(0);
            if(jugador > 0 && jugador > 2)
                throw invalid_argument("Opc no valida");
            compu = rand()%3;
            
            cout<<setColor(amarillo)
                <<endl<< "Jugador: "<< menu[jugador]
                <<endl<< "Compu  : "<< menu[compu];
            if (jugador == compu)  
                cout<<endl<< "(- -) EMPATE";
            else
                ((( jugador > compu) && (compu != 0))  || ((jugador == 0) && (compu == 2)))
                ? cout<<endl<< "(*o*) GANASTE"
                : cout<<endl<< "(´-´) PERDISTE";
            
            cout<<endl<<endl<<"Deseas salir:  << Press 's' >> ";
            cin>>s;
            if(s == "s")  exit(0);
        }
        catch(...)
        {
            cout<< setColor(rojo)
                << ":( Ingresa un numero" <<endl;
        }
    } while (true);
    cout<<endl;
    return 0;
}
