 //
 //			PRACTICA 1.3
 //			ECUACIONES DE TERCER GRADO
 //			
#include <iostream>
#include <math.h>//librerias
#include <conio.h>
using namespace std;
 
int main(){
   double a,b,c,d;  //variables de la ecuación
   double a1,b1,c1;
   double p,q,dsc;
   double x,y,z,pi;
   double ab,ac;
   double u,v,t;
 
   cout << "                 Calculadora de Ecuacion cubica"<<endl;
   cout << ""<<endl;
   cout << "  Inserte los datos para la siguiente forma: aX^3 + bX^2 + cX + d"<<endl;
   cout << ""<<endl;
   cout << " Para a :"; cin>> a;
   cout << " Para b :"; cin>> b;
   cout << " Para c :"; cin>> c;
   cout << " Para d :"; cin>> d;
   cout<<""<<endl;
 if (char()==a or char()==b  or char()==c  or char()==d  )
	{
		cout << "                 INGRESE NUMEROS, NO LETRAS!!!" << endl;
	}
   cout.precision(5); // decimales que se mostrarán
   pi = 3.14159;
   a1 = b/a;
   b1 = c/a;
   c1 = d/a;
   p = b1 - (a1*a1)/3;
   q = (2*a1*a1*a1)/27 - (a1*b1)/3 + c1; 
   dsc = (q*q) + (4*p*p*p)/27; 
   
   if ( dsc > 0 ) { //discriminante > 0
     ab = 0.5*(-q + sqrt(dsc));
     double rcb(ab); // raiz cubica 1, calculo de u
     if (ab> 0) {
	rcb = exp(log(ab)/3);
     };
     if (ab== 0){
	rcb = 0;
     };
     if (ab<0) {
	rcb =-exp(log(-ab)/3);
     };
     ac = -0.5*(q + sqrt(dsc));
	 double rcb2(ac);
    if (ac> 0) {
	rcb2 = exp(log(ac)/3); //raiz cubica 2, calculo de v
     };
     if (ac== 0){
	rcb2 = 0;
     };
     if (ac<0) {
	rcb2 =-exp(log(-ac)/3);
     };
     u = rcb; // variable u del metodo de cardano
     v = rcb2; // variable v del metodo de cardano
     x = u + v -(a1/3);
     y = (-0.5)*(u+v) -(a1/3);
     z = (0.5)*sqrt(3)*(u-v);
   	cout<<" Existe una raiz real y 2 complejas "<<endl;
     cout<<" X1 :"<<x<<endl;
     cout<<" X2 :"<<y<<" + "<<z<<"i"<<endl;
     cout<<" X3 :"<<y<<" - "<<z<<"i"<<endl;
    };
 
 
   if ((dsc == 0) and (p == 0)){ //discriminante= p = 0
     cout<<" Existe una sola raiz"<<endl;
     cout<<" X :"<<-(a1/3);
	};
 
 
   if ((dsc == 0) and (p!=0)){ // discriminante = 0
     ab = -0.5*q;
     double rcb(ab);
     if (ab> 0) {
	rcb = exp(log(ab)/3); // raiz cubica de u, solo se calcula u
     };
     if (ab== 0){
	rcb = 0;
     };
     if (ab<0) {
	rcb =-exp(log(-ab)/3);
     };
     u = rcb;
     x = 2*u -(a1/3);
     y = -u -(a1/3);
     cout<<" La solucion tiene las siguientes raices:"<<endl;
     cout<<" X1    :"<<x<<endl;
     cout<<" X2=X3 :"<<y<<endl;
	};
 
 
   if ( dsc < 0) { // discriminate < 0
    x = (2*sqrt(-p/3))*cos(acos((-q/2)*sqrt(-27/(p*p*p)))/3) -(a1/3);
    y = (2*sqrt(-p/3))*cos(acos((-q/2)*sqrt((-27)/(p*p*p)))/3 +2*pi/3) -(a1/3);
    z = (2*sqrt(-p/3))*cos(acos((-q/2)*sqrt((-27)/(p*p*p)))/3 +4*pi/3) -(a1/3);
     cout<<" La solucion es la siguiente: "<<endl;
     cout<<" X1 :"<<x<<endl;
     cout<<" X2 :"<<y<<endl;
     cout<<" X3 :"<<z<<endl;
    };

    return 0;
} 
 

