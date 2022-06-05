#include <iostream>

using namespace std;

struct Cuenta {
	int num_cuenta, dni;
	double saldo, interes_anual;
	public:
		void inicio (){
			num_cuenta = 100001;
			dni = 123456789;
			saldo = 5000.00;
			interes_anual = 10.00;
		}
		void actualizarSaldo (){
			if ((saldo - interes_anual) <= 0){
				cout<<"\n\t\tTe quedaste sin dinero... ESTAS QUEBRADO... tenga un buen dia";
				saldo = 0.00;
			} else {
				saldo -= saldo * (interes_anual / 36500.00);
			}
		}
		void ingresar (double x){
			saldo += x;
		}
		void retirar (double x){
			if (x <= saldo){
				saldo -= x;
			} else {
				cout<<"\n\tNO HAY SUFICIENTE PARA LA TRANSACCION PEDIDA";
			}
		}
};

int main(){
	cout<<"\t\t\t\tB A N C O";
	int n, opcion, key = 0;
	cout<<"\n\n\tCuantos usuarios estan usando el banco? ";		cin>>n;
	Cuenta usuario[n];
	double monto[n], deposito[n], cobro[n];
	for (int i = 0; i < n; i++){
		usuario[0].inicio();
		monto[i] = 0.00;
		deposito[i] = 0.00;
		cobro[i] = 0.00;
		usuario[i].num_cuenta += i;
		usuario[i].dni += i;
		fflush(stdin);
		
		if (key > 0)
			continue;

		cout<<"\n\tMenu:	Cuenta actual ["<<i+1<<"]\n\t1)Entrar con la cuenta ["<<i+2<<"]";
		cout<<"\n\t2)Actualizar saldo\n\t3)Depositar";
		cout<<"\n\t4)Retirar\n\t5)Mostrar el estado de la cuenta\n\t6)Salir del Banco";
		cout<<"\n\n\tNumero de cuenta: "<<usuario[i].num_cuenta;
		cout<<"\n\tDNI: "<<usuario[i].dni;
		cout<<"\n\tSaldo: "<<usuario[i].saldo<<" sus";
		cout<<"\n\tInteres Anual: "<<usuario[i].interes_anual<<" %";
		while (true){
			cout<<"\n\n\tOpcion: ";		cin>>opcion;
			switch (opcion){
				case 1:
					usuario[i].inicio();
					cout<<"\n\tNumero de cuenta: "<<usuario[i].num_cuenta;
					cout<<"\n\tDNI: "<<usuario[i].dni;
					cout<<"\n\tSaldo: "<<usuario[i].saldo<<" sus";
					cout<<"\n\tInteres Anual: "<<usuario[i].interes_anual<<" %";
					opcion = 10;	
					break;
				case 2:
					usuario[i].actualizarSaldo();
					cout<<"\n\tSe ha efectuado el interes diario de "<<usuario[i].interes_anual/365.00<<" %";
					cobro[i] += usuario[i].saldo * (usuario[i].interes_anual/36500.00);
					cout<<"\n\tSaldo: "<<usuario[i].saldo<<" sus";
					continue;
				case 3:
					double y;
					cout<<"\n\tIngrese el monto a depositar: ";		cin>>y;
					deposito[i] += y;
					usuario[i].ingresar(y);
					cout<<"\n\tSaldo: "<<usuario[i].saldo<<" sus";
					continue;
				case 4:
					double z;
					cout<<"\n\tIngrese el monto a retirar: ";		cin>>z;
					usuario[i].retirar(z);
					if (usuario[i].saldo > z){
						cout<<"\n\t(RECIBISTE "<<z<<" sus )";
						monto[i] += z;
					}
					cout<<"\n\tSaldo: "<<usuario[i].saldo<<" sus";
					continue;
				case 5:
					cout<<"\n\tNumero de cuenta: "<<usuario[i].num_cuenta;
					cout<<"\n\tDNI: "<<usuario[i].dni;
					cout<<"\n\tSaldo: "<<usuario[i].saldo<<" sus";
					cout<<"\n\tInteres Anual: "<<usuario[i].interes_anual<<" %";
					continue;
				case 6:
					opcion = 20;	key = 1;
					break;
				default:
					cout<<"\n\tNo selecciono ninguna de las otras opciones... VUELVA A INTENTARLO\n\n";
					continue;
			}
			if (opcion == 10 || opcion == 20) 
				break;
		}
		if (opcion == 10 || opcion == 20)
			continue;
	}
	for(int i = 0; i < n; i++){
		cout<<"\n\t\t\t\t El Usuario ["<<i+1<<"] Salio del banco con: "<<monto[i]<<" sus\n\t\t\t\t\t\t";
		cout<<"Tambien depositando: "<<deposito[i]<<" sus \n\t\t\t\t\t\tPor ultimo, el interes le cobro: "<<cobro[i]<<" sus\n";
	}
	return 0;
}
