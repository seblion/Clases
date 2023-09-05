#include <iomanip>
#include <unistd.h>
#include <iostream>

using namespace std;
#define SLEEP 50000

string setBar(string c, int size)
{
    string str=""; 
    for (int i = 0; i < size; i++)
        str += c;
    return str;
}

void showWaiting()  // *.*
{
    for (int i = 0; i <= 30; i++)
    {
        string str ="ooo"; 
        cout << "\r" << str.replace(i%3,1,"O") << " " ;
        usleep(SLEEP*5);
    }
}

void showLoadingSpinner()
{
    char c[] ="\\|/- ";
    for (int i = 0; i <= 100; i++)
    {   //<<fixed<<setprecision(3)    <<setfill('0') 
        cout << "\r" << c[i%5] << " " <<setw(3) <<i << " % ";
        usleep(SLEEP);
    }
}

void showBarLoading(int size)
{
    for (int i = 0; i <= 100; i++)
    {   
        cout << "\r[" << setBar("=", size).replace(i%size,1,"-") << "] " <<setw(3) <<i << " % ";
        usleep(SLEEP);
    }
}

void showWaitingLoading(int size)
{
    bool avanzar=false;
    for (int i = 0; i <= 100; i++)
    {   
        if(i%size==0)
            avanzar =!avanzar;
        int ix = (avanzar)? i%size: (size - i%size);
        cout << "\r[" << setBar(" ", size).replace(ix,0,"<>") << "] " <<setw(3) <<i << " % ";
        usleep(SLEEP);
    }
}

void showFace()
{
     for (int i = 0; i < 15; i++)
     {
        cout << "\x1B[2J\x1B[H";
        string desplazar = setBar("  ",i);
        cout << "\r" << desplazar << "   \\|||/  " << endl;
        cout << "\r" << desplazar << "   (> <)   " << endl;
        cout << "\r" << desplazar << "ooO-(*)-Ooo" << endl;
        usleep(SLEEP*5);
     }
}

int main()
{
    showFace();
    showWaiting();
    cout<< endl;
    showLoadingSpinner();
    cout<< endl;
    showBarLoading(20);
    cout<< endl;
    showWaitingLoading(20);
    cout<< endl;
    return 0;
}

/*
Gui�n, 
conceptualiza�n
codigo
    - explicar lib
    - main
    - metodos
    - ejecucion
*/
