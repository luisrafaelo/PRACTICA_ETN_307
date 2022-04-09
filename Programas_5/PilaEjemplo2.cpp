#include <iostream>

using namespace std;

int stack[100], n=100, top=-1;
//void para ingresar datos a la pila
void push(int val) {
   if(top>=n-1)
   cout<<"Pila completa, no puede almacenar mas datos"<<endl;
   else {
      top++;
      stack[top]=val;
   }
}
//void para eliminar el ultimo elemento cargado a la pila
void pop() {
   if(top<=-1)
   cout<<"Pila vacia, no se puede eliminar nada"<<endl;
   else {
      cout<<"el elemento eliminado es:  "<< stack[top] <<endl;
      top--;
   }
}
//void para mostrar los elementos almacenados en la pila
void display() {
   if(top>=0) {
      cout<<"Los elementos de pila son:\n";
      for(int i=top; i>=0; i--)
      cout<<stack[i]<<" \n";
      cout<<endl;
   } else
   cout<<"La pila esta vacia\n";
}
int main() {
   int ch, val;
   cout<<"1) Ingrese un dato en la pila"<<endl;
   cout<<"2) Elimine el dato la pila"<<endl;
   cout<<"3) Mostrar los elementos en la pila"<<endl;
   cout<<"4) Salir"<<endl;
   do {
      cout<<"\nIntroduce tu eleccion: "<<endl;
      cin>>ch;
      switch(ch) {
         case 1: {
            cout<<"Ingrese el valor del nuevo elemento de la pila:\n\t";
            cin>>val;
            push(val);
            break;
         }
         case 2: {
            pop();
            break;
         }
         case 3: {
            display();
            break;
         }
         case 4: {
            cout<<"Salida"<<endl;
            break;
         }
         default: {
            cout<<"Eleccion no valida"<<endl;
         }
      }
   }while(ch!=4);
   return 0;
}
