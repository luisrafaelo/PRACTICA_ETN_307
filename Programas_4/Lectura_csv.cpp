#include <iostream>
#include <sstream>
#include <fstream>
#include <string.h>
#define NOMBRE_ARCHIVO "titanic.csv"
using namespace std;

int main()
{
	int count=0;
    ifstream archivo(NOMBRE_ARCHIVO);
    string linea;
    char delimitador = ',';
    // Leemos la primer línea para descartarla, pues es el encabezado
    getline(archivo, linea);
    // Leemos todas las líneas
    while (getline(archivo, linea))
    {

        stringstream stream(linea); // Convertir la cadena a un stream
        string num,PassengerId,Survived,Pclass,Apellido,Name,Sex,Age,Sibsp,Parch,Ticket,Fare,Cabin,Embarked
;
        // Extraer todos los valores de esa fila
        getline(stream, num, delimitador);
        getline(stream, PassengerId, delimitador);
        getline(stream, Survived, delimitador);
        getline(stream, Pclass, delimitador);
        getline(stream, Apellido, delimitador);
        getline(stream, Name, delimitador);
        getline(stream, Sex, delimitador);
        getline(stream, Age, delimitador);

        // Imprimir
        cout << "\n______________________________" << endl;
        
    	cout << "Numero: " << num << endl;
		cout << "Pasajero Id: " << PassengerId << endl;
		cout << "Superviviente: " << Survived << endl;
		cout << "Clase: " << Pclass << endl;	
        cout << "Apellido: " << Apellido << endl;
        cout << "Nombre: " << Name << endl;
        cout << "Sexo: " << Sex << endl;
        cout << "Edad: " << Age << endl;
       
    }

    archivo.close();
}
