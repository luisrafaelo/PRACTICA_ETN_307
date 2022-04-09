#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main()
{
    string* Nombre = NULL; //Se inicializa el puntero (inicia en null)
    string* Edad = NULL; //Se inicializa el puntero (inicia en null)
//NULL es para dejar el puntero vacio, en caso de tener algun dato almacenado
    int tamanio ; //Se inicializa la variable
cout << "\n\n\t\tPractica 5 APUNTADORES\n\n";
    cout << "Cuantos Datos desea ingresar?\n\n";
    string entrada;
//string son secuencuas de caracteres guardados
    getline(cin, entrada); //Se asigna el valor ingresado

    tamanio = std::stoi(entrada); //Se transforma la entrada en número

    //Declaramos un arreglo del tamaño ingresado para los Nombres
    Nombre = new string[tamanio];

    //Declaramos un arreglo del tamaño ingresado para las edades
    Edad = new string[tamanio];

    cout << "\nPor favor ingrese la siguiente informacin: \n\n";
    for(int i = 0; i < tamanio; i++)
    {
        cout << "\n******* Datos " << i + 1 << "********\n";
        cout << "Nombre: ";
        //cin >> Nombre[i]; //No funciona con espacios
        getline(cin, Nombre[i]);
        cout << "Edad: ";
        //cin >> autores[i]; //No funciona con espacios
        getline(cin, Edad[i]);
    }

    //Liberamos la memoria de ambos punteros
    delete [] Nombre;
    delete [] Edad;
    Nombre = NULL;
    Edad = NULL;

    system("pause");

    return 0;
}
