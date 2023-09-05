// Unir 2 listas circulares simples:  lista L1 con L2 y muestra la L1 que es la final

#include <iostream>
#include <stdlib.h>
using namespace std;

struct nodo{
       int nro;        // en este caso es un numero entero
       struct nodo *sgte;
};

typedef struct nodo *TlistaC;

TlistaC lista1, lista2,  fin1, fin2;

void mostrarListas()
{
     TlistaC aux;
     aux = lista1;
     
     if(lista1!=NULL)
     {
          cout<<"\n\n Lista 1 :\n\n";           
          do
          {
               cout<<"  "<<aux->nro;
               aux = aux->sgte;
          }while(aux!=lista1);          
     }
     else
         cout<<"\n\n\tLista vacia...!"<<endl;
     
     aux = lista2;    
     if(lista2!=NULL)
     {
          cout<<"\n\n Lista 2 :\n\n";           
          do
          {
               cout<<"  "<<aux->nro;
               aux = aux->sgte;
          }while(aux!=lista2);          
     }
     else
         cout<<"\n\n\tLista vacia...!"<<endl;     
}

void insertar(TlistaC &lista, TlistaC &fin, int valor)
{
     TlistaC q;
     q = new(struct nodo);
     q->nro = valor;
     
     
     if(lista==NULL)
     {
          lista = q;
          lista->sgte = lista;
          fin = q ;          
     }
     else
     {
          fin->sgte = q;
          q->sgte = lista;
          fin = q;
     }
}

void ingresarListas()
{
     int tam1, tam2, dato;
     
     cout<<"\n Tamanio de lista 1 : "; cin>> tam1;
     cout<<endl;
     
     for(int i=0; i<tam1; i++)
     {
          cout<<"\tElemento "<<i+1<<": ";   cin>> dato;
          insertar(lista1, fin1, dato);  
     }
     
     cout<<"\n Tamanio de lista 2 : "; cin>> tam2;
     cout<<endl;
     
     for(int i=0; i<tam2; i++)
     {
          cout<<"\tElemento "<<i+1<<": ";   cin>> dato;
          insertar(lista2, fin2, dato);  
     }
}

void unirListas()
{
     fin1->sgte = lista2;
     fin2->sgte = lista1;
     
     cout<<"\n\n\tListas circulares L1 y L2 unidas..."<<endl;
}

void mostrarLista1()
{
     TlistaC aux;
     aux = lista1;
     
     if(lista1!=NULL)
     {
          cout<<"\n\n Lista 1 :\n\n";           
          do
          {
               cout<<"  "<<aux->nro;
               aux = aux->sgte;
          }while(aux!=lista1);          
     }
     else
         cout<<"\n\n\tLista vacia...!"<<endl;
}
void menu()
{
    cout<<"\n\t\tUNIR LISTAS CIRCULARES\n\n";
    cout<<" 1. INGRESAR LISTAS                  "<<endl;
    cout<<" 2. MOSTRAR LISTAS                   "<<endl;
    cout<<" 3. UNIR LISTAS                      "<<endl;
    cout<<" 4. MOSTRAR LISTA 1                  "<<endl;
    cout<<" 5. SALIR                            "<<endl;

    cout<<"\n INGRESE OPCION: ";
}

/*                        Funcion Principal
---------------------------------------------------------------------*/
int main()
{
    TlistaC lista = NULL;
    int op;     // opcion del menu
    
    TlistaC lista1 = lista2 = NULL;
    do
    {
        menu();  cin>> op;
        switch(op)
        {
            case 1:
                 ingresarListas( );
            break;
            
            case 2:
                 mostrarListas();
            break;
            
            case 3:
                 unirListas();
            break;
            
            case 4:
                 mostrarLista1();
            break;
                 
        }
        cout<<endl<<endl;
    }while(op!=5);
   return 0;
}