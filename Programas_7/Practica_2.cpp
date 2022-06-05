#include <iostream>
#include <sstream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#define ARCHIVO "predictive_maintenance.csv"
#define MAX 10010
using namespace std;
char stopApp;

void desviacion_y_media (int, string);

int main(){
	int dato = 0, m;
	string nombre;
	double mediaX, mediaY, desvX, desvY;
	cout<<"\t\t\tDESVIACION MEDIA DEL CONJUNTO DE DATOS\n\n";
	do{
		cout<<"\t\t\tTIPOS DE DATOS\n\n";
		cout<<"\t1. Temperatura de Aire [K]\t\t 2. Temperatura del Proceso [K]\n";
		cout<<"\t3. Velocidad Rotacional [rpm]\t\t 4. Torque [Nm]\n";
		cout<<"\t5. Desgaste de herramientas [min]\n";
		while(true){
			m = 0;
			cout<<"\n=>\tIndique el tipo de dato: ";	cin>>dato;
			//Por si estan fuera de las opciones
			if (dato < 1 || dato > 5){
				cout<<"\nNo es opcion valida\n";
				continue;
			}
			break;
		}
		switch (dato){
			case 1:
				nombre = "Temperatura de Aire [K]";
				break;
			case 2:
				nombre = "Temperatura del Proceso [K]";
				break;
			case 3:
				nombre = "Velocidad Rotacional [rpm]";
				break;
			case 4:
				nombre = "Torque [Nm]";
				break;
			case 5:
				nombre = "Desgaste de herramientas [min]";
				break;
		}
		//Resultados
		desviacion_y_media(dato, nombre);
		cout<<"\n\n\t\tPara seguir en la App digite 'Y' (Y/N)"<<endl;
	    cin>>stopApp;
	} 
	while(toupper(stopApp) == 'Y');	
}

void desviacion_y_media(int dato, string nombre){
	int  i, count = 0;
	double x[MAX], media, desv;
    ifstream archivo(ARCHIVO);
    string linea;
    char delimitador = ',';
    // Leemos la primer línea para descartarla, pues es el encabezado
    getline(archivo, linea);
    // Leemos todas las líneas
    while (getline(archivo, linea)){
    	
    	stringstream stream(linea); // Convertir la cadena a un stream
        string UDI, Product_ID, Type, Air_Temperature_K, Process_Temperature_K, Rotational_Speed_rpm,Torque_Nm, Tool_Wear_min;
        
        // Extraer todos los valores de esa fila en strings
		getline(stream, UDI, delimitador);
        getline(stream, Product_ID, delimitador);
        getline(stream, Type, delimitador);
        getline(stream, Air_Temperature_K, delimitador);
        getline(stream, Process_Temperature_K, delimitador);
        getline(stream, Rotational_Speed_rpm, delimitador);
        getline(stream, Torque_Nm, delimitador);
        getline(stream, Tool_Wear_min, delimitador);
        
        //Dependiendo de la opcion escogida, se leera y almacenara ese tipo de dato
        switch (dato){
			case 1:		
				x[i] = atof(Air_Temperature_K.c_str());; 	//atof es para transformar de string a double y es por stdlib.h
				break;
			case 2:
				x[i] = atof(Process_Temperature_K.c_str()); 
				break;
			case 3:
				x[i] = atof(Rotational_Speed_rpm.c_str()); 
				break;
			case 4:
				x[i] = atof(Torque_Nm.c_str()); 
				break;
			case 5:
				x[i] = atof(Tool_Wear_min.c_str()); 
				break;
		}
		i++;
	}
	archivo.close();	//Se cierra el archivo
	
	//Calculando la media aritmetica
	for (int j = 0; j < (i+1); j++){
		media += x[j] / (i+1);
	}
	//Calculando la desviacion media
	for (int k = 0; k < (i+1); k++){
		desv += abs(x[k] - media);
	}
	desv = desv / (i+1);
	
	//resultados
	cout<<"\n\n-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-";
	cout<<"\n\tLa Media es: \t\t\t\t"<<media;
	cout<<"\n\tLa Desviacion Media es: \t\t"<<desv;
	cout<<"\n\t\t\t\t\t\t"<<nombre;
	cout<<"\n\n-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-";
	
}
