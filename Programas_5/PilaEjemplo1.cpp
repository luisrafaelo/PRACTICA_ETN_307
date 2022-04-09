#include <iostream>
#include <stack>

using namespace std;

int main()
{
  stack<int> stack1; //pila vacia de tipo entero
  stack1.push(100);//push; se utiliza para insertar
  stack1.push(200);//los elementos en la pila
  stack1.push(300);
  stack1.push(400);
  stack1.push(500);
//	stack1.pop();//Esta funcion hace estallar el elemnto superior de la pila
//	stack1.pop();//lo elimina
  cout << "El elemento superior de la pila es:" << stack1.top() << endl;
  //top,Devuelve una referencia al elemento superior de la pila
  cout << "El tamaño de la pila es=" << stack1.size() << endl;
//size, devuelve varios elementos de la pila
  if (stack1.empty())//empty,avisa si la pila está vacia o no
  {
    cout << "La pila esta vacia" << endl;
  }
  else
  {
  	while (!stack1.empty())
  {
    cout << "Elementos =" << stack1.top() << endl;
    //al estar en un WHILE, lee los elementos de la pila
    stack1.pop();
  }
    cout << "La pila no esta vacia" << endl;
  }
}
