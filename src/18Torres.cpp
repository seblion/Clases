#include <iostream>
#include <windows.h>
#include <iomanip>
using namespace std;

#define NIVEL 4
               //  0 1 2 3 
int TA[NIVEL]; //={4,3,2,1}    TA[0]-->4    TA[2]-->2
int TB[NIVEL]; //={0,0,0,0} 
int TC[NIVEL]; //={0,0,0,0} 
enum color { azul = 1, verde, turqueza, rojo, rosa, amarillo };
string setColor(color c)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
    return "";
}

string drawNivelTorre(const int nroDisk){
    string space= string(NIVEL-nroDisk, ' '), disk= string(nroDisk, '-');
    return space + disk +"|"+ disk + space;
}
int getTopDisco(int torre[])
{
    int i = 0;
    for (; i < NIVEL; i++)
        if (torre[i]==0)  
            break;
    return i;
}
void moveDisco(int torreIni[], int torreFin[])
{
    int ini= getTopDisco(torreIni), fin= getTopDisco(torreFin);
    if (ini>0)
        ini--;

    torreFin[fin]=torreIni[ini];
    torreIni[ini]=0;
}
void drawTorres(){
    cout<< "\x1B[2J\x1B[H" << setColor(rojo) << endl
        << setw(20) << "TORRE DE HANOI" 
        << endl <<endl << setColor(amarillo);
    for (int n = NIVEL - 1; n >= 0; n--) 
        cout<<drawNivelTorre(TA[n]) <<drawNivelTorre(TB[n]) <<drawNivelTorre(TC[n]) <<endl ; 
    cout<< setw(5)<<"A"<<setw(9) <<"B"<<setw(9) <<"C" << endl << endl;
}
void testShowMatriz()
{
    cout<<endl<<"TA:  ";    
    for (auto &&n : TA)
        cout<<n <<", ";
    cout<<"    TOP: " << getTopDisco(TA);

    cout<<endl<<"TB:  ";        
    for (auto &&n : TB)
        cout<<n <<", ";
    cout<<"    TOP: " << getTopDisco(TB);

    cout<<endl<<"TC:  ";    
    for (auto &&n : TC)
        cout<<n <<", ";
    cout<<"    TOP: " << getTopDisco(TC);

    cout<<endl<<endl;
}
bool validarIngreso(string opc)
{
    for (auto &&torre : {"a","b","c"})
        if (opc == torre)
            return true;
    return false;    
}
bool jugar()
{
    int *TI, * TF;  // int TA[NIVEL] --> TA[] --> *TA
    string torreIni="", torreFin="";
    do 
    {
        try
        {
            cout << setColor(azul) <<endl <<"(x) para salir" <<endl;
            cout<< "(?) Sacar disco de la TORRE: ";
            getline(cin, torreIni);
            cout<< "(?) Poner disco en la TORRE: ";
            getline(cin, torreFin);
            cin.clear();
            if (   torreIni == "x" || torreFin ==  "x")
                exit(0);  
            if (   torreIni != torreFin 
                   &&  validarIngreso(torreIni) // --> {a,b,c}
                   &&  validarIngreso(torreFin) )
                break;
            throw invalid_argument("Opc no valida");
        }
        catch (...) {
            torreIni = torreFin ="";
            cout <<setColor(rojo) <<":(  Opcion no valida... \n ";
        }
    }while (true);
    
    if(torreIni == "a") TI =TA;  
    if(torreIni == "b") TI =TB;  
    if(torreIni == "c") TI =TC;  

    if(torreFin == "a") TF =TA;  
    if(torreFin == "b") TF =TB;  
    if(torreFin == "c") TF =TC;  

    moveDisco( TI,TF );
    drawTorres();
    return true;
}

int main()
{
    int disco = NIVEL;
    for (int i = 0; i < NIVEL; i++)
    {
        TA[i] = TB[i] = TC[i] = 0;
        TA[i] = disco--;
    }

    drawTorres();
    while (jugar());
    //---------------------------------
    // // testShowMatriz();


    
    // // TB[0] = TA[3];
    // // TA[3] = 0;
    // moveDisco( TA,TB );
    // drawTorres();
    // // testShowMatriz();
    // getchar();

    // // TC[0] = TA[2];
    // // TA[2] = 0;
    // moveDisco( TA,TC );
    // drawTorres();
    // // testShowMatriz();
    // getchar();

    // // TC[1] = TB[0];
    // // TB[0] = 0;
    // moveDisco( TB,TC );
    // drawTorres();
    // // testShowMatriz();
    // getchar();


    // moveDisco( TA,TB );
    // drawTorres();
    // getchar();


    // moveDisco( TC,TA );
    // drawTorres();
    // getchar();

    // moveDisco( TC,TB );
    // drawTorres();
    // getchar();

    // moveDisco( TA,TB );
    // drawTorres();
    // getchar();

    // moveDisco( TA,TC );
    // drawTorres();
    // getchar();
    // cout<<endl;
    return 0;
}
