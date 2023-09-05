/*
*Nombre: Juan Sebastian Leon Espinosa
*Fecha: 09/08/2023
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <unistd.h>
#include <windows.h>
#include <cctype> 
#include <vector>
#include "..\lib\jlUtilities.h"
#include "..\lib\patColor.h"
#include "..\lib\patString.h"
#include "..\lib\patSerie.h"
#include "..\lib\patUtility.h"
#include "..\lib\utilitario.h"
using namespace std;
const string pathCliente = "../data/cliente.csv";
const string pathMascota = "../data/mascota.csv";


struct Mascota
{
    int idCliente;
    string tipo;
    string raza;
    char sexo;
    int edad;
    string nombre;
};
struct Cliente
{
    int ID;
    string cedula;
    string nombre;
    vector<Mascota> pets;
};

vector<Cliente> clientes;

//Procesos

bool validarID(int idIngresado)
{
    for (const auto& c : clientes)
            if(c.ID == idIngresado)
                return true;
    return false;           
}

bool readArchivo(string pathFileName)
{
    fstream f;
    string line;

    cout << "readArchivo:" << pathFileName << endl;
    f.open(pathFileName, ios_base::in);
    if (!f.is_open())
        cout << "Error al abrir el archivo:" << pathFileName << endl;
        else 
        {
            while(!f.eof())
            {
                getline(f, line);
                cout<< line << endl;
            }
            return true;
        }
        f.close();
        return false;

}

bool readCliente()
{
    fstream f;
    string line;

    cout << "readArchivo:" << pathCliente << endl;
    f.open(pathCliente, ios_base::in);
    if (!f.is_open())
        cout << "Error al abrir el archivo:" << pathCliente << endl;

    clientes.clear();
    
    getline(f, line);
    while(!f.eof())
    {
        struct Cliente c;
        vector<string> vDato;

        getline(f, line);
        vDato= SplitToVector(line, ';');

        c.ID       = stoi           (vDato.at(0));
        c.cedula    = ppToUpperStr  (vDato.at(1));
        c.nombre    = ppToCapitalStr(vDato.at(2));
       
        clientes.push_back(c);

        cout << "Cliente.ID: " <<c.ID << endl
            << "Cliente.cedula: " <<c.cedula << endl
            << "Cliente.nombre: " <<c.nombre << endl <<endl;
            
            
    }
    f.close();
    cout << endl << "lectura OK!" <<endl;
    return false;

}

bool readMascota()
{
    fstream f;
    string line;

    cout << "readArchivo:" << pathMascota << endl;
    f.open(pathMascota, ios_base::in);
    if (!f.is_open())
    {
        cout << "Error al abrir el archivo:" << pathMascota << endl;
        return false;
    } 
    getline(f, line);
    while(!f.eof())
    {
        struct Mascota m;
        vector<string> vDato;

        getline(f, line);
        vDato= SplitToVector(line, ';');

        m.idCliente = stoi          (vDato.at(0));
        m.tipo      = ppToUpperStr  (vDato.at(1));
        m.raza      = ppToCapitalStr(vDato.at(2));
        m.sexo      =               (vDato.at(3))[0];
        m.edad      = stoi          (vDato.at(4));
        m.nombre    = ppToCapitalStr(vDato.at(5));

         for (auto &c : clientes)
        {
            if (m.idCliente == c.ID)
            {
                c.pets.push_back(m);
                break; 
            }
        }
            cout << "Mascota.tipo: " <<m.tipo << endl
                 << "Mascota.raza: " <<m.raza << endl
                 << "Mascota.sexo: " <<m.sexo << endl
                 << "Mascota.edad: " <<m.edad << endl
                 << "Mascota.nombre: " <<m.nombre << endl <<endl;
    }
    f.close();
    cout << endl << "lectura OK!" <<endl;
    return false;

}

bool saveCliente()
{
    int cElem = 0;
    fstream f;
    string line;
    int tamClientes = clientes.size();
    cout << "saveCliente:" << pathCliente <<endl;
    f.open(pathCliente, ios_base::out);
    if(!f.is_open())
    {
        cout << endl << "Error al salvar el archivo: " << pathCliente <<endl;
        return false;
    }
    f << "ID;CEDULA;NOMBRE" <<endl;
    for (const auto& c : clientes)
    {  
        f << c.ID << ";" << c.cedula << ";" <<c.nombre;
        if (cElem!= (tamClientes-1))
            f <<endl;
        cargaCien(cElem,tamClientes);
        cElem++;
    }
    f.close();
    cout << endl << "clientes guardados OK!" << endl;
    return false;
}

void cantMascotas(int& cant)
{
    for (const auto& c : clientes)
        for (const auto& m : c.pets)
            cant++;
}

bool saveMascota()
{
    int nElem = 0;
    fstream f;
    string line;
    int cantM = 0;
    cantMascotas(cantM);

    cout << "saveMascota:" << pathMascota << endl;
    f.open(pathMascota, ios_base::out);
    if (!f.is_open())
    {
        cout << endl << "Error al salvar el archivo: " << pathMascota << endl;
        return false;
    }
    f << "ID_CLIENTE;TIPO;RAZA;SEXO;EDAD;NOMBRE" << endl;
    for (const auto& c : clientes)
    {        
        for (const auto& m : c.pets)
        {
            nElem++;
            f << m.idCliente << ";" << m.tipo << ";" << m.raza << ";" << m.sexo << ";" << m.edad << ";" << m.nombre;
            if (nElem != cantM ) 
            {
                f << endl;
            }  
            cargaC(nElem,cantM); 
        }
    }
    f.close();
    cout << endl << "mascotas guardadas OK!" << endl;
    return true;
}


void showCliente()
{
    cout << setColor(rosa) <<endl <<setw(10) <<"  ID\t" <<setw(15)<<"\t CEDULA \t" <<setw(10)<<"\t NOMBRE \n";
    cout << setColor(turqueza);
    for (const auto& c : clientes)
                cout <<endl <<setw(10)<<c.ID <<"\t" << setw(20)<<c.cedula << "\t" <<setw(25)<<c.nombre <<endl;
}


bool showMascota(int clienteID)
{
    for (const auto& c : clientes)
    {
        if(c.ID == clienteID)
        {
            cout <<setColor(turqueza) <<endl << "Cliente: " <<c.nombre <<endl; 
            if(c.pets.empty())
            {
                cout <<setColor(rojo) <<endl <<setw(10)<<"\t\tNO HAY MASCOTAS" <<endl;
                return false;
            }
        
            cout << setColor(rosa) <<endl <<setw(10) <<"  TIPO\t" <<setw(8)<<"\t RAZA \t" <<setw(10)<<"\t SEXO \t" <<setw(10)<<"\t EDAD \t"<<setw(10)<< "\t NOMBRE \n";
            cout << setColor(turqueza);
            for (const auto& m : c.pets)
                cout <<endl <<setw(10)<<m.tipo <<"\t" << setw(10)<<m.raza << "\t" <<setw(10)<<m.sexo << "\t" <<setw(10)<<m.edad<< "\t" <<setw(10)<<m.nombre <<endl;
            return true;
        }
    }
    return true;
}


void addCliente()
{
    struct Cliente c;
    fflush(stdin);

    do
    {
    getNumeroPositivo("Ingrese un nuevo ID: ", c.ID);
    if (validarID(c.ID))
        cout << "El ID ingresado ya esta en uso"<<endl;
    }while(validarID(c.ID));
    fflush(stdin);
    cout << "Ingrese cedula_cliente: ";
    getline(cin, c.cedula);
    cout <<endl << "Ingrese nombre_cliente:";
    string nombre;
    getline(cin, c.nombre);
    ppToCapitalStr(c.nombre);

    clientes.push_back(c);
}

void addMascota(int clienteID)
{
    struct Mascota m;
    fflush(stdin);
    m.idCliente = clienteID;
    cout <<endl << "Ingrese tipo_mascota:";
    getline(cin, m.tipo);
    cout <<endl << "Ingrese raza_mascota:";
    getline(cin, m.raza);
    cout <<endl;
    getSexo("(M/F)Ingrese sexo_mascota:", m.sexo);
    cout <<endl;
    getNumeroPositivo("Ingrese edad_mascota:", m.edad);
    cin.ignore();
    cout <<endl << "Ingrese nombre_mascota:";
    getline(cin, m.nombre);
    ppToCapitalStr(m.nombre);

    for (auto& c : clientes)
        if(c.ID == clienteID)
        {
            c.pets.push_back(m);
            break;
        }
}


int main()
{
    int opcCliente = 0;
    int idAgregar = 0;

    cout <<"---- mascotas ----" <<endl;
    int eleccion=0;
    int salir = false;
    do{
        menu(eleccion);
        fflush(stdin);
        switch (eleccion)
        {
            case 1: readCliente();
                break;
            case 2: readMascota();
                break;
            case 3: showCliente();
                break;
            case 4: getNumeroPositivo("Ingrese ID Cliente para ver sus mascotas:", opcCliente);
                    if(validarID(opcCliente))
                    {
                        showMascota(opcCliente);
                        break;
                    }
                    cout <<setColor(rojo)<< "No existe el ID ingresado" << endl << endl;
                break;
            case 5: addCliente();
                break;   
            case 6: getNumeroPositivo("Ingrese ID del cliente:", idAgregar);
                    if (validarID(idAgregar))
                    {
                        addMascota(idAgregar);
                        break;
                    }
                    cout <<setColor(rojo)<< "No existe el ID ingresado" << endl << endl;
                break;
            case 7:  saveMascota();
                 break;
            case 8:  saveCliente();
                break;
            case 9:  salir = true;
                break;
        }
        cout <<endl;
    }while (!salir);
    return 0;
}