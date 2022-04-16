#include <iostream>
 
using namespace std;
 
void tower(int n, char source, char des, char via){
if(n == 1){//base
    cout << "Mueva el anillo "<< n << " desde " << source << " para " << des << ".\n";
 
}
else{//recursividad
    tower(n-1,source, via, des);
    cout << "Mueva el anillo " << n << " desde " << source << " para " << des << ".\n";
    tower(n-1,via,des,source);
}
 
}
 
int main()
{
    int rings;
    char source='A';
    char des = 'B';
    char via = 'C';
    	cout<<"\n\n\t\t Algoritmo numero 7\n";
    	cout<<"\n\n\t\tTorres de Hanoi \n";
    cout << "\n Ingres el numero de anillos : "; 
    cin >> rings;
    tower(rings,source,des,via);
 
    return 0;
}
