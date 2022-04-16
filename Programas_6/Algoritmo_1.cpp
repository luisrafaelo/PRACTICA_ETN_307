#include <iostream>
using namespace std;
char StopApp;
// Funcion recursiva con static
// variables p y f
double e(int x, int n)
{
    static double p = 1, f = 1;
    double r;
 
    //Condicion de terminacion
    if (n == 0)
        return 1;
 
    // Llamada recursiva
    r = e(x, n - 1);
    p = p * x;
    // Factorial
    f = f * n;
    return (r + p / f);
}
 
// Corre el codigo
int main()
{

    int x=0, n = 18;
    cout<<"\n\n\t\t Algoritmo numero 1\n";
    cout<<"\nIngrese el valor de x para e^x\n ";
    cin>>x;
    do{
    cout<<"\n e^"<<x<<" = "<< e(x, n);
cout<<"\nPara reiniciar la APP ingrese 'Y' (Si), si no quiere ingrese cualquier tecla\n";
        cin>>StopApp;
    }
    while(toupper(StopApp) == 'Y');
    return 0;
}
 
