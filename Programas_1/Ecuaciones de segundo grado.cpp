 //
 //			PRACTICA 1.2
 //			ECUACIONES DE SEGUNDO GRADO
 //	
#include <iostream>
#include <math.h>// librerias

using namespace std;

int main ()
{
	float a, b, c, T;
	char A;
	float a1, a2;
	float b1, b2;//variebles para imaginarios
T = 0,00001;
	
   cout << "                 Calculadora de Ecuacion cuadratica"<<endl;
   cout << ""<<endl;
   cout << "  Inserte los datos para la siguiente forma: aX^2 + bX + c"<<endl;
   cout << ""<<endl;
   cout << " Para a :"; cin>> a;
   if (char () ==a)
	{
		cout << "                 INGRESE NUMEROS, NO LETRAS!!!" << endl;
	}
   cout << " Para b :"; cin>> b;
   if (char () ==b)
	{
		cout << "                 INGRESE NUMEROS, NO LETRAS!!!" << endl;	
	}
   cout << " Para c :"; cin>> c;
if (char () ==c)
	{
		cout << "                 INGRESE NUMEROS, NO LETRAS!!!" << endl;
	}
   
		if (a!=0){
			
				if (b*b-4*a*c >= 0)//discriminante
				{
					a1 = (-b+sqrt(b*b-4*a*c))/(2*a);
					a2 = (-b-sqrt(b*b-4*a*c))/(2*a);
					cout<<" La solucion tiene las siguientes raices:"<<endl;
		
       				 cout<<" X1    :"<<a1<<endl;
       				 cout<<" X2    :"<<a2<<endl;
				}
					else
					{
			
					a1=(-b)/(2*a);
					a2=(-b)/(2*a);
		
					b1=sqrt(abs(b*b-4*a*c))/(2*a);
					b2=((-1)*sqrt(abs(b*b-4*a*c)))/(2*a);
			
					cout<<" La solucion tiene raices imaginarias:"<<endl;
					cout<<"X1 = " << a1 << " +" <<b1<<" i"<<endl;
					cout<<"X2 = " << a2 << " " <<b2<<" i"<<endl;
				
					}	
				}		
	   else	
		cout <<"solo tiene una raiz:  "<< -c/b <<endl; 	
	}

		

