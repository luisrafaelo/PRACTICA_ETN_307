/*
	Name:  CALCULADORA MATRICIAL
	Autores: Alberto Limachi Luis Rafael
	         Nina Mamani Itamar Esteban
	Description: a) dadas2 matrices a y b de orden m x n  y j x k  calcular  a x b  ,  a+b  , a -b    a/b
   tambien calcular para la matriz A y B :   Determinante, matriz inversa, matriz transpuesta rango, 
   multiplicar por u n escalar , matriz triangular , matriz diagonal , matriz elevada , factorizacion LU,
    factorizacion de cholñsky, calculo de valores propios y vectores propios
*/

#include <iostream>
#include <limits>
#include <cmath>
using namespace std;

//NOTA. si quiere conocer mas sobre cada funcion, vaya hasta las ultimas lineas

int x, y;  char Apagado, operador;

void Space (int n) 
{
    while (n!=0)
    {
        cout<<"\t";
        n = n - 1;
    }
}

//verificador es una funcion para verificar que los datos introducidos sean letras o algo asi
//solo permite numeros int y si no le dice al usuario caracter invalidp
//tambien tiene limites al valor que se le meta
int Verificador (string Variable, int limiteDerecho, int limiteIzquierdo) 
{
    while (true)        //Para la verificacion de datos
    {
        cout << "Ingrese "<<Variable<<" (de "<<limiteDerecho<<" a "<<limiteIzquierdo<<") : "; cin >> x;
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
        if (x<limiteIzquierdo || x>limiteDerecho)       //poniendo limite al numero de caracteres escritos
        {   cout<<"Limite de caracteres alcanzado\n";
            continue;   //el ciclo iniciarÃ¡ de nuevo
        }
        return x;
        break; //rompe el ciclo
    }   
}

//similar a verificador, verificador2 no dice nada al usuario si mete caracteres no numericos
//solo pasa a la siguiente linea y usa Space si es necesario
//sirve para la funcion que muestra las matrices resultado y las matrices introducidas
int Verificador2 (int limiteDerecho, int limiteIzquierdo, int n)
{
    while (true)        //Para la verificacion de datos
    {
        Space(n);
        cin >> y;
        if (cin.fail()) // Si nada se pone serÃ¡ verdadero
        {   cout<<"\n"; 
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
        {   cout<<"\n"; 
            continue; // el ciclo iniciarÃ¡ de nuevo
        }
        if (y<limiteIzquierdo || y>limiteDerecho)       //poniendo limite al numero de caracteres escritos
        {   cout<<"\n"; 
            continue;   //el ciclo iniciarÃ¡ de nuevo
        }
        return y;
        break; //rompe el ciclo
    }   
};

//aqui se introducen los datos de cada matriz, mientras el operador ve cual sera la forma de la misma
void EntradaDeDatos (int matrizA [][10], int matrizB [][10], 
int filaA, int filaB, int columnaA, int columnaB);

//matriz cholesky
void FactorizacionCholesky (int matrizC [][10], int orden);

//matriz transpuesta
void Transpuesta (int matriz[][10], int orden);

//matriz unica
void EntradaDeDats (int matriz1 [][10], 
int orden);

int determinante(int matriz1[][10],int orden);

int cofactor(int matriz1[][10],int orden, int fila, int columna);

// Factorizacion LU
void factorizacionLU(int matriz1[][10], int matrizL[][10], int matrizU[][10], int orden);

//matriz triangular
void inferior(int matriz1[][10], int orden);
void superior(int matriz1[][10], int orden);

// escalar
void Escalar(int matriz1[][10], int orden);

//multiplica las matrices
void Multiplicador (int matrizA [][10], int matrizB [][10], int resultado [][10],
int filaA, int filaB, int columnaA, int columnaB);

//suma las matrices
void Suma (int matrizA [][10], int matrizB [][10], int resultado [][10],
int filaA, int filaB, int columnaA, int columnaB);

//resta las matrices
void Resta (int matrizA [][10], int matrizB [][10], int resultado [][10],
int filaA, int filaB, int columnaA, int columnaB);

void filaD (double matrizC[][10], double matrizD[][10], int filaC, int columnaC, double k, int f, int c);

//muestra cualquier matriz que se le ordene mostrar
void SalidaDeDatos2 (int solucion [][10], 
int filaC, int columnaC);

//Muestra las matrices a operar y la matriz resultado
void SalidaDeDatos (int matrizA [][10], int matrizB [][10], int resultado [][10],
int filaA, int filaB, int columnaA, int columnaB, char operador);

//le da valor int 0 a cada elemento de la matriz resultante
void Inicializador (int resultado [][10], int filaC, int columnaC);

//le da valor double 0.00000 a cada elemento de la matriz resultante
void Inicializador2 (double inversa[][10], int filaC, int columnaC); 

int des;

int main ()
{
    do
    {   int Operador, matrizA [10][10], matrizB [10][10], resultado [10][10], 
        matrizT[10][10] , filaA, filaB, columnaA, columnaB;
        double inversa[10][10];
        //matriz unica
        int matriz1[10][10], matrizL[10][10], matrizU[10][10];
        int orden=0;
        int potencia;
        int escalr;
        bool esDiagonal = true;
        //        
        cout<<"\n\n\t\t\tCALCULADORA DE MATRICES\n\n";
        cout<<"\tSi desea realizar operaciones con 2 matrices ingrese '1',\n"; 
        cout<<"\tsi quiere hallar el determinante, Factorizacion LU, etc '2'\n\n -"; 
        cin>>des;
        if (des==1)
        {
            //pide al usuario definir las dimensiones de las matrices a ingresar
            filaA = Verificador ("el numero entero de filas de la Primera Matriz", 10, 0);
            columnaA = Verificador ("el numero entero de columnas de la Primera Matriz", 10, 0);
            filaB = Verificador ("el numero entero de filas de la Segunda Matriz", 10, 0);
            columnaB = Verificador ("el numero entero de columnas de la Segunda Matriz", 10, 0);

            //pide al usuario definir la operacion que se hara entre las matrices
            cout<<"\n\nMultiplicacion = 1    Division = 2     Suma = 3    Resta = 4    Ninguno = 5\n";
            Operador = Verificador ("el operador que desea usar", 5, 1);

            //pide al usuario ingresar los elementos de cada matriz
            EntradaDeDatos (matrizA, matrizB, filaA, filaB, columnaA, columnaB);
        }
		if (des==2)
		{
            cout << "Ingresa el orden de la matriz (maximo " << 10 << "): ";
            cin>>orden;
            while (orden < 0 || orden > 10) 
            {
                cout << "\nEl orden de la matriz no puede ser mayor que " << 10 << endl;
                cout << "Ingrese nuevamente el orden de la matriz: ";
                cin >> orden;
            }
   
            cout << "\nIngrese los elementos de la matriz:\n\n";
            for (int i = 0; i < orden; i++) 
            {
                for (int j = 0; j < orden; j++)     {cin >> matriz1[i][j];}
            }
            cout<<"\n\ndeterminante = 6    L.U = 7     Elevada = 8    Diagonal = 9    Triangular = 10\n";
            cout<<"\nEscalar = 11    Factorizacion de Cholesky = 12\n";
            Operador = Verificador ("el operador que desea usar", 13, 5);
		}

        //Para cada operacion que el usuario elija
        switch (Operador) 
        {
            case 1: 
            //si cumplen las condiciones se operara las matrices
            if (columnaA == filaB)
            {   //prepara la matriz resultante
                Inicializador (resultado, filaA, columnaB); cout<<endl;

                //multiplica las matrices
                Multiplicador (matrizA, matrizB, resultado, filaA, filaB, columnaA, columnaB);
                operador = 'X'; 

                //muestra cada matriz y la matriz resultante
                SalidaDeDatos (matrizA, matrizB, resultado, filaA, filaB, columnaA, columnaB, operador);
            }   
            //caso contrario, le dira el usuario porque no se puede hacer eso
            else {  cout<<"\nNO SE PUEDE MULTIPLICAR, el NUMERO de COLUMNAS de la PRIMERA matriz\n";
                        cout<<" NO ES EL MISMO que el NUMERO de FILAS de la SEGUNDA matriz: \n";
                        cout<<"las columnas de A: "<<columnaA<<" no son iguales a las filas de B: "<<filaB;}
            break;

            case 3: 
            //si cumplen las condiciones se operara las matrices
            if ((columnaA == columnaB) && (filaA == filaB))
            {   //prepara la matriz resultante
                Inicializador (resultado, filaA, columnaB); cout<<endl;
                
                //suma las matrices
                Suma (matrizA, matrizB, resultado, filaA, filaB, columnaA, columnaB);
                operador = '+';

                //muestra cada matriz y la matriz resultante
                SalidaDeDatos (matrizA, matrizB, resultado, filaA, filaB, columnaA, columnaB, operador);
            }   
            //caso contrario, le dira el usuario porque no se puede hacer eso
            else {  cout<<"\nNO SE PUEDE SUMAR porque el ORDEN de la PRIMERA matriz\n";
                        cout<<" NO ES EL MISMO que el ORDEN de la SEGUNDA matriz";
                        cout<<"Las columnas de A: "<<columnaA<<" no son iguales a las columnas de B: "<<columnaB<<" y tampoco \n";
                        cout<<"Las filas de A: "<<filaA<<" son iguales a las filas de B: "<<filaB;}
            break;
            //si cumplen las condiciones se operara las matrices
            case 4: 
            if ((columnaA == columnaB) && (filaA == filaB))
            {   //prepara la matriz resultante
                Inicializador (resultado, filaA, columnaB); cout<<endl;
                
                //resta las matrices
                Resta (matrizA, matrizB, resultado, filaA, filaB, columnaA, columnaB);
                operador = '-';

                //muestra cada matriz y la matriz resultante
                SalidaDeDatos (matrizA, matrizB, resultado, filaA, filaB, columnaA, columnaB, operador);
            }   
            //caso contrario, le dira el usuario porque no se puede hacer eso
            else {  cout<<"\nNO SE PUEDE RESTAR porque el ORDEN de la PRIMERA matriz\n";
                        cout<<" NO ES EL MISMO que el ORDEN de la SEGUNDA matriz";
                        cout<<"Las columnas de A: "<<columnaA<<" no son iguales a las columnas de B: "<<columnaB<<" y tampoco \n";
                        cout<<"Las filas de A: "<<filaA<<" son iguales a las filas de B: "<<filaB;}
            break;

            case 6:
            cout << "\nMostrando la matriz ingresada:\n";
   			EntradaDeDats(matriz1, orden);
   			cout << "\nEl determinante es: " << determinante(matriz1, orden) << endl;
		    break;

		    case 7:
            factorizacionLU(matriz1, matrizL, matrizU, orden);
            cout << "La descomposicion de L: "<<endl;
            for (int i = 0; i < orden; i++) 
            {
                for (int j = 0; j < orden; j++)     {cout<<matrizL[i][j]<<" ";}
                cout << endl;
            }
            cout << "La descomposicion de U: "<<endl;
            for (int i = 0; i < orden; i++) 
            {
                for (int j = 0; j < orden; j++)     {cout<<matrizU[i][j]<<" ";}
                cout << endl;
   			}	
            break;

            case 8:
            cout << "\nPotencia: ";
            cin >> potencia;
            cout << "\nEl resultado de la matriz es:\n";
            for (int i = 0; i < orden; i++)
            {
                cout << " | ";
                for (int j = 0; j < orden; j++) {cout << pow(matriz1[i][j], potencia) << " ";}
                cout << " |\n";
    		}
		    break;

		    case 9:
		    for (int i = 0; i < orden; i++)
            {
                cout << "\n| ";
                for (int j = 0; j < orden; j++) 
                {   
                    cout << matriz1[i][j] << " ";
                    if (i != j)
                    {
                        if (matriz1[i][j] != 0)
                            esDiagonal = false;
                    }
                    else
                    {
                        if (matriz1[i][j] == 0)
                            esDiagonal = false;
                    }
                }
                cout << " |";
            }
            cout << endl << endl;
            if (!esDiagonal)
                cout << "NO ";
        
            cout << "Es Diagonal" << endl;
        
            cout << endl;	
		    break;

            case 10:
                
            cout << "Matriz triangular inferior: \n";
            inferior(matriz1, orden);
            cout << "Matriz triangular superior: \n";
            superior(matriz1, orden);
            break;
        
            case 11:

            cout << "Matriz multiplicada por un escalar: \n";
            Escalar(matriz1, orden);	
            break;

            case 12:
            cout<<"la factorizacion de cholesky de la primera matriz es: \n";
            FactorizacionCholesky (matrizA, filaA);
            
            cout<<"\n\nla factorizacion de cholesky de la primera matriz es: \n\n";
            FactorizacionCholesky (matrizB,  filaB);
            break;
        }

        cout<<endl;

        cout<<"\nPara reiniciar la calculadora ingrese 'Y' (Si), si no quiere ingrese cualquier tecla\n";
        cin>>Apagado;
    }

    while(toupper(Apagado) == 'Y');
    system("pause"); 
    return 0;
}

void EntradaDeDatos (int matrizA [][10], int matrizB [][10], 
int filaA, int filaB, int columnaA, int columnaB)
{
    int f, c;
    //Esta funcion recoge los datos que ponga el usuario, mientras este
    //puede ver en tiempo real la forma que le esta dando a la matriz.

    //El verificador2 funciona para evitar que el usario rompa el programa al ingresar
    //datos que no sean numeros enteros o que se salgan del limite

    //el ciclo for() ira pasando
    //columna por columna y cuando pase el tamaÃ±o maximo a la siguiente
    //fila, hasta pasar por cada elemento de ambas matrices
    //f es fila y c es columna 

    cout<<"\nIngrese la Primera Matriz (numeros enteros de 100 a -100): \n\n";
    for (c = 0; c < columnaA; ++c)
    {
        for (f = 0; f < filaA; ++f)
        {
            Space (c);
            matrizA[f][c] = Verificador2 (100, -100, c);
        }
    }
    cout<<"\nIngrese la Segunda Matriz (numeros enteros de 100 a -100): \n\n";
    for (c = 0; c < columnaB; ++c)
    {
        for (f = 0; f < filaB; ++f)
        {
            Space (c);
            matrizB[f][c] = Verificador2 (100, -100, c);
        }
    }
}

void Inicializador (int resultado [][10], int filaC, int columnaC)
{
    int f, c;
    //basicamente la funcion le da valores de int 0  a cada elemento de la matriz 
    //es para las matrices resultado y no causar un problema cuando una otra funcion
    //le de valor a la matriz de infinito o ninguno. Evita que las funciones operadoras
    //tengan problemas con la matriz resultante

    //el ciclo for() ira pasando
    //columna por columna y cuando pase el tamaÃ±o maximo a la siguiente
    //fila, hasta pasar por cada elemento de ambas matrices
    //f es fila y c es columna 

    for (f = 0; f < filaC; ++f)
    {
        for (c = 0; c < columnaC; ++c)
        {
            resultado[f][c]=0;
        }
    }   
}

void Inicializador2 (double inversa[][10], int filaC, int columnaC)
{
    int f, c;
    //basicamente la funcion le da valores de double 0.00000  a cada elemento de la matriz 
    //es para las matrices resultado y no causar un problema cuando una otra funcion
    //le de valor a la matriz de infinito o ninguno. Evita que las funciones operadoras
    //tengan problemas con la matriz resultante

    //el ciclo for() ira pasando
    //columna por columna y cuando pase el tamaÃ±o maximo a la siguiente
    //fila, hasta pasar por cada elemento de ambas matrices
    //f es fila y c es columna 

    for (f = 0; f < filaC; ++f)
    {
        for (c = 0; c < columnaC; ++c)
        {
            inversa[f][c]=0;
        }
    }
}

void FactorizacionCholesky (int matrizC [][10], int orden)
{
    int matrizT[10][10], matriz[10][10];
    for (int f = 0; f < orden; ++f)
    {
        for (int c = 0; c < orden; ++c)
        {
            matriz[f][c] = 0;
            matrizT[f][c] = 0;
        }
    }
    char Prueba; 
    for (int f = 0; f < orden; ++f)
    {
        for (int c = 0; c < orden; ++c)
        {   
            if (matrizC[c][f] == matrizC[f][c]) {continue;}
            else {Prueba = 'F';}
        }    
    }
    if (Prueba == 'F')    {cout<<"\nLa matriz no es simetrica\n";  }   
    else 
    {
        for (int i = 0; i < orden; ++i)
        {
            for (int j = 0 ;j < orden; ++j)
            {
                if (i == j)
                {
                    int sumatoria = 0;
                    for (int k = 0; k < j; ++k)
                    {
                        sumatoria += pow (matriz[i][k], 2);
                    }
                    matriz[i][j] = sqrt ( matrizC[i][j] - sumatoria); 
                }
                else if (j > i) {matriz[i][j] = 0;}
                else 
                {
                    int sumatoria = 0;
                    for (int k = 0; k < j; ++k)
                    {
                        sumatoria += matriz[i][k] * matriz[j][k];
                    }
                    matriz[i][j] = ( matrizC[i][j] - sumatoria) / matriz[j][j];
                }
            }
        }
        cout<<"\n";
        SalidaDeDatos2 (matriz, orden, orden);
        cout<<"\n\n";
        for (int f = 0; f < orden; ++f)
        {
            for (int c = 0; c < orden; ++c)
            {   
                if (f == c) {matrizT[f][f] = matriz[f][f];}
                else    {matrizT[c][f] = matriz[f][c];}
            }    
        }
        SalidaDeDatos2 (matrizT, orden, orden);
        cout<<"\n\n";
    };
}

void Transpuesta (int matriz[][10], int orden)
{
    int matrizT [10][10];
    Inicializador (matrizT, orden, orden);
    for (int f = 0; f < orden; ++f)
    {
        for (int c = 0; c < orden; ++c)
        {   
            if (f == c) {matrizT[f][f] = matriz[f][f];}
            else    {matrizT[c][f] = matriz[f][c];}
        }    
    }
    cout<<"\n";
    SalidaDeDatos2 (matrizT, orden, orden);
    cout<<"\n\n";
}

void Multiplicador (int matrizA [][10], int matrizB [][10], int resultado [][10],
int filaA, int filaB, int columnaA, int columnaB)
{
    int f, c, k;
    //basicamente esta multiplicando cada elemento de las columnas de A
    //y elementos de la fila de B, gracias a que el ciclo for() ira pasando
    //columna por columna de A multiplicandolo por cada elemento de la fila de B
    //esto es gracias a k que es el numero de columna de A y el numero de fila de B
    //k ira aumentando a medida que se multiplica cada elemento y se suma con +=
    //f es fila y c es columna 
    for (f = 0; f < filaA; ++f)
    {
        for (c = 0; c < columnaB; ++c)
        {
            for (k = 0; k < columnaA; ++k)
            {
                resultado[f][c] += matrizA[f][k] * matrizB[k][c];
            }
        }
    }
}

void Suma (int matrizA [][10], int matrizB [][10], int resultado [][10],
int filaA, int filaB, int columnaA, int columnaB)
{
    int f, c;
    //basicamente esta sumando cada elemento de ambas matrices con las mismas
    //coordenadas, gracias a que el ciclo for() ira pasando
    //columna por columna y cuando pase el tamaÃ±o maximo a la siguiente
    //fila, hasta pasar por cada elemento de ambas matrices
    //f es fila y c es columna 
    for (f = 0; f < filaA; ++f)
    {
        for (c = 0; c < columnaB; ++c)
        {
            resultado[f][c] = matrizA[f][c] + matrizB[f][c];
        }
    }
}

void Resta (int matrizA [][10], int matrizB [][10], int resultado [][10],
int filaA, int filaB, int columnaA, int columnaB)
{
    int f, c;
    //basicamente esta restando cada elemento de ambas matrices con las mismas
    //coordenadas, gracias a que el ciclo for() ira pasando
    //columna por columna y cuando pase el tamaÃ±o maximo a la siguiente
    //fila, hasta pasar por cada elemento de ambas matrices
    //f es fila y c es columna 
    for (f = 0; f < filaA; ++f)
    {
        for (c = 0; c < columnaB; ++c)
        {
            resultado[f][c] = matrizA[f][c] - matrizB[f][c];
        }
    }
}

void SalidaDeDatos2 (int solucion [][10], 
int filaC, int columnaC)
{
    int f, c;
    //el codigo ira formando la matriz que se le dio, desde cada columna
    //hasta cada fila, ademas de poner la matriz entre barras
    
    //El ciclo for() ira pasando
    //columna por columna y cuando pase el tamaÃ±o maximo a la siguiente
    //fila, hasta pasar por cada elemento de ambas matrices
    //f es fila y c es columna 

    for (f = 0; f < filaC; ++f)
    {
        for (c = 0; c < columnaC; ++c)
        {
            if (c == 0 )    {   cout<<"|\t";}
            cout<<solucion[f][c]<<"\t";
            if (c == (columnaC - 1))   {   cout<<"|\n";}
        }
    }
}

void SalidaDeDatos (int matrizA [][10], int matrizB [][10], int resultado [][10],
int filaA, int filaB, int columnaA, int columnaB, char operador)
{
    int f, c;
    //empezara mostrando la primera matriz entre barras
    cout<<"\n\n";
    SalidaDeDatos2 (matrizA, filaA, columnaA);
    
    //luego, abajo mostrara el operador que se uso 
    cout<<"\n\n";   Space(columnaA/2 + 1);  cout<<operador<<"\n\n";

    //muestra la segunda matriz entre barras
    SalidaDeDatos2 (matrizB, filaB, columnaB);

    //muestra el igual y la matriz resultante
    cout<<"\n\n";   Space(columnaB/2 + 1);  cout<<"|  |\n";
    Space(columnaB/2 + 1);  cout<<"|  |\n\n";
    SalidaDeDatos2 (resultado, filaA, columnaB);
}

void EntradaDeDats(int matriz1[][10], int orden)
{
   cout << "Orden: " << orden << endl;
   for (int i = 0; i < orden; i++) {
      for (int j = 0; j < orden; j++) {
         cout << "\t" << matriz1[i][j];
      }
      cout << "\n";
   }
}

int determinante(int matriz1[][10], int orden)
{
   int det = 0.0;
   
   if (orden == 1) {
      det = matriz1[0][0];
   } else {
      for (int j = 0; j < orden; j++) {
         det = det + matriz1[0][j] * cofactor(matriz1, orden, 0, j);
      }
   }
   
   return det;
}


int cofactor(int matriz1[][10], int orden, int fila, int columna)
{
   int submatriz[10][10];
   int n = orden - 1;
   
   int x = 0;
   int y = 0;
   for (int i = 0; i < orden; i++) {
      for (int j = 0; j < orden; j++) {
         if (i != fila && j != columna) {
            submatriz[x][y] = matriz1[i][j];
            y++;
            if (y >= n) {
               x++;
               y = 0;
            }
         }
      }
   }
   
   return pow(-1.0, fila + columna) * determinante(submatriz, n);
}

//factorizacion LU
void factorizacionLU(int matriz1[][10], int matrizL[][10], int matrizU[][10], int orden) {
   int i = 0, j = 0, k = 0;
   for (i = 0; i < orden; i++) {
      for (j = 0; j < orden; j++) {
         if (j < i)
         matrizL[j][i] = 0;
         else {
            matrizL[j][i] = matriz1[j][i];
            for (k = 0; k < i; k++) {
              matrizL[j][i] = matrizL[j][i] - matrizL[j][k] * matrizU[k][i];
            }
         }
      }
      for (j = 0; j < orden; j++) {
         if (j < i)
         matrizU[i][j] = 0;
         else if (j == i)
         matrizU[i][j] = 1;
         else {
            matrizU[i][j] = matriz1[i][j] / matrizL[i][i];
            for (k = 0; k < i; k++) {
               matrizU[i][j] = matrizU[i][j] - ((matrizL[i][k] * matrizU[k][j]) / matrizL[i][i]);
            }
         }
      }
   }
}

//Funcion matriz inferior
void inferior(int matriz1[][10], int orden)
{
    int i, j;
    for (i = 0; i < orden; i++)
    {
        for (j = 0; j < orden; j++)
        {
            if (i < j)
            {
                cout << "0" << " ";
            }
            else
            cout << matriz1[i][j] << " ";
        }
        cout << endl;
    }
}
 
// Funcion matriz superior
void superior(int matriz1[][10], int orden)
{
    int i, j;
     
    for (i = 0; i < orden; i++)
    {
        for (j = 0; j < orden; j++)
        {
            if (i > j)
            {
                cout << "0" << " ";
            }
            else
            cout << matriz1[i][j] << " ";
        }
        cout << endl;
    }
}

//multiplicacion por un escalar
void Escalar(int matriz1[][10], int orden)
{
	int escalr;
			cout << "\nEscalar: ";
     		cin >> escalr; 
   for (int i = 0; i < orden; i++) {
      for (int j = 0; j < orden; j++) {
         cout << "\t" << matriz1[i][j]*escalr;
      }
      cout << "\n";
   }
}