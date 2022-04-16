#include <iostream>
using namespace std;
// Función para imprimir permutaciones de cadena
// Esta función toma tres parámetros:
// 1.Cadena
// 2. Índice inicial de la cadena
// 3. Índice final de la cadena.
void permute(string a, int l, int r)
{
	//caso base
	if (l == r)
		cout<<a<<endl;
	else
	{
		// permutaciones hechas
		for (int i = l; i <= r; i++)
		{
			// Intercambio hecho
			swap(a[l], a[i]);//swap sirve para cambiar los valores

			// llamando a la recursividad
			permute(a, l+1, r);

			//Retractarse
			swap(a[l], a[i]);
		}
	}
}

// Correr el codigo
int main()
{
	string leter;
	cout<<"\n\n\t\t Algoritmo numero 3\n";
	cout<<"\n\n\t\tPermutaciones ABC... \n";
    cout<<"\nIngrese las letras: ";
    getline(cin,leter);
	int n = leter.size();
	permute(leter, 0, n-1);
	return 0;
}
