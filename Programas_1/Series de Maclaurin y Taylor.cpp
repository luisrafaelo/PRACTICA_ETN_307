//
//    PRACTICA 1.1
//    FUNCION EXPONENCIAL, SENO, COSENO
//	  UNIV.:LUIS RAFAEL ALBERTO LIMACHI
//		
#include <iostream>		//libreria estandar de entrada y 5salida
#include <math.h>		//libreria  para matemáticas básicas
using namespace std;    //espacio entre nombres
long long factorial (long long n);		//almacena datos en "n" de hasta 64 bits
double exp_mctylr(int terminos, double x);  //"double" almacena valores en decimales
double sen_mctylr(int terminos, double s);		
double cos_mctylr(int terminos, double c);

int main ()
{

	char();
	float elevacion; float TERMINOS; 		//"int" variable para un valor entero
	cout << "                 PRACTICA NUMERO 1, FUNCION EXPONENCIAL, SENO Y COSENO." << endl;
	cout << "" << endl;

	cout << "Ingrese el valor del exponente/angulo EN RADIANES: "; cin >> elevacion;//"cout" salidas en c
	cout << "y el numero de terminos por favor: "; cin >> TERMINOS;//"cin" entradas en c
	cout << "" << endl;
	
	if (char()==elevacion  or char()==TERMINOS)
	{
		cout << "                 INGRESE NUMEROS, NO LETRAS!!!" << endl;
		return 0;	
	}
	cout << "Valor del Exponencial segun cmath:" << exp(elevacion) << endl; //generamos el 
	cout << "Valor del Angulo SENO segun cmath:" << sin(elevacion) << endl;// valor de manera
	cout << "Valor del Angulo COSENO segun cmath:" << cos(elevacion) << endl;//directa
	cout << "" << endl;
	
	int a = lround((float)TERMINOS);

	for (int i = 1; i<=a; i++)		//"for" ciclo que se repite hasta el valor de "termino"
	{
	cout << "Con " <<  i  << "  terminos: Exponente "<< exp_mctylr(i,elevacion)//se genera todos
	<<"   angulo de seno: " << sen_mctylr(i,elevacion)								//los terminos
	<<"   angulo de coseno: " << cos_mctylr(i,elevacion) << endl;
	}
	cout << endl;
	return 0; //se termina de ejecutar el programa
}
long long factorial (long long n)// funcion para el factorial
{
	long long fact =1;
	for (long long i = 1; i <= n; i++)
	{
	fact *= i;
	
	}
	return fact;
}
double exp_mctylr(int terminos, double x)//funcio para suma de la serie de exponentes
{
	double sumatoria =0;
	for (int n=0; n <= terminos; n++)
	{
	sumatoria += pow(x,  n)/factorial(n);
}
return sumatoria;
}
double sen_mctylr(int terminos, double s)//funcion para suma de la serie de seno
{
	double seno = 0;
	for (int n=0; n<=terminos; n++)
	{
		seno += pow(-1,  n)*pow(s,2*n+1)/factorial(2*n+1);
	}
	return seno;
}
double cos_mctylr(int terminos, double c)//funcion para suma de la serie de coseno
{
	double coseno = 0;
	for (int n=0; n<=terminos; n++)
	{
		coseno += pow(-1,  n)*pow(c,2*n)/factorial(2*n);
	}
	return coseno;
}
