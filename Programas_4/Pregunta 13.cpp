#include <iostream>

using namespace std;
char StopApp;
int main ()
{
	do{
int Venta[10], i;

double X=0,X1=0,X2=0,X3=0,X4=0,X5=0;
cout<<"\n\n\t\t Ejercicio Numero 13\n\n";
for (i=0; i<=9;i++)
{
  cout<<"\n\tValor de la venta "<<i+1<<": \t";
               cin>>Venta[i];

if(  Venta[i] >550)
{
X=X+1;
X1=X1 + Venta[i];
}

else if (Venta[i] >200&& Venta[i]<=550 )
 {
X2=X2+1;
X3=X3 + Venta[i];
 }

X4=X1/X;
X5=X3/X2;
}
cout<<"\n a) Ventas mayores a 550: \n\t"<<X<<endl;
cout<<endl;
cout<<" b) Ventas mayores a 200 y menores o iguales a 550 :\n\t"<<X2<<endl;
cout<<endl;
cout<<" Promedio de ventas mayores de 550:\n\t"<<X4<<endl;
cout<<endl;
cout<<" Promedio de ventas mayores a 200 y menores o iguales a 550:\n\t"<<X5<<endl;
cout<<endl;
cout<<"\nPara reiniciar la calculadora ingrese 'Y' (Si), si no quiere ingrese cualquier tecla\n";
        cin>>StopApp;
    }

    while(toupper(StopApp) == 'Y');
    return 0;
}
