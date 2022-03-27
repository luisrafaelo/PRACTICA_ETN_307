#include<fstream>
#include<iostream>
#include<string>
using namespace std;
///funciones del programa
void lectura1();
void lectura2();
void escritura();
char stopApp;

//main
int main(int argo, char *argv[])
{
	do{
	int opcion=0;
		cout << "\n\n\t\tPregunta numero 2\n\n";
	cout << "\n\tPara leer y contar las palabras 'Fisica.txt' digite '1";
	cout << "\n\tPara leer y contar las palabras 'datos.txt' digite '2'";
	cout << "\n\tPara Escribir en 'datos.txt' digite '3':\n\n=>\t";
	cin >> opcion;
	switch (opcion)
	{
		case 1:
			lectura1();
			break;
		case 2:
			lectura2();
			break;	
		case 3:
			escritura();
			break;	
	
	}
	cout <<endl;
cout << "\n\n\t\tPara seguir en la App digite 'Y' (Y/N)" << endl;
        cin >> stopApp;
	 } 
	while(toupper(stopApp) == 'Y');

}
//funcion para leer
void lectura2(){
	ifstream f;
char dato;
f.open("datos.txt");
if(!f)
cout << "Error abriendo el fichero" << endl;
else
{
	dato=f.get();
while(! f.eof())
{
cout << dato;
dato = f.get();
}
	ifstream ifs("datos.txt");
	int words = 0;
	string word;
	while (ifs >> word)
	{
	++words;
	}
	cout << "\nNumero de palabras:\n\n\t"<<words<<endl;
f.close();
}
}
//funcion de leer
void escritura(){
	ofstream f;
char texto[2000];
// APERTURA del fichero
f.open("datos.txt");
if(!f)
cout << "Error abriendo el fichero" << endl;
else
{
// OPERACIONES sobre el fichero
cout<< "Ingrese lo que quiera escribir en el texto tenga en cuenta\n";
cout<< "que lo escrito antes se borrara (max 2000 caracteres):\n\n";
cout<< "NOTA: LA PRIMERA PALABRA NO SE REGISTRA!!!\n";
cin>>texto;
cin.getline(texto,2000);
f << texto << endl;
// CIERRE del fichero
f.close();
}
}
//funcion para leer
void lectura1(){
	ifstream f;
char dato;
f.open("Fisica.txt");
if(!f)
cout << "Error abriendo el fichero" << endl;
else
{
	dato=f.get();
while(! f.eof())
{
cout << dato;
dato = f.get();
}
	ifstream ifs("Fisica.txt");
	int words = 0;
	string word;
	while (ifs >> word)
	{
	++words;
	}
	cout << "\n\n\tNumero de palabras:\n\n\t"<<words<<endl;
f.close();
}
}
/// LAS PALABRAS CONTADAS EN FISICA.TXT SON  19104, LAS PALABRAS EN DATOS VARÍAN SEGUN LO QUE ESCRIBAMOS

