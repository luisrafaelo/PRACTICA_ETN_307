/*
	Name: Hallar las partes que componen un triangulo
	Autores: Alberto Limachi Luis Rafael
	         Nina Mamani Itamar Esteban
	Description: 1 Resolución de triángulos  dados 3 datos
	  tres lados , tres ángulos, 2 lados  1 ángulo ,
	  2 ángulos 1 lado  resolver los otros tres valores  y 
	  calcular  el area y superficie del triangulo y medianas
*/
#include <iostream>
#include <conio.h>
#include <math.h>
using namespace std;
char stopApp;
char A, B, C;
char a, b, c;
char dato1, dato2, dato3;
float aux1, aux2, aux3;
float num1, num2, num3;
float grad,rad;
int main()
{
do{
	cout<<    "		    PARA EL TRIANGULO"<<endl;
	cout<<    ""<<endl;
	cout<<    "		           C"<<endl;
	cout<<    "		           *"<<endl;
	cout<<    "		          * *"<<endl;
	cout<<    "		         *   *"<<endl;
	cout<<    "		     b  *     *"<<endl;
	cout<<    "		       *       *  a"<<endl;
	cout<<    "		      *         *"<<endl;
	cout<<    "		     *           *"<<endl;
	cout<<    "		  A * * * * * * * * B "<<endl;
	cout<<    "		           c         "<<endl;
	cout<<    ""<<endl;
	cout<<    "Siendo los lados 'a','b'y 'c'; los angulos 'A', 'B' y 'C'"<<endl;
	cout<<    "que se aprecian en la figura."<<endl;
	cout<<    ""<<endl;
	cout<<    "Ingrese un lado o angulo, poniendo al letra correspondiente:"<<endl;
	cout<<    " y presione 'enter':"<<endl;
	cin>>dato1;
	cout<<    "Ingrese el valor:"<<endl;
	cin>>num1;
	cout<<    "Ingrese el segundo lado o angulo"<<endl;
	cin>>dato2;
	cout<<    "Ingrese el valor:"<<endl;
	cin>>num2;
	cout<<    "Ingrese el tercer lado o angulo"<<endl;
	cin>>dato3;
	cout<<    "Ingrese el valor:"<<endl;
	cin>>num3;
	grad=180/3.14159265359;
	rad=3.14159265359/180;
	switch(dato1)
{
    case 'a'://INICIO a
   			switch(dato2)	{
		    case 'b'://INICIO a b
  			switch(dato3)	{
			    case 'c'://PARA a b c
			    		if(num1<num2+num3 and num2<num1+num3 and num3<num1+num2)//propiedad triangular
						{
					aux1=acos((num2*num2+num3*num3-num1*num1)/(2*num2*num3));	
					aux2=acos((num3*num3+num1*num1-num2*num2)/(2*num1*num3));	
					aux3=acos((num2*num2-num3*num3+num1*num1)/(2*num2*num1));
					
					cout << ""<<endl;
					
					cout << "los lados son: "<<endl;
					cout << "  a: "<<num1<<endl;
					cout << "  b: "<<num2<<endl;
					cout << "  c: "<<num3<<endl;
					
					cout << "los angulos son: "<<endl;
					cout << "  A: "<<aux1*grad<<endl;
					cout << "  B: "<<aux2*grad<<endl;
					cout << "  C: "<<aux3*grad<<endl;
					
					cout << "las medianas son: "<<endl;
					cout <<"  Ma= "<<(sqrt(2*(num2*num2+num3*num3)-num1*num1))/2<<endl;
					cout <<"  Mb= "<<(sqrt(2*(num1*num1+num3*num3)-num2*num2))/2<<endl;
					cout <<"  Mc= "<<(sqrt(2*(num2*num2+num1*num1)-num3*num3))/2<<endl;
					
					cout << "el area:  "<<(num3*sin(aux2)*num1)/2<<endl;
					cout << "el perimetro:  "<<num1+num2+num3<<endl;
						}
						else
						cout << "los datos ingresados no cumplen la propiedad triangular"<<endl;
			            break;
    
			    case 'A'://PARA a b A
			    if (num2*sin(num3*rad)<=num1)
				{ 
				if (num1<num2)
				{
					aux2=asin(num2*sin(num3*rad)/num1)*grad;
					aux3=180-(num3+aux2);
					aux1=num1*sin(aux3*rad)/sin(num3*rad);
										
					cout << "los lados son: "<<endl;
					cout << "  a: "<<num1<<endl;
					cout << "  b: "<<num2<<endl;
					cout << "  c: "<<aux1<<endl;
										
					cout << "los angulos son: "<<endl;
					cout << "  A: "<<num3<<endl;
					cout << "  B: "<<aux2<<endl;
					cout << "  C: "<<aux3<<endl;
					
					cout << "las medianas son: "<<endl;
					cout <<"  Ma= "<<(sqrt(2*(num2*num2+aux1*aux1)-num1*num1))/2<<endl;
					cout <<"  Mb= "<<(sqrt(2*(num1*num1+aux1*aux1)-num2*num2))/2<<endl;
					cout <<"  Mc= "<<(sqrt(2*(num2*num2+num1*num1)-aux1*aux1))/2<<endl;
					
					cout << "el area:  "<<(num1*sin(aux3*rad)*num2)/2<<endl;
					cout << "el perimetro:  "<<num1+num2+aux1<<endl;
					cout << ""<<endl;
					cout << "segunda solucion"<<endl;
					aux2=180-asin(num2*sin(num3*rad)/num1)*grad;
					aux3=180-(num3+aux2);
					aux1=num1*sin(aux3*rad)/sin(num3*rad);
										
					cout << "los lados son: "<<endl;
					cout << "  a: "<<num1<<endl;
					cout << "  b: "<<num2<<endl;
					cout << "  c: "<<aux1<<endl;
										
					cout << "los angulos son: "<<endl;
					cout << "  A: "<<num3<<endl;
					cout << "  B: "<<aux2<<endl;
					cout << "  C: "<<aux3<<endl;
					
					cout << "las medianas son: "<<endl;
					cout <<"  Ma= "<<(sqrt(2*(num2*num2+aux1*aux1)-num1*num1))/2<<endl;
					cout <<"  Mb= "<<(sqrt(2*(num1*num1+aux1*aux1)-num2*num2))/2<<endl;
					cout <<"  Mc= "<<(sqrt(2*(num2*num2+num1*num1)-aux1*aux1))/2<<endl;
					
					cout << "el area:  "<<(num1*sin(aux3*rad)*num2)/2<<endl;
					cout << "el perimetro:  "<<num1+num2+aux1<<endl;			
				}
				else
				{
					aux2=asin(num2*sin(num3*rad)/num1)*grad;
					aux3=180-(num3+aux2);
					aux1=num1*sin(aux3*rad)/sin(num3*rad);
										
					cout << "los lados son: "<<endl;
					cout << "  a: "<<num1<<endl;
					cout << "  b: "<<num2<<endl;
					cout << "  c: "<<aux1<<endl;
										
					cout << "los angulos son: "<<endl;
					cout << "  A: "<<num3<<endl;
					cout << "  B: "<<aux2<<endl;
					cout << "  C: "<<aux3<<endl;
					
					cout << "las medianas son: "<<endl;
					cout <<"  Ma= "<<(sqrt(2*(num2*num2+aux1*aux1)-num1*num1))/2<<endl;
					cout <<"  Mb= "<<(sqrt(2*(num1*num1+aux1*aux1)-num2*num2))/2<<endl;
					cout <<"  Mc= "<<(sqrt(2*(num2*num2+num1*num1)-aux1*aux1))/2<<endl;
					
					cout << "el area:  "<<(num1*sin(aux3*rad)*num2)/2<<endl;
					cout << "el perimetro:  "<<num1+num2+aux1<<endl;
				}
			}
			    else
			    cout<<"NO TIENE SOLUCION"<<endl;
			
			    break;
    
			    case 'B':// PARA a b B
			     if (num2*sin(num3*rad)<=num1)
				{
					if (num1>num2)
				{
					aux2=asin(num1*sin(num3*rad)/num2)*grad;
					aux3=180-(num3+aux2);
					aux1=num1*sin(aux3*rad)/sin(aux2*rad);
									
					cout << "los lados son: "<<endl;
					cout << "  a: "<<num1<<endl;
					cout << "  b: "<<num2<<endl;
					cout << "  c: "<<aux1<<endl;
										
					cout << "los angulos son: "<<endl;
					cout << "  A: "<<aux2<<endl;
					cout << "  B: "<<num3<<endl;
					cout << "  C: "<<aux3<<endl;
					
					cout << "las medianas son: "<<endl;
					cout <<"  Ma= "<<(sqrt(2*(num2*num2+aux1*aux1)-num1*num1))/2<<endl;
					cout <<"  Mb= "<<(sqrt(2*(num1*num1+aux1*aux1)-num2*num2))/2<<endl;
					cout <<"  Mc= "<<(sqrt(2*(num2*num2+num1*num1)-aux1*aux1))/2<<endl;
					
					cout << "el area:  "<<(num1*sin(aux3*rad)*num2)/2<<endl;
					cout << "el perimetro:  "<<num1+num2+aux1<<endl;
					cout << ""<<endl;
					cout << "segunda solucion"<<endl;
					aux2=180-asin(num1*sin(num3*rad)/num2)*grad;
					aux3=180-(num3+aux2);
					aux1=num1*sin(aux3*rad)/sin(aux2*rad);
									
					cout << "los lados son: "<<endl;
					cout << "  a: "<<num1<<endl;
					cout << "  b: "<<num2<<endl;
					cout << "  c: "<<aux1<<endl;
										
					cout << "los angulos son: "<<endl;
					cout << "  A: "<<aux2<<endl;
					cout << "  B: "<<num3<<endl;
					cout << "  C: "<<aux3<<endl;
					
					cout << "las medianas son: "<<endl;
					cout <<"  Ma= "<<(sqrt(2*(num2*num2+aux1*aux1)-num1*num1))/2<<endl;
					cout <<"  Mb= "<<(sqrt(2*(num1*num1+aux1*aux1)-num2*num2))/2<<endl;
					cout <<"  Mc= "<<(sqrt(2*(num2*num2+num1*num1)-aux1*aux1))/2<<endl;
					
					cout << "el area:  "<<(num1*sin(aux3*rad)*num2)/2<<endl;
					cout << "el perimetro:  "<<num1+num2+aux1<<endl;
				}
				else{
					aux2=asin(num1*sin(num3*rad)/num2)*grad;
					aux3=180-(num3+aux2);
					aux1=num1*sin(aux3*rad)/sin(aux2*rad);
									
					cout << "los lados son: "<<endl;
					cout << "  a: "<<num1<<endl;
					cout << "  b: "<<num2<<endl;
					cout << "  c: "<<aux1<<endl;
										
					cout << "los angulos son: "<<endl;
					cout << "  A: "<<aux2<<endl;
					cout << "  B: "<<num3<<endl;
					cout << "  C: "<<aux3<<endl;
					
					cout << "las medianas son: "<<endl;
					cout <<"  Ma= "<<(sqrt(2*(num2*num2+aux1*aux1)-num1*num1))/2<<endl;
					cout <<"  Mb= "<<(sqrt(2*(num1*num1+aux1*aux1)-num2*num2))/2<<endl;
					cout <<"  Mc= "<<(sqrt(2*(num2*num2+num1*num1)-aux1*aux1))/2<<endl;
					
					cout << "el area:  "<<(num1*sin(aux3*rad)*num2)/2<<endl;
					cout << "el perimetro:  "<<num1+num2+aux1<<endl;
				}
				}
			    else
			    cout<<"NO TIENE SOLUCION"<<endl;
			    break;
    
			    case 'C':// para a b C
			    if (num3!=180)
				{
					aux1=sqrt(num1*num1+num2*num2-(2*num1*num2*cos(num3*rad)));		
					aux2=acos((num2*num2+aux1*aux1-num1*num1)/(2*num2*aux1));	
					aux3=acos((aux1*aux1+num1*num1-num2*num2)/(2*num1*aux1));	
					
										
					cout << "los lados son: "<<endl;
					cout << "  a: "<<num1<<endl;
					cout << "  b: "<<num2<<endl;
					cout << "  c: "<<aux1<<endl;
										
					cout << "los angulos son: "<<endl;
					cout << "  A: "<<aux2*grad<<endl;
					cout << "  B: "<<aux3*grad<<endl;
					cout << "  C: "<<num3<<endl;
					
					cout << "las medianas son: "<<endl;
					cout <<"  Ma= "<<(sqrt(2*(num2*num2+aux1*aux1)-num1*num1))/2<<endl;
					cout <<"  Mb= "<<(sqrt(2*(num1*num1+aux1*aux1)-num2*num2))/2<<endl;
					cout <<"  Mc= "<<(sqrt(2*(num2*num2+num1*num1)-aux1*aux1))/2<<endl;
					
					cout << "el area:  "<<(num1*sin(num3*rad)*num2)/2<<endl;
					cout << "el perimetro:  "<<num1+num2+aux1<<endl;
				}
			    else
			    cout<<"NO TIENE SOLUCION"<<endl;
			    break;
    
			    default: cout << "Usted ha ingresado una opcion incorrecta"<<endl;
								} 
			break;//fin switch case a partir del tercer Dato
											 
		    case 'c':// INICIO a c
		    switch(dato3)	{
		    	
			    case 'b':// PARA a c b
			    if(num1<num2+num3 and num2<num1+num3 and num3<num1+num2)//propiedad triangular
						{
					aux1=acos((num2*num2+num3*num3-num1*num1)/(2*num2*num3));	
					aux2=acos((num3*num3+num1*num1-num2*num2)/(2*num1*num3));	
					aux3=acos((num2*num2-num3*num3+num1*num1)/(2*num2*num1));
					
					cout << ""<<endl;
					
					cout << "los lados son: "<<endl;
					cout << "  a: "<<num1<<endl;
					cout << "  b: "<<num3<<endl;
					cout << "  c: "<<num2<<endl;
					
					cout << "los angulos son: "<<endl;
					cout << "  A: "<<aux1*grad<<endl;
					cout << "  B: "<<aux3*grad<<endl;
					cout << "  C: "<<aux2*grad<<endl;
					
					cout << "las medianas son: "<<endl;
					cout <<"  Ma= "<<(sqrt(2*(num2*num2+num3*num3)-num1*num1))/2<<endl;
					cout <<"  Mb= "<<(sqrt(2*(num2*num2+num1*num1)-num3*num3))/2<<endl;
					cout <<"  Mc= "<<(sqrt(2*(num1*num1+num3*num3)-num2*num2))/2<<endl;
					
					cout << "el area:  "<<(num3*sin(aux2)*num1)/2<<endl;
					cout << "el perimetro:  "<<num1+num2+num3<<endl;
						}
						else
						cout << "los datos ingresados no cumplen la propiedad triangular"<<endl;
			            break;	    
    
			    case 'A': // PARA a c A
			    if (num2*sin(num3*rad)<=num1)
				{
					if(num1<num2){
					aux2=asin(num2*sin(num3*rad)/num1)*grad;
					aux3=180-(num3+aux2);
					aux1=num1*sin(aux3*rad)/sin(num3*rad);
										
					cout << "los lados son: "<<endl;
					cout << "  a: "<<num1<<endl;
					cout << "  b: "<<aux1<<endl;
					cout << "  c: "<<num2<<endl;
										
					cout << "los angulos son: "<<endl;
					cout << "  A: "<<num3<<endl;
					cout << "  B: "<<aux3<<endl;
					cout << "  C: "<<aux2<<endl;
					
					cout << "las medianas son: "<<endl;
					cout <<"  Ma= "<<(sqrt(2*(num2*num2+aux1*aux1)-num1*num1))/2<<endl;
					cout <<"  Mb= "<<(sqrt(2*(num1*num1+num2*num2)-aux1*aux1))/2<<endl;
					cout <<"  Mc= "<<(sqrt(2*(num1*num1+aux1*aux1)-num2*num2))/2<<endl;
					
					cout << "el area:  "<<(num1*sin(aux3*rad)*num2)/2<<endl;
					cout << "el perimetro:  "<<num1+num2+aux1<<endl;
					cout << " "<<endl;
					cout << "Segunda solucion: "<<endl;
					aux2=180-asin(num2*sin(num3*rad)/num1)*grad;
					aux3=180-(num3+aux2);
					aux1=num1*sin(aux3*rad)/sin(num3*rad);
										
					cout << "los lados son: "<<endl;
					cout << "  a: "<<num1<<endl;
					cout << "  b: "<<aux1<<endl;
					cout << "  c: "<<num2<<endl;
										
					cout << "los angulos son: "<<endl;
					cout << "  A: "<<num3<<endl;
					cout << "  B: "<<aux3<<endl;
					cout << "  C: "<<aux2<<endl;
					
					cout << "las medianas son: "<<endl;
					cout <<"  Ma= "<<(sqrt(2*(num2*num2+aux1*aux1)-num1*num1))/2<<endl;
					cout <<"  Mb= "<<(sqrt(2*(num1*num1+num2*num2)-aux1*aux1))/2<<endl;
					cout <<"  Mc= "<<(sqrt(2*(num1*num1+aux1*aux1)-num2*num2))/2<<endl;
					
					cout << "el area:  "<<(num1*sin(aux3*rad)*num2)/2<<endl;
					cout << "el perimetro:  "<<num1+num2+aux1<<endl;
				}
				else
				{
					aux2=asin(num2*sin(num3*rad)/num1)*grad;
					aux3=180-(num3+aux2);
					aux1=num1*sin(aux3*rad)/sin(num3*rad);
										
					cout << "los lados son: "<<endl;
					cout << "  a: "<<num1<<endl;
					cout << "  b: "<<aux1<<endl;
					cout << "  c: "<<num2<<endl;
										
					cout << "los angulos son: "<<endl;
					cout << "  A: "<<num3<<endl;
					cout << "  B: "<<aux3<<endl;
					cout << "  C: "<<aux2<<endl;
					
					cout << "las medianas son: "<<endl;
					cout <<"  Ma= "<<(sqrt(2*(num2*num2+aux1*aux1)-num1*num1))/2<<endl;
					cout <<"  Mb= "<<(sqrt(2*(num1*num1+num2*num2)-aux1*aux1))/2<<endl;
					cout <<"  Mc= "<<(sqrt(2*(num1*num1+aux1*aux1)-num2*num2))/2<<endl;
					
					cout << "el area:  "<<(num1*sin(aux3*rad)*num2)/2<<endl;
					cout << "el perimetro:  "<<num1+num2+aux1<<endl;
				}
			}
			    else
			    cout<<"NO TIENE SOLUCION"<<endl;
				break;
    
			    case 'B':// para a c B
			    if (num3!=180)
				{
					aux1=sqrt(num1*num1+num2*num2-(2*num1*num2*cos(num3*rad)));		
					aux2=acos((num2*num2+aux1*aux1-num1*num1)/(2*num2*aux1));	
					aux3=acos((aux1*aux1+num1*num1-num2*num2)/(2*num1*aux1));	
					
										
					cout << "los lados son: "<<endl;
					cout << "  a: "<<num1<<endl;
					cout << "  b: "<<aux1<<endl;
					cout << "  c: "<<num2<<endl;
										
					cout << "los angulos son: "<<endl;
					cout << "  A: "<<aux2*grad<<endl;
					cout << "  B: "<<num3<<endl;
					cout << "  C: "<<aux3*grad<<endl;
					
					cout << "las medianas son: "<<endl;
					cout <<"  Ma= "<<(sqrt(2*(num2*num2+aux1*aux1)-num1*num1))/2<<endl;
					cout <<"  Mb= "<<(sqrt(2*(num2*num2+num1*num1)-aux1*aux1))/2<<endl;
					cout <<"  Mc= "<<(sqrt(2*(num1*num1+aux1*aux1)-num2*num2))/2<<endl;
					
					cout << "el area:  "<<(num1*sin(num3*rad)*num2)/2<<endl;
					cout << "el perimetro:  "<<num1+num2+aux1<<endl;
				}
			    else
			    cout<<"NO TIENE SOLUCION"<<endl;
			    break;
    
			    case 'C': //PARA a c C
			    if (num2*sin(num3*rad)<=num1)
				{
					if(num2<num1)
					{
					aux2=asin(num1*sin(num3*rad)/num2)*grad;
					aux3=180-(num3+aux2);
					aux1=num1*sin(aux3*rad)/sin(aux2*rad);
					
					cout << "los lados son: "<<endl;
					cout << "  a: "<<num1<<endl;
					cout << "  b: "<<aux1<<endl;
					cout << "  c: "<<num2<<endl;
										
					cout << "los angulos son: "<<endl;
					cout << "  A: "<<aux2<<endl;
					cout << "  B: "<<aux3<<endl;
					cout << "  C: "<<num3<<endl;
					
					cout << "las medianas son: "<<endl;
					cout <<"  Ma= "<<(sqrt(2*(num2*num2+aux1*aux1)-num1*num1))/2<<endl;
					cout <<"  Mb= "<<(sqrt(2*(num1*num1+num2*num2)-aux1*aux1))/2<<endl;
					cout <<"  Mc= "<<(sqrt(2*(num1*num1+aux1*aux1)-num2*num2))/2<<endl;
					
					cout << "el area:  "<<(num1*sin(aux3*rad)*num2)/2<<endl;
					cout << "el perimetro:  "<<num1+num2+aux1<<endl;
					cout<<""<<endl;
					cout<<"segunda solucion"<<endl;
					aux2=180-asin(num1*sin(num3*rad)/num2)*grad;
					aux3=180-(num3+aux2);
					aux1=num1*sin(aux3*rad)/sin(aux2*rad);
					
					cout << "los lados son: "<<endl;
					cout << "  a: "<<num1<<endl;
					cout << "  b: "<<aux1<<endl;
					cout << "  c: "<<num2<<endl;
										
					cout << "los angulos son: "<<endl;
					cout << "  A: "<<aux2<<endl;
					cout << "  B: "<<aux3<<endl;
					cout << "  C: "<<num3<<endl;
					
					cout << "las medianas son: "<<endl;
					cout <<"  Ma= "<<(sqrt(2*(num2*num2+aux1*aux1)-num1*num1))/2<<endl;
					cout <<"  Mb= "<<(sqrt(2*(num1*num1+num2*num2)-aux1*aux1))/2<<endl;
					cout <<"  Mc= "<<(sqrt(2*(num1*num1+aux1*aux1)-num2*num2))/2<<endl;
					
					cout << "el area:  "<<(num1*sin(aux3*rad)*num2)/2<<endl;
					cout << "el perimetro:  "<<num1+num2+aux1<<endl;
				}
				else
				{
					aux2=asin(num1*sin(num3*rad)/num2)*grad;
					aux3=180-(num3+aux2);
					aux1=num1*sin(aux3*rad)/sin(aux2*rad);
					
					cout << "los lados son: "<<endl;
					cout << "  a: "<<num1<<endl;
					cout << "  b: "<<aux1<<endl;
					cout << "  c: "<<num2<<endl;
										
					cout << "los angulos son: "<<endl;
					cout << "  A: "<<aux2<<endl;
					cout << "  B: "<<aux3<<endl;
					cout << "  C: "<<num3<<endl;
					
					cout << "las medianas son: "<<endl;
					cout <<"  Ma= "<<(sqrt(2*(num2*num2+aux1*aux1)-num1*num1))/2<<endl;
					cout <<"  Mb= "<<(sqrt(2*(num1*num1+num2*num2)-aux1*aux1))/2<<endl;
					cout <<"  Mc= "<<(sqrt(2*(num1*num1+aux1*aux1)-num2*num2))/2<<endl;
					
					cout << "el area:  "<<(num1*sin(aux3*rad)*num2)/2<<endl;
					cout << "el perimetro:  "<<num1+num2+aux1<<endl;}
				}
			    else
			    cout<<"NO TIENE SOLUCION"<<endl;
			    break;
    
			    default: cout << "Usted ha ingresado una opcion incorrecta"<<endl;
								}
		    break;// fin de a c
    
		    case 'A':// PARA a A
		    switch(dato3)	{
			    case 'c': // PARA a A c
			   if (num3*sin(num2*rad)<=num1)
				{
					if(num1<num3){
					aux2=asin(num3*sin(num2*rad)/num1)*grad;
					aux3=180-(num2+aux2);
					aux1=num1*sin(aux3*rad)/sin(num2*rad);
										
					cout << "los lados son: "<<endl;
					cout << "  a: "<<num1<<endl;
					cout << "  b: "<<aux1<<endl;
					cout << "  c: "<<num3<<endl;
										
					cout << "los angulos son: "<<endl;
					cout << "  A: "<<num2<<endl;
					cout << "  B: "<<aux3<<endl;
					cout << "  C: "<<aux2<<endl;
					
					cout << "las medianas son: "<<endl;
					cout <<"  Ma= "<<(sqrt(2*(num3*num3+aux1*aux1)-num1*num1))/2<<endl;
					cout <<"  Mb= "<<(sqrt(2*(num1*num1+num3*num3)-aux1*aux1))/2<<endl;
					cout <<"  Mc= "<<(sqrt(2*(num1*num1+aux1*aux1)-num3*num3))/2<<endl;
					
					cout << "el area:  "<<(num1*sin(aux3*rad)*num3)/2<<endl;
					cout << "el perimetro:  "<<num1+num3+aux1<<endl;
					cout << " "<<endl;
					cout << "Segunda solucion: "<<endl;
					aux2=180-asin(num3*sin(num2*rad)/num1)*grad;
					aux3=180-(num2+aux2);
					aux1=num1*sin(aux3*rad)/sin(num2*rad);
										
					cout << "los lados son: "<<endl;
					cout << "  a: "<<num1<<endl;
					cout << "  b: "<<aux1<<endl;
					cout << "  c: "<<num3<<endl;
										
					cout << "los angulos son: "<<endl;
					cout << "  A: "<<num2<<endl;
					cout << "  B: "<<aux3<<endl;
					cout << "  C: "<<aux2<<endl;
					
					cout << "las medianas son: "<<endl;
					cout <<"  Ma= "<<(sqrt(2*(num3*num3+aux1*aux1)-num1*num1))/2<<endl;
					cout <<"  Mb= "<<(sqrt(2*(num1*num1+num3*num3)-aux1*aux1))/2<<endl;
					cout <<"  Mc= "<<(sqrt(2*(num1*num1+aux1*aux1)-num3*num3))/2<<endl;
					
					cout << "el area:  "<<(num1*sin(aux3*rad)*num3)/2<<endl;
					cout << "el perimetro:  "<<num1+num3+aux1<<endl;
				}
				else
				{
					aux2=asin(num3*sin(num2*rad)/num1)*grad;
					aux3=180-(num2+aux2);
					aux1=num1*sin(aux3*rad)/sin(num2*rad);
										
					cout << "los lados son: "<<endl;
					cout << "  a: "<<num1<<endl;
					cout << "  b: "<<aux1<<endl;
					cout << "  c: "<<num3<<endl;
										
					cout << "los angulos son: "<<endl;
					cout << "  A: "<<num2<<endl;
					cout << "  B: "<<aux3<<endl;
					cout << "  C: "<<aux2<<endl;
					
					cout << "las medianas son: "<<endl;
					cout <<"  Ma= "<<(sqrt(2*(num3*num3+aux1*aux1)-num1*num1))/2<<endl;
					cout <<"  Mb= "<<(sqrt(2*(num1*num1+num3*num3)-aux1*aux1))/2<<endl;
					cout <<"  Mc= "<<(sqrt(2*(num1*num1+aux1*aux1)-num3*num3))/2<<endl;
					
					cout << "el area:  "<<(num1*sin(aux3*rad)*num3)/2<<endl;
					cout << "el perimetro:  "<<num1+num3+aux1<<endl;
				}
			}
			    else
			    cout<<"NO TIENE SOLUCION"<<endl;
			    break;
    
			    case 'b':// para a A b
			    if (num3*sin(num2*rad)<=num1)
				{ 
				if (num1<num3)
				{
					aux2=asin(num3*sin(num2*rad)/num1)*grad;
					aux3=180-(num2+aux2);
					aux1=num1*sin(aux3*rad)/sin(num2*rad);
										
					cout << "los lados son: "<<endl;
					cout << "  a: "<<num1<<endl;
					cout << "  b: "<<num3<<endl;
					cout << "  c: "<<aux1<<endl;
										
					cout << "los angulos son: "<<endl;
					cout << "  A: "<<num2<<endl;
					cout << "  B: "<<aux2<<endl;
					cout << "  C: "<<aux3<<endl;
					
					cout << "las medianas son: "<<endl;
					cout <<"  Ma= "<<(sqrt(2*(num3*num3+aux1*aux1)-num1*num1))/2<<endl;
					cout <<"  Mb= "<<(sqrt(2*(num1*num1+aux1*aux1)-num3*num3))/2<<endl;
					cout <<"  Mc= "<<(sqrt(2*(num3*num3+num1*num1)-aux1*aux1))/2<<endl;
					
					cout << "el area:  "<<(num1*sin(aux3*rad)*num3)/2<<endl;
					cout << "el perimetro:  "<<num1+num3+aux1<<endl;
					cout << ""<<endl;
					cout << "segunda solucion"<<endl;
					aux2=180-asin(num3*sin(num2*rad)/num1)*grad;
					aux3=180-(num2+aux2);
					aux1=num1*sin(aux3*rad)/sin(num2*rad);
										
					cout << "los lados son: "<<endl;
					cout << "  a: "<<num1<<endl;
					cout << "  b: "<<num3<<endl;
					cout << "  c: "<<aux1<<endl;
										
					cout << "los angulos son: "<<endl;
					cout << "  A: "<<num2<<endl;
					cout << "  B: "<<aux2<<endl;
					cout << "  C: "<<aux3<<endl;
					
					cout << "las medianas son: "<<endl;
					cout <<"  Ma= "<<(sqrt(2*(num3*num3+aux1*aux1)-num1*num1))/2<<endl;
					cout <<"  Mb= "<<(sqrt(2*(num1*num1+aux1*aux1)-num3*num3))/2<<endl;
					cout <<"  Mc= "<<(sqrt(2*(num3*num3+num1*num1)-aux1*aux1))/2<<endl;
					
					cout << "el area:  "<<(num1*sin(aux3*rad)*num3)/2<<endl;
					cout << "el perimetro:  "<<num1+num3+aux1<<endl;			
				}
				else
				{
					aux2=asin(num3*sin(num2*rad)/num1)*grad;
					aux3=180-(num2+aux2);
					aux1=num1*sin(aux3*rad)/sin(num2*rad);
										
					cout << "los lados son: "<<endl;
					cout << "  a: "<<num1<<endl;
					cout << "  b: "<<num3<<endl;
					cout << "  c: "<<aux1<<endl;
										
					cout << "los angulos son: "<<endl;
					cout << "  A: "<<num2<<endl;
					cout << "  B: "<<aux2<<endl;
					cout << "  C: "<<aux3<<endl;
					
					cout << "las medianas son: "<<endl;
					cout <<"  Ma= "<<(sqrt(2*(num3*num3+aux1*aux1)-num1*num1))/2<<endl;
					cout <<"  Mb= "<<(sqrt(2*(num1*num1+aux1*aux1)-num3*num3))/2<<endl;
					cout <<"  Mc= "<<(sqrt(2*(num3*num3+num1*num1)-aux1*aux1))/2<<endl;
					
					cout << "el area:  "<<(num1*sin(aux3*rad)*num3)/2<<endl;
					cout << "el perimetro:  "<<num1+num3+aux1<<endl;
				}
			}
			    else
			    cout<<"NO TIENE SOLUCION"<<endl;
			    break;
    
			    case 'B': // PARA a A B
			    if (num2+num3<180)
			    {
					aux1=180-(num3+num2);
					aux2=num1*sin(num3*rad)/sin(num2*rad);
					aux3=sqrt(num1*num1+aux2*aux2-(2*cos(aux1*rad)*num1*aux2));
										
					cout << "los lados son: "<<endl;
					cout << "  a: "<<num1<<endl;
					cout << "  b: "<<aux2<<endl;
					cout << "  c: "<<aux3<<endl;
										
					cout << "los angulos son: "<<endl;
					cout << "  A: "<<num2<<endl;
					cout << "  B: "<<num3<<endl;
					cout << "  C: "<<aux1<<endl;
					
					cout << "las medianas son: "<<endl;
					cout <<"  Ma= "<<(sqrt(2*(aux2*aux2+aux3*aux3)-num1*num1))/2<<endl;
					cout <<"  Mb= "<<(sqrt(2*(num1*num1+aux3*aux3)-aux2*aux2))/2<<endl;
					cout <<"  Mc= "<<(sqrt(2*(aux2*aux2+num1*num1)-aux3*aux3))/2<<endl;
					
					cout << "el area:  "<<(num1*sin(aux1*rad)*aux2)/2<<endl;
					cout << "el perimetro:  "<<num1+aux2+aux3<<endl;	
				}
				else
			    cout<<"NO TIENE SOLUCION"<<endl;
			    break;
    
			    case 'C':// PARA a A C
			    			    if (num2+num3<180)
			    {
					aux1=180-(num3+num2);
					aux2=num1*sin(num3*rad)/sin(num2*rad);
					aux3=sqrt(num1*num1+aux2*aux2-(2*cos(aux1*rad)*num1*aux2));
										
					cout << "los lados son: "<<endl;
					cout << "  a: "<<num1<<endl;
					cout << "  b: "<<aux3<<endl;
					cout << "  c: "<<aux2<<endl;
										
					cout << "los angulos son: "<<endl;
					cout << "  A: "<<num2<<endl;
					cout << "  B: "<<aux1<<endl;
					cout << "  C: "<<num3<<endl;
					
					cout << "las medianas son: "<<endl;
					cout <<"  Ma= "<<(sqrt(2*(aux2*aux2+aux3*aux3)-num1*num1))/2<<endl;
					cout <<"  Mb= "<<(sqrt(2*(num1*num1+aux3*aux3)-aux2*aux2))/2<<endl;
					cout <<"  Mc= "<<(sqrt(2*(aux2*aux2+num1*num1)-aux3*aux3))/2<<endl;
					
					cout << "el area:  "<<(num1*sin(aux1*rad)*aux2)/2<<endl;
					cout << "el perimetro:  "<<num1+aux3+aux2<<endl;	
				}
				else
			    cout<<"NO TIENE SOLUCION"<<endl;
			    break;
    
			    default: cout << "Usted ha ingresado una opcion incorrecta"<<endl;
								}
		    break;//fin de a A
    
		    case 'B': //PARA  a B
		    
		    switch(dato3)	{
			    case 'c': //PARA EL CASO a, B, c
			    if (num3!=180)
				{
					aux1=sqrt(num1*num1+num3*num3-(2*num1*num3*cos(num2*rad)));		
					aux2=acos((num3*num3+aux1*aux1-num1*num1)/(2*num3*aux1));	
					aux3=acos((aux1*aux1+num1*num1-num3*num3)/(2*num1*aux1));	
					
										
					cout << "los lados son: "<<endl;
					cout << "  a: "<<num1<<endl;
					cout << "  b: "<<aux1<<endl;
					cout << "  c: "<<num3<<endl;
										
					cout << "los angulos son: "<<endl;
					cout << "  A: "<<aux2*grad<<endl;
					cout << "  B: "<<num2<<endl;
					cout << "  C: "<<aux3*grad<<endl;
					
					cout << "las medianas son: "<<endl;
					cout <<"  Ma= "<<(sqrt(2*(num3*num3+aux1*aux1)-num1*num1))/2<<endl;
					cout <<"  Mb= "<<(sqrt(2*(num3*num3+num1*num1)-aux1*aux1))/2<<endl;
					cout <<"  Mc= "<<(sqrt(2*(num1*num1+aux1*aux1)-num3*num3))/2<<endl;
					
					cout << "el area:  "<<(num1*sin(num2*rad)*num3)/2<<endl;
					cout << "el perimetro:  "<<num1+num3+aux1<<endl;
				}
			    else
			    cout<<"NO TIENE SOLUCION"<<endl;
			    break;
    
			    case 'A': // PARA a B A
			    if (num2+num3<180)
			    {
					aux1=180-(num3+num2);
					aux2=num1*sin(num2*rad)/sin(num3*rad);
					aux3=sqrt(num1*num1+aux2*aux2-(2*cos(aux1*rad)*num1*aux2));
										
					cout << "los lados son: "<<endl;
					cout << "  a: "<<num1<<endl;
					cout << "  b: "<<aux2<<endl;
					cout << "  c: "<<aux3<<endl;
										
					cout << "los angulos son: "<<endl;
					cout << "  A: "<<num3<<endl;
					cout << "  B: "<<num2<<endl;
					cout << "  C: "<<aux1<<endl;
					
					cout << "las medianas son: "<<endl;
					cout <<"  Ma= "<<(sqrt(2*(aux2*aux2+aux3*aux3)-num1*num1))/2<<endl;
					cout <<"  Mb= "<<(sqrt(2*(num1*num1+aux3*aux3)-aux2*aux2))/2<<endl;
					cout <<"  Mc= "<<(sqrt(2*(aux2*aux2+num1*num1)-aux3*aux3))/2<<endl;
					
					cout << "el area:  "<<(num1*sin(aux1*rad)*aux2)/2<<endl;
					cout << "el perimetro:  "<<num1+aux2+aux3<<endl;	
				}
				else
			    cout<<"NO TIENE SOLUCION"<<endl;
			    break;
    
			    case 'b': // PARA a B b
			    if (num1*sin(num2*rad)<=num3)
				{
					if (num1>num3)
				{
					aux2=asin(num1*sin(num2*rad)/num3)*grad;
					aux3=180-(num2+aux2);
					aux1=num1*sin(aux3*rad)/sin(aux2*rad);
									
					cout << "los lados son: "<<endl;
					cout << "  a: "<<num1<<endl;
					cout << "  b: "<<num3<<endl;
					cout << "  c: "<<aux1<<endl;
										
					cout << "los angulos son: "<<endl;
					cout << "  A: "<<aux2<<endl;
					cout << "  B: "<<num2<<endl;
					cout << "  C: "<<aux3<<endl;
					
					cout << "las medianas son: "<<endl;
					cout <<"  Ma= "<<(sqrt(2*(num3*num3+aux1*aux1)-num1*num1))/2<<endl;
					cout <<"  Mb= "<<(sqrt(2*(num1*num1+aux1*aux1)-num3*num3))/2<<endl;
					cout <<"  Mc= "<<(sqrt(2*(num3*num3+num1*num1)-aux1*aux1))/2<<endl;
					
					cout << "el area:  "<<(num1*sin(aux3*rad)*num3)/2<<endl;
					cout << "el perimetro:  "<<num1+num3+aux1<<endl;
					cout << ""<<endl;
					cout << "segunda solucion"<<endl;
					aux2=180-asin(num1*sin(num2*rad)/num3)*grad;
					aux3=180-(num2+aux2);
					aux1=num1*sin(aux3*rad)/sin(aux2*rad);
									
					cout << "los lados son: "<<endl;
					cout << "  a: "<<num1<<endl;
					cout << "  b: "<<num3<<endl;
					cout << "  c: "<<aux1<<endl;
										
					cout << "los angulos son: "<<endl;
					cout << "  A: "<<aux2<<endl;
					cout << "  B: "<<num2<<endl;
					cout << "  C: "<<aux3<<endl;
					
					cout << "las medianas son: "<<endl;
					cout <<"  Ma= "<<(sqrt(2*(num3*num3+aux1*aux1)-num1*num1))/2<<endl;
					cout <<"  Mb= "<<(sqrt(2*(num1*num1+aux1*aux1)-num3*num3))/2<<endl;
					cout <<"  Mc= "<<(sqrt(2*(num3*num3+num1*num1)-aux1*aux1))/2<<endl;
					
					cout << "el area:  "<<(num1*sin(aux3*rad)*num3)/2<<endl;
					cout << "el perimetro:  "<<num1+num3+aux1<<endl;
				}
				else{
					aux2=asin(num1*sin(num2*rad)/num3)*grad;
					aux3=180-(num2+aux2);
					aux1=num1*sin(aux3*rad)/sin(aux2*rad);
									
					cout << "los lados son: "<<endl;
					cout << "  a: "<<num1<<endl;
					cout << "  b: "<<num3<<endl;
					cout << "  c: "<<aux1<<endl;
										
					cout << "los angulos son: "<<endl;
					cout << "  A: "<<aux2<<endl;
					cout << "  B: "<<num2<<endl;
					cout << "  C: "<<aux3<<endl;
					
					cout << "las medianas son: "<<endl;
					cout <<"  Ma= "<<(sqrt(2*(num3*num3+aux1*aux1)-num1*num1))/2<<endl;
					cout <<"  Mb= "<<(sqrt(2*(num1*num1+aux1*aux1)-num3*num3))/2<<endl;
					cout <<"  Mc= "<<(sqrt(2*(num3*num3+num1*num1)-aux1*aux1))/2<<endl;
					
					cout << "el area:  "<<(num1*sin(aux3*rad)*num3)/2<<endl;
					cout << "el perimetro:  "<<num1+num3+aux1<<endl;
				}
				}
			    else
			    cout<<"NO TIENE SOLUCION"<<endl;
			    break;
    
			    case 'C':// PARA a B C
			    if (num2+num3<180)
			    {
					aux1=180-(num3+num2);
					aux2=num1*sin(num2*rad)/sin(aux1*rad);
					aux3=num1*sin(num3*rad)/sin(aux1*rad);
										
					cout << "los lados son: "<<endl;
					cout << "  a: "<<num1<<endl;
					cout << "  b: "<<aux2<<endl;
					cout << "  c: "<<aux3<<endl;
										
					cout << "los angulos son: "<<endl;
					cout << "  A: "<<aux1<<endl;
					cout << "  B: "<<num2<<endl;
					cout << "  C: "<<num3<<endl;
					
					cout << "las medianas son: "<<endl;
					cout <<"  Ma= "<<(sqrt(2*(aux2*aux2+aux3*aux3)-num1*num1))/2<<endl;
					cout <<"  Mb= "<<(sqrt(2*(num1*num1+aux3*aux3)-aux2*aux2))/2<<endl;
					cout <<"  Mc= "<<(sqrt(2*(aux2*aux2+num1*num1)-aux3*aux3))/2<<endl;
					
					cout << "el area:  "<<(num1*sin(num3*rad)*aux2)/2<<endl;
					cout << "el perimetro:  "<<num1+aux2+aux3<<endl;	
				}
				else
			    cout<<"NO TIENE SOLUCION"<<endl;
			    break;
    
			    default: cout << "Usted ha ingresado una opcion incorrecta"<<endl;
								}
		    break;//fin a B
    
		    case 'C':// PARA a C
		    switch(dato3)	{
			    case 'c':// para a C c
			    if (num3*sin(num2*rad)<=num1)
				{
					if(num3<num1)
					{
					aux2=asin(num1*sin(num2*rad)/num3)*grad;
					aux3=180-(num2+aux2);
					aux1=num1*sin(aux3*rad)/sin(aux2*rad);
					
					cout << "los lados son: "<<endl;
					cout << "  a: "<<num1<<endl;
					cout << "  b: "<<aux1<<endl;
					cout << "  c: "<<num3<<endl;
										
					cout << "los angulos son: "<<endl;
					cout << "  A: "<<aux2<<endl;
					cout << "  B: "<<aux3<<endl;
					cout << "  C: "<<num2<<endl;
					
					cout << "las medianas son: "<<endl;
					cout <<"  Ma= "<<(sqrt(2*(num3*num3+aux1*aux1)-num1*num1))/2<<endl;
					cout <<"  Mb= "<<(sqrt(2*(num1*num1+num3*num3)-aux1*aux1))/2<<endl;
					cout <<"  Mc= "<<(sqrt(2*(num1*num1+aux1*aux1)-num3*num3))/2<<endl;
					
					cout << "el area:  "<<(num1*sin(aux3*rad)*num3)/2<<endl;
					cout << "el perimetro:  "<<num1+num3+aux1<<endl;
					cout<<""<<endl;
					cout<<"segunda solucion"<<endl;
					aux2=180-asin(num1*sin(num2*rad)/num3)*grad;
					aux3=180-(num2+aux2);
					aux1=num1*sin(aux3*rad)/sin(aux2*rad);
					
					cout << "los lados son: "<<endl;
					cout << "  a: "<<num1<<endl;
					cout << "  b: "<<aux1<<endl;
					cout << "  c: "<<num3<<endl;
										
					cout << "los angulos son: "<<endl;
					cout << "  A: "<<aux2<<endl;
					cout << "  B: "<<aux3<<endl;
					cout << "  C: "<<num2<<endl;
					
					cout << "las medianas son: "<<endl;
					cout <<"  Ma= "<<(sqrt(2*(num3*num3+aux1*aux1)-num1*num1))/2<<endl;
					cout <<"  Mb= "<<(sqrt(2*(num1*num1+num3*num3)-aux1*aux1))/2<<endl;
					cout <<"  Mc= "<<(sqrt(2*(num1*num1+aux1*aux1)-num3*num3))/2<<endl;
					
					cout << "el area:  "<<(num1*sin(aux3*rad)*num3)/2<<endl;
					cout << "el perimetro:  "<<num1+num3+aux1<<endl;
				}
				else
				{
					aux2=asin(num1*sin(num2*rad)/num3)*grad;
					aux3=180-(num2+aux2);
					aux1=num1*sin(aux3*rad)/sin(aux2*rad);
					
					cout << "los lados son: "<<endl;
					cout << "  a: "<<num1<<endl;
					cout << "  b: "<<aux1<<endl;
					cout << "  c: "<<num3<<endl;
										
					cout << "los angulos son: "<<endl;
					cout << "  A: "<<aux2<<endl;
					cout << "  B: "<<aux3<<endl;
					cout << "  C: "<<num2<<endl;
					
					cout << "las medianas son: "<<endl;
					cout <<"  Ma= "<<(sqrt(2*(num3*num3+aux1*aux1)-num1*num1))/2<<endl;
					cout <<"  Mb= "<<(sqrt(2*(num1*num1+num3*num3)-aux1*aux1))/2<<endl;
					cout <<"  Mc= "<<(sqrt(2*(num1*num1+aux1*aux1)-num3*num3))/2<<endl;
					
					cout << "el area:  "<<(num1*sin(aux3*rad)*num3)/2<<endl;
					cout << "el perimetro:  "<<num1+num3+aux1<<endl;
					}
				}
			
			    else
			    cout<<"NO TIENE SOLUCION"<<endl;
			    break;
    
			    case 'A': // para a C A
			    		    if (num3+num2<180)
			    {
					aux1=180-(num2+num3);
					aux2=num1*sin(num2*rad)/sin(num3*rad);
					aux3=sqrt(num1*num1+aux2*aux2-(2*cos(aux1*rad)*num1*aux2));
										
					cout << "los lados son: "<<endl;
					cout << "  a: "<<num1<<endl;
					cout << "  b: "<<aux3<<endl;
					cout << "  c: "<<aux2<<endl;
										
					cout << "los angulos son: "<<endl;
					cout << "  A: "<<num3<<endl;
					cout << "  B: "<<aux1<<endl;
					cout << "  C: "<<num2<<endl;
					
					cout << "las medianas son: "<<endl;
					cout <<"  Ma= "<<(sqrt(2*(aux2*aux2+aux3*aux3)-num1*num1))/2<<endl;
					cout <<"  Mb= "<<(sqrt(2*(num1*num1+aux3*aux3)-aux2*aux2))/2<<endl;
					cout <<"  Mc= "<<(sqrt(2*(aux2*aux2+num1*num1)-aux3*aux3))/2<<endl;
					
					cout << "el area:  "<<(num1*sin(aux1*rad)*aux2)/2<<endl;
					cout << "el perimetro:  "<<num1+aux3+aux2<<endl;	
				}
				else
			    cout<<"NO TIENE SOLUCION"<<endl;
			    break;
    
			    case 'B': // para a C B
			    if (num3+num2<180)
			    {
					aux1=180-(num2+num3);
					aux2=num1*sin(num3*rad)/sin(aux1*rad);
					aux3=num1*sin(num2*rad)/sin(aux1*rad);
										
					cout << "los lados son: "<<endl;
					cout << "  a: "<<num1<<endl;
					cout << "  b: "<<aux2<<endl;
					cout << "  c: "<<aux3<<endl;
										
					cout << "los angulos son: "<<endl;
					cout << "  A: "<<aux1<<endl;
					cout << "  B: "<<num3<<endl;
					cout << "  C: "<<num2<<endl;
					
					cout << "las medianas son: "<<endl;
					cout <<"  Ma= "<<(sqrt(2*(aux2*aux2+aux3*aux3)-num1*num1))/2<<endl;
					cout <<"  Mb= "<<(sqrt(2*(num1*num1+aux3*aux3)-aux2*aux2))/2<<endl;
					cout <<"  Mc= "<<(sqrt(2*(aux2*aux2+num1*num1)-aux3*aux3))/2<<endl;
					
					cout << "el area:  "<<(num1*sin(num2*rad)*aux2)/2<<endl;
					cout << "el perimetro:  "<<num1+aux2+aux3<<endl;	
				}
				else
			    cout<<"NO TIENE SOLUCION"<<endl;
			    break;
    
			    case 'b': // para a C b
			    if (num2!=180)
				{
					aux1=sqrt(num1*num1+num3*num3-(2*num1*num3*cos(num2*rad)));		
					aux2=acos((num3*num3+aux1*aux1-num1*num1)/(2*num3*aux1));	
					aux3=acos((aux1*aux1+num1*num1-num3*num3)/(2*num1*aux1));	
					
										
					cout << "los lados son: "<<endl;
					cout << "  a: "<<num1<<endl;
					cout << "  b: "<<num3<<endl;
					cout << "  c: "<<aux1<<endl;
										
					cout << "los angulos son: "<<endl;
					cout << "  A: "<<aux2*grad<<endl;
					cout << "  B: "<<aux3*grad<<endl;
					cout << "  C: "<<num2<<endl;
					
					cout << "las medianas son: "<<endl;
					cout <<"  Ma= "<<(sqrt(2*(num3*num3+aux1*aux1)-num1*num1))/2<<endl;
					cout <<"  Mb= "<<(sqrt(2*(num1*num1+aux1*aux1)-num3*num3))/2<<endl;
					cout <<"  Mc= "<<(sqrt(2*(num3*num3+num1*num1)-aux1*aux1))/2<<endl;
					
					cout << "el area:  "<<(num1*sin(num2*rad)*num3)/2<<endl;
					cout << "el perimetro:  "<<num1+num3+aux1<<endl;
				}
			    else
			    cout<<"NO TIENE SOLUCION"<<endl;
			    break;
    
			    default: cout << "Usted ha ingresado una opcion incorrecta"<<endl;
			}
				break;
				default: cout << "Usted ha ingresado una opcion incorrecta"<<endl;
			}
	break;//FIN a

    case 'b': // INICIO b
      			switch(dato2)	{
		    case 'a': // inicio b a
  			switch(dato3)	{
			    case 'c': // inicio b a c
			    if(num1<num2+num3 and num2<num1+num3 and num3<num1+num2)//propiedad triangular
						{
					aux1=acos((num1*num1+num3*num3-num2*num2)/(2*num1*num3));	
					aux2=acos((num3*num3+num2*num2-num1*num1)/(2*num2*num3));	
					aux3=acos((num1*num1-num3*num3+num2*num2)/(2*num1*num2));
					
					cout << ""<<endl;
					
					cout << "los lados son: "<<endl;
					cout << "  a: "<<num2<<endl;
					cout << "  b: "<<num1<<endl;
					cout << "  c: "<<num3<<endl;
					
					cout << "los angulos son: "<<endl;
					cout << "  A: "<<aux1*grad<<endl;
					cout << "  B: "<<aux2*grad<<endl;
					cout << "  C: "<<aux3*grad<<endl;
					
					cout << "las medianas son: "<<endl;
					cout <<"  Ma= "<<(sqrt(2*(num1*num1+num3*num3)-num2*num2))/2<<endl;
					cout <<"  Mb= "<<(sqrt(2*(num2*num2+num3*num3)-num1*num1))/2<<endl;
					cout <<"  Mc= "<<(sqrt(2*(num1*num1+num2*num2)-num3*num3))/2<<endl;
					
					cout << "el area:  "<<(num3*sin(aux2)*num2)/2<<endl;
					cout << "el perimetro:  "<<num1+num2+num3<<endl;
						}
						else
						cout << "los datos ingresados no cumplen la propiedad triangular"<<endl;
			    break;
    
			    case 'A': // para b a A
			    if (num1*sin(num3*rad)<=num2)
				{ 
				if (num2<num1)
				{
					aux2=asin(num1*sin(num3*rad)/num2)*grad;
					aux3=180-(num3+aux2);
					aux1=num2*sin(aux3*rad)/sin(num3*rad);
										
					cout << "los lados son: "<<endl;
					cout << "  a: "<<num2<<endl;
					cout << "  b: "<<num1<<endl;
					cout << "  c: "<<aux1<<endl;
										
					cout << "los angulos son: "<<endl;
					cout << "  A: "<<num3<<endl;
					cout << "  B: "<<aux2<<endl;
					cout << "  C: "<<aux3<<endl;
					
					cout << "las medianas son: "<<endl;
					cout <<"  Ma= "<<(sqrt(2*(num1*num1+aux1*aux1)-num2*num2))/2<<endl;
					cout <<"  Mb= "<<(sqrt(2*(num2*num2+aux1*aux1)-num1*num1))/2<<endl;
					cout <<"  Mc= "<<(sqrt(2*(num2*num2+num1*num1)-aux1*aux1))/2<<endl;
					
					cout << "el area:  "<<(num1*sin(aux3*rad)*num2)/2<<endl;
					cout << "el perimetro:  "<<num1+num2+aux1<<endl;
					cout << ""<<endl;
					cout << "segunda solucion"<<endl;
					aux2=180-asin(num1*sin(num3*rad)/num2)*grad;
					aux3=180-(num3+aux2);
					aux1=num2*sin(aux3*rad)/sin(num3*rad);
										
					cout << "los lados son: "<<endl;
					cout << "  a: "<<num2<<endl;
					cout << "  b: "<<num1<<endl;
					cout << "  c: "<<aux1<<endl;
										
					cout << "los angulos son: "<<endl;
					cout << "  A: "<<num3<<endl;
					cout << "  B: "<<aux2<<endl;
					cout << "  C: "<<aux3<<endl;
					
					cout << "las medianas son: "<<endl;
					cout <<"  Ma= "<<(sqrt(2*(num1*num1+aux1*aux1)-num2*num2))/2<<endl;
					cout <<"  Mb= "<<(sqrt(2*(num2*num2+aux1*aux1)-num1*num1))/2<<endl;
					cout <<"  Mc= "<<(sqrt(2*(num2*num2+num1*num1)-aux1*aux1))/2<<endl;
					
					cout << "el area:  "<<(num1*sin(aux3*rad)*num2)/2<<endl;
					cout << "el perimetro:  "<<num1+num2+aux1<<endl;			
				}
				else
				{
					aux2=asin(num1*sin(num3*rad)/num2)*grad;
					aux3=180-(num3+aux2);
					aux1=num2*sin(aux3*rad)/sin(num3*rad);
										
					cout << "los lados son: "<<endl;
					cout << "  a: "<<num2<<endl;
					cout << "  b: "<<num1<<endl;
					cout << "  c: "<<aux1<<endl;
										
					cout << "los angulos son: "<<endl;
					cout << "  A: "<<num3<<endl;
					cout << "  B: "<<aux2<<endl;
					cout << "  C: "<<aux3<<endl;
					
					cout << "las medianas son: "<<endl;
					cout <<"  Ma= "<<(sqrt(2*(num1*num1+aux1*aux1)-num2*num2))/2<<endl;
					cout <<"  Mb= "<<(sqrt(2*(num2*num2+aux1*aux1)-num1*num1))/2<<endl;
					cout <<"  Mc= "<<(sqrt(2*(num2*num2+num1*num1)-aux1*aux1))/2<<endl;
					
					cout << "el area:  "<<(num1*sin(aux3*rad)*num2)/2<<endl;
					cout << "el perimetro:  "<<num1+num2+aux1<<endl;
				}
			}
			    else
			    cout<<"NO TIENE SOLUCION"<<endl;
			    break;
    
			    case 'B': //para b a B
			    
			     if (num1*sin(num3*rad)<=num2)
				{
					if (num2>num1)
				{
					aux2=asin(num2*sin(num3*rad)/num1)*grad;
					aux3=180-(num3+aux2);
					aux1=num2*sin(aux3*rad)/sin(aux2*rad);
									
					cout << "los lados son: "<<endl;
					cout << "  a: "<<num2<<endl;
					cout << "  b: "<<num1<<endl;
					cout << "  c: "<<aux1<<endl;
										
					cout << "los angulos son: "<<endl;
					cout << "  A: "<<aux2<<endl;
					cout << "  B: "<<num3<<endl;
					cout << "  C: "<<aux3<<endl;
					
					cout << "las medianas son: "<<endl;
					cout <<"  Ma= "<<(sqrt(2*(num1*num1+aux1*aux1)-num2*num2))/2<<endl;
					cout <<"  Mb= "<<(sqrt(2*(num2*num2+aux1*aux1)-num1*num1))/2<<endl;
					cout <<"  Mc= "<<(sqrt(2*(num1*num1+num2*num2)-aux1*aux1))/2<<endl;
					
					cout << "el area:  "<<(num1*sin(aux3*rad)*num2)/2<<endl;
					cout << "el perimetro:  "<<num1+num2+aux1<<endl;
					cout << ""<<endl;
					cout << "segunda solucion"<<endl;
					aux2=180-asin(num2*sin(num3*rad)/num1)*grad;
					aux3=180-(num3+aux2);
					aux1=num2*sin(aux3*rad)/sin(aux2*rad);
									
					cout << "los lados son: "<<endl;
					cout << "  a: "<<num2<<endl;
					cout << "  b: "<<num1<<endl;
					cout << "  c: "<<aux1<<endl;
										
					cout << "los angulos son: "<<endl;
					cout << "  A: "<<aux2<<endl;
					cout << "  B: "<<num3<<endl;
					cout << "  C: "<<aux3<<endl;
					
					cout << "las medianas son: "<<endl;
					cout <<"  Ma= "<<(sqrt(2*(num1*num1+aux1*aux1)-num2*num2))/2<<endl;
					cout <<"  Mb= "<<(sqrt(2*(num2*num2+aux1*aux1)-num1*num1))/2<<endl;
					cout <<"  Mc= "<<(sqrt(2*(num2*num2+num1*num1)-aux1*aux1))/2<<endl;
					
					cout << "el area:  "<<(num1*sin(aux3*rad)*num2)/2<<endl;
					cout << "el perimetro:  "<<num1+num2+aux1<<endl;
				}
				else{
					aux2=asin(num2*sin(num3*rad)/num1)*grad;
					aux3=180-(num3+aux2);
					aux1=num2*sin(aux3*rad)/sin(aux2*rad);
									
					cout << "los lados son: "<<endl;
					cout << "  a: "<<num2<<endl;
					cout << "  b: "<<num1<<endl;
					cout << "  c: "<<aux1<<endl;
										
					cout << "los angulos son: "<<endl;
					cout << "  A: "<<aux2<<endl;
					cout << "  B: "<<num3<<endl;
					cout << "  C: "<<aux3<<endl;
					
					cout << "las medianas son: "<<endl;
					cout <<"  Ma= "<<(sqrt(2*(num1*num1+aux1*aux1)-num2*num2))/2<<endl;
					cout <<"  Mb= "<<(sqrt(2*(num2*num2+aux1*aux1)-num1*num1))/2<<endl;
					cout <<"  Mc= "<<(sqrt(2*(num2*num2+num1*num1)-aux1*aux1))/2<<endl;
					
					cout << "el area:  "<<(num1*sin(aux3*rad)*num2)/2<<endl;
					cout << "el perimetro:  "<<num1+num2+aux1<<endl;
				}
				}
			    else
			    cout<<"NO TIENE SOLUCION"<<endl;
			    break;
    
			    case 'C': //para b a C
			     if (num3!=180)
				{
					aux1=sqrt(num1*num1+num2*num2-(2*num1*num2*cos(num3*rad)));		
					aux2=acos((num2*num2+aux1*aux1-num1*num1)/(2*num2*aux1));	
					aux3=acos((aux1*aux1+num1*num1-num2*num2)/(2*num1*aux1));	
					
										
					cout << "los lados son: "<<endl;
					cout << "  a: "<<num2<<endl;
					cout << "  b: "<<num1<<endl;
					cout << "  c: "<<aux1<<endl;
										
					cout << "los angulos son: "<<endl;
					cout << "  A: "<<aux3*grad<<endl;
					cout << "  B: "<<aux2*grad<<endl;
					cout << "  C: "<<num3<<endl;
					
					cout << "las medianas son: "<<endl;
					cout <<"  Ma= "<<(sqrt(2*(num2*num2+aux1*aux1)-num1*num1))/2<<endl;
					cout <<"  Mb= "<<(sqrt(2*(num1*num1+aux1*aux1)-num2*num2))/2<<endl;
					cout <<"  Mc= "<<(sqrt(2*(num2*num2+num1*num1)-aux1*aux1))/2<<endl;
					
					cout << "el area:  "<<(num1*sin(num3*rad)*num2)/2<<endl;
					cout << "el perimetro:  "<<num1+num2+aux1<<endl;
				}
			    else
			    cout<<"NO TIENE SOLUCION"<<endl;
			    break;
    
			    default: cout << "Usted ha ingresado una opcion incorrecta"<<endl;
								} 
			break;// FIN b a 
								 
		    case 'c': //inicio b c
		    switch(dato3)	{
			    case 'a': //para b c a
			    if(num1<num2+num3 and num2<num1+num3 and num3<num1+num2)//propiedad triangular
						{
					aux1=acos((num2*num2+num3*num3-num1*num1)/(2*num2*num3));	
					aux2=acos((num3*num3+num1*num1-num2*num2)/(2*num1*num3));	
					aux3=acos((num2*num2-num3*num3+num1*num1)/(2*num2*num1));
					
					cout << ""<<endl;
					
					cout << "los lados son: "<<endl;
					cout << "  a: "<<num3<<endl;
					cout << "  b: "<<num1<<endl;
					cout << "  c: "<<num2<<endl;
					
					cout << "los angulos son: "<<endl;
					cout << "  A: "<<aux3*grad<<endl;
					cout << "  B: "<<aux1*grad<<endl;
					cout << "  C: "<<aux2*grad<<endl;
					
					cout << "las medianas son: "<<endl;
					cout <<"  Ma= "<<(sqrt(2*(num2*num2+num3*num3)-num1*num1))/2<<endl;
					cout <<"  Mb= "<<(sqrt(2*(num2*num2+num1*num1)-num3*num3))/2<<endl;
					cout <<"  Mc= "<<(sqrt(2*(num1*num1+num3*num3)-num2*num2))/2<<endl;
					
					cout << "el area:  "<<(num3*sin(aux2)*num1)/2<<endl;
					cout << "el perimetro:  "<<num1+num2+num3<<endl;
						}
						else
						cout << "los datos ingresados no cumplen la propiedad triangular"<<endl;
			    break;
    
			    case 'A': //para b c A
			    if (num3!=180)
				{
					aux1=sqrt(num1*num1+num2*num2-(2*num1*num2*cos(num3*rad)));		
					aux2=acos((num2*num2+aux1*aux1-num1*num1)/(2*num2*aux1));	
					aux3=acos((aux1*aux1+num1*num1-num2*num2)/(2*num1*aux1));	
					
										
					cout << "los lados son: "<<endl;
					cout << "  a: "<<aux1<<endl;
					cout << "  b: "<<num1<<endl;
					cout << "  c: "<<num2<<endl;
										
					cout << "los angulos son: "<<endl;
					cout << "  A: "<<num3<<endl;
					cout << "  B: "<<aux2*grad<<endl;
					cout << "  C: "<<aux3*grad<<endl;
					
					cout << "las medianas son: "<<endl;
					cout <<"  Ma= "<<(sqrt(2*(num2*num2+aux1*aux1)-num1*num1))/2<<endl;
					cout <<"  Mb= "<<(sqrt(2*(num2*num2+num1*num1)-aux1*aux1))/2<<endl;
					cout <<"  Mc= "<<(sqrt(2*(num1*num1+aux1*aux1)-num2*num2))/2<<endl;
					
					cout << "el area:  "<<(num1*sin(num3*rad)*num2)/2<<endl;
					cout << "el perimetro:  "<<num1+num2+aux1<<endl;
				}
			    else
			    cout<<"NO TIENE SOLUCION"<<endl;
			    break;
    
			    case 'B': //para b c B
			    if (num2*sin(num3*rad)<=num1)
				{
					if(num1<num2){
					aux2=asin(num2*sin(num3*rad)/num1)*grad;
					aux3=180-(num3+aux2);
					aux1=num1*sin(aux3*rad)/sin(num3*rad);
										
					cout << "los lados son: "<<endl;
					cout << "  a: "<<aux1<<endl;
					cout << "  b: "<<num1<<endl;
					cout << "  c: "<<num2<<endl;
										
					cout << "los angulos son: "<<endl;
					cout << "  A: "<<aux3<<endl;
					cout << "  B: "<<num3<<endl;
					cout << "  C: "<<aux2<<endl;
					
					cout << "las medianas son: "<<endl;
					cout <<"  Ma= "<<(sqrt(2*(num2*num2+aux1*aux1)-num1*num1))/2<<endl;
					cout <<"  Mb= "<<(sqrt(2*(num1*num1+num2*num2)-aux1*aux1))/2<<endl;
					cout <<"  Mc= "<<(sqrt(2*(num1*num1+aux1*aux1)-num2*num2))/2<<endl;
					
					cout << "el area:  "<<(num1*sin(aux3*rad)*num2)/2<<endl;
					cout << "el perimetro:  "<<num1+num2+aux1<<endl;
					cout << " "<<endl;
					cout << "Segunda solucion: "<<endl;
					aux2=180-asin(num2*sin(num3*rad)/num1)*grad;
					aux3=180-(num3+aux2);
					aux1=num1*sin(aux3*rad)/sin(num3*rad);
										
					cout << "los lados son: "<<endl;
					cout << "  a: "<<aux1<<endl;
					cout << "  b: "<<num1<<endl;
					cout << "  c: "<<num2<<endl;
										
					cout << "los angulos son: "<<endl;
					cout << "  A: "<<aux3<<endl;
					cout << "  B: "<<num3<<endl;
					cout << "  C: "<<aux2<<endl;
					
					cout << "las medianas son: "<<endl;
					cout <<"  Ma= "<<(sqrt(2*(num2*num2+aux1*aux1)-num1*num1))/2<<endl;
					cout <<"  Mb= "<<(sqrt(2*(num1*num1+num2*num2)-aux1*aux1))/2<<endl;
					cout <<"  Mc= "<<(sqrt(2*(num1*num1+aux1*aux1)-num2*num2))/2<<endl;
					
					cout << "el area:  "<<(num1*sin(aux3*rad)*num2)/2<<endl;
					cout << "el perimetro:  "<<num1+num2+aux1<<endl;
				}
				else
				{
					aux2=asin(num2*sin(num3*rad)/num1)*grad;
					aux3=180-(num3+aux2);
					aux1=num1*sin(aux3*rad)/sin(num3*rad);
										
					cout << "los lados son: "<<endl;
					cout << "  a: "<<aux1<<endl;
					cout << "  b: "<<num1<<endl;
					cout << "  c: "<<num2<<endl;
										
					cout << "los angulos son: "<<endl;
					cout << "  A: "<<aux3<<endl;
					cout << "  B: "<<num3<<endl;
					cout << "  C: "<<aux2<<endl;
					
					cout << "las medianas son: "<<endl;
					cout <<"  Ma= "<<(sqrt(2*(num2*num2+aux1*aux1)-num1*num1))/2<<endl;
					cout <<"  Mb= "<<(sqrt(2*(num1*num1+num2*num2)-aux1*aux1))/2<<endl;
					cout <<"  Mc= "<<(sqrt(2*(num1*num1+aux1*aux1)-num2*num2))/2<<endl;
					
					cout << "el area:  "<<(num1*sin(aux3*rad)*num2)/2<<endl;
					cout << "el perimetro:  "<<num1+num2+aux1<<endl;
				}
			}
			    else
			    cout<<"NO TIENE SOLUCION"<<endl;
			    break;
    
			    case 'C': //para b c C
			     if (num2*sin(num3*rad)<=num1)
				{
					if (num1>num2)
				{
					aux2=asin(num1*sin(num3*rad)/num2)*grad;
					aux3=180-(num3+aux2);
					aux1=num1*sin(aux3*rad)/sin(aux2*rad);
									
					cout << "los lados son: "<<endl;
					cout << "  a: "<<aux1<<endl;
					cout << "  b: "<<num1<<endl;
					cout << "  c: "<<num2<<endl;
										
					cout << "los angulos son: "<<endl;
					cout << "  A: "<<aux3<<endl;
					cout << "  B: "<<aux2<<endl;
					cout << "  C: "<<num3<<endl;
					
					cout << "las medianas son: "<<endl;
					cout <<"  Ma= "<<(sqrt(2*(num2*num2+aux1*aux1)-num1*num1))/2<<endl;
					cout <<"  Mb= "<<(sqrt(2*(num1*num1+aux1*aux1)-num2*num2))/2<<endl;
					cout <<"  Mc= "<<(sqrt(2*(num2*num2+num1*num1)-aux1*aux1))/2<<endl;
					
					cout << "el area:  "<<(num1*sin(aux3*rad)*num2)/2<<endl;
					cout << "el perimetro:  "<<num1+num2+aux1<<endl;
					cout << ""<<endl;
					cout << "segunda solucion"<<endl;
					aux2=180-asin(num1*sin(num3*rad)/num2)*grad;
					aux3=180-(num3+aux2);
					aux1=num1*sin(aux3*rad)/sin(aux2*rad);
									
					cout << "los lados son: "<<endl;
					cout << "  a: "<<aux1<<endl;
					cout << "  b: "<<num1<<endl;
					cout << "  c: "<<num2<<endl;
										
					cout << "los angulos son: "<<endl;
					cout << "  A: "<<aux3<<endl;
					cout << "  B: "<<aux2<<endl;
					cout << "  C: "<<num3<<endl;
					
					cout << "las medianas son: "<<endl;
					cout <<"  Ma= "<<(sqrt(2*(num2*num2+aux1*aux1)-num1*num1))/2<<endl;
					cout <<"  Mb= "<<(sqrt(2*(num1*num1+aux1*aux1)-num2*num2))/2<<endl;
					cout <<"  Mc= "<<(sqrt(2*(num2*num2+num1*num1)-aux1*aux1))/2<<endl;
					
					cout << "el area:  "<<(num1*sin(aux3*rad)*num2)/2<<endl;
					cout << "el perimetro:  "<<num1+num2+aux1<<endl;
				}
				else{
					aux2=asin(num1*sin(num3*rad)/num2)*grad;
					aux3=180-(num3+aux2);
					aux1=num1*sin(aux3*rad)/sin(aux2*rad);
									
					cout << "los lados son: "<<endl;
					cout << "  a: "<<aux1<<endl;
					cout << "  b: "<<num1<<endl;
					cout << "  c: "<<num2<<endl;
										
					cout << "los angulos son: "<<endl;
					cout << "  A: "<<aux3<<endl;
					cout << "  B: "<<aux2<<endl;
					cout << "  C: "<<num3<<endl;
					
					cout << "las medianas son: "<<endl;
					cout <<"  Ma= "<<(sqrt(2*(num2*num2+aux1*aux1)-num1*num1))/2<<endl;
					cout <<"  Mb= "<<(sqrt(2*(num1*num1+aux1*aux1)-num2*num2))/2<<endl;
					cout <<"  Mc= "<<(sqrt(2*(num2*num2+num1*num1)-aux1*aux1))/2<<endl;
					
					cout << "el area:  "<<(num1*sin(aux3*rad)*num2)/2<<endl;
					cout << "el perimetro:  "<<num1+num2+aux1<<endl;
				}
				}
			    else
			    cout<<"NO TIENE SOLUCION"<<endl;
			    break;
    
			    default: cout << "Usted ha ingresado una opcion incorrecta"<<endl;
								}
		    break;// fin b c
     
		    case 'A': //inicio b A
		    switch(dato3)	{
			    case 'c': // para b A c
				if (num2!=180)
				{
					aux1=sqrt(num1*num1+num3*num3-(2*num1*num3*cos(num2*rad)));		
					aux2=acos((num3*num3+aux1*aux1-num1*num1)/(2*num3*aux1));	
					aux3=acos((aux1*aux1+num1*num1-num3*num3)/(2*num1*aux1));	
					
										
					cout << "los lados son: "<<endl;
					cout << "  a: "<<aux1<<endl;
					cout << "  b: "<<num1<<endl;
					cout << "  c: "<<num3<<endl;
										
					cout << "los angulos son: "<<endl;
					cout << "  A: "<<num2<<endl;
					cout << "  B: "<<aux2*grad<<endl;
					cout << "  C: "<<aux3*grad<<endl;
					
					cout << "las medianas son: "<<endl;
					cout <<"  Ma= "<<(sqrt(2*(num3*num3+aux1*aux1)-num1*num1))/2<<endl;
					cout <<"  Mb= "<<(sqrt(2*(num1*num1+aux1*aux1)-num3*num3))/2<<endl;
					cout <<"  Mc= "<<(sqrt(2*(num3*num3+num1*num1)-aux1*aux1))/2<<endl;
					
					cout << "el area:  "<<(num1*sin(num2*rad)*num3)/2<<endl;
					cout << "el perimetro:  "<<num1+num3+aux1<<endl;
				}
			    else
			    cout<<"NO TIENE SOLUCION"<<endl;
			    break;
    
			    case 'a': //para b A a
				if (num3*sin(num2*rad)<=num1)
				{
					if(num3<num1)
					{
					aux2=asin(num1*sin(num2*rad)/num3)*grad;
					aux3=180-(num2+aux2);
					aux1=num1*sin(aux3*rad)/sin(aux2*rad);
					
					cout << "los lados son: "<<endl;
					cout << "  a: "<<num3<<endl;
					cout << "  b: "<<num1<<endl;
					cout << "  c: "<<aux1<<endl;
								//aCc-bAa		
					cout << "los angulos son: "<<endl;
					cout << "  A: "<<num2<<endl;
					cout << "  B: "<<aux2<<endl;
					cout << "  C: "<<aux3<<endl;
					
					cout << "las medianas son: "<<endl;
					cout <<"  Ma= "<<(sqrt(2*(num3*num3+aux1*aux1)-num1*num1))/2<<endl;
					cout <<"  Mb= "<<(sqrt(2*(num1*num1+num3*num3)-aux1*aux1))/2<<endl;
					cout <<"  Mc= "<<(sqrt(2*(num1*num1+aux1*aux1)-num3*num3))/2<<endl;
					
					cout << "el area:  "<<(num1*sin(aux3*rad)*num3)/2<<endl;
					cout << "el perimetro:  "<<num1+num3+aux1<<endl;
					cout<<""<<endl;
					cout<<"segunda solucion"<<endl;
					aux2=180-asin(num1*sin(num2*rad)/num3)*grad;
					aux3=180-(num2+aux2);
					aux1=num1*sin(aux3*rad)/sin(aux2*rad);
					
					cout << "los lados son: "<<endl;
					cout << "  a: "<<num3<<endl;
					cout << "  b: "<<num1<<endl;
					cout << "  c: "<<aux1<<endl;
								//aCc-bAa		
					cout << "los angulos son: "<<endl;
					cout << "  A: "<<num2<<endl;
					cout << "  B: "<<aux2<<endl;
					cout << "  C: "<<aux3<<endl;
					
					cout << "las medianas son: "<<endl;
					cout <<"  Ma= "<<(sqrt(2*(num3*num3+aux1*aux1)-num1*num1))/2<<endl;
					cout <<"  Mb= "<<(sqrt(2*(num1*num1+num3*num3)-aux1*aux1))/2<<endl;
					cout <<"  Mc= "<<(sqrt(2*(num1*num1+aux1*aux1)-num3*num3))/2<<endl;
					
					cout << "el area:  "<<(num1*sin(aux3*rad)*num3)/2<<endl;
					cout << "el perimetro:  "<<num1+num3+aux1<<endl;
				}
				else
				{
					aux2=asin(num1*sin(num2*rad)/num3)*grad;
					aux3=180-(num2+aux2);
					aux1=num1*sin(aux3*rad)/sin(aux2*rad);
					
					cout << "los lados son: "<<endl;
					cout << "  a: "<<num3<<endl;
					cout << "  b: "<<num1<<endl;
					cout << "  c: "<<aux1<<endl;
								//aCc-bAa		
					cout << "los angulos son: "<<endl;
					cout << "  A: "<<num2<<endl;
					cout << "  B: "<<aux2<<endl;
					cout << "  C: "<<aux3<<endl;
					
					cout << "las medianas son: "<<endl;
					cout <<"  Ma= "<<(sqrt(2*(num3*num3+aux1*aux1)-num1*num1))/2<<endl;
					cout <<"  Mb= "<<(sqrt(2*(num1*num1+num3*num3)-aux1*aux1))/2<<endl;
					cout <<"  Mc= "<<(sqrt(2*(num1*num1+aux1*aux1)-num3*num3))/2<<endl;
					
					cout << "el area:  "<<(num1*sin(aux3*rad)*num3)/2<<endl;
					cout << "el perimetro:  "<<num1+num3+aux1<<endl;
					}
				}
			
			    else
			    cout<<"NO TIENE SOLUCION"<<endl;
			    break;
    
			    case 'B': //para b A B
				   if (num3+num2<180)
			    {
					aux1=180-(num2+num3);
					aux2=num1*sin(num2*rad)/sin(num3*rad);
					aux3=sqrt(num1*num1+aux2*aux2-(2*cos(aux1*rad)*num1*aux2));
										
					cout << "los lados son: "<<endl;
					cout << "  a: "<<aux2<<endl;
					cout << "  b: "<<num1<<endl;
					cout << "  c: "<<aux3<<endl;
										
					cout << "los angulos son: "<<endl;
					cout << "  A: "<<num2<<endl;
					cout << "  B: "<<num3<<endl;
					cout << "  C: "<<aux1<<endl;
					
					cout << "las medianas son: "<<endl;
					cout <<"  Ma= "<<(sqrt(2*(aux2*aux2+aux3*aux3)-num1*num1))/2<<endl;
					cout <<"  Mb= "<<(sqrt(2*(num1*num1+aux3*aux3)-aux2*aux2))/2<<endl;
					cout <<"  Mc= "<<(sqrt(2*(aux2*aux2+num1*num1)-aux3*aux3))/2<<endl;
					
					cout << "el area:  "<<(num1*sin(aux1*rad)*aux2)/2<<endl;
					cout << "el perimetro:  "<<num1+aux3+aux2<<endl;	
				}
				else
			    cout<<"NO TIENE SOLUCION"<<endl;
			    break;
    
			    case 'C': // para b A C
				 if (num3+num2<180)
			    {
					aux1=180-(num2+num3);
					aux2=num1*sin(num3*rad)/sin(aux1*rad);
					aux3=num1*sin(num2*rad)/sin(aux1*rad);
										
					cout << "los lados son: "<<endl;
					cout << "  a: "<<aux3<<endl;
					cout << "  b: "<<num1<<endl;
					cout << "  c: "<<aux2<<endl;
										
					cout << "los angulos son: "<<endl;
					cout << "  A: "<<num2<<endl;
					cout << "  B: "<<aux1<<endl;
					cout << "  C: "<<num3<<endl;
					
					cout << "las medianas son: "<<endl;
					cout <<"  Ma= "<<(sqrt(2*(aux2*aux2+aux3*aux3)-num1*num1))/2<<endl;
					cout <<"  Mb= "<<(sqrt(2*(num1*num1+aux3*aux3)-aux2*aux2))/2<<endl;
					cout <<"  Mc= "<<(sqrt(2*(aux2*aux2+num1*num1)-aux3*aux3))/2<<endl;
					
					cout << "el area:  "<<(num1*sin(num2*rad)*aux2)/2<<endl;
					cout << "el perimetro:  "<<num1+aux2+aux3<<endl;	
				}
				else
			    cout<<"NO TIENE SOLUCION"<<endl;
			    break;
    
			    default: cout << "Usted ha ingresado una opcion incorrecta"<<endl;
								}
		    break;// fin b A
    
		    case 'B': // Inicio b B
		    switch(dato3)	{
			    case 'c': // Para b B c
			    break;
    
			    case 'A': // Para b B A
			    break;
    
			    case 'a': // Para b B a
			    break;
    
			    case 'C': // Para b B C
			    break;
    
			    default: cout << "Usted ha ingresado una opcion incorrecta"<<endl;
								}
		    break;// fin b B
    
		    case 'C': //inicio b C
		    switch(dato3)	{
			    case 'c': // Para b C c
			    break;
    
			    case 'A': // Para b C A
			    break;
    
			    case 'B': // Para b C B
			    break;
    
			    case 'a': // Para b C a
			    break;
    
			    default: cout << "Usted ha ingresado una opcion incorrecta"<<endl;
								}
		    break;// fin b c
    
		    default: cout << "Usted ha ingresado una opción incorrecta"<<endl;
							}
    break; // fin b
    case 'c': // inicio c
    
   			switch(dato2)	{
		    case 'b': // inicio c b
  			switch(dato3)	{
			    case 'a': // para c b a
			    break;
    
			    case 'A': //para c b A
			    break;
    
			    case 'B': //para c b B
			    break;
    
			    case 'C': //para c b C
			    break;
    
			    default: cout << "Usted ha ingresado una opcion incorrecta"<<endl;
								} 
			break;//fin c b
								 
		    case 'a': // inicio c a
		    switch(dato3)	{
			    case 'b': // para c a b
			    break;
    
			    case 'A': // para c a A
			    break;
    
			    case 'B': // para c a B
			    break;
    
			    case 'C': // para c a C
			    break;
    
			    default: cout << "Usted ha ingresado una opcion incorrecta"<<endl;
								}
		    break;// fin  c a 
    
		    case 'A': // inicio c A
		    switch(dato3)	{
			    case 'a': // para c A a
			    break;
    
			    case 'b': // para c A b
			    break;
    
			    case 'B': // para c A B
			    break;
    
			    case 'C': // para c A C
			    break;
    
			    default: cout << "Usted ha ingresado una opcion incorrecta"<<endl;
								}
		    break; // fin c A
    
		    case 'B': // inicio c B
		    switch(dato3)	{
			    case 'a': // para c B a
			    break;
    
			    case 'A': // para c B A
			    break;
    
			    case 'b': // para c B b
			    break;
    
			    case 'C': // para c B C
			    break;
    
			    default: cout << "Usted ha ingresado una opcion incorrecta"<<endl;
								}
		    break;
    
		    case 'C': // inicio c C
		    switch(dato3)	{
			    case 'a': // para c C a
			    break;
    
			    case 'A': // para c C A
			    break;
    
			    case 'B': // para c C B
			    break;
    
			    case 'b': // para c C b
			    break;
    
			    default: cout << "Usted ha ingresado una opcion incorrecta"<<endl;
								}
		    break;// fin c C
    
		    default: cout << "Usted ha ingresado una opción incorrecta"<<endl;
							}
    break;// fin c
    case 'A': //inicio A
    
    			switch(dato2)	{
		    case 'b': // inicio A b
  			switch(dato3)	{
			    case 'c': // para A b  c
			    break;
    
			    case 'a': // para A b  a
			    break;
    
			    case 'B': // para A b  B
			    break;
    
			    case 'C': // para A b  C
			    break;
    
			    default: cout << "Usted ha ingresado una opcion incorrecta"<<endl;
								} 
			break;// fin A b
								 
		    case 'c': // inicio A c
		    switch(dato3)	{
			    case 'b': // para A c b
			    break;
    
			    case 'a': // para A c a
			    break;
    
			    case 'B': // para A c B
			    break;
    
			    case 'C': // para A c C
			    break;
    
			    default: cout << "Usted ha ingresado una opcion incorrecta"<<endl;
								}
		    break;// fin A c
    
		    case 'a': // inicio A a
		    switch(dato3)	{
			    case 'c': // para A a c
			    break;
    
			    case 'b':// para A a b
			    break;
    
			    case 'B': // para A a B
			    break;
    
			    case 'C': // para A a C
			    break;
    
			    default: cout << "Usted ha ingresado una opcion incorrecta"<<endl;
								}
		    break;// fin A a 
    
		    case 'B': //inicio A B
		    switch(dato3)	{
			    case 'c': // para A B c
			    break;
    
			    case 'a': // para A B a
				// PARA a B A
			    if (num2+num1<180)
			    {
					aux1=180-(num1+num2);
					aux2=num3*sin(num2*rad)/sin(num1*rad);
					aux3=sqrt(num3*num3+aux2*aux2-(2*cos(aux1*rad)*num3*aux2));
										
					cout << "los lados son: "<<endl;
					cout << "  a: "<<num3<<endl;
					cout << "  b: "<<aux2<<endl;
					cout << "  c: "<<aux3<<endl;
										
					cout << "los angulos son: "<<endl;
					cout << "  A: "<<num1<<endl;
					cout << "  B: "<<num2<<endl;
					cout << "  C: "<<aux1<<endl;
					
					cout << "las medianas son: "<<endl;
					cout <<"  Ma= "<<(sqrt(2*(aux2*aux2+aux3*aux3)-num3*num3))/2<<endl;
					cout <<"  Mb= "<<(sqrt(2*(num3*num3+aux3*aux3)-aux2*aux2))/2<<endl;
					cout <<"  Mc= "<<(sqrt(2*(aux2*aux2+num3*num3)-aux3*aux3))/2<<endl;
					
					cout << "el area:  "<<(num3*sin(aux1*rad)*aux2)/2<<endl;
					cout << "el perimetro:  "<<num3+aux2+aux3<<endl;	
				}
				else
			    cout<<"NO TIENE SOLUCION"<<endl;
			    break;
    
			    case 'b': // para A B b
			    break;
    
			    case 'C': // para A B C
			    if (num1+num2+num3==180)
			    {
			    	cout <<endl;
			        cout << "los angulos son: "<<endl;
					cout << "  A: "<<num1<<endl;
					cout << "  B: "<<num2<<endl;
					cout << "  C: "<<num3<<endl;	
					cout <<"El triangulo tiene infinitas soluciones"<<endl;					
				}
				else
				{
				cout <<"La suma de los angulos es:  "<<(num1+num2+num3)<<endl;
				cout <<"Los valores son contradictorios, TIENEN QUE SUMAR 180 GRADOS"<<endl;
				}
			    break;
    
			    default: cout << "Usted ha ingresado una opcion incorrecta"<<endl;
								}
		    break;
    
		    case 'C': // para A C
		    switch(dato3)	{
			    case 'c': // inicio A C c
			    break;
    
			    case 'a': // para A C a
			    break;
    
			    case 'B': // para A C B
			    break;
    
			    case 'b': // para A C b
			    break;
    
			    default: cout << "Usted ha ingresado una opcion incorrecta"<<endl;
								}
		    break;// fin A C
    
		    default: cout << "Usted ha ingresado una opción incorrecta"<<endl;
							}   
    break;// fin A
	case 'B': // inicio B
			switch(dato2)	{
			    case 'b': // inicio B b 
 	 			switch(dato3)	{
			    case 'c': // para B b c
			    break;
    
			    case 'A': // para B b A
			    break;
    
			    case 'a': // para B b a
			    break;
    
			    case 'C': // para B b C
			    break;
    
			    default: cout << "Usted ha ingresado una opcion incorrecta"<<endl;
								} 
			break;// fin B b
								 
		    case 'c': // inicio B c
		    switch(dato3)	{
			    case 'b': // para B c b
			    break;
    
			    case 'A': // para B c A
			    break;
    
			    case 'a': // para B c a
			    break;
    
			    case 'C': // para B c C
			    break;
    
			    default: cout << "Usted ha ingresado una opcion incorrecta"<<endl;
								}
		    break;// fin B c
    
		    case 'A': // inicio B A
		    switch(dato3)	{
			    case 'c': // para B A c
			    break;
    
			    case 'b': // para B A b
			    break;
    
			    case 'a': // para B A a 
			    break;
    
			    case 'C': // para B A C
			    break;
    
			    default: cout << "Usted ha ingresado una opcion incorrecta"<<endl;
								}
		    break;// fin de B A 
    
		    case 'a': // inicio B a
		    switch(dato3)	{
			    case 'c': // para B a c
			    break;
    
			    case 'A': // para B a A
			    break;
    
			    case 'b': // para B a b
			    break;
    
			    case 'C': // para B a C
			    break;
    
			    default: cout << "Usted ha ingresado una opcion incorrecta"<<endl;
								}
		    break;// fin de B a
    
		    case 'C': // inicio B C
		    switch(dato3)	{
			    case 'c': // para B C c
			    break;
    
			    case 'A': // para B C A
			    break;
    
			    case 'a': // para B C a
			    break;
    
			    case 'b': // para B C b
			    break;
    
			    default: cout << "Usted ha ingresado una opcion incorrecta"<<endl;
								}
		    break;// fin B C
    
		    default: cout << "Usted ha ingresado una opción incorrecta"<<endl;
							}	
    break;// fin B
    
    case 'C': // inicio C
switch(dato2)	{
		    case 'b': // inicio C b
  			switch(dato3)	{
			    case 'c': // para C b c
			    break;
    
			    case 'A': // para C b A
			    break;
    
			    case 'B': // para C b B
			    break;
    
			    case 'a': // para C b a
			    break;
    
			    default: cout << "Usted ha ingresado una opcion incorrecta"<<endl;
								} 
			break;// fin C b
								 
		    case 'c': // inicio C c
		    switch(dato3)	{
			    case 'b': // para C c b
			    break;
    
			    case 'A': // para C c A
			    break;
    
			    case 'B':// para C c B
			    break;
    
			    case 'a': // para C c a
			    break;
    
			    default: cout << "Usted ha ingresado una opcion incorrecta"<<endl;
								}
		    break;// fin C c
    
		    case 'A': // inicio C A
		    switch(dato3)	{
			    case 'c': // para C A c
			    break;
    
			    case 'b': // para C A b
			    break;
    
			    case 'B':// para C A B
			    break;
    
			    case 'a': // para C A a
			    break;
    
			    default: cout << "Usted ha ingresado una opcion incorrecta"<<endl;
								}
		    break;// fin C A
    
		    case 'B': // inicio C B
		    switch(dato3)	{
			    case 'c': // para C B c
			    break;
    
			    case 'A': // para C B A
			    break;
    
			    case 'b': // para C B b
			    break;
    
			    case 'a':// para C B a
			    break;
    
			    default: cout << "Usted ha ingresado una opcion incorrecta"<<endl;
								}
		    break;// fin C B
    
		    case 'a': // inicio C a
		    switch(dato3)	{
			    case 'c': // para C a c
			    break;
    
			    case 'A': // para C a A
			    break;
    
			    case 'B': // para C a B
			    break;
    
			    case 'b': // para C a b
			    break;
    
			    default: cout << "Usted ha ingresado una opcion incorrecta"<<endl;
								}
		    break; // fin C a
    
		    default: cout << "Usted ha ingresado una opción incorrecta"<<endl;
							}
    break;// fin C
    cout <<""<<endl;
    default: cout << "    Usted ha ingresado una opción incorrecta"<<endl;
}
cout <<""<<endl;
cout << "Para seguir en la App digite 'Y' (Y/N)" << endl;
        cin >> stopApp;

    } 
	while(toupper(stopApp) == 'Y');
//system("PAUSE");
    return 0;
}