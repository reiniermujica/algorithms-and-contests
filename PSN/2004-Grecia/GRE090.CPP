/*
 Reinier Cesar Mujica
 28/05/2008
 "Mapas Marcianos"
 Segment Tree + Sweep Line
 Hoy cumplo 17!!!
*/

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define REP( i, s, e ) \
    for ( i = s; i <= (e); i++ )

typedef long long int64;

const int
	MAXN = 10001,
	MAXC = 30001;

struct segment {
    int start, lo, hi, val;
    bool operator < ( const segment &P ) const {
        return start < P.start;
    }
};

int N, last, i, MAX;
int x1, x2, y1, y2;
int T[3 * MAXC], M[3 * MAXC];
int64 sol;
vector < segment > L;

void update( int node, int lo, int hi,
             int x, int y, int value ) {

     if ( lo > y || hi < x )
      return ;
      
     if ( lo >= x && hi <= y )
      T[node] += value;
     else {
      int mid = ( hi + lo ) / 2 ;
      update( node * 2, lo, mid, x, y, value );
      update( node * 2 + 1, mid + 1, hi, x, y, value );
     }
     
     if ( !T[node] ) {
        if ( lo == hi )
         M[node] = 0;
        else
         M[node] = ( M[node * 2] + M[node * 2 + 1] );
     }
     else
      M[node] = ( hi - lo ) + 1;
}

int main() {

    freopen( "mar.in", "r", stdin );
    freopen( "mar.out", "w", stdout );

    scanf( "%d", &N );
    
    REP( i, 0, N - 1 ) {
        scanf( "%d%d%d%d", &x1, &y1, &x2, &y2 );
        if ( x1 > x2 ) swap( x1, x2 );
        if ( y1 > y2 ) swap( y1, y2 );

        MAX >?= y1; MAX >?= y2;

        L.push_back( (segment) { x1, y1, y2 - 1 , 1 } );
        L.push_back( (segment) { x2, y1, y2 - 1, -1 } );
    }

    sort( L.begin(), L.end() );
    
    REP( i, 0, L.size() - 1 ) {
      sol += ( L[i].start - last ) * M[1];
      last = L[i].start;
      update( 1, 0, MAX, L[i].lo, L[i].hi, L[i].val );
    }
    
    printf( "%lld\n", sol );
    
    fflush( stdout );
    return 0;
}

/*
90ş Mapas Marcianos.                                       Grecia 2004
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

En el a¤o 2051, varias expediciones a Marte han explorado diferentes
 reas del planeta rojo y producido mapas de estas  reas. La BaSA
(Baltic Space Agency) tiene un plan ambicioso: a ellos les
gustar¡a producir un mapa del planeta completo. Para calcular el
esfuerzo necesario, ellos necesitan conocer el tama¤o total del  rea
para la cual el mapa ya existe. Su tarea es escribir un programa que
calcule esta  rea.

Tarea

Escribir un programa que:

. lea la descripci¢n de la forma del mapa del fichero de entrada
  MAR.IN,
. calcule el  rea total cubierta por el mapa,
. escriba el resultado hacia el fichero de salida MAR.OUT.

Entrada

El fichero de entrada MAR.IN comienza con una l¡nea conteniendo un
entero simple N (1 <= N <= 10000) el n£mero de mapas disponibles. Cada
una de las siguientes N l¡neas describe un mapa. Cada una de estas
l¡neas contiene cuatros enteros X1, Y1, X2, Y2 (0 <= X1 <= X2 <=
30000, 0 <= Y1 <= Y2 <= 30000). El valor (X1, Y1) y (X2, Y2) son las
coordenadas de, respectivamente, la esquina inferior izquierda y la
superior derecha del  rea mapeada. Cada mapa tiene forma rectangular,
y sus lados son paralelos a los ejes X y Y, del sistema de
coordenadas.

Salida

El fichero de salida MAR.OUT debe contener un entero A, el  rea total
explorada (esta es el  re0a de todos los rect ngulos).

Ejemplo de entrada y salida.

ÚÄÄÄÄÄÄÄÄÄÄÄÄÄ¿  ÚÄÄÄÄÄÄÄÄÄ¿
³ MAR.IN      ³  ³ MAR.OUT ³
ÃÄÄÄÄÄÄÄÄÄÄÄÄÄ´  ÃÄÄÄÄÄÄÄÄÄ´
³ 2           ³  ³  225    ³
³ 10 10 20 20 ³  ÀÄÄÄÄÄÄÄÄÄÙ
³ 15 15 25 30 ³
ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
*/
