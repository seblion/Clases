#include <iostream>
#include <unistd.h>
using namespace std;
#define SLEEP 70000

string  ladoIzq[]   = { "Obs","Lobo","Cape","Uvas"}, 
        ladoDer[]   = { "","","",""},
        actorCruza  = "";
bool obsEstaIzq     = true;
int  opcSeleccionada= -1, anchoRIO  = 20, Obs=0, Lobo=1, Cape=2, Uvas=3;

string aguaRio(int len) 
{
    string str=""; 
    for (int i = 0; i < len; i++)
        str += ". ";
    return str;
}
string getActores(const string arrActores[]) 
{
    string str=""; 
    for (int i = 1; i < 4; i++)
            str += " " + arrActores[i];
    return str;    
}
void validarReglas()
{
    string msg="";
    bool todosCruzan= (  !ladoDer[Obs].empty() && !ladoDer[Lobo].empty() 
                      && !ladoDer[Cape].empty() && !ladoDer[Uvas].empty() );
    bool lobCap     = (obsEstaIzq)
                    ? (!ladoDer[Lobo].empty() &&  !ladoDer[Cape].empty())
                    : (!ladoIzq[Lobo].empty() &&  !ladoIzq[Cape].empty());
    bool capUva     = (obsEstaIzq)
                    ? (!ladoDer[Cape].empty() &&  !ladoDer[Uvas].empty())
                    : (!ladoIzq[Cape].empty() &&  !ladoIzq[Uvas].empty());
    msg  += (lobCap)? ">> MarchoooOO0 Caperusita" : "";
    msg  += (capUva)? ">> MarchoooOO0 las uvas"   : "";
    msg  =  (todosCruzan) ? ">> LO HAZ LOGRADO CAMPEON...!" : msg;
    if (!msg.empty())
    {
        cout << "OVER GAME" << endl << msg << endl;
        exit(0);
    }
}
void showBarcaRio(int i, const string barca) 
{
    cout << "\r" + getActores(ladoIzq) + aguaRio(i) + barca +  aguaRio(anchoRIO - i) + getActores(ladoDer);
    usleep(SLEEP);
}
void showNavegacion() 
{
    string barca  = " \\_patmic_,_?_/ ";
    barca.replace(12,1,actorCruza);
    cout << "\x1B[2J\x1B[H";
    if (opcSeleccionada < 0 )
        showBarcaRio(0, barca);
    if ((opcSeleccionada >= 0 ) && obsEstaIzq  )
        for (int pos = anchoRIO; pos >= 0 ; pos--)  
            showBarcaRio(pos, barca);
    if ((opcSeleccionada >= 0 ) && !obsEstaIzq )
        for (int pos = 0; pos <= anchoRIO; pos++)  
            showBarcaRio(pos, barca);
}
int main()
{
    do{
        showNavegacion();
        cout <<"\n\n0 Solo  \n1 Lobo  \n2 Caperucita  \n3 Uvas  \n4 SALIR\n";
        do{
            try
            {
                string s="";
                cout<< "> Cruzar: ";
                cin >> s;
                opcSeleccionada = stoi(s);
                actorCruza = (obsEstaIzq) ?  ladoIzq[opcSeleccionada] : ladoDer[opcSeleccionada];
                if (actorCruza.empty())
                    throw invalid_argument("No hay actor");
            } catch (...) {
                actorCruza      = "";
                opcSeleccionada = -1;  
                cerr  <<"  :(  Opcion no valida... \n";
            }
            if (opcSeleccionada > 3)  exit(0);
        }while(opcSeleccionada<0);
        obsEstaIzq =!obsEstaIzq;
        ladoIzq[Obs] = ladoIzq[opcSeleccionada] = ladoDer[Obs] = ladoDer[opcSeleccionada] = "";
        if(obsEstaIzq){
            ladoIzq[Obs] = "Obs";
            ladoIzq[opcSeleccionada]  = actorCruza;
        }
        else{
            ladoDer[Obs] = "Obs";
            ladoDer[opcSeleccionada]  = actorCruza;
        }
        validarReglas();
    }while(true);
    return 0;
}