#include<iostream>
using namespace std;

float horner(float A[],int d ,float x)

{               double r;
                int i;
                r=A[d];
                i=d-1;
                while (i>=0)
                r = A[i--] + r * x;
                return r;
        }

int main()

{

          float *coeficientes,*A0,*A1,A0X,A1X, f_xo1,f_xo2;;                //para los numeros enteros
          int    grado, i,k, n,x0,z;                                        // Grado   

          cout << "Grado del polinomio: ";

          cin >> grado;   

        

          coeficientes = new float[grado+1];

        cout << "Ingrese los coeficientes : \n";

        for(i = grado; i > -1; i--)
{
                cin >> coeficientes[i];
}
             
         cout<<"f(x)= ";

         for(i=grado;i>=0;i--)

         {
                if(i==0)

                  cout<<coeficientes[i]<<"x^"<<i;

                else

                  cout<<coeficientes[i]<<"x^"<<i<<" + "; 

         }

         cout<<endl<<endl;

     if((grado+1) % 2)

             A0 = new float[ (grado+1) / 2 + 1];

         else

             A0 = new float[(grado+1) / 2];

       A1 = new float[(grado+1) / 2];
       for(i=0 ; i<=grado ;  i += 2 )
       {
            A0[i]=coeficientes[i];
            A1[i + 1]=coeficientes[i + 1];
       }       
            if((grado+1) % 2 != 0)      

        A0[(grado+1) / 2 + 1] = coeficientes[grado];

       cout << "Evaluar el polinomio en x0 = ";
           cin  >> x0;

           cout<<endl;

       A0X = horner(A0,grado ,x0);

       A1X = horner(A1,grado, x0);

       f_xo1 = A0X + x0 * A1X;       

       cout<<" -  (x0,f(x0)  : ("<<x0<<" , "<<f_xo1<<" )"<<endl<<endl;

       f_xo2 = A0X - x0 * A1X;    

       cout<<" -  (-x0,f(-x0)  : ( -"<<x0<<" , "<<f_xo2<<" )"<<endl<<endl;
system("pause");  
return 0;
}

