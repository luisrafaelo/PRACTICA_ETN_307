#include <iostream>
#include <cmath>
using namespace std;

void regresion_lineal(int[], int[], int);

int main(){
	cout<<"\t\t\tINCISO 8:	REGRESION LINEAL";
	cout<<"\n\n\tNumero de pares de datos :\t\t12";
	int n = 12;
	cout<<"\n";
	int peso[n] = {74,92,63,72,58,78,85,85,73,62,80,72};
	int altura[n] = {168,196,170,175,162,169,190,186,176,170,176,179};
	cout<<"\n\tPESO\t|\tALTURA";
	for (int i = 0; i < n; i++){
		cout<<"\n"<<i+1<<".\t"<<peso[i]<<"\t|\t"<<altura[i];
	}
	regresion_lineal(peso, altura, n);
	return 0;
}

void regresion_lineal(int x[], int y[], int m){
	double promedioY = 0.000, promedioX = 0.000, promedioXY = 0.000, promedioX2 = 0.000;
	double a = 0.000, b = 0.000; 
	for(int i = 0; i < m; i++){
		promedioY += y[i] / m;
		promedioX2 += pow(x[i], 2) / m;
		promedioX += x[i] / m;
		promedioXY += (x[i] * y[i]) / m;
	}
	b = (promedioXY - (promedioX * promedioY)) / (promedioX2 - pow(promedioX, 2));
	a = promedioY - (promedioX * b);
	
	cout<<"\n\n\tLa regresion lineal simple Yi = A + B*Xi  es:"<<endl;
	cout<<"\n\tALTURA = ("<<a<<") + ("<<b<<") * PESO\n\n\tA = "<<a<<"\n\tB = "<<b;
	
}
