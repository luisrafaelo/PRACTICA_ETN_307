#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main()
{
    int cols = 2; //El número de columnas es fijo (sólo título y autor)

    string** Datos; //Si inicializa la matriz (punteros de punteros)
//CUANDO tiene dos '*' es para indicar que hay un apuntador dentro
    int tamanio ; //Se inicializa la variable
cout << "\n\n\t\tPractica 5 APUNTADORES\n\n";
    cout << "Cuantos Datos desea ingresar?\n\n";

    string entrada;

    getline(cin, entrada); //Se asigna el valor ingresado

    tamanio = stoi(entrada); //Se transforma la entrada en número

    Datos = new string*[tamanio];//Se asigna el número de filas según el usuario

    cout << "\nPor favor ingrese la siguiente informacion: \n\n";
    string Nombre ,Edad, Estado;
    for(int i = 0; i < tamanio; i++)
    {
        Datos[i] = new string[cols]; //Cada fila contendrá dos columnas
        //Notar que cols pudo haber sido ingresada por el usuario también

        cout << "\n******* Datos " << i + 1 << "********\n";
        cout << "Nombre: ";
        getline(cin,Nombre);
        cout << "Edad: ";
        getline(cin,Edad);
        //cout << "Estado Civil: ";
        //getline(cin,Estado);
        Datos[i][0] = Nombre;
        Datos[i][1] = Edad;
        //Datos[i][2] = Estado;
    }

    //Para liberar la memoria debemos recorrer fila por fila primero.
    for (int i = 0; i < tamanio; ++i)
    {
        delete [] Datos[i]; //Cada fila de libros es otro array de punteros
        //Por eso son punteros a punteros
    }

    //Luego de limpiar las columnas, quitamos la fila única que quedó
    delete [] Datos;


    system("pause");

    return 0;
}
