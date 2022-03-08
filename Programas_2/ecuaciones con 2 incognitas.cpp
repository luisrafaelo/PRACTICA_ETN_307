/*
	Name:  Ecuaciones lineales 2x2
	Autores: Alberto Limachi Luis Rafael
	         Nina Mamani Itamar Esteban
	Description: Resolver un sistema de 2 ecuaciones y 2 incógnitas
*/

#include <iostream> //librerias
#include <limits>   //Para usar informacion de propiedades aritmeticas, como max()
                    //Basicamente es para el codigo de la verificacion de datos
using namespace std;
float x;
float Verificador (string Variable) {
    while (true)        //Para la verificacion de datos
    {
        cout << "Escriba el numero "<<Variable<<": "; cin >> x;
        if (cin.fail()) // Si nada se pone serÃ¡ verdadero
        {   cout<<"Caracter invalido\n";
            cin.clear(); // Para resetear los bits
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            //ignore() es usado para limpiar los datos incorrectos
            continue; // El ciclo iniciarÃ¡ de nuevo
        }
        //Para limpiar datos adicionales como: atr15 (atr es adicional)
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        // Remueve los datos adicionales de la entrada de datos
        if (cin.gcount() > 1) 
        // Devolvera mas de 1 si hay algun sobrante de datos invalidos
        {   cout<<"Caracter invalido, no te pases de listo\n";
            continue; // el ciclo iniciarÃ¡ de nuevo
        }
        if (x>1000 || x<-1000)       //poniendo limite al numero de caracteres escritos
        {   cout<<"Limite de caracteres alcanzado\n";
            continue;   //el ciclo iniciarÃ¡ de nuevo
        }
        return x;
        break; //rompe el ciclo
    }   
}
void t1 (){cout<<"EL VALOR DE Y ES: Infinito\n";}
void t2 (){cout<<"EL VALOR DE X ES: Infinito\n";}
void t3 (){cout<<"EL VALOR DE Y ES: Ninguno\n";}
void t4 (){cout<<"EL VALOR DE X ES: Ninguno\n";}
void t5 (){cout<<"EL VALOR DE Y ES: 0\n";}
void t6 (){cout<<"EL VALOR DE X ES: 0\n";}
char stopApp;

int main()
{
    do
    {   cout<<"2 ECUACIONES CON 2 INCOGNITAS\n"; cout<<"   -\n";
        cout<<"   | aX+bY=c\n";
        cout<<"   | dX+eY=f\n"; cout<<"   -\n";
        cout<<"Inserta la primera ecuacion:  ";     cout<<"aX+bY=c   (-1000 < a,b,c < 1000)\n\n"; 
        float x1 = Verificador ("a");         //La variable se iguala al verificador
        float y1 = Verificador ("b");         //luego se le agrega el nombre de la variable en " "
        float re1 = Verificador ("c");        //finalmente el verificador devolvera el valor
                                            //que ya fue verificado segun las condiciones
                                            //previamente establecidas
        cout<<"Inserta la segunda ecuacion:   ";    cout<<"dX+eY=f   (-1000 < d,e,f < 1000)\n\n";
        float x2 = Verificador ("d");
        float y2 = Verificador ("e");
        float re2 = Verificador ("f");

        //Esta cadena de "else if" ira descartando cada caso hasta encontrar la
        //solucion correcta a las ecuaciones lineales 2 x 2
        if ((x1==0 && y1==0 && re1==0 && x2==0 && y2==0 && re2==0) || (x2==0 && y2==0 && re2==0 && x1==0 && y1==0 && re1==0)) {t1(); t2();}
        else if ((x1==0 && y1==0 && x2==0 && y2==0) || (x2==0 && y2==0 && x1==0 && y1==0)) {t3(); t4();}
        else if ((x1==0 && y1==0 && re2==0 && y2==0) || (x2==0 && y2==0 && re1==0 && y1==0)) {t1(); t6();}
        else if ((x1==0 && y1==0 && x2==0 && re2==0) || (x2==0 && y2==0 && x1==0 && re1==0)) {t5(); t2();}
        else if (x1==0 && y1==0 && x2==0 && re1==0) {cout<<"EL VALOR DE Y ES: "<<re2/y2<<"\n"; t2();}
        else if (x1==0 && y1==0 && x2==0) {cout<<"EL VALOR DE Y ES: "<<re2/y2<<"\n"; t4();}
        else if (x2==0 && y2==0 && x1==0 && re2==0) {cout<<"EL VALOR DE Y ES: "<<re1/y1<<"\n"; t2();}
        else if (x2==0 && y2==0 && x1==0) {cout<<"EL VALOR DE Y ES: "<<re1/y1<<"\n"; t4();}
        else if (x1==0 && y1==0 && y2==0 && re1==0) {;t1(); cout<<"EL VALOR DE X ES: "<<re2/x2<<"\n";}
        else if (x1==0 && y1==0 && y2==0) {;t3(); cout<<"EL VALOR DE X ES: "<<re2/x2<<"\n";}
        else if (x2==0 && y2==0 && y1==0 && re2==0) {;t1(); cout<<"EL VALOR DE X ES: "<<re1/x1<<"\n";}
        else if (x2==0 && y2==0 && y1==0) {;t3(); cout<<"EL VALOR DE X ES: "<<re1/x1<<"\n";}
        else if ((x1==0 && y1==0) || (x2==0 && y2==0)){t1(); t2();}
        else if (x1==x2 && y1==y2 && re1==re2) 
        {cout<<"Hay soluciones infinitas porque las ecuaciones son rectas identicas\n";}
        else {
            float z = x1*y2 - y1*x2;
            float xr = (re1*y2 - y1*re2) / z;
            float yr = (x1*re2 - re1*x2) / z;
            if (z != 0)
            {   if (xr == 0 || yr == 0) 
                {   cout<<"Hay soluciones infinitas porque las ecuaciones son rectas identicas\n";}
                else
                {   cout<<"EL VALOR DE Y ES: "<<yr<<"\n";
                    cout<<"EL VALOR DE X ES: "<<xr<<"\n";}    
            }   
            else 
            {   cout<<"No hay solucion porque las ecuaciones son rectas paralelas y nunca se cruzaran\n";}
        }
        cout << "\nPara seguir en la App digite 'Y' (Si) o cualquier tecla para no seguir\n";
        cin >> stopApp;
    }
    while(toupper(stopApp) == 'Y');     //le permite al usuario correr el programa de nuevo
    system("pause");                        //"Presione cualquier tecla para salir"
    return 0;
}