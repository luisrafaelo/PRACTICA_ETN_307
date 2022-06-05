#include <iostream>
#include <cmath>
using namespace std;

//histograma de una lista de datos con decimales
void histograma (double[], int);

int main(){
	//ejemplo de una 
	double x[6] = {50.00,48.00,15.00,100.00,60.00,80.00};	//debe ser: 2, 1, 0, 5, 3, 4
	histograma (x, 6);
	return 0;
}

void histograma (double y[], int n){
	//ejeX es donde se pondran el orden de primero a ultimo lugar de cada dato
	//x es donde se ordenaran los datos de y
	//pos es de posicion para ayudar a generar ejeX y ordenar x
	//graf1 y graf2 son los histogramas en matriz 2x2
	//graf1 es un histograma de y
	//graf2 es un histograma ordenado de y. este se hara con x
	
	int pos, ejeX[n], aux;
	double x[n];
	char graf1[n][n], graf2[n][n];
	//Inicializando x y ejeX
	for (int i = 0; i < n; i++){
		ejeX[i] = 0;
		x[i] = y[i];
	}
	//Ordenamiento de y en x. Generacion de ejeX, las posiciones de cada dato de y
	for (int i = 0; i < n; i++){
		pos = i;
		aux = x[i];
		ejeX[i] = i;
		for (int j = i; j > 0; j--){
			if (y[j-1] > y[i]){
				x[pos] = x[pos-1];
				ejeX[j-1]++;
				pos--;
			}
		}
		ejeX[i] = pos;
		x[pos] = aux;
	}
	aux = n - 1;
	cout<<"\n\n";
	//Inicializacion de los graficos de los histogramas
	for (int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			graf1[i][j] = ' ';
			graf2[i][j] = ' ';
		}
		aux--;
	}
	//generacion de los graficos
	aux = n - 1;
	for (int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if (ejeX[j] == aux){
				for (int o = i; o < n; o++){
					graf1[o][j] = 'N';	
				}			
			}
			if (j == aux){
				for (int o = i; o < n; o++){
					graf2[o][j] = 'N';				}
			}
		}
		aux--;
	}
	//histograma de y. Pueden cambiar el titulo para otro tipo de ejex y ejey
	cout<<"\nFrecuencia\t|\nRelativa\t|";
	for (int b = 0; b < n; b++){
		cout<<"\n\t"<<x[n - b - 1]<<"---\t|";
		for	(int i = 0; i < n; i++){
			cout<<"\t"<<graf1[b][i];
		}
	}
	cout<<"\n\t\t|\tM\tM\tM\tM\tM\tM\n\t\t|\tM\tM\tM\tM\tM\tM";
	cout<<"\n\t\t|------------------------------------------------------------";
	cout<<"\n\t\t|";
	for (int i = 0; i < n; i++){
		cout<<"\t"<<y[i];
	}
	
	//histograma ordenado de menor a mayor de y
	cout<<"\n\nFrecuencia\t|\nAcumulativa\t|";
	for (int b = 0; b < n; b++){
		cout<<"\n\t"<<x[n - b - 1]<<"---\t|";
		for	(int i = 0; i < n; i++){
			cout<<"\t"<<graf2[b][i];
		}
	}
	cout<<"\n\t\t|\tM\tM\tM\tM\tM\tM\n\t\t|\tM\tM\tM\tM\tM\tM";
	cout<<"\n\t\t|------------------------------------------------------------";
	cout<<"\n\t\t|";
	for (int i = 0; i < n; i++){
		cout<<"\t"<<x[i];
	}
}
