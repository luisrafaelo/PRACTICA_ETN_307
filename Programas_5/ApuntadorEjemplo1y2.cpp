/*
	Name: Apuntadores 
	Autores: Alberto Limachi Luis Rafael
	         Nina Mamani Itamar Esteban
	Description: Ejemplos de apuntadores para explicar su funcionamiento
*/
#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;
char StopApp;
void apuntador1();
void apuntador2();
int main()
{
	do{
	int opcion=0;
		cout << "\n\n\t\tPractica 5 APUNTADORES\n\n";		
	cout << "\n\tPRIMER EJEMPLO DE APUNTADORES'1";
	cout << "\n\tSEGUNDO EJEMPLO DE APUNTADORES'2'";
	cout << "\nDigite una opcion por favor:\n\n=>\t";
	cin >> opcion;
	switch (opcion)
	{
		case 1:
			cout<< endl;
			apuntador1();
			break;
		case 2:
			cout<< endl;
			apuntador2();
			break;	
	}
	cout <<endl;	
		
		cout<<"\nPara reiniciar la APP ingrese 'Y' (Si), si no quiere ingrese cualquier tecla\n";
        cin>>StopApp;
    }

    while(toupper(StopApp) == 'Y');
    return 0;
}
void apuntador1()
{
	 int *pi,i,val;// se agrega * delante de 'pi' como prefijo al declarar
    			// una variable de tipo apuntador
	cout<<"\tIngrese un numero entero por favor:\n-";
	cin>>i;			
    cout<<"valor del entero i:\n "<<i<<endl;
    pi=&i;	//'&' es un operador de dirección o referencia
    		//en este caso se asigna la dirección de i a la variable apuntador 'pi'
    val=*pi;//asigna el contenido de i(al que apunta pi) a la variable val
    cout<<"valor asignado con apuntador:\n "<<val<<endl;
}

int funcion(int valor)//se crea una funcion para un entero
{
    valor = valor + 20; //Se le suma 10
    return valor;
}
int funcionPunteros(int* valor)//se crea una funcion para un puntero
{
    *valor = *valor + 30; //Se le suma 10 a la posición en memoria
    return *valor;
}
void apuntador2()
{
	int numero;
    cout<<"\tIngrese un numero entero por favor:\n-";
	cin>>numero;	
    cout << "Antes de funcion " << numero << "\n"; //10
    funcion(numero); //Se pasa por valor
    cout << "Despues de funcion " << numero << "\n"; //10
    cout << "Antes de funcionPunteros " << numero << "\n"; //10
    funcionPunteros(&numero); //Se envía la dirección de memoria y la función resuelve la referencia
    cout << "Despues de funcionPunteros " << numero << "\n"; //n (10+10)
}
