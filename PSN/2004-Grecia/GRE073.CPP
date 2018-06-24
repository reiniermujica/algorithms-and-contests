/*
 Reinier César Mujica
 5/5/08 PSN - 2008
 Convex Hull
*/

#include <cstdio>
#include <algorithm>

using namespace std;

const int
    MAXN = 102,
    oo = 1 << 29;
    
struct point {
    int x, y;
};

int N, M, sol, S[MAXN], i, j;
int x = oo, y = oo, s, top, D[MAXN];
point L[MAXN], T[MAXN];

int cross( const point &a, const point &b, const point &c ) {
    int d1 = ( a.x - c.x ) * ( b.y - c.y );
    int d2 = ( b.x - c.x ) * ( a.y - c.y );
    return d1 - d2;
}

bool cmp( const point &a, const point &b ) {
     return cross( a, b, T[0] ) > 0;
}

bool cmp_X( const int &a, const int &b ) {
     if ( T[a].x != T[b].x ) return T[a].x < T[b].x;
     return T[a].y < T[b].y;
}

int main() {

    freopen( "vacas.in", "r", stdin );
    freopen( "vacas.out", "w", stdout );
    
    scanf( "%d %d", &N, &M );
    
    for ( i = 1; i <= N; i++ )
      scanf( "%d %d", &L[i].x, &L[i].y );

    for ( i = 1; i <= M; i++ ) {
      scanf( "%d %d", &T[i].x, &T[i].y );
      if ( T[i].x < x || ( T[i].x == x && T[i].y < y ) ) {
         x = T[i].x; y = T[i].y; s = i;
         T[0].x = x; T[0].y = y;
      }
    }
    
    swap( T[s], T[M] ); M--;
    
    sort( T + 1, T + M + 1, cmp );

    top = 2;
    for ( i = 0; i < 3; i++ ) S[i] = i;
    
    for ( i = 3; i <= M; i++ ) {
      while ( cross( T[S[top]], T[S[top - 1]], T[i] ) > 0 ) top--;
      S[++top] = i;
    }
    
    S[top + 1] = 0;
    
    for ( i = 1; i <= N; i++ ) {
     bool ok = true;
     
     for ( j = 0; j <= top; j++ ) {
      if ( cross( L[i], T[S[j]], T[S[j + 1]] ) <= 0 ) {
        ok = false;
        break;
      }
     }

     if ( !ok ) D[++sol] = i;
    }
    
    printf( "%d\n", sol );
    
    for ( i = 1; i <= sol; i++ )
     printf( "%d ", D[i] );
     
    printf( "\n" );
    
    fflush( stdout );
    return 0;
}

/*
73þ Plan de sacrificio.                                    Grecia 2004
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Mikol tiene en su finca instalado un sistema de aislamiento contra
plagas que consta de varios postes, cuando dos de ellos se conectan
crean una especie de pared magn‚tica que no deja pasar a ninguna
plaga. Al conectar varios postes se puede crear un area cerrada y
aislada. Mikol se entera que se aproxima un plaga maligna para su
ganado, el sabe la posici¢n de cada vaca. Como las vacas que no se
puedan aislar se infestar n, Mikol debe saber cu les son para
sacrificarlas, usted debe ayudarlo y decirle cuales son esas vacas.
Enti‚ndase las vacas que no puedan ser aisladas, o sea, aquellas que
siempre queden fuera de cualquier  rea aislada que se forme.

Tarea

- Leer del fichero de entrada "VACAS.IN" la ubicaci¢n de las vacas y
  la ubicaci¢n de los postes, ambos representados en un sistema de
  coordenadas.
- Encontar las vacas que deber n ser sacrificadas.
- Escribir hacia el fichero de salida "VACAS.OUT" el n£mero de las
  vacas que deber n ser sacrificadas.

Entrada

El fichero de entrada "VACAS.IN" contendr  en la primera l¡nea dos
enteros N (cantidad de vacas) y M (cantidad de postes) (3 <= N, M <=
100). En las siguientes N l¡neas, en la l¡nea i+1 (i=1..N) aparecer n
dos enteros A y B, fila y columna de la posici¢n de la i-‚sima vaca
(-10000 <= A, B <= 10000). En las £ltimas M l¡neas aparecer n, en la
l¡nea j+N+1 (j=1..M) dos enteros X y Y, fila y columna de la posici¢n
del j-‚simo poste (-10000<=X, Y<=10000). No habr n tres puntos en el
sistema que pertenezcan a una misma l¡nea.

Salida

El fichero de salida "VACAS.OUT" contendr  en la primera l¡nea un
entero K denotando la cantidad de vacas que hay que sacrificar. En la
segunda l¡nea del fichero aparecer n K enteros, representando los
n£meros de las K vacas.

 Ejemplo #1 de Entrada y Salida.

 ÚÄÄÄÄÄÄÄÄ¿  ÚÄÄÄÄÄÄÄÄÄ¿
 ³VACAS.IN³  ³VACAS.OUT³
 ÃÄÄÄÄÄÄÄÄ´  ÃÄÄÄÄÄÄÄÄÄ´
 ³ 4 4    ³  ³ 2       ³
 ³ 3 2    ³  ³ 3 4     ³
 ³ 3 4    ³  ÀÄÄÄÄÄÄÄÄÄÙ
 ³ 1 1    ³
 ³ 1 3    ³
 ³ 2 1    ³
 ³ 2 4    ³
 ³ 4 2    ³
 ³ 4 5    ³
 ÀÄÄÄÄÄÄÄÄÙ
*/
