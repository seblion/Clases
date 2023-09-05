#include <iostream>
#include <fstream>
#include <iomanip>
#include "../lib/ppString.h"
using namespace std;
const string pathCliente = "../data/cliente.csv";
const string pathMascota = "../data/mascotas.csv";

struct Mascota      // una generalidad
{
    int idCliente;
    string tipo;
    string nombre;
    //...
};
struct Cliente      // generalidad  --> (hombres, mujeres, yyasd) --> pepe, juan
{
    int ID;                       //[1]                 [2]
    string cedula;
    string nombre;               // pepe             // juan
    vector<Mascota> mascotas;       // lasi, botas,..   // lupe,..
};
vector<Cliente> clientes;

Mascota mascotaDomesticas[7];
int indexMascota=0;

void getMascota(string lineArchivo, char del)
{
    //struct Mascota m;
    // stringstream ss(lineArchivo);
    // string word;
    // int i=1;
    // while (!ss.eof()) {    
        
    //     getline(ss, word, del); // perro;max ito
    //     if (i == 1 )
    //         m.tipo = word;
    //         //cout << "Tipo Mascota: " <<word << endl;
    //     if (i == 2 )
    //         m.nombre = word;
    //         //cout << "Nombre Mascota: " <<word << endl;
    //     // m.edad = 12; 
    //     i++;
    // }
    // mascotaDomesticas[indexMascota++] = m;
    // cout << "Mascota.tipo: "   <<m.tipo << endl;
    // cout << "Mascota.nombre: " <<m.nombre << endl;
}
void showMascota()
{
    cout <<endl <<setw(10) <<"TIPO" <<"\t NOMBRE \n";
    for (auto &&m : mascotaDomesticas)
        cout <<setw(10)<< m.tipo  << " \t " <<m.nombre <<endl;
}
void addMascota()
{
    struct Mascota m;
    cout <<endl <<"Ingresa el tipo_mascota  : ";
    getline(cin, m.tipo);
    cout <<"Ingresa el nombre_mascota: ";
    getline(cin, m.nombre);
    mascotaDomesticas[indexMascota++] = m;
}

bool readArchivo(string pathFileName)  // pathFileName  -->  "./data/alumnos.txt"
{
    fstream f;
    string line;

	cout << "readArchivo:" << pathFileName << endl;
    f.open(pathFileName, ios_base::in);  // in  out app   (in-> leer, out-> crea & escribe, app: leer / agregar / crea)
    if ( !f.is_open() ) 
		cout << "Error al abrir el archivo: " << pathFileName << endl;
	else
    {
        while( !f.eof() ) 
		{
			getline( f, line );
			cout << line << endl;
		}
        return true;
    }
	f.close();
    return false;
}
bool readMascota()  // pathMascota  -->  "./data/alumnos.txt"
{
    fstream f;
    string line;

	cout << "readArchivo:" << pathMascota << endl;
    f.open(pathMascota, ios_base::in); 
    if ( !f.is_open() ) 
    {
        cout << endl << "Error al abrir el archivo: " << pathMascota << endl;
        return false;
    }
    getline( f, line );   // TIPO;NOMBRE
    while( !f.eof() ) 
    {
        struct Mascota m;
        vector<string> vDato;

        getline( f, line );   
        //getMascota(line, ';');
        vDato= SplitToVector(line,';');
        
        m.idCliente = stoi        (vDato.at(0));
        m.tipo      = ppToUpperStr  (vDato.at(1));
        m.nombre    = ppToCapitalStr(vDato.at(2));

        if (m.idCliente == 2)
            cout <<endl << " tipo:" << m.tipo  <<"   nombre:" << m.nombre;

        //cout << line << endl;
    }
	f.close();
    cout << endl << "lectura OK! " << endl;
    return false;
}
bool saveMascota(string pathFileName)  // pathFileName  -->  "./data/alumnos.txt"
{
    fstream f;
    string line;

	cout << "saveMascota:" << pathFileName << endl;
    f.open(pathFileName, ios_base::out);   // app
    if ( !f.is_open() ) 
    {
        cout << endl << "Error al salvar el archivo: " << pathFileName << endl;
        return false;
    }
    

    for (int i = 0; i < indexMascota; i++)
    {
        auto &&m = mascotaDomesticas[i];
        f << m.tipo  << ";" <<m.nombre <<endl;
        // -/ 20 % ...
    }
    // -/ 20 % ...
	f.close();
    cout << endl << "mascotas guardadas OK! " << endl;
    return false;
}

int main()
{
    // cout <<"---- alumnos  ----" << endl;
    // readArchivo("../data/alumnos.txt");
   
    cout <<"---- mascotas  ----" << endl;
    readMascota();
    addMascota();
    showMascota();
    saveMascota(pathMascota);

    cout <<endl;
    return 0;
    
    
}

/*
-------
TAREAS:
-------
- Archivo de mascotas :
    agregar encabezado: TIPO; RAZA; SEXO; EDAD; NOMBRE
    insertar 5 registros según encabezado

- struct Mascota
    agregar TIPO; RAZA; SEXO(char); EDAD(int); NOMBRE

- ajustar Mascota:
    getMascota()
    showMascota()
        + formato
    addMascota()
    readMascota()
        + saltar el encabezado: TIPO; RAZA; SEXO; EDAD; NOMBRE
    saveMascota()
        + no dejar lineas en blanco
        + agregar encabezado: TIPO; RAZA; SEXO; EDAD; NOMBRE
        + al guardar un waiting/espera visual.. (\ 30...100 %)

- agregar procedimiento/funcion:
    menu()
     1. recurpar mascoptas --> readMascota() -- getMascota() --> guardar en el array 
     2. agregar Mascota
     3. presentart Mascota
     4. salvar mascotas  -->  saveMascota()
     5. Salir
    (?) Ingrese opc: (Ooo oOo ooO)     Ingrese opc:
        + try - catch
        + color
        + agregar un waiting/espera visual..
*/