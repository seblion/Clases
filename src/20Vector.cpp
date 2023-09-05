#include <iostream>
#include <vector>
using namespace std;

void defVectorInt()
{
    int num[] ={2,8,9,5};
    vector<int> vNumero;  // ={2,8,9,5};

    vNumero.push_back(12);
    cout<<endl<<"vNumero:" <<endl;
    for (int n : vNumero)
        cout<<n <<" ";
    
    cout<<endl<<"num:" <<endl;
    num[4]=12;
    for (int n : num)
        cout<<n <<" ";
}
void defVectorIntOpc()
{
    vector<int> vRepetido(5,30); // {30, 30, 30, 30, 30 }
    for (const int& n : vRepetido)
        cout<<n <<" ";
}
void defVectorString()
{
    string str;
    vector<string> vNombres ={"pepe", "juan", "ana", "lucia" };
    
    for (int i = 0; i < 3; i++)
    {
        cout<<"AGREGAR un nombre:";
        cin>>str;
        vNombres.push_back(str);
    }
        
    for (string s : vNombres)
        cout<<s << ", "; 
    
    cout<<endl<<"ELIMINAR 2 nombres"<<endl;
    vNombres.pop_back();
    vNombres.pop_back();

     for (string s : vNombres)
        cout<<s << ", "; 
    
    cout<<endl<<"ACCEDER ";
    cout<<endl<<vNombres[2];
    cout<<endl<<vNombres.at(2);  //when out range: throw excep. 
    vNombres.at(2)="ANA";
    vNombres[1]="JUANA";
    cout<<endl<<vNombres.at(1);  
    cout<<endl<<vNombres.at(2);  
}
void iterarVector()
{
    vector<int> num = {1, 2, 3, 4};
    vector<int>::iterator iter;

    iter = num.begin();     // apuntar al inicio  iter --> num[0]
    cout << "num[0] = " << *iter << endl;
    iter++;
    cout << "num[1] = " << *iter << endl;

    iter = num.begin()+2; 
    cout << "num[2] = " << *iter << endl;

    iter = num.end()-1;     // apuntar al inicio  iter --> num[3]
    cout << "num[3] = " << *iter << endl;

    cout << "use iterator for loop" << endl;
    for (iter = num.begin(); iter != num.end(); ++iter) 
        cout << *iter << "  ";

    // EXTRAS
    cout << "\nSize :       " << num.size();
    cout << "\nCapacity :   " << num.capacity();
    cout << "\nMax_Size :   " << num.max_size();

    if (num.empty())
        cout << "\n num is empty";
    else
        cout << "\n num is not empty";
    
    // Shrinks the vector
    num.shrink_to_fit();
    cout << "\n num elements are whit shrink_to_fit() ";
    for (auto it = num.begin(); it != num.end(); it++)
        cout << *it << " ";

    // inserts at the beginning
    cout << "\n inserts at the beginning whit emplace" <<endl;
    num.emplace(num.begin(), 5);
    num.emplace(num.begin() + 3, 5);
    num.emplace(num.end(), 5);     // num.emplace_back(20);
    for (auto it = num.begin(); it != num.end(); it++)
        cout << *it << " ";

    num.clear();
    cout << "\n num.clear" <<endl;
    for (auto it = num.begin(); it != num.end(); it++)
        cout << *it << " ";
}
int main()
{
    // defVectorInt();

    // - [ok] Agregar elementos
    // - [ok] Elementos de acceso
    // - [ok] Cambiar elementos
    // - [ok] Quitar elementos
    //defVectorString();

    iterarVector();

    cout<<endl;
    return 0;
}