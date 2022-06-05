#include <iostream>
#include <stdlib.h>
#include <limits>
using namespace std;

struct Cafetera {
	int _capacidadMaxima, _cantidadActual, _cantidad;
	
	public:
		void Constructor_Predeterminado (){
			_capacidadMaxima = 1000;
			_cantidadActual = 0;
		}
		void Constructor_Capacidad_Maxima (){
			_cantidadActual = _capacidadMaxima;
		}
		void Constructor_Capacidad_Maxima_y_Actual (){
			if (_cantidadActual >= _capacidadMaxima)
				_cantidadActual = _capacidadMaxima;
		}
		
		
		void llenarCafetera (){
			_cantidadActual = _capacidadMaxima;
		}
		void servirTaza (int _capacidad){
			if (_cantidadActual >= _capacidad){
				_cantidad += _capacidad;
				_cantidadActual -= _capacidad;
			} else {
				_cantidad += _cantidadActual;
				_cantidadActual = 0;
			}
		}
		void agregarCafe (int _capacidad){
			if (_capacidad > _capacidadMaxima){
				cout<<"\n\tLa cantidad pedida es mayor al maximo... se derramo "<<_capacidad - (_capacidadMaxima - _cantidadActual)<<" cc.";
				_cantidadActual = _capacidadMaxima; 
			} else {
				_cantidadActual += _capacidad;	
			}
		}
		void vaciarCafetera (){
			_cantidadActual = 0;
		}
}taza;

int main (){
	cout<<"\t\t\t\tC A F E T E R I A\n";
	int opcion = 0;
	while (true){
		cout<<"\n\tCafetera:\n\t1)Capacidad Maxima 1000 cc y Cafetera vacia";
		cout<<"\n\t2)Cafetera llena a la capacidad maxima\n\t3)Si la cafetera esta mas llena de lo que deberia, se ajustara al maximo";
		cout<<"\n\t4)Personalizar los valores de capacidad maxima y la cantidad actual de la cafetera\n\t5)Continuar con la taza";
		while (true){
			cout<<"\n\n\tOpcion: ";		cin>>opcion;
			switch (opcion){
				case 1:
					taza.Constructor_Predeterminado();
					cout<<"\n\tSe lleno la cafetera a: "<<taza._cantidadActual<<" cc";
					cout<<"\n\tLa capacidad maxima de la cafetera es: "<<taza._capacidadMaxima<<" cc";
					continue;
				case 2:
					taza.Constructor_Capacidad_Maxima();
					cout<<"\n\tSe lleno la cafetera a: "<<taza._cantidadActual<<" cc";
					cout<<"\n\tLa capacidad maxima de la cafetera es: "<<taza._capacidadMaxima<<" cc";
					continue;
				case 3:
					taza.Constructor_Capacidad_Maxima_y_Actual();
					cout<<"\n\tSe lleno la cafetera a: "<<taza._cantidadActual<<" cc";
					cout<<"\n\tLa capacidad maxima de la cafetera es: "<<taza._capacidadMaxima<<" cc";
					continue;
				case 4:
					cout<<"\n\tCapacidad Maxima de la cafetera: ";		cin>>taza._capacidadMaxima;
					cout<<"\n\tCantidad actual de la cafetera: ";		cin>>taza._cantidadActual;
					continue;
				case 5:
					opcion = 10;
					break;
				default:
					cout<<"\n\tNo selecciono ninguna de las otras opciones... VUELVA A INTENTARLO\n\n";
					continue;
			}
			if (opcion == 10)
				break;
		}
			
		opcion = 0;
		cout<<"\n\tTaza:\n\t1)LLenar la cafetera";
		cout<<"\n\t2)Vaciar la cafetera\n\t3)Servir la Taza";
		cout<<"\n\t4)Agregar cafe a la cafetera\n\t5)Volver a la cafetera\n\t6)Terminar el programa";	
		while (true){
			cout<<"\n\n\tOpcion: ";		cin>>opcion;
			switch (opcion) {
				case 1:
					taza.llenarCafetera();
					cout<<"\n\tSe lleno la cafetera a "<<taza._cantidadActual<<" cc.";
					continue;
				case 2:
					taza.vaciarCafetera();
					cout<<"\n\tSe vacio la cafetera";
					continue;
				case 3:
					int x;
					cout<<"\n\tCon cuanto desea llenar la taza?: ";		cin>>x;
					taza.servirTaza(x);
					cout<<"\n\tLa taza tiene: "<<taza._cantidad<<" cc.";
					cout<<"\n\tLa cafetera tiene: "<<taza._cantidadActual<<" cc.";
					continue;
				case 4:
					int y;
					cout<<"\n\tCuanto cafe desea agregar a la cafetera?: ";		cin>>y;
					taza.agregarCafe(y);
					cout<<"\n\tLa cantidad actual en la cafetera es: "<<taza._cantidadActual<<" cc.";
					continue;
				case 5:
					opcion = 10;
					break;
				case 6:
					opcion = 20;
					break;
				default:
					cout<<"\n\tNo selecciono ninguna de las otras opciones... VUELVA A INTENTARLO\n\n";
					continue;
			}
			if (opcion == 10 || opcion == 20)
				break;
		}
		if (opcion == 20)
			break;
	}
	cout<<"\n\t\t\t(Salio de la cafeteria)";
	return 0;
}
