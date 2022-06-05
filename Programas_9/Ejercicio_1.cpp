#include <iostream>
using namespace std;

class Complejo {
public:
	//Constructor 1 (cuatro vertices)
	Complejo(double r = 0.0, double i = 0.0) :real(r), imag(i) {}
	// Escribe los datos
	void set() {
		cin >> real >> imag;
	}
//	Reglas de adición, (a+bi)+(c+di)=(a+c)+(b+d)i
	// suma compleja
	Complejo operator+ (const Complejo &c2) const {
		return Complejo(real + c2.real, imag + c2.imag);
	}
//Reglas de resta, (a+bi)-(c+di)=(a-c)+(b-d)i
	// Resta de números complejos
	Complejo operator- (const Complejo &c2) const {
		return Complejo(real - c2.real, imag - c2.imag);
	}
//Reglas de multiplicación, (a+bi)*(c+di)=(ac-bd)+(ad+bc)i
	// Multiplicación compleja
	Complejo operator* (const Complejo &c2) const {
		return Complejo(real*c2.real - imag * c2.imag, real*c2.imag + imag * c2.real);
	}
//Reglas de división, (a+bi)/(c+di)=(ac+bd)/(c^2+d^2 )+(bc-ad)/(c^2+d^2 ) i (a+bi)/(c+di)=
//=(ac+bd)/(c2+d2)+(bc-ad)/(c2+d2)i
	// División compleja
	Complejo operator/ (const Complejo &c2) const {
		if (!c2.real && !c2.imag) {
			exit(-1);
		}
		return Complejo((real*c2.real + imag * c2.imag) / (c2.real*c2.real + c2.imag*c2.imag), 
			(imag * c2.real - real * c2.imag) / (c2.real*c2.real + c2.imag*c2.imag));
	}

	// Pantalla de salida
	void display() const{
		if(imag<0)
		{
			cout << real <<imag<< "i";
		}
		else
		{
		cout << real << "+" <<imag<< "i";
	}
	}
private:
	double real, imag;
};
int main()
{
	Complejo c1, c2, c3, c4, c5, c6;
	int dato = 0;
	cout << "\n\n\t\t\t\tEjercicio Numero 1\n";
	cout << "\n\tIntroduzca el primer numero complejo separado por espacios:\n\n\t->\t";
	c1.set();
	cout << "\n\tIntroduzca el segundo numero complejo separado por espacios:\n\n\t->\t";
	c2.set();
	cout << "\n\t\tLos numero ingresados son los siguientes\n\n";
	cout << "\tPrimer Numero Complejo =\n\t\t";c1.display(); cout << endl;
	cout << "\tSegundo Numero Complejo =\n\t\t";c2.display(); cout << endl;
	cout << endl;
	do{
	cout << "\n\tElija una opcion:\n\t";
	cout << "\n\t1.Suma   2.resta   3.Multiplicacion   4.Division   5.Salir\n\n\t->\t";
	cin >> dato;

switch (dato){
	case 1:{
			c3 = c1 + c2;
	cout << "\n\t\tLa suma es = ";	c3.display(); cout << endl;
		system("pause");
		break;
	}
case 2:{
	c4 = c1 - c2;
	cout << "\n\t\tLa resta es = ";	c4.display(); cout << endl;
	cout << endl;
		system("pause");
		break;
}
case 3:{
	c5 = c1 * c2;
	cout << "\n\t\tElproducto es = ";	c5.display(); cout << endl;
	system("pause");
	break;
}
case 4:{
		c6 = c1 / c2;
	cout << "\n\t\tLa Division es = ";	c6.display(); cout << endl;
	cout << endl;
	system("pause");
	break;
}

case 5:{
	cout << "\n\t\tGracias, Hasta luego!!!";
    return 0;
	system("pause");
	break;
}
default:{
	cout<<"\n\n\t\t\tEleccion no valida!!!"<<endl; 
	break;
}
}
}   while (dato != 5);
return 0;
     
}


