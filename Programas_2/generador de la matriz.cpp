/*
	Name: Matriz enesima de Vandermonde 
	Author: Luis Rafael Alberto Limachi
	Description: Generar matrices enésimas de Vandermonde  
	y calcular el determinante
*/

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;
int **matriz(int fila, int columna); // para crear la matriz
void matriz_libre(int **arr);          // para el espacio dentro de la magtriz
void print2(char *var, int **arr, int nx, int ny);
void print1(char *var, int *arr, int nx);
void matrizVandermonde(int *nsimo, int **vander, int nx);
long long factorial (long long n);

int main(int argc, char **argv)
{
  int nx;
  int *nsimo, **vandermonde;
  int i;
  
  cout<<"Ingrese el enesimo de Vandermonde a generar"<<endl;
  cin>>nx;
  vandermonde = matriz(nx, nx); // crea la salida de la matriz
  nsimo = (int*) calloc (nx, sizeof(int));
  for(i=0; i<nx; i++) //llena el enesimo valor
    nsimo[i] = i+1;
  
  matrizVandermonde(nsimo, vandermonde, nx); // proceso de vandermonde
  
  print1("enesimo", nsimo, nx); //muestra la salida 
  print2("vandermonde", vandermonde, nx, nx); 
  
  // memoria libre asignada
  free(nsimo);
  matriz_libre(vandermonde);
  cout<<"a ver que sale:"<<factorial(nx);
}

void matrizVandermonde(int *nsimo, int **vander, int nx)
{
  int i, j;
  for(i=0; i<nx; i++)
    for(j=0; j<nx; j++)
      vander[i][j] = pow(nsimo[i], nx-j-1);
}

int **matriz(int fila, int columna)
{
    int i;
    int **arr=NULL;
 
    //asigna punteros a las filas
    arr = (int **) malloc((fila*sizeof(int*)));
    if (!arr) {
        fprintf(stderr, "matriz: error al localizar la fila");
        exit(0);
    }
 
    //asigna filas y establece punteros
    arr[0]=(int*) malloc((fila*columna)*sizeof(int));
    if (!arr[0]) {
        fprintf(stderr, "matriz: error al localizar la columna");
        exit(0);
    }
 
    for(i=1; i<fila; i++)
        arr[i]=arr[i-1] + columna;
    return arr;
}

void matriz_libre(int **arr)
{
    free (arr[0]);
    free (arr);
}

void print2(char *var, int **arr, int nx, int ny)
{
  int i, j;
  printf("Matriz generada de  %s \n", var);
  for(i=0; i<ny; i++)
  {
    for(j=0; j<nx; j++)
      printf("%i \t", arr[i][j]);  
      printf("\n");
  }
  printf("\n\n");
}

void print1(char *var, int *arr, int nx)
{
  int i;
  printf("Valor %s \n", var);
  for(i=0; i<nx; i++)
    printf("%i \t", arr[i]);   
    printf("\n\n");
}
long long factorial (long long n)// funcion para el factorial
{
	int m=0;
	int h=0;
	long long fact =1;
	for (long long i = 1; i <= n; i++)
	{
	h=n-i;
	fact=fact*(n-h);
	}
	return fact;
}
