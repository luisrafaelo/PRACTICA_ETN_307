#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

class Quadratic{
   
public:
// ecuacion ax * 2 + bx + x
//encuentra raices
void findRoots(int a, int b, int c)
{
     
    // Si a es 0, entonces la ecuacion
    // no es cuadratica, pero si es lineal
    if (a == 0)
    {
        cout << "No es cuadratica\n";
        return;
    }
 
    int d = b * b - 4 * a * c;
    float sqrt_val = sqrt(abs(d));
 
    // Raices reales
    if (d > 0)
    {
       cout << "Las raices son reales y diferentes" << endl;
       cout << fixed << setprecision(1)
            << float((-b + sqrt_val) / (2 * a)) << endl;
       cout << fixed << setprecision(1)
            << float((-b - sqrt_val) / (2 * a)) << endl;
    }
 
    // Raices imaginarias
    else
    {
        cout << "Las raices son complejas" << endl;
        cout << fixed <<setprecision(1)
             << float(-b / (2.0 * a)) << " + i"
             << sqrt_val/ (2 * a) << endl;
        cout << fixed << setprecision(1)
             << float(-b / (2.0 * a)) << " - i"
             << sqrt_val/ (2 * a) << endl;
    }
}
};
 
//corre el codigo
int main()
{
    Quadratic obj;
 
    // Valor dado en los coeficientes
    int a, b, c;
    cout<<"\n\n\t\t Algoritmo numero 2\n";
    cout<<"\n\n\tEcuacion cuadratica de la forma ax^2+bx+c=0\n";
   cout<<"\ningrese a\n: ";
   cin>>a; 
    cout<<"\ningrese b\n:";
   cin>>b;
    cout<<"\ningrese c\n:";
   cin>>c;
    obj.findRoots(a, b, c);
}
