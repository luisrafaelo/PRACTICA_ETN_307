#include <iostream>
#include <sstream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <cmath>
#define ARCHIVO "fuga_clientes_empresa_telefonica_explotacion.csv"
#define MAX 295
using namespace std;

void estadistica (int);
void perchist(int);

int main(){
	int dato = 0;
 
	cout<<"\n\n\t\t\t\tConjunto de datos Fuga de Clientes Empresas Telefonica.CSV\n\n";
	

		cout<<"\n\t1. Lectura del archivo\n";
		cout<<"\n    Encontrar la media, La varianza, Desviacion estadar, Distancia a su media, Coef Pearson, Histograma, Percentiles\n";
		cout<<"\n\t2. Edad de la red.\t\t3. Antiguedad del cliente mes.\t\t4. Gasto total mes 1 y 2.\n";
		cout<<"\n\t5. Gasto total SMS.\t\t6. Gasto total en Datos.\t\t7. Consumo total de datos.\n";
		cout<<"\n\t8. Llamadas unicas totales.\t9. Gasto total en la red.\t\t10. Gasto total fuera de la red.\n\n\t11. Total llamadas de queja.\n";
		cout<<"\n\t\t12.Salida"<<endl;
		do{
		cout<<"\n\n-Elija una opcion: ";	cin>>dato;
		estadistica(dato);
		//perchist(dato);

	     }
	     while (dato != 12);
	     return 0;
}

void estadistica(int dato){
	int  i;
	double x[MAX], Aux1, Aux2, Aux3, media, desv, cantidad, varianza, dist_media, pearson, histograma, percentil;
    ifstream archivo(ARCHIVO);
    string linea;
    char delimitador = ',';
   
    getline(archivo, linea);
    // Leemos todas las líneas
    while (getline(archivo, linea)){
    	
    	stringstream stream(linea); // Convertir la cadena a un stream
        string n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11, n12, n13, n14, n15;
        
        // Extraer todos los valores de esa fila en strings
		getline(stream, n1, delimitador);
        getline(stream, n2, delimitador);
        getline(stream, n3, delimitador);
        getline(stream, n4, delimitador);
        getline(stream, n5, delimitador);
        getline(stream, n6, delimitador);
        getline(stream, n7, delimitador);
        getline(stream, n8, delimitador);
        getline(stream, n9, delimitador);
        getline(stream, n10, delimitador);
		getline(stream, n11, delimitador);
        getline(stream, n12, delimitador);
        getline(stream, n13, delimitador);
        getline(stream, n14, delimitador);
        getline(stream, n15, delimitador);
     
        //Dependiendo de la opcion escogida, se leera y almacenara ese tipo de dato
        switch (dato){
			case 1:	
			while(getline(archivo, linea)){
		cout << "\n______________________________" << endl; 
		cout << "ID del cliente:\t\t\t " << n1 << endl;
    	cout << "Edad de la red:\t\t\t " << n2 << endl;
		cout << "Antiguedad del cliente mes:\t " << n3 << endl;
		cout << "Gasto total mes 1 y 2:\t\t " << n4 << endl;
		cout << "Gasto total SMS:\t\t " << n5 << endl;	
		cout << "Gasto total en Datos:\t\t " << n6 << endl;
		cout << "Consumo total de datos:\t\t " << n7 << endl;
		cout << "Llamadas unicas totales:\t " << n8 << endl;
		cout << "Gasto total en la red:\t\t " << n9 << endl;	
		cout << "Gasto total fuera de la red:\t " << n10 << endl;
		cout << "Total llamadas de queja:\t " << n11 << endl;
		cout << "Suscripcion red mes 1:\t\t " << n12 << endl;
		cout << "Suscripcion red mes 2:\t\t " << n13 << endl;	
		cout << "Competidor mas querido 1:\t " << n14 << endl;
		cout << "Competidor mas querido 2:\t " << n15 << endl;
}
return;
				break;
		    	case 2:
				x[i] = atof(n2.c_str()); 
				break;
				case 3:
				x[i] = atof(n3.c_str()); 
				break;
				case 4:
				x[i] = atof(n4.c_str()); 
				break;
				case 5:
				x[i] = atof(n5.c_str()); 
				break;
				case 6:
				x[i] = atof(n6.c_str()); 
				break;
				case 7:
				x[i] = atof(n7.c_str()); 
				break;
				case 8:
				x[i] = atof(n8.c_str()); 
				break;
				case 9:
				x[i] = atof(n9.c_str()); 
				break;
				case 10:
				x[i] = atof(n10.c_str()); 
				break;
				case 11:
				x[i] = atof(n11.c_str()); 
				break;
			case 12: 
            return;
            break;
            default: {
            	  cout<<"\n\n\t\t\tEleccion no valida!!!"<<endl;
          return;
          
         }
     		}
		i++;
	
	}
	archivo.close();	//Se cierra el archivo
dato=dato*+sqrt(0);
	//Calculando la media
	for (int j = 0; j <(i); j++)
	{
		media += x[j] /(i);
		
	}
	
	//Varianza
	for (int j = 0; j < (i); j++)
	{
		varianza += pow((x[j]-media),2.0);
	
		}
	
	Aux1= varianza/(i-1);
	//Calculando la desviacion estandar
	desv = sqrt(Aux1);	
	//Calculando la desviacion media
	for (int j = 0; j < (i); j++){
		dist_media += abs(x[j] - media);
	}
	dist_media = dist_media / (i);
	//Calculando peraso
	pearson = desv/media;	
	//percentiles
	cout<<"\n\tPercentil:\n";
	for (int j = 2; j < (i); j++){
		percentil=0;
		for (int k = 0; k < (i); k++)
		{
	if (x[j] > x[k])
	percentil = percentil + 1;
	}
	Aux2=(percentil*100)/(i-1);
	cout<<"\n\tPercentil de: "<<x[j]<<"\tes\t"<<Aux2<<"%";
}
cout<<endl;
// histograma
	cout<<"\n\tHistograma:\n";
   for (int j = 2; j <(i) ; j++) {
      cout.width(6);
      cout << right << x[j] << " |";
     for (int k = 0; k < x[j]; k++) {
         if (x[j] > k)
            cout << "I";
      }
      cout << "\n";
      }
      //datos
	cout<<"\n\tLa Media es: \t\t\t\t"<<media;
	cout<<"\n\tLa Varianza: \t\t\t\t"<<Aux1;
	cout<<"\n\tLa Desviacion Estandar es: \t\t"<<desv;	
	cout<<"\n\tLa Distancia a la media es: \t\t"<<dist_media;	
	cout<<"\n\tcoeficiente de variacion de Pearson: \t"<<pearson;

	
}
