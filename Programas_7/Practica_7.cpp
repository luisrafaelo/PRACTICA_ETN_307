#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//calcular media
double media(int arr[], int size){
   int sum = 0;
   for (int i = 0; i < size; i++)
      sum += arr[i];
   return (double)sum/(double)size;
}
//calcular moda
double moda(int arr[], int size){
	int aux = 0, aux1 = 0, vale;
   for(int j=0; j<size; j++){
    for(int k=0; k<size; k++){
		if(arr[j]==arr[k]&& j!=k)
		aux++;
	}
	if(aux>aux1)
	{
		aux1=aux;
	vale=arr[j];
		}
		aux=0;
	}
	return vale;
}
//calcular mediana
double mediana(int arr[], int size){
   sort(arr, arr+size);
   if (size % 2 != 0)
      return (double)arr[size/2];
   return (double)(arr[(size-1)/2] + arr[size/2])/2.0;
}

int main(){
	int dato=0;
	   	cout<<"\n\n\t\tPregunta 5\n\n";
	do{
	
   	cout<<"\n\nDesea ver la media, mediana y moda de:";
	cout<<"\n\n\t 1.NORMALES \t\t 2.INTEGRALES:\n\n\t\t3. SALIR\n\n ==>";cin>>dato;
   
	   
switch (dato){
case 1:{
   	cout<<"\n\n\t\tNORMALES\n";
int arr[] = {125,125,150,135,150,130,130,145,135,145,130,150,140,150,140,
                145,130,130,130,140};
   int size = sizeof(arr)/sizeof(arr[0]);
   cout<<"\n\tLa Media es: \t\t\t"<< media(arr, size)<<endl;
   cout<<"\n\tLa Mediana es: \t\t\t"<< mediana(arr, size)<< endl;
   cout<<"\n\tLa Moda: \t\t\t"<<moda(arr, size)<< endl;
    cout<<"\n\tLos datos son: \n\n\t";
   for(int j=0; j<size; j++){
 		cout<<(float)arr[j]<<", ";}
   }
   break;
   	//   
  	case 2 :
  		{
   	cout<<"\n\n\t\tINTEGRALES\n";
int arr[] = {135,135,130,135,125,140,150,135,135,145,150,130};
   int size = sizeof(arr)/sizeof(arr[0]);
   cout<<"\n\tLa Media es: \t\t\t"<< media(arr, size)<<endl;
   cout<<"\n\tLa Mediana es: \t\t\t"<< mediana(arr, size)<< endl;
   cout<<"\n\tLa Moda: \t\t\t"<<moda(arr, size)<<endl;
   cout<<"\n\tLos datos son: \n\n\t";
   for(int j=0; j<size; j++){
 		cout<<(float)arr[j]<<", ";}
   }
      
   	 break;
   	 case 3:
   	 return 0;
   	 break;
   	   default: {
            	  cout<<"\n\n\t\t\tEleccion no valida!!!"<<endl;    
         }
	}	
	}   while (dato != 3);
   return 0;
}
