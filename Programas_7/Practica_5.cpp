#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	float aux=0, aux1=0, moda, sum, mediana, media;
   double arr[] = {0.16,0.2,0.06,0.06,0.07,0.17,0.06,0.22,0.2,0.2,0.2,0.2};
   	cout<<"\n\n\t\t\tPregunta 5\n\n";
 
   int size = sizeof(arr)/sizeof(arr[0]);
   //paises
   for(int j=0; j<size; j++){
 		cout<<"\t\t"<<(float)arr[j]<<endl;}
 		//media
 	for(int j=0; j<size; j++){
 		sum += (double)arr[j];
		 }	
	media = (double)sum/(double)size;
  cout<<"\n\tLa Media es: \t\t\t"<< media<<endl;
  //mediana
  sort(arr, arr+size);
   if (size % 2 != 0)
   mediana = (double)arr[size/2];
   mediana = (double)(arr[(size-1)/2] + arr[size/2])/2.0;
  cout<<"\n\tLa Mediana es: \t\t\t"<< mediana<< endl;
  //moda
   for(int j=0; j<size; j++){
    for(int k=0; k<size; k++){
		if(arr[j]==arr[k]&& j!=k)
		aux++;
	}
	if(aux>aux1)
	{
		aux1=aux;
	moda=arr[j];
		}
		aux=0;
	}
   	cout<<"\n\tLa Moda: \t\t\t"<<moda;
   return 0;
}
