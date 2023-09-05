#include <iostream>
#include <unistd.h>
#include <iomanip>
#include "../lib/patColor.h"
using namespace std;
#define SLEEP 1000000

int n[] = {3,2,1,8,5,6,9,7};
int tmp;
void showArray(int i, int j)
{
    cout<< CLS_CLEAR    << endl << endl 
        << COLOR_GREEN  << "  " << string(i*3,' ') << "i"
        << COLOR_BLUE   << endl << "[ ";
    for (int k = 0; k < 8; k++)
    {
        if(k==i)    cout<< COLOR_GREEN;
        if(k==j)    cout<< COLOR_YELLOW;   
        cout<<n[k]<<"  "<< COLOR_BLUE;
    }
    cout<<"]" << endl
        << COLOR_YELLOW << "  " << string(j*3,' ') << "j"<< endl;
    usleep(SLEEP);
}

void bubbleSort()
{
    showArray(0,0);
    for (int i = 0; i < 8; i++)
        for (int j = i; j < 8; j++)
        {
            showArray(i, j);
            if(n[i] > n[j])
            {
                cout<<endl<< string(i*3,' ')<< COLOR_RED
                    <<"SWAP( "<<n[i] <<" > " << n[j]<< " )" << endl;
                getchar();
                tmp =n[i];
                n[i]=n[j];
                n[j]=tmp;
            }
        }    
}

void selectionSort() 
{
    for(int i = 0; i < 8; i++) 
    {
        int min = i;
        for(int j = i + 1; j < 8; j++) 
        {
            showArray(i,j);
            if (n[min] > n[j]) 
            {
                min = j;
                cout<<endl<< COLOR_RED <<"min = "<<n[min]  <<endl;
                usleep(SLEEP);
            }
        }
        cout<<endl<< COLOR_RED <<"min = "<<n[min]  <<endl;
        cout<<"SWAP( "<<n[i] <<" > " << n[min]<< " )" << endl;
        getchar();
        
        tmp    = n[i];
        n[i]   = n[min];
        n[min] = tmp;
    }
    showArray(0,0);
}

int main()
{
    //bubbleSort();
    selectionSort() ;
    return 0;
}
