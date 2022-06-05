#include <iostream>
using namespace std;
/////////////////////////////////////////////////
class Motor
{
private:
int m2=2,m1;

public:
		Motor():m1() {}//constructor
	//escribe el dato
void set(int m1){
this->m1=m1;
m2=m1;
}
//
int Estado(){	
return m2;
}
//

/////////////////////////////////////////////////
};
class Rueda
{
private:
int r2=2,r3=1,r4=2,r5=1,r1;

public:
		Rueda():r1(0) {}//constructor
	//escribe el dato
void set(int r1){
this->r1=r1;
r2=r1;
r3=r1;
r4=r1;
r5=r1;
}
//
int Estado(){
return r1;
}
int Estado2(){
return r2;
}

int Estado3(){
return r3;
}

int Estado4(){
return r4;
}
int Estado5(){
return r5;
}
//
//
};
//////////////////////////////////////////////////////
class Ventana
{
private:
int v2=1,v1;

public:
		Ventana():v1(0) {}//constructor
	//escribe el dato
void set(int v1){
this->v1=v1;
v2=v1;
}
//
int Estado(){	
return v2;
}
//
};
////////////////////////////////////////////
class Puerta
{
private:
int p2=2,p1;

public:
		Puerta():p1(0) {}//constructor
	//escribe el dato
void set(int p1){
this->p1=p1;
p2=p1;
}
//
int Estado(){	
return p2;
}
//
};
////////////////////////////////////////
class Coche
{
private:
int c2=2,c1;

public:
		Coche():c1(0) {}//constructor
	//escribe el dato
void set(int c1){
this->c1=c1;
c2=c1;
}
//
int Estado(){	
return c2;
}
//
};
 //////////////////////////////////////////////////
int main()
{
	Coche c;
	Motor m;
	Rueda r;
	Ventana v;
	Puerta p;
int dato=0;
cout << "\n\n\t\t\t\tEjercicio Numero 9\n";
	do{
		cout << "\n\tElija una opcion\n\t";
cout << "\n1.Motor   2.Rueda   3.Ventana   4.Puerta   5.Posicion respecto al auto   6.Verificar estado   7.Avanzar(manejar)\n\n\t-";		
cin >> dato;

switch (dato){
	case 0:{
		cout << "\n\t\tGracias, Hasta luego!!!";
		break;
	}
	case 1:{//motor
		double m1;
		{
		cout<<"\nVerificando estado:..."<<endl;
		if(m.Estado()==1)
		cout<<"\nEsta encendido el motor\n";
		if(m.Estado()==2)
		cout<<"\nEl motor esta apagado\n";
		cout<<"\nElija la siguiente accion:...\n";
		cout<<"\n1.Encender   2.apagar   3.Hacer otra cosa\n"<<endl;
		cin>>m1;	
		if(m1==3)
		cout<<"dejando la accion\n";	
		else{
		if(c.Estado()==1 and p.Estado()==2)
{	    m.set(m1);
	    cout<<"\n\n\t\tlisto!!!\n";
	    system("pause");
	}
		else
		cout<<"Primero suba al auto y cierre la puerta!!\n";
			}
		}
		break;
	}
	case 2:{//rueda
				double r1;
				int dato1=0;
		{		
		if(c.Estado()==2){
		cout<<"\nRevisar las ruedas :\n";
				cout<<"\nVerificando estado:..."<<endl;
		if(r.Estado2()==2)
		cout<<"\n1. La llanta esta desinflada\n";
		if(r.Estado2()==1)
		cout<<"\n1. La llanta esta inflada\n";	
		if(r.Estado3()==2)
		cout<<"\n2. La llanta esta desinflada\n";
		if(r.Estado3()==1)
		cout<<"\n2. La llanta esta inflada\n";	
		if(r.Estado4()==2)
		cout<<"\n3. La llanta esta desinflada\n";
		if(r.Estado4()==1)
		cout<<"\n3. La llanta esta inflada\n";	
		if(r.Estado5()==2)
		cout<<"\n4. La llanta esta desinflada\n";
		if(r.Estado5()==1)
		cout<<"\n4. La llanta esta inflada\n";	
		cout<<"\nElija la siguiente accion:...\n";
		cout<<"\n1.Inflar    2.Desinflar   3.Hacer otra cosa\n"<<endl;
		cin>>r1;
		if(r1==3)
		cout<<"dejando la accion\n";
		else
	    r.set(r1);
	    cout<<"\n\n\t\tlisto!!!\n";
	    system("pause");
	}
		else
		{
		cout<<"Debe estar abajo para revisar!\n";
		}	    	
	}
	break;
}	
	case 3:{//ventana
				double v1;
		{	
		cout<<"\nVerificando estado:..."<<endl;
		if(v.Estado()==1)
		cout<<"\nLa ventana esta subida\n";
		if(v.Estado()==2)
		cout<<"\nLa ventana esta abajo\n";
			
		cout<<"\nElija la siguiente accion:...\n";
		cout<<"\n1.Subir la ventana   2.Bajar la ventana   3.Hacer otra cosa\n"<<endl;
		cin>>v1;	
		if(v1==1 or v1==2)	
		{
		v.set(v1);
		cout<<"\n\n\t\tlisto!!!\n";
	    system("pause");
		}
		else
	    cout<<"dejando la accion\n";	
		}

		break;
	}
	case 4:{//puerta
				double p1;
		{		
		cout<<"\nVerificando estado:..."<<endl;
		if(p.Estado()==1)
		cout<<"\nLa puerta esta abierta\n";
		if(p.Estado()==2)
		cout<<"\nLa puerta esta cerrada\n";
		
		cout<<"\nElija la siguiente accion:...\n";
		cout<<"\n1.Abrir la puerta   2.Cerrar la puerta   3.Hacer otra cosa\n"<<endl;
		cin>>p1;	
		if(p1==1 or p1==2)	
		{
		p.set(p1);
		cout<<"\n\n\t\tlisto!!!\n";
	    system("pause");
		}
		else
	    cout<<"dejando la accion\n";	
		}

		break;
	}
	case 5:{//coche
		double c1;
		{	
		cout<<"\nVerificando estado:..."<<endl;
		if(c.Estado()==1)
		cout<<"\nEsta dentro el coche\n";
		if(c.Estado()==2)
		cout<<"\nEsta afuera del coche\n";	
		cout<<"\nElija la siguiente accion:...\n";
		cout<<"\n1.Subir al coche   2.Bajar del coche   3.Hacer otra cosa\n"<<endl;
		cin>>c1;	
		if(c1==3)
		cout<<"dejando la accion\n";	
		else{
			if(p.Estado()==2)
			cout<<"Debe abrir la puerta para subir o bajar\n";
			else{
	        c.set(c1);
			cout<<"\n\n\t\tlisto!!!\n";
	    system("pause");
	}
			}
		}

		break;
	}
	case 6:{
		cout<<"Los estados son:"<<endl;
		if(m.Estado()==0)
		cout<<"\nRevise el motor\n";
		if(m.Estado()==1)
		cout<<"\nEl motor esta encendido\n";
		if(m.Estado()==2)
		cout<<"\nEl motor esta apagado\n";
		if(c.Estado()==0)
		cout<<"\nRevise su posicion\n";
		if(c.Estado()==1)
		cout<<"\nEsta dentro el coche\n";
		if(c.Estado()==2)
		cout<<"\nEsta afuera del coche\n";
	    if(r.Estado()==0)
		cout<<"\nRevise las ruedas\n";
		if(r.Estado()==1)
		cout<<"\nLas ruedas estan en buen estado\n";
		if(r.Estado()==2)
		cout<<"\nLe falta aire a las ruedas\n";
		if(v.Estado()==2)
		cout<<"\nLa ventana esta abajo\n";
		if(v.Estado()==1)
		cout<<"\nLa ventana esta subida\n";
		if(p.Estado()==1)
		cout<<"\nLa puerta esta abierta\n";
		if(p.Estado()==2)
		cout<<"\nLa puerta esta cerrada\n";	
		break;
	}
	case 7:{
		if(c.Estado()==1 and m.Estado()==1 and r.Estado()==1 and p.Estado()==2)
	{	cout <<"\n\t\t\t\tBuen viaje!!!\n\n\n";
		system("pause");
}
		else
		{
		cout <<"Revise el auto!!!\n";

	}
			break;
		}
		default:{
	cout<<"\n\n\t\t\tEleccion no valida!!!"<<endl; 
	break;
}
}
}   while (dato != 0);
    return 0; 
}


