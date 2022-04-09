#include <iostream>  
#include <queue>  //libreria de cola

using namespace std;  
//void para mostrar la cola con .front
void MostrarCola(queue <int> que)  
{  
    queue <int> sq = que;  
    while (!sq.empty())  
    {  
        cout << '\n' << sq.front();  
        sq.pop();  
    }  
    cout << '\n';  
}  
  
int main()  
{  
    queue <int> Numeros; //se declara que todos los ingresos seran en la cola
	int ingreso; 
    Numeros.push(100);  //push para ingresar datos
    Numeros.push(200);  
    Numeros.push(300);  
    //Numeros.pop();// pop para borrar el inicio de la cola
    cout<<"\n\n\t\t EJEMPLOS DE USO DE COLAS";
    cout << "\n\nEsta es la cola  : ";  
    MostrarCola(Numeros);  //llama la funcion para mostrar la cola
  //size, lee el numero de elementos
    cout << "\nTamano de la cola : " << Numeros.size(); 
	//front, lee el frente de la cola 
    cout << "\nFrente de la cola : " << Numeros.front();  
    //front, lee la parte posterior de la cola
    cout << "\nAtras de la cola : " << Numeros.back();  
	return 0;  
} 
