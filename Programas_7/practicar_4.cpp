#include <iostream>
using namespace std;

void inciso_A (int, int, int, int, int[], int);
void inciso_B (int, int[], int);
void inciso_C (int, int, int[], int);

int main(){
	cout<<"\t\t\tInciso 4";
	cout<<"\n\n\tCuantos elementos son? :\t\t80";
	int n = 80;		
	cout<<"\n";
	int dato[80] = {60,66,77,70,66,68,57,70,66,52,75,65,69,71,58,66,67,74,61,63,
					69,80,59,66,70,67,78,75,64,71,81,62,64,69,68,72,83,56,65,74,
					67,54,65,65,69,61,67,73,57,62,67,68,63,67,71,68,76,61,62,63,
					76,61,67,67,64,72,64,73,79,58,67,71,68,59,69,70,66,62,63,66};
	
	for (int i = 0; i < n; i++){
		cout<<"\n=>\tIngrese el dato "<<i+1<<" :\t\t";
		cout<<dato[i];
	}
	
	int mayor = dato[0];
	int menor = dato [1];
	for (int i = 0; i < n; i++){
		if (dato[i] >= mayor){
			mayor = dato[i];
		}
		if (dato[i] <= menor){
			menor = dato[i];
		}
	}
	cout<<"\nEl dato mayor es:\t"<<mayor<<"\nEl dato menor es:\t"<<menor<<endl;
	//Calculo de cada inciso
	inciso_A (5, 50, mayor, menor, dato, n);
	inciso_B (65, dato, n);
	inciso_C (70, 85, dato, n);
	return 0;
}

void inciso_A (int amplitud, int inicio, int mayor, int menor, int dato[], int n){
	int j = 0, Frec = 0, frecuencia[n];
	for (int i = 0; i < n; i++){
		frecuencia[i] = 0;
	}
	cout<<"\n\tINCISO A";
	cout<<"\n\n\tNumero\t|\tRango\t\t|\tFrecuencia\t|\tFrecuencia Acumulativa";
	for (int aux = inicio; aux < mayor; aux = aux + amplitud){
		for (int i = 0; i < n; i++){
			if (dato[i] >= aux && dato[i] <= (aux + amplitud)){
				if(dato[i] == (aux + amplitud) ){
					continue;
				}
				else {
					frecuencia[j]++;	
				}
			}
		}
		//mostrar resultados
		Frec += frecuencia[j];
		cout<<"\n\t"<<j+1<<"\t|\t[ "<<aux<<" - "<<aux + amplitud<<"]\t|\t"<<frecuencia[j]<<"\t|\t"<<Frec;	
		j++;
	}
	cout<<endl;
}

void inciso_B (int marca, int dato[], int n){
	double aux = 0.00, sum = 0.00;
	for (int i = 0; i < n; i++){
		sum++;
		if (dato[i] < marca)
		aux++;
	}
	double porcentaje = (aux / sum) * 100;
	cout<<"\n\tINCISO B\n\n\tPorcentaje de personas con pesos menores a "<<marca<<" kg :\t"<<porcentaje<<" %";
	cout<<endl;
}

void inciso_C (int x, int y, int dato[], int n){
	int aux = 0;
	for (int i = 0; i < n; i++){
		if (dato[i] >= x){
			if (dato[i] < y)
			aux++;
		}
	}
	cout<<"\n\tINCISO C\n\n\tEl numero de personas con peso mayor o igual a "<<x<<" kg, pero menor a "<<y<<" kg es de:\t\t"<<aux;
	cout<<endl;
}
