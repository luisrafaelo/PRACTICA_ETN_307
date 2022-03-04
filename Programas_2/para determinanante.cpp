#include <iostream>
#include <math.h>

using namespace std;
long long factorial (long long n);

int main (){
	
	int nx;
	cout<<"Ingrese el enesimo de Vandermonde a generar"<<endl;
  cin>>nx;
  cout<<"a ver que sale:"<<factorial(nx);
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
