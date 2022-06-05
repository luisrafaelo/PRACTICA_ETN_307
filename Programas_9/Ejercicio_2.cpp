#include <iostream>
using namespace std;
class Rectangulo
{
private:
	int x1,x2,y1,y2,t1,t2,x,y;	
public:
	Rectangulo():x1(0),x2(0),y1(0),y2(0),x(0),y(0)//constructor por vertice
	{ 	t1=abs(y2-y1);
		t2=abs(x2-x1);}
	Rectangulo(int base, int altura):x1(base),y2(altura)//constructor copia
	{	t1=x1;
		t2=y2;
	}
	void showinfo(){
	cout << "\n\tLos vertices son:\n\t";
	 cout<<'('<<x1<<','<<y1<<')'<<'('<<x2<<','<<y2<<')'<<'('<<x1<<','<<y2<<')'<< '('<<x2<<','<<y1<<')';
	}
	//almacena los datos en variables
	void set(int x1,int y1,int x2,int y2, int x, int y){
		this->x1=x1;
		this->x2=x2;
		this->y1=y1;
		this->y2=y2;
		this->y=y;
		this->x=x;
		t1=abs(y2-y1);
		t2=abs(x2-x1);
	}
			void showin(){
	cout << "\n\tLos vertices son:\n\t";
	 cout<<'('<<x<<','<<y<<')'<<'('<<x+t1<<','<<y+t2<<')'<<'('<<x<<','<<y+t1<<')'<< '('<<x+t2<<','<<y<<')';
	}
	int perimetro(){
		return 2*(t1+t2);
	}
	int area(){
		return t1*t2;
	}
	void show();
	~Rectangulo(){
	}
};
void Rectangulo::show(){

	for(int i=0;i<t1;i++)
	{
		for(int j=0;j<t2;j++)
		{
			cout<<"* ";
		}
		cout<<endl;
	}
}
