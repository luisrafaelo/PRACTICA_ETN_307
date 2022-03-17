/*	Name:  DOMINO
//	Autores: Alberto Limachi Luis Rafael
	         Nina Mamani Itamar Esteban
	Description: Problema del domino
Las fichas del domino se pueden representar por pares de números enteros.
El problema del domino consiste en colocar todas las fichas de una lista dada 
de forma que el segundo número de cada ficha coincida con el primero de la siguiente.
*/

#include <time.h>//libreria de tiempo
#include <cstdlib>
#include <list>//lista, contenedor de secuencia
#include <iostream>
 
using namespace std;
 char stopApp;
#define CARAS 6  // crea un macro para identificar
void delay(int secs) {
  for(int i = (time(NULL) + secs); time(NULL) != i; time(NULL));
}
class Ficha {		//bloque de construcci�n que conduce a la programaci�n orientada a objetos
public:
   Ficha();
   Ficha(int l1, int l2);
 
   bool puntaje();
   bool dobles();
   bool probar(Ficha c);
   void rotar();
   int lado_1();
   int lado_2();
 
   friend bool operator < (Ficha a, Ficha b);
   friend bool operator == (Ficha a, Ficha b);
   friend ostream& operator << (ostream& os, Ficha c);
 
private:
   int lado1;
   int lado2;
};
 
Ficha::Ficha()
{
   lado1 = 0;
   lado2 = 0;
}
 
Ficha::Ficha(int l1, int l2)
{
   lado1 = l1;
   lado2 = l2;
}
 
bool Ficha::probar(Ficha c)
{
   if (lado1 == c.lado1)
      return true;
   if (lado1 == c.lado2)
      return true;
   if (lado2 == c.lado1)
      return true;
   if (lado2 == c.lado2)
      return true;
   return false;
}
 
bool Ficha::dobles()
{
   if (lado1 == lado2)
      return true;
   return false;
}
 
int Ficha::lado_1()
{
   return lado1;
}
 
int Ficha::lado_2()
{
   return lado2;
}
 
bool Ficha::puntaje()
{
   return (lado1+lado2);
}
 
void Ficha::rotar()
{
    int tmp = lado1;
    lado1 = lado2;
    lado2 = tmp;
}
 
bool operator == (Ficha a, Ficha b)
{
     if (a.lado1 == b.lado1 && a.lado2 == b.lado2)
       return true;
     if (a.lado1 == b.lado2 && a.lado2 == b.lado1)
       return true;
     return false;
}
 
bool operator < (Ficha a, Ficha b)
{
    if (a.dobles() && b.dobles())
    {
       if (a.lado1 < b.lado1)
          return true;
       else
          return false;
    }
    if (a.dobles())
    {
       return false;
    }
    if (b.dobles())
    {
       return true;
    }
    if ((a.lado1+a.lado2) <= (b.lado1+b.lado2))
    {
       return true;
    }
    // La suma podria ser igual, arreglar.
    return false;
}
 
ostream& operator << (ostream& os, Ficha c)
 
{
    os << "[ " << c.lado1 << " | " << c.lado2 << " ]";
    return os;
}
 
 
class Mesa {
public:
   // En el constructor vamos a generar y revolver las fichas
   Mesa();
 
   // poner ficha a la izquierda de la mesa
   void jugar_enfrente(Ficha c);
   // poner ficha a la derecha de la mesa
   void jugar_atras(Ficha c);
 
   // Entrega los 2 numeros que se puede jugar en la mesa
   Ficha jugable();
 
   // Entrega una ficha del monton al jugador al comenzar la partida
   Ficha robar();
 
   friend ostream& operator << (ostream& os, Mesa m);
private:
   list<Ficha> monton;
   list<Ficha> jugadas;
};
 
Mesa::Mesa()
{
    int pos = 0;
    int total = (CARAS+1)*(CARAS+2)/2;
    Ficha mazo[total];
    for (int i=0; i<=CARAS; i++)
    {
      for (int j=i; j<=CARAS; j++)
      {
          Ficha f(i,j);
          mazo[pos] = f;
          pos++;
      }
    }
 
    for (int n=0; n<total; n++)
    {
        int aleat = rand() % (total-n);
        monton.push_back(mazo[aleat]);
        mazo[aleat] = mazo[total-1-n];
    }
}
 
Ficha Mesa::jugable()
{
   Ficha adelante = *(jugadas.begin());
   Ficha atras = *(jugadas.rbegin());
   Ficha j(adelante.lado_1(), atras.lado_2());
   return j;
}
 
Ficha Mesa::robar()
{
   Ficha f = *(monton.begin());
   monton.pop_front();
   return f;
}
 
// en las listas: push pone ficha, pop quita ficha.
void Mesa::jugar_enfrente(Ficha f)
{
   jugadas.push_front(f);
}
 
ostream& operator << (ostream& os, Mesa m)
{
    for (list<Ficha>::iterator i = m.jugadas.begin();
         i != m.jugadas.end();
         i++)
    {
         cout << (*i);
    }
    return os;
}
 
void Mesa::jugar_atras(Ficha f)
{
   jugadas.push_back(f);
}
 
class Jugador {
public:
   Jugador(string name, Mesa& m);
 
   void quitar(Ficha f);
   int puntaje();
   bool tiene_juego(Ficha f);
   virtual Ficha jugar(Ficha f, bool& es_adelante)=0;
 
   int cant_fichas();
   Ficha cand_comienzo();
 
   friend ostream& operator << (ostream& os, Jugador& j);
 
protected:
   string name;
   list<Ficha> fichas;
};
 
Jugador::Jugador(string n, Mesa& m)
{
   name = n;
   for (int i=0; i<7; i++)
   {
       Ficha f = m.robar();
       fichas.push_back(f);
   }
}
 
int Jugador::puntaje()
{
    int puntos = 0;
    for (list<Ficha>::iterator i = fichas.begin();
         i != fichas.end();
         i++)
    {
         Ficha mia = (*i);
         puntos += mia.lado_1();
         puntos += mia.lado_2();
    }
    return puntos;
}
 
bool Jugador::tiene_juego(Ficha f)
{
    for (list<Ficha>::iterator i = fichas.begin();
         i != fichas.end();
         i++)
    {
         Ficha mia = (*i);
         if (mia.lado_1() == f.lado_1())
           return true;
         if (mia.lado_1() == f.lado_2())
           return true;
         if (mia.lado_2() == f.lado_1())
           return true;
         if (mia.lado_2() == f.lado_2())
           return true;
    }
    return false;
}
 
int Jugador::cant_fichas()
{
    return fichas.size();
}
 
void Jugador::quitar(Ficha f)
{
    for (list<Ficha>::iterator i = fichas.begin();
         i != fichas.end();
         i++)
    {
         if ((*i) == f)
         {
           fichas.erase(i);
           return;
         }
    }
}
 
Ficha Jugador::cand_comienzo()
{
    Ficha f = *(fichas.begin());
    for (list<Ficha>::iterator i = fichas.begin();
         i != fichas.end();
         i++)
    {
         Ficha cand = (*i);
         if (f < cand)
            f = cand;
    }
    return f;
}
 
ostream& operator << (ostream& os, Jugador& j)
{
   os << "Jugador: " << j.name << endl;
   os << "   Fichas: " << endl;
   for (list<Ficha>::iterator i = j.fichas.begin();
        i != j.fichas.end();
        i++)
   {
       os << "            " << (*i) << endl;
   }
}
 
class JugadorTonto : public Jugador {
public:
   JugadorTonto(string name, Mesa& m);
   Ficha jugar(Ficha f, bool& es_adelante);
};
 
JugadorTonto::JugadorTonto(string n, Mesa& m)
  : Jugador(n, m)
{
}
 
Ficha JugadorTonto::jugar(Ficha f, bool& es_adelante)
{
    for (list<Ficha>::iterator i = fichas.begin();
         i != fichas.end();
         i++)
    {
         Ficha mia = (*i);
         if (mia.lado_1() == f.lado_1())
         {
           mia.rotar();
           es_adelante = true;
           fichas.erase(i);
           return mia;
         }
         if (mia.lado_1() == f.lado_2())
         {
           es_adelante = false;
           fichas.erase(i);
           return mia;
         }
         if (mia.lado_2() == f.lado_1())
         {
           es_adelante = true;
           fichas.erase(i);
           return mia;
         }
         if (mia.lado_2() == f.lado_2())
         {
           mia.rotar();
           es_adelante = false;
           fichas.erase(i);
           return mia;
         }
    }
}
 
int main(int argc, char *argv[])
{
	do
{ 
int sec;
    int juegos_j1 = 0;
    int juegos_j2 = 0;
 delay(1);
	Mesa m;
    JugadorTonto j1("player1", m);
    JugadorTonto j2("player2", m);
 delay(1);
    cout << j1;
    cout << j2;
 delay(1);
    Ficha f1 = j1.cand_comienzo();
    Ficha f2 = j2.cand_comienzo();
    cout << "Mejor ficha jugador 1: " << f1 << endl;
    cout << "Mejor ficha jugador 2: " << f2 << endl;
 delay(1);
    bool es_turno_j1;
    if (f1 < f2)
       es_turno_j1 = false;
    else
       es_turno_j1 = true;

    if (es_turno_j1)
    {
       j1.quitar(f1);
       m.jugar_enfrente(f1);
       es_turno_j1 = false;
    }
    else
    {
       j2.quitar(f2);
       m.jugar_enfrente(f2);
       es_turno_j1 = true;
    }

    int cant_paso = 0;
    while ((j1.cant_fichas() > 0) &&
           (j2.cant_fichas() > 0) &&
           (cant_paso < 2))
    {
       if (es_turno_j1)
       {
          if (j1.tiene_juego(m.jugable()))
          {
             bool es_adelante;
             Ficha f = j1.jugar(m.jugable(),es_adelante);
             if (es_adelante)
                m.jugar_enfrente(f);
             else
                m.jugar_atras(f);
             cant_paso = 0;
          }
          else
          {
              cant_paso++;
          }
          es_turno_j1 = false;
       }
       else
       {
          if (j2.tiene_juego(m.jugable()))
          {
             bool es_adelante;
             Ficha f = j2.jugar(m.jugable(),es_adelante);
             if (es_adelante)
                m.jugar_enfrente(f);
             else
                m.jugar_atras(f);
             cant_paso = 0;
          }
          else
          {
              cant_paso++;
          }
          es_turno_j1 = true;
 
       }
    }
  delay(2);
    cout << "Mesa: " << endl << m << endl << "Fin mesa" << endl;
    cout << j1;
    cout << j2;
  delay(2);
    if (j1.cant_fichas() < j2.cant_fichas())
    {
       juegos_j1++;
    }
    if (j2.cant_fichas() < j1.cant_fichas())
    {
       juegos_j2++;
    }
    if (j2.cant_fichas() == j1.cant_fichas())
    {
       if (j1.puntaje() < j2.puntaje())
         juegos_j1++;
       if (j2.puntaje() < j1.puntaje())
         juegos_j2++;
    }

    cout << "Juegos J1: " << juegos_j1 << endl;
    cout << "Juegos J2: " << juegos_j2 << endl;
    
    cout << "\nPara seguir en la App digite 'Y' (Si) o cualquier tecla para no seguir\n";
        cin >> stopApp;
    }
    while(toupper(stopApp) == 'Y');
    system("PAUSE");
    return EXIT_SUCCESS;
}

