#include <iostream>
using namespace std;
 
int ack(long long m, long long n)
{
    if (m == 0){//Base
        return n + 1;
    }//recursividad
    else if((m > 0) && (n == 0)){
        return ack(m - 1, 1);
    }
    else if((m > 0) && (n > 0)){
        return ack(m - 1, ack(m, n - 1));
    }
}
 
// Corre el codigo
int main()
{
    long long m,n;
    cout<<"\n\n\t\t  Algoritmo numero 10\n";
	cout<<"\n\n\t\tFuncion de Ackerman (m,n)\n";
    cout<<"\nIngrese el primer numero: \n";
    cin>>m;
    cout<<"Ingrese el segundo numero: \n";
    cin>>n;
    cout << "\nA(m,n) = "<<ack(m,n) << endl;
    return 0;
}
