/*
	Name:  Resolver un sistema de 2 ecuaciones y 2 incógnitas
	Author: Luis Rafael Alberto Limachi
	Date: 04/03/22 14:26
	Description: 
*/

#include <iostream> //librerias

using namespace std;
char stopApp;

int main()
{
	do{
float x1,y1,re1;
float x2,y2,re2;
float y,x,z,xr,yr,zr;

cout<<"2 ECUACIONES CON 2 INCOGNITAS"<<endl;
cout<<"   -"<<endl;
cout<<"   | aX+bY=c"<<endl;
cout<<"   | dX+eY=f"<<endl;
cout<<"   -"<<endl;
cout<<"inserta la primera ecuacion"<<endl;
cout<<"  "<<endl;
cout<<"inserta el valor de aX: "<<endl;
cin>>x1;
cout<<"inserta el valor de bY: "<<endl;
cin>>y1;
cout<<"inserta el resulado c: "<<endl;
cin>>re1;
cout<<"  "<<endl;
cout<<"inserta la segunda ecuacion"<<endl;
cout<<"  "<<endl;
cout<<"inserta el valor de dX: "<<endl;
cin>>x2;
cout<<"inserta el valor de eY: "<<endl;
cin>>y2;
cout<<"inserta el resultado f: "<<endl;
cin>>re2;

x=-x2*x1;
y=-x2*y1;
z=-x2*re1;

xr=x1*x2;
yr=x1*y2;
zr=x1*re2;

x=x+xr;
y=y+yr;
z=z+zr;
y=z/y;

z=re1-y*y1;
x=z/x1;

cout<<"EL VALOR DE Y ES: "<<y<<endl;
cout<<"EL VALOR DE X ES: "<<x<<endl;

cout <<""<<endl;
cout << "Para seguir en la App digite 'Y' (Y/N)" << endl;
        cin >> stopApp; 
    }
	while(toupper(stopApp) == 'Y');
system("pause");

return 0;
}
