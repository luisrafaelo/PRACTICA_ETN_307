#include <iostream>
using namespace std;
 
//Declaración paa el nuevo nodo del árbol
struct node  { 
int data; 
struct node *left; 
struct node *right; 
}; 
   
//Asigna un nuevo nodo 
struct node* newNode(int data) { 
  // Declarar y asignar un nuevo nodo 
  struct node* node = new struct node(); 
   
  node->data = data;    // Asignar datos a este nodo
   
  // Iniciar la izquierda y derecha como nulo 
node->left = NULL; 
node->right = NULL; 
return(node); 
} 
   
int main() { 
  /*crear un nodo raiz*/
struct node *rootNode = newNode(100);  
cout<<"\n\tEl arbol creado es el siguiente:"<<endl;
cout<<"\t\t\t "<<rootNode->data<<endl;
cout<<"\t\t\t "<<"/ "<<"\\"<<endl;
rootNode->left= newNode(200); 
rootNode->right= newNode(300); 
cout<<"\t\t\t"<<rootNode->left->data<<"  "<<rootNode->right->data;
cout<<endl; 
rootNode->left->left  = newNode(400);
rootNode->right->right  = newNode(500); 
cout<<"\t\t\t"<<"/"<<"\t\\"<<endl;
cout<<"\t\t      "<<rootNode->left->left->data<<"\t"<<rootNode->right->right->data; 
 
return 0; 
}
