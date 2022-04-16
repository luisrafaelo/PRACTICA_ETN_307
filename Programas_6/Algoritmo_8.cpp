#include <iostream>
using namespace std;
 
// Función para encontrar si el número es divisible por 11 o no
int check(string str)
{
    int n = str.length();
 
    // Calcular la suma de pare y impares
    // sumas
    int oddDigSum = 0, evenDigSum = 0;
    for (int i=0; i<n; i++)
    {
        // Cuando i es par, la posición del dígito es impar
        if (i%2 == 0)//base
            oddDigSum += (str[i]-'0');
        else//recursividad
            evenDigSum += (str[i]-'0');
    }
 
    // Comprueba si su diferencia es divisible por 11 o no
    return ((oddDigSum - evenDigSum) % 11 == 0);
}
 
// Corre el codigo
int main()
{
   
   string num;
   	cout<<"\n\n\t\t Algoritmo numero 8\n";
	cout<<"\n\n\tComprueba si es divisor de 11\n";
   cout<<"\nIngrese el numero: ";
getline(cin,num);
    check(num)?  cout << "Si" : cout << "No ";
    return 0;
}
