#include <iostream>
using namespace std;
 
struct nodo {
    int nro;
    struct nodo *sgte;
};

struct cola {
    nodo *delante;
    nodo *atras  ;
};

void encolar( struct cola &q, int valor )
{
     struct nodo *aux = new(struct nodo);
     aux->nro = valor;
     aux->sgte = NULL;
     
     if( q.delante == NULL)
         q.delante = aux;   // encola el primero elemento
     else
         (q.atras)->sgte = aux;
         
     q.atras = aux;        // puntero que siempre apunta al ultimo elemento
     cout <<" << encolado >> " <<endl;
}

void desencolar( struct cola &q )
{
     int num ;
     struct nodo *aux ;
     
     aux = q.delante;      // aux apunta al inicio de la cola
     num = aux->nro;
     q.delante = (q.delante)->sgte;
     delete(aux);          // libera memoria a donde apuntaba aux
     
     cout <<" << desencolado >> " << num <<endl;
}

void muestraCola( struct cola q )
{
    struct nodo *aux;
    aux = q.delante;

    cout << "<<  \t";
    while( aux != NULL )
    {
        cout << aux->nro <<"\t";    //aux[]->
        aux = aux->sgte;            //[1]->[5]->[]->[]->[]->[]->[]->NULL
    }  
    cout << " << "<<endl;
}

void vaciaCola( struct cola &q)
{
     struct nodo *aux;
     while( q.delante != NULL)
     {
            aux = q.delante;
            q.delante = aux->sgte;
            cout <<"<< "<< aux->nro <<"\t";
            delete(aux);
     }
     q.delante = NULL;
     q.atras   = NULL;
     cout<<"\n\n\t\t Cola despachada...\n\n";
}

int menu()
{
    int op;
    cout<<endl
        <<" 1. ENCOLAR       "<<endl
        <<" 2. DESENCOLAR    "<<endl
        <<" 3. VACIAR COLA   "<<endl
        <<" 4. SALIR         "<<endl
        <<" INGRESE OPCION:  ";
    cin>> op;
    if (op==4)  exit(0);
    return op;
}

int main()
{
    struct cola q;
    q.delante = NULL;
    q.atras   = NULL;
    int valor;  // numero a encolar //  <pop>---<desencolar>
    do
    {
        cout<<"\n\n\n\t  FUNCIONALIDAD COLA : \t";
        if(q.delante==NULL)
            cout<<" <<    vacia    << ";
        else   
            muestraCola( q );
        switch(menu())
        {
            case 1: cout<< "\n NUMERO A ENCOLAR: "; cin>> valor;
                    encolar( q, valor );  //q.encolar(1);
                    break;
            case 2: desencolar( q );
                    break;
            case 3: vaciaCola( q );
                    break;
        }
    }while(true);
    return 0;
}