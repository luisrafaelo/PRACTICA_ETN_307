#include <iostream>
#include <conio.h>
#include <limits>
using namespace std;


int Verificador2 (string, int, string, int, int);

int suma_recursiva (int[], int);
int sucesion_recursiva (int);
int mcd_recursivo (int, int);

int main(){
	
	int i, n;
	do {
		cout<<"\t\t\nMENU\n\n"<<endl;
		cout<<"1. Suma de entradas de un arreglo, con recursividad"<<endl;
		cout<<"2. Sucesion (an+1) = (an-1) + (an) , siendo a0 = 1 y a1 = 1; con recursividad"<<endl;
		cout<<"3. Maximo comun divisor, con recursividad"<<endl;
		cout<<"4. Salir\n";		
		n = Verificador2("Opcion: ", 0, " ", 1, 4);
		cout<<"\n\n";
		
		switch(n){	
													//DESDE AQUI
			case 1:	
			{		cout<<"SUMA DE ENTRADAS DE UN ARREGLO, CON RECURSIVIDAD\n\n";
					cout<<"Ejemplo: arreglo = (1, 2, 3, 4, 5)    SUMA = 1 + 2 + 3 + 4 + 5 = 15 ";
					cout<<"\n\nLa funcion empieza con el primer elemento y luego se llama a si misma";
					cout<<"\npara sumar con el siguiente elemento hasta que ya no hallan elementos que sumar\n"; 
					
					int m = Verificador2("Ingrese el numero de elementos del arreglo: ", 0, " ", -100, 100);
					int *arreglo = new int [m];
					cout<<endl;
					for (int i = 0; i < m; i++){
						arreglo [i] = Verificador2("Ingrese el elemento #", i+1, " del arreglo: ", -10000, 10000);
						cout<<"\n";
					}
					cout<<endl;
					cout<<"\nLa suma de sus elementos es: "<<suma_recursiva (arreglo, m)<<endl;
			}
					break;
					
			case 2:
			{		cout<<"SUCESION (AN+1) = (AN-1) + (AN); DONDE A0 = A1 = 1 , CON RECURSIVIDAD\n\n";
					cout<<"Ejemplo:  n=1   A2 = A0 + A1 = 2   y    n=2    A3 = A1 + A2 = 3 ...";
					cout<<"\n La sucesion va asi:  1, 1, 2, 3, 5, ...  es decir: A0, A1, A2, ...AN ";
					cout<<"\n\nEsencialmente es la SERIE DE FIBONACHI que es asi:   (An) = (An-1) + (An-2)   con el caso a1 = a2 = 1\n";
					cout<<"excepto que aqui es con N = n + 1  y  A0 = A1 = 1,  se escribe diferente pero es la misma sucesion\n";
					
					int c = Verificador2 ("Ingrese n: ", 0, " ", 0, 300);
					cout<<"\nLa serie es: \n\n\t 1";
				    for(i=1; i<c; i++)
				    {	if(sucesion_recursiva(i) != 0){
					       	cout<< ", "; 
					        cout<< sucesion_recursiva (i);
						}         
				    }
				    cout<<endl;
			}		
					break;		
			
			case 3:
			{		cout<<"MAXIMO COMUN DIVISOR, CON RECURSIVIDAD\n\n";
					cout<<"Ejemplo: 34 y 56     34 se descompone en: 2*17    y    56 en: 2*4*7     entonces MCD = 2 ";
					cout<<"\n\nLa funcion encuentra el residuo entre ambos numeros y luego se repite el proceso ";
					cout<<"\ncon el residuo y el segundo numero hasta que solo queden numeros primos que descompongan a ambos numeros, es decir el MCD\n";
					cout<<"\nRECUERDE QUE DEBE SER A > B\n";
					int a, b;
					do {
						a = Verificador2 ("Ingrese A: ", 0, " ", -10000, 10000);
						cout<<"\n";
						b = Verificador2 ("Ingrese B: ", 0, " ", -10000, 10000);
						cout<<"\n";
						if (a<b) {
							cout<<"A no es mayor a B, intentelo de nuevo\n";
						}
					}	while (a<b);
			
					cout<<"El Maximo Comun Divisor entre "<<a<<" y "<<b<<" es: "<<mcd_recursivo (a, b)<<endl;
			}
					break;

			case 4:	break;
		}
		system("pause");
		system("cls");
	}	while (n != 4);
	return 0;
}
 
int suma_recursiva (int arreglo[], int k){
	if (k == 1) return arreglo [0];
	return arreglo [k-1] + suma_recursiva (arreglo, k-1);
}

int sucesion_recursiva (int n){
    if(n == 0 || n == 1){
    	return 1;
	}
    else{
    	return sucesion_recursiva (n - 2) + sucesion_recursiva (n - 1);
	}     
}

int mcd_recursivo (int a, int b){
	if (a == 0){
		return b;
	}
	return mcd_recursivo (b % a, a);
}

int Verificador2 (string Parte_inicial, int Numero_Variable, string Parte_final, int Lim_izquierda, int Lim_Derecha) {
	int x;	
    while (true){
    	if (Numero_Variable != 0){
			cout <<"\n"<<Parte_inicial<<Numero_Variable<<Parte_final;
		}
		else {
			cout <<"\n"<<Parte_inicial;
		}
		
        cin >> x;
        if (cin.fail()) // Si nada se pone serÃ¡ verdadero
        {   cout<<"\nCaracter invalido";
            cin.clear(); // Para resetear los bits
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            //ignore() es usado para limpiar los datos incorrectos
            continue; // El ciclo iniciarÃ¡ de nuevo
        }
        //Para limpiar datos adicionales como: atr15 (atr es adicional)
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        // Remueve los datos adicionales de la entrada de datos
        if (cin.gcount() > 1) 
        // Devolvera mas de 1 si hay algun sobrante de datos invalidos
        {   cout<<"\nCaracter invalido";
            continue; // el ciclo iniciarÃ¡ de nuevo
        }
		if (x<Lim_izquierda || x>Lim_Derecha)       //poniendo limite al numero de caracteres escritos
        {   cout<<"\nLimite de caracteres alcanzado";
            continue;   //el ciclo iniciarÃ¡ de nuevo
        }
        return x;
        break; //rompe el ciclo
    }   
}
