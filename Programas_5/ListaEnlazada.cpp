#include <iostream>
using namespace std;

// Creamos un nodo
struct Node {
  int data;
  struct Node* next;
};
void insertAtBeginning(struct Node** head_ref, int new_data) {
  //Asignar memoria a un nodo
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

  // Insertamos los datos
  new_node->data = new_data;
  new_node->next = (*head_ref);

  // Mover a la cabeza al nuevo nodo
  (*head_ref) = new_node;
}

// Insertar un nodo despues de un nodo
void insertAfter(struct Node* prev_node, int new_data) {
  if (prev_node == NULL) {
  cout << "El nodo anterior no puede ser NULO";
  return;
  }

  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  new_node->data = new_data;
  new_node->next = prev_node->next;
  prev_node->next = new_node;
}

// Insertar al final
void insertAtEnd(struct Node** head_ref, int new_data) {
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  struct Node* last = *head_ref; /* Utilizado en el paso 5*/

  new_node->data = new_data;
  new_node->next = NULL;

  if (*head_ref == NULL) {
  *head_ref = new_node;
  return;
  }

  while (last->next != NULL) last = last->next;

  last->next = new_node;
  return;
}

// Void para elimidar un nodo
void deleteNode(struct Node** head_ref, int key) {
  struct Node *temp = *head_ref, *prev;

  if (temp != NULL && temp->data == key) {
  *head_ref = temp->next;
  free(temp);
  return;
  }
  // encontramos lo que vamos a eliminar
  while (temp != NULL && temp->data != key) {
  prev = temp;
  temp = temp->next;
  }

  // Si no esta presente
  if (temp == NULL) return;

  // Quitar el nodo
  prev->next = temp->next;

  free(temp);
}

// Buscar un nodo
bool searchNode(struct Node** head_ref, int key) {
  struct Node* current = *head_ref;

  while (current != NULL) {
  if (current->data == key) return true;
  current = current->next;
  }
  return false;
}

// ordenar la lista enlazada
void sortLinkedList(struct Node** head_ref) {
  struct Node *current = *head_ref, *index = NULL;
  int temp;

  if (head_ref == NULL) {
  return;
  } else {
  while (current != NULL) {
    // el índice apunta al nodo al lado del actual
    index = current->next;

    while (index != NULL) {
    if (current->data > index->data) {
      temp = current->data;
      current->data = index->data;
      index->data = temp;
    }
    index = index->next;
    }
    current = current->next;
  }
  }
}

// Imprime la lista enlazada
void printList(struct Node* node) {
  while (node != NULL) {
  cout << node->data << " ";
  node = node->next;
  }
}

// corre el programa
int main() {
  struct Node* head = NULL;

  insertAtEnd(&head, 1);
  insertAtBeginning(&head, 2);
  insertAtBeginning(&head, 3);
  insertAtEnd(&head, 4);
  insertAfter(head->next, 5);

  cout << "Lista enlazada:\n ";
  printList(head);

  cout << "\nDespues de eliminar un elemento:\n ";
  deleteNode(&head, 1);
  printList(head);

  int item_to_find = 1;
  if (searchNode(&head, item_to_find)) {
  cout << endl << item_to_find << " se encuentra";
  } else {
  cout << endl << item_to_find << " ya no se encuentra.";
  }

  sortLinkedList(&head);
  cout << "\nLista ordenada: \n";
  printList(head);
}
