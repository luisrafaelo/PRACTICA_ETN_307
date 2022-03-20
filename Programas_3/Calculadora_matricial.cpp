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
#define MAX 10
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
void EntradaDeDatos1 (int matrizA [][MAX], int matrizB [][MAX], 
int filaA, int filaB, int columnaA, int columnaB);

//matriz cholesky
void FactorizacionCholesky (int matrizC [][MAX], int orden);

//matriz unica
void EntradaDeDats (int matriz1 [][MAX], int orden);

int determinante(int matriz1[][MAX],int orden);

int cofactor(int matriz1[][MAX],int orden, int fila, int columna);

int cofactor2 (int matriz1[][MAX], int orden, int fila, int columna);

void inversa(int matriz1[][MAX], int orden);

void Rango (int mat[][MAX], int n, int m);

// Factorizacion LU
void factorizacionLU(int matriz1[][MAX], int matrizL[][MAX], int matrizU[][MAX], int orden);

//matriz triangular
void inferior(int matriz1[][MAX], int orden);
void superior(int matriz1[][MAX], int orden);

//Matriz transpuesta
void Transpuesta (int matriz[][MAX], int filaC, int columnaC);

// escalar
void Escalar(int matriz1[][MAX], int orden);

//multiplica las matrices
void Multiplicador (int matrizA [][MAX], int matrizB [][MAX], int resultado [][MAX],
int filaA, int filaB, int columnaA, int columnaB);

//divide las matrices
void Division (int matrizA[][MAX], int matrizB [][MAX], double sol[][MAX], int orden);

//suma las matrices
void Suma (int matrizA[][MAX], int matrizB[][MAX], int resultado[][MAX], int orden);

//resta las matrices
void Resta (int matrizA[][MAX], int matrizB[][MAX], int resultado[][MAX], int orden);

//muestra cualquier matriz que se le ordene mostrar
void SalidaDeDatos2 (int solucion [][MAX], int filaC, int columnaC);

int main ()
{
    do
    {   int Operador, matrizA [MAX][MAX], matrizB [MAX][MAX], resultado [MAX][MAX], 
        matrizT[MAX][MAX] , filaA, filaB, columnaA, columnaB; 
        //matriz unica
        int matriz1[MAX][MAX], matrizL[MAX][MAX], matrizU[MAX][MAX];
        int orden=0, potencia, escalr;  bool esDiagonal = true;

        cout<<"\n\n\t\t\tCALCULADORA DE MATRICES\n\n";
        //pide al usuario definir la operacion que se hara entre las matrices

        /*
        cout<<"\n\nMultiplicacion = 1\nDivision = 2\nSuma = 3\nResta = 4\nNinguno= 5\n"; //antiguo
        cout<<"\nDeterminante = 6\nL.U = 7\nElevada = 8\nDiagonal = 9\nTriangular = 10\n";  //antiguo
        cout<<"\nEscalar = 11    Factorizacion de Cholesky = 12\n"; //antiguo
        Operador = Verificador ("el operador que desea usar", 13, 0);
        */
        
        cout<<"\n\nMultiplicacion = 1\nSuma = 2\nResta = 3\nDivision = 4\n\nDeterminante = 5\n"; 
        cout<<"Matriz Inversa = 6\nMatriz Transpuesta = 7\nRango = 8\nMultiplicacion por escalar = 9\n";
        cout<<"Matriz Triangular = 10\nMatriz Diagonal = 11\nMatriz Elevada = 12\nFactorizacion LU = 13\n";  
        cout<<"Factorizacion de Cholesky = 14\n";
        Operador = Verificador ("el operador que desea usar", 15, 0);     cout<<"\n";
       
        switch (Operador) 
        {
            case 1: 
            //si cumplen las condiciones se operara las matrices
            while (columnaA != filaB)
            {   
                cout<<"\nEn la multiplicacion de matrices: el NUMERO de COLUMNAS de la PRIMERA MATRIZ\n";
                cout<<"DEBE SER IGUAL al NUMERO de FILAS de la SEGUNDA MATRIZ\n\n";
                
                filaA = Verificador ("el numero entero de filas de la Primera Matriz\t", 10, 0);
                columnaA = Verificador ("el numero entero de columnas de la Primera Matriz\t", 10, 0);
                filaB = Verificador ("el numero entero de filas de la Segunda Matriz\t", 10, 0);
                columnaB = Verificador ("el numero entero de columnas de la Segunda Matriz\t", 10, 0);
            }

            //pide al usuario ingresar los elementos de cada matriz
            EntradaDeDatos1 (matrizA, matrizB, filaA, filaB, columnaA, columnaB);

            operador = 'X';
            //multiplica las matrices
            Multiplicador (matrizA, matrizB, resultado, filaA, filaB, columnaA, columnaB);
            break;

            case 2:   
            //ingresa el orden de las matrices 
            orden = Verificador ("el orden de ambas matrices\t", 10, 0);

            //pide al usuario ingresar los elementos de cada matriz
            EntradaDeDatos1 (matrizA, matrizB, orden, orden, orden, orden);

            operador = '+';
            //suma las matrices
            Suma (matrizA, matrizB, resultado, orden);
            break;
            
            case 3:    
            //ingresa el orden de las matrices 
            orden = Verificador ("el orden de ambas matrices\t", 10, 0);

            //pide al usuario ingresar los elementos de cada matriz
            EntradaDeDatos1 (matrizA, matrizB, orden, orden, orden, orden);

            operador = '-';
            //resta las matrices
            Resta (matrizA, matrizB, resultado, orden); 
            break;

            case 4:    
            //ingresa el orden de las matrices 
            orden = Verificador ("el orden de ambas matrices\t", 10, 1);

            
            //pide al usuario ingresar los elementos de cada matriz
            EntradaDeDatos1 (matrizA, matrizB, orden, orden, orden, orden);

            operador = '/';     double sol[MAX][MAX];
            
            //divide las matrices
            Division (matrizA, matrizB, sol, orden);
            break;

            case 5:    
            //ingresa el orden de la matriz
            orden = Verificador ("el orden de la Matriz\t", 10, 0); cout<<"\n";

            //pide al usuario ingresar los elementos de cada matriz    
   			EntradaDeDats(matriz1, orden);
            cout<<"\n";
   			cout << "\nEl determinante es: " << determinante(matriz1, orden) << endl;
		    break;

            case 6:    
            //ingresa el orden de la matriz
            orden = Verificador ("el orden de la Matriz", 6, 1);    cout<<"\n";

            //pide al usuario ingresar los elementos de cada matriz    
            EntradaDeDats (matriz1, orden); cout<<"\n\n";
            
            inversa (matriz1, orden); 
            break;

            case 7:     
            //Obtiene las dimensiones de la matriz
            filaA = Verificador ("el numero entero de filas de la Matriz\t", 10, 0);
            columnaA = Verificador ("el numero entero de columnas de la Matriz\t", 10, 0);
            cout<<"\n";
            //pide al usuario ingresar los elementos de cada matriz    
   			cout<<"\nIngrese la Matriz (numeros enteros de 100 a -100): \n\n";
            for (int c = 0; c < columnaA; ++c)
            {
                for (int f = 0; f < filaA; ++f)
                {
                    Space (c);
                    matriz1[f][c] = Verificador2 (100, -100, c);
                }
            }   cout<<"\n";
            Transpuesta (matriz1, filaA, columnaA);
            break;

            case 8:    
            //Obtiene las dimensiones de la matriz
            filaA = Verificador ("el numero entero de filas de la Matriz\t", 10, 0);
            columnaA = Verificador ("el numero entero de columnas de la Matriz\t", 10, 0);
            cout<<"\n";
            //pide al usuario ingresar los elementos de cada matriz    
   			cout<<"\nIngrese la Matriz (numeros enteros de 100 a -100): \n\n";
            for (int c = 0; c < columnaA; ++c)
            {
                for (int f = 0; f < filaA; ++f)
                {
                    Space (c);
                    matriz1[f][c] = Verificador2 (100, -100, c);
                }
            }   cout<<"\n";

            Rango (matriz1, filaA, columnaA);
            break;

            case 9:     
            //ingresa el orden de las matrices 
            orden = Verificador ("el orden de la Matriz\t", 10, 0);
            cout<<"\n";
            //pide al usuario ingresar los elementos de cada matriz    
   			EntradaDeDats(matriz1, orden);
            cout<<"\n";
            cout << "Matriz multiplicada por un escalar: \n";
            Escalar(matriz1, orden);	
            break;

            case 10:    
            //ingresa el orden de las matrices 
            orden = Verificador ("el orden de la Matriz\t", 10, 0);
            cout<<"\n";
            //pide al usuario ingresar los elementos de cada matriz    
   			EntradaDeDats(matriz1, orden);
            cout<<"\n";
            cout << "Matriz triangular inferior: \n";
            inferior(matriz1, orden);   cout<<"\n";
            cout << "Matriz triangular superior: \n";
            superior(matriz1, orden);
            break;

            case 11:    
            //ingresa el orden de las matrices 
            orden = Verificador ("el orden de la Matriz\t", 10, 0);
            cout<<"\n";
            //pide al usuario ingresar los elementos de cada matriz    
   			EntradaDeDats(matriz1, orden);
            cout<<"\n";
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
		    break;

            case 12:
            //ingresa el orden de las matrices 
            orden = Verificador ("el orden de la Matriz\t", 10, 0);
            cout<<"\n";
            //pide al usuario ingresar los elementos de cada matriz    
   			EntradaDeDats(matriz1, orden);
            cout<<"\n";
            potencia = Verificador ("la potencia\t", 10, 1);
            
            //muestra el resultado
            cout << "\nEl resultado de la matriz es:\n\n";
            for (int i = 0; i < orden; i++)
            {
                cout << " | ";
                for (int j = 0; j < orden; j++) 
                {cout << pow(matriz1[i][j], potencia) << " ";}
                cout << " |\n";
    		}
		    break;

		    case 13:
            //ingresa el orden de las matrices 
            orden = Verificador ("el orden de la Matriz\t", 10, 0);
            cout<<"\n";
            //pide al usuario ingresar los elementos de cada matriz    
   			EntradaDeDats(matriz1, orden);
            cout<<"\n";
            factorizacionLU(matriz1, matrizL, matrizU, orden);
            
            //muestra el resultado
            cout<<"\nLa descomposicion de L: \n\n";
            SalidaDeDatos2 (matrizL, orden, orden);

            cout<<"\nLa descomposicion de U: \n\n";
            SalidaDeDatos2 (matrizU, orden, orden);
            break;

            case 14:
            //ingresa el orden de las matrices 
            orden = Verificador ("el orden de la Matriz\t", 10, 0);
            cout<<"\n";
            //pide al usuario ingresar los elementos de cada matriz    
   			EntradaDeDats(matriz1, orden);
            cout<<"\n";
            FactorizacionCholesky (matriz1, orden);
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

void EntradaDeDatos1 (int matrizA [][MAX], int matrizB [][MAX], 
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

    //pide al usuario definir las dimensiones de las matrices a ingresar

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

void EntradaDeDats(int matriz1[][MAX], int orden)
{   
    cout<<"\nIngrese la Matriz (numeros enteros de 100 a -100): \n\n";
    for (int c = 0; c < orden; ++c)
    {
        for (int f = 0; f < orden; ++f)
        {
            Space (c);
            matriz1[f][c] = Verificador2 (100, -100, c);
        }
    }
}

void FactorizacionCholesky (int matrizC [][MAX], int orden)
{
    int matrizT[MAX][MAX], matriz[MAX][MAX];
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
        cout<<"la factorizacion de cholesky de la Matriz es: \n";
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

void Transpuesta (int matriz[][MAX], int filaC, int columnaC)
{
    int matrizT [MAX][MAX];

    for (int f = 0; f < columnaC; ++f)
    {
        for (int c = 0; c < filaC; ++c)
        {
            matrizT[f][c] = 0;
            matrizT[f][c] = matriz[c][f];
        }
    }
    cout<<"\n";
    SalidaDeDatos2 (matrizT, columnaC, filaC);
    cout<<"\n\n";
}

void Division (int matrizA[][MAX], int matrizB [][MAX], double sol[][MAX], int orden)
{
    int k, i, j, matrizD[MAX][MAX];   double d, matrizI[MAX][MAX];
    
    if (orden == 2)
    {   
        matrizD[0][0] = matrizB[1][1];
        matrizD[1][1] = matrizB[0][0];
        matrizD[0][1] = - matrizB[0][1];
        matrizD[1][0] = - matrizB[1][0];
        d = 1.0000 / (matrizB[0][0]*matrizB[1][1] - matrizB[0][1]*matrizB[1][0]);
        for (i = 0; i < orden; ++i)
        {
            for (j = 0; j < orden; j++) 
            {
                matrizI[i][j] = matrizD[i][j] * d;
            } 
        }

        for (i = 0; i < orden; ++i)
        {
            for (j = 0; j < orden; ++j)
            {
                sol[i][j] = 0;
            }
        }

        for (i = 0; i < orden; ++i)
        {
            for (j = 0; j < orden; ++j)
            {
                for (int n = 0; n < orden; ++n)
                {
                    sol[i][j] += matrizA[i][n] * matrizI[n][j];
                }
            }
        }
        //empezara mostrando la primera matriz entre barras
        cout<<"\n\n";
        SalidaDeDatos2 (matrizA, orden, orden);
        
        //luego, abajo mostrara el operador que se uso 
        cout<<"\n\n";   Space(orden/2 + 1);  cout<<operador<<"\n\n";

        //muestra la segunda matriz entre barras
        SalidaDeDatos2 (matrizB, orden, orden);
        
        //muestra el igual y la matriz resultante
        cout<<"\n\n";   Space(orden/2 + 1);  cout<<"|  |\n";
        Space(orden/2 + 1);  cout<<"|  |\n\n";
        for (i = 0; i < orden; ++i)
        {
            for (j = 0; j < orden; ++j)
            {
                if (j == 0 )    {   cout<<"|\t";}
                cout<<sol[i][j]<<"\t";
                if (j == (orden - 1))   {   cout<<"|\n";}
            }
        }
    }
    else 
    {
        for (i = 0; i < orden; ++i)
        {
            for (j = 0; j < orden; j++) 
            {
                matrizD[i][j] = cofactor2(matrizB, orden, i, j);
            } 
        }

        k = determinante (matrizB, orden);
        d = 1.0000 / k;
        if (k == 0)   {cout<<"\n NO HAY MATRIZ INVERSA DE LA SEGUNDA MATRIZ, SU DETERMINANTE ES 0\n";}
        else 
        {
            for (i = 0; i < orden; ++i)
            {
                for (j = 0; j < orden; j++) 
                {
                    matrizI[i][j] = matrizD[j][i] * d;
                } 
            }
        }

        for (i = 0; i < orden; ++i)
        {
            for (j = 0; j < orden; ++j)
            {
                sol[i][j] = 0;
            }
        }

        for (i = 0; i < orden; ++i)
        {
            for (j = 0; j < orden; ++j)
            {
                for (int n = 0; n < orden; ++n)
                {
                    sol[i][j] += matrizA[i][n] * matrizI[n][j];
                }
            }
        }
        //empezara mostrando la primera matriz entre barras
        cout<<"\n\n";
        SalidaDeDatos2 (matrizA, orden, orden);
        
        //luego, abajo mostrara el operador que se uso 
        cout<<"\n\n";   Space(orden/2 + 1);  cout<<operador<<"\n\n";

        //muestra la segunda matriz entre barras
        SalidaDeDatos2 (matrizB, orden, orden);
        
        //muestra el igual y la matriz resultante
        cout<<"\n\n";   Space(orden/2 + 1);  cout<<"|  |\n";
        Space(orden/2 + 1);  cout<<"|  |\n\n";
        for (i = 0; i < orden; ++i)
        {
            for (j = 0; j < orden; ++j)
            {
                if (j == 0 )    {   cout<<"|\t";}
                cout<<sol[i][j]<<"\t";
                if (j == (orden - 1))   {   cout<<"|\n";}
            }
        }
    }   

    
    k = determinante (matrizB, orden);
    d = 1.0000 / k;
    if (k == 0)   {cout<<"\n NO HAY MATRIZ INVERSA DE LA SEGUNDA MATRIZ, SU DETERMINANTE ES 0\n";}
    else 
    {
        for (i = 0; i < orden; ++i)
        {
            for (j = 0; j < orden; j++) 
            {
                matrizI[i][j] = matrizD[j][i] * d;
            } 
        }
    }
        
}

void Multiplicador (int matrizA [][MAX], int matrizB [][MAX], int resultado [][MAX],
int filaA, int filaB, int columnaA, int columnaB)
{
    int f, c, k;

    //vuelve la matriz resultante nula (todos sus elementos son cero)
    for (f = 0; f < filaA; ++f)
    {
        for (c = 0; c < columnaB; ++c)
        {
            resultado[f][c] = 0;
        }
    }

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

void Suma (int matrizA[][MAX], int matrizB[][MAX], int resultado[][MAX], int orden)
{
    int f, c;
    
    //vuelve la matriz resultante nula (todos sus elementos son cero)
    for (f = 0; f < orden; ++f)
    {
        for (c = 0; c < orden; ++c)
        {
            resultado[f][c] = 0;
        }
    }

    //basicamente esta sumando cada elemento de ambas matrices con las mismas
    //coordenadas, gracias a que el ciclo for() ira pasando
    //columna por columna y cuando pase el tamaÃ±o maximo a la siguiente
    //fila, hasta pasar por cada elemento de ambas matrices
    //f es fila y c es columna 
    for (f = 0; f < orden; ++f)
    {
        for (c = 0; c < orden; ++c)
        {
            resultado[f][c] = matrizA[f][c] + matrizB[f][c];
        }
    }
    
    //empezara mostrando la primera matriz entre barras
    cout<<"\n\n";
    SalidaDeDatos2 (matrizA, orden, orden);
    
    //luego, abajo mostrara el operador que se uso 
    cout<<"\n\n";   Space(orden/2 + 1);  cout<<operador<<"\n\n";

    //muestra la segunda matriz entre barras
    SalidaDeDatos2 (matrizB, orden, orden);

    //muestra el igual y la matriz resultante
    cout<<"\n\n";   Space(orden/2 + 1);  cout<<"|  |\n";
    Space(orden/2 + 1);  cout<<"|  |\n\n";
    SalidaDeDatos2 (resultado, orden, orden);
}

void Resta (int matrizA[][MAX], int matrizB[][MAX], int resultado[][MAX], int orden)
{
    int f, c;

    //vuelve la matriz resultante nula (todos sus elementos son cero)
    for (f = 0; f < orden; ++f)
    {
        for (c = 0; c < orden; ++c)
        {
            resultado[f][c] = 0;
        }
    }

    //basicamente esta restando cada elemento de ambas matrices con las mismas
    //coordenadas, gracias a que el ciclo for() ira pasando
    //columna por columna y cuando pase el tamaÃ±o maximo a la siguiente
    //fila, hasta pasar por cada elemento de ambas matrices
    //f es fila y c es columna 
    for (f = 0; f < orden; ++f)
    {
        for (c = 0; c < orden; ++c)
        {
            resultado[f][c] = matrizA[f][c] - matrizB[f][c];
        }
    }

    //empezara mostrando la primera matriz entre barras
    cout<<"\n\n";
    SalidaDeDatos2 (matrizA, orden, orden);
    
    //luego, abajo mostrara el operador que se uso 
    cout<<"\n\n";   Space(orden/2 + 1);  cout<<operador<<"\n\n";

    //muestra la segunda matriz entre barras
    SalidaDeDatos2 (matrizB, orden, orden);

    //muestra el igual y la matriz resultante
    cout<<"\n\n";   Space(orden/2 + 1);  cout<<"|  |\n";
    Space(orden/2 + 1);  cout<<"|  |\n\n";
    SalidaDeDatos2 (resultado, orden, orden);
}

void SalidaDeDatos2 (int solucion [][MAX], 
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

int determinante(int matriz1[][MAX], int orden)
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

int cofactor(int matriz1[][MAX], int orden, int fila, int columna)
{
   int submatriz[MAX][MAX];
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

int cofactor2 (int matriz1[][MAX], int orden, int fila, int columna)
{
   int submatriz[MAX][MAX];
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

void Rango (int mat[][MAX], int n, int m)
{
  int i,j,k,r,N,z,R,p,q,v;
  if(mat[0][0]==0){
    for(j=0;j<m;j++)
    {
      z=-1;
      for(i=1;i<n;i++)
      {
        if(mat[i][j]!=0)
        {
          z=i;
          break;
        }
      }
      if(z!=-1)
      {
        for( v=0;v<m;v++)
        {
          int t=mat[0][v];
          mat[0][v]=mat[i][v];
          mat[i][v]=t;
        }
        break; 
      }
    }
  }
  for(k=0;k<n-1;k++)
  {
    for(i=k+1;i<n;i++)
    {
      p=mat[k][k];
      q=mat[i][k];
      for(j=0;j<m;j++)
      {
        mat[i][j]=p*mat[i][j] - q*mat[k][j];
      }
    }
  }
  z=0;
  for(i=0;i<n;i++)
  {
    int c=0;
    for(int j=0;j<m;j++)
    {
      if(mat[i][j]==0)  {c++;}
    }
    if(c==m)  {z++;}
  }
  R=n-z;
  N=m-R;
  cout<<"\nRango = "<<R<<endl;
  cout<<"Nulidad = "<<N<<endl;
}


void inversa(int matriz1[][MAX], int orden)
{
    int matrizD[MAX][MAX];
    int i, j, k;   double matrizI[MAX][MAX], d;

    if (orden == 2)
    {   
        matrizD[0][0] = matriz1[1][1];
        matrizD[1][1] = matriz1[0][0];
        matrizD[0][1] = - matriz1[0][1];
        matrizD[1][0] = - matriz1[1][0];
        d = 1.0000 / (matriz1[0][0]*matriz1[1][1] - matriz1[0][1]*matriz1[1][0]);
        for (i = 0; i < orden; ++i)
        {
            for (j = 0; j < orden; j++) 
                {
                    matrizI[i][j] = matrizD[i][j] * d;
                } 
        }
        cout<<"\nla matriz inversa de la matriz es: \n\n";

        for (i = 0; i < orden; ++i)
        {
            for (j = 0; j < orden; ++j)
            {
                if (j == 0 )    {   cout<<"|\t";}
                cout<<matrizI[i][j]<<"\t";
                if (j == (orden - 1))   {   cout<<"|\n";}
            }
        }
    }
    else 
    {
        for (i = 0; i < orden; ++i)
        {
            for (j = 0; j < orden; j++) 
                {
                    matrizD[i][j] = cofactor2(matriz1, orden, i, j);
                } 
        }

        k = determinante (matriz1, orden);
        d = 1.0000 / k;
        if (k == 0)   {cout<<"\n NO HAY, LA DETERMINANTE ES 0\n";}
        else 
        {
            for (i = 0; i < orden; ++i)
                {
                    for (j = 0; j < orden; j++) 
                        {
                            matrizI[i][j] = matrizD[j][i] * d;
                        } 
                }
            cout<<"\nla matriz inversa de la matriz es: \n\n";

            for (i = 0; i < orden; ++i)
            {
                for (j = 0; j < orden; ++j)
                {
                    if (j == 0 )    {   cout<<"|\t";}
                    cout<<matrizI[i][j]<<"\t";
                    if (j == (orden - 1))   {   cout<<"|\n";}
                }
            }
        }
    }   
}

//factorizacion LU
void factorizacionLU(int matriz1[][MAX], int matrizL[][MAX], int matrizU[][MAX], int orden) {
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
void inferior(int matriz1[][MAX], int orden)
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
void superior(int matriz1[][MAX], int orden)
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
void Escalar(int matriz1[][MAX], int orden)
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