#include <iostream>       
#include <queue>          // libreria para la cola
using namespace std;  
int main ()
{
queue<int> Numeros;
  int Datos;
cout<<"\n\n\t\t EJEMPLOS DE USO DE COLAS";
cout << "\n\nPor favor ingrese los datos de a C0la (ingrese '0' al finalizar):\n";

  do {
cin >> Datos;

    Numeros.push (Datos);
    
  } while (Datos);
     //size, lee el numero de elementos
    cout << "\nTamano de la cola : " << Numeros.size(); 
	//front, lee el frente de la cola 
    cout << "\nFrente de la cola : " << Numeros.front();  
    //front, lee la parte posterior de la cola
    cout << "\nAtras de la cola : " << Numeros.back();

cout << "\n\n*******LUEGO DE BORRAR 2 ELEMENTOS*******\n " ;
Numeros.pop();//elimina la parte frontal de la cola
Numeros.pop();//elimina la parte frontal de la cola
cout << "\nTamano de la cola : " << Numeros.size();
cout << "\nFrente de la cola : " << Numeros.front();  
cout << "\nAtras de la cola : " << Numeros.back();
cout << "\nNumeros contenidos: ";
  while (!Numeros.empty())//funcion while para mostrar los numeros en la cola
  {
cout << " \n" << Numeros.front();
    Numeros.pop();
    
  }
  return 0;
}
