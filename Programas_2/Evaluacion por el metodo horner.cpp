/*
	Name: METODO HORNER
	Autores: Alberto Limachi Luis Rafael
	         Nina Mamani Itamar Esteban
	Description: Realizar la division de polinomios con el m�todo Horner
*/

#include <iostream>
#include <math.h>
#include <limits>

using namespace std;
char stopApp;

int main ( )
 {
 	do
 	{
      int n, i, m, t, k;
    while (true)        //Para la verificacion de datos
    {
    cout << "\n\n\t\t METODO DE HORNER PARA EVALUAR POLINOMIOS ";
    cout << "\n\n\t Ingrese el grado del polinomio:  ";
    cin >> n;
        if (cin.fail()) // Si nada se pone será verdadero
        {   cout<<"Caracter invalido\n";
            cin.clear(); // Para resetear los bits
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            //ignore() es usado para limpiar los datos incorrectos
            continue; // El ciclo iniciará de nuevo
        }
        //Para limpiar datos adicionales como: atr15 (atr es adicional)
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        // Remueve los datos adicionales de la entrada de datos
        if (cin.gcount() > 1) 
        // Devolvera mas de 1 si hay algun sobrante de datos invalidos
        {   cout<<"Caracter invalido, no te pases de listo\n";
            continue; // el ciclo iniciará de nuevo
        }
        if (n>=100 || n<=0)       //poniendo limite al numero de caracteres escritos
        {   cout<<"Limite de caracteres alcanzado\n";
            continue;   //el ciclo iniciará de nuevo
        }
     break; //rompe el ciclo
    }
    int a[n], b[n];

    cout << "\n\n Ingrese los coeficientes con su signo correspondiente \n";
    for(i=0; i<=n; i++)
    {
           m = n-i;
           cout << "\n a("<< m <<") : > ";
           cin >> a[n-i];

    }
     

     cout << "\n\n ingrese el polinomio: \n\n P(x) = ";
     for(i=0; i<=n; i++)
     {
           m=n-i;
           if(i!=n)
           {
                cout << " " << a[m] << " x^" << m << " + ";
            }
           else
            {
               cout << " " << a[m] << " ";
             }
      }

cout << "\n\n\n Coloque el valor para evaluar el P(x): ";
cin >> t;

b[n] = a[n];
for(k=(n-1); k>=0; k--)
{
     b[k] = t*b[k+1]+a[k];
}
   
cout << "\n\n\t La raiz es:  " << b[0];
cout << endl << endl;
cout<<endl;
cout << "Para seguir en la App digite 'Y' (Y/N)" << endl;
          cin >> stopApp;
    } 
	while(toupper(stopApp) == 'Y');
system("PAUSE");
return 0;
}

