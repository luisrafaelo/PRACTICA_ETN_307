#include <iostream>
#include <sstream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <cmath>
#define ARCHIVO "potencia1.csv"
#define MAX 160000
using namespace std;
char stopApp;

void estadistica (int);

int main(){
	int dato = 0;


	cout<<"\n\n\t\tConjunto de datos POTENCIA.CSV\n\n";
	do{

		cout<<"\n\t1. Lectura del archivo\n";
		cout<<"\n\t2. Encontrar la media, el valor maximo, el valor minimo, varianza y desviacion estadar\n";
		cout<<"\n\t3. Ordenar de Forma Ascendente\n";
		cout<<"\n-Elija una opcion: ";	cin>>dato;
		estadistica(dato);
		cout<<"\n\n\t\tPara seguir en la App digite 'Y' (Y/N)"<<endl;
	    cin>>stopApp;
	} 
	while(toupper(stopApp) == 'Y');	
}

void estadistica(int dato){
	int  i, count = 0;
	double x[MAX], media, desv, cantidad, varianza, max, min, aux;
    ifstream archivo(ARCHIVO);
    string linea;
    char delimitador = ',';
   
    getline(archivo, linea);
    // Leemos todas las líneas
    while (getline(archivo, linea)){
    	
    	stringstream stream(linea); // Convertir la cadena a un stream
        string Tipo, Precio, Fecha, Hora;
        
        // Extraer todos los valores de esa fila en strings
		getline(stream, Tipo, delimitador);
        getline(stream, Precio, delimitador);
        getline(stream, Fecha, delimitador);
        getline(stream, Hora, delimitador);
        switch (dato){
			case 1:		
		cout << "\n______________________________" << endl; 
    	cout << "Tipo:\t " << Tipo << endl;
		cout << "Precio:\t " << Precio << endl;
		cout << "Fecha:\t " << Fecha << endl;
		cout << "Hora:\t " << Hora << endl;	
				break;
			case 2:
				x[i] = atof(Precio.c_str()); 
				break;
			case 3:
				x[i] = atof(Precio.c_str()); 
				 	for (int j = 0; j < i; j++){
			for (int k = 0; k < i-(j+1); k++){
		if(x[k] < x[k+1])
		{
			aux=x[k];
            x[k]=x[k+1];
            x[k+1]=aux;
		}
	}
}
		 for(int l=i-1; l>0; l--){
		  cout << "\n______________________________" << endl;
          cout<< "ordenado: \t"<<x[l]<<endl;
          cout << "Fecha:\t\t" << Fecha << endl;
	      cout << "Hora:\t\t" << Hora << endl;	 
	}

				break;

     		}
		i++;
	}
	archivo.close();	//Se cierra el archivo
	
	//Calculando la media
	for (int j = 0; j < i; j++)
	{
		media += x[j] / i;
	}
	//Varianza
	for (int j = 0; j < i ; j++)
	{
		varianza += pow((x[j]- media),2.0);
		}
	varianza = varianza/(i-1);
	//Calculando la desviacion estandar
	desv = sqrt(varianza);	
	//valor mimimo
	for (int j = 0; j < i ; j++)
	{
      if (j == 0 || min > x[j])
           min = x[j];
    }
    for (int j = 0; j < i ; j++)
	{
      if (j == 0 || max < x[j])
           max = x[j];
    }
	cout<<"\n\tLa Media es: \t\t\t\t"<<media;
	cout<<"\n\tEl valor Maximo: \t\t\t"<<max;
	cout<<"\n\tEl valor Minimo: \t\t\t"<<min;
	cout<<"\n\tLa Varianza: \t\t\t\t"<<varianza;
	cout<<"\n\tLa Desviacion Estandar es: \t\t"<<desv;	
}
