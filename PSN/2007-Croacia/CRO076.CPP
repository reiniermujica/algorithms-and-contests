/*
 Reinier Cesar Mujica
 23/06/2008
 "Lubenica"
*/

#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

const int
    MAXN = 100002,
    MAXL = 17,
    oo = 1 << 29;

struct node {
    int id, cost;
};

int N, queries;
int i, j, k, x, y, c, act;
int L[MAXN];
int LCA[MAXL][MAXN];
int min_s[MAXL][MAXN], max_s[MAXL][MAXN];
bool mk[MAXN];

vector < node > G[MAXN];
queue < int > Q;

int main() {

    freopen( "lubenica.in", "r", stdin );
    freopen( "lubenica.out", "w", stdout );

    scanf( "%d", &N );
    
    for ( i = 1; i < N; i++ ) {
      scanf( "%d %d %d", &x, &y, &c );
      G[x].push_back( (node) { y, c } );
      G[y].push_back( (node) { x, c } );
    }

    mk[1] = true; L[1] = 1;
    Q.push( 1 );
    
    while ( !Q.empty() ) {
      act = Q.front();
      Q.pop();
      
      mk[act] = true;
      for ( i = 0; i < G[act].size(); i++ ) {
        int next = G[act][i].id;
        int cost = G[act][i].cost;
        
        if ( !mk[next] ) {
           Q.push( next );
           LCA[0][next] = act;
           max_s[0][next] = min_s[0][next] = cost;
           L[next] = L[act] + 1;
           
           c = (int)log2( L[next] );
           for ( j = 1; j <= c; j++ )
             if ( LCA[j - 1][next] ) {
                LCA[j][next] = LCA[j - 1][LCA[j - 1][next]];
                min_s[j][next] = min_s[j - 1][next] <?
                                 min_s[j - 1][LCA[j - 1][next]];
                max_s[j][next] = max_s[j - 1][next] >?
                                 max_s[j - 1][LCA[j - 1][next]];
             }
        }
      }
    }
    
    scanf( "%d", &queries );
    
    for ( act = 0; act < queries; act++ ) {
      scanf( "%d %d", &x, &y );
      j = oo; k = 0;
      if ( L[x] < L[y] ) swap( x, y );
      c = (int)log2( L[x] );
      
      for ( i = c; i >= 0; i-- ) {
        if ( L[x] - (1 << i) >= L[y] ) {
          j <?= min_s[i][x];
          k >?= max_s[i][x];
          x = LCA[i][x];
        }
      }

      if ( x != y ) {
       c = (int)log2( L[x] );
       for ( i = c; i >= 0; i-- ) {
         if ( LCA[i][x] && LCA[i][y] != LCA[i][x] ) {
            j <?= ( min_s[i][x] <? min_s[i][y] );
            k >?= ( max_s[i][x] >? max_s[i][y] );
            x = LCA[i][x];
            y = LCA[i][y];
         }
       }
       j <?= ( min_s[0][x] <? min_s[0][y] );
       k >?= ( max_s[0][x] >? max_s[0][y] );
      }
      printf( "%d %d\n", j, k );
    }
    
    fflush( stdout );
    return 0;
}

/*
76¦ Lubenica.                                             Croacia 2007
----------------------------------------------------------------------

La red de tráfico en un pais consiste de N ciudades (identificadas con
enteros desde 1 hasta N) y N-1 caminos conectando las ciudades. Existe
un único  camino entre  cada par  de ciudades diferentes, y  conocemos
la longitud exacta de cada camino.

Escriba un programa, para cada uno  de los K pares de ciudades  dados,
encuentre la   longitud del   camino más   corto y   la longitud   del
camino más largo  en la ruta  entre cada una  de las  dos  ciudades en
cada par dado.

Entrada

El fichero de entrada LUBENICA.IN contiene un entero N,2<= N <=100000.
Cada una  de las siguientes N-1 lineas contiene tres enteros A, B y  C
representando   que  existe  un  camino   de  longitud   C  entre   la
ciudad A y la  ciudad B.  La longitud  de cada camino será   un entero
positivo menor que o igual a  1 000 000. La próxima linea  contiene un
entero K,  1 <=  K <=  100 000.  Cada una  de las  siguientes K lineas
contiene dos enteros diferentes D y E - los identificadores de las dos
ciudades que constituyen una pregunta.

Salida

Cada una de las K  lineas del fichero de salida  LUBENICA.OUT contiene
dos enteros  - la   longitud de  la descripcion  de  la  tarea para el
correspondiente par de ciudades.

Ejemplos de Entrada y Salida

Ejemplo # 1          Ejemplo # 2             Ejemplo # 3

+--------------+     +--------------+        +--------------+
¦ LUBENICA.IN  ¦     ¦ LUBENICA.IN  ¦        ¦ LUBENICA.IN  ¦
+--------------¦     +--------------¦        +--------------¦
¦ 5            ¦     ¦ 7            ¦        ¦ 9            ¦
¦ 2 3 100      ¦     ¦ 3 6 4        ¦        ¦ 1 2 2        ¦
¦ 4 3 200      ¦     ¦ 1 7 1        ¦        ¦ 2 3 1        ¦
¦ 1 5 150      ¦     ¦ 1 3 2        ¦        ¦ 3 4 5        ¦
¦ 1 3 50       ¦     ¦ 1 2 6        ¦        ¦ 2 7 4        ¦
¦ 3            ¦     ¦ 2 5 4        ¦        ¦ 1 5 3        ¦
¦ 2 4          ¦     ¦ 2 4 4        ¦        ¦ 5 6 1        ¦
¦ 3 5          ¦     ¦ 5            ¦        ¦ 5 9 2        ¦
¦ 1 2          ¦     ¦ 6 4          ¦        ¦ 1 8 3        ¦
+--------------+     ¦ 7 6          ¦        ¦ 5            ¦
+--------------+     ¦ 1 2          ¦        ¦ 6 9          ¦
¦ LUBENICA.OUT ¦     ¦ 1 3          ¦        ¦ 7 8          ¦
+--------------¦     ¦ 3 5          ¦        ¦ 9 4          ¦
¦ 100 200      ¦     +--------------+        ¦ 1 2          ¦
¦ 50 150       ¦     +--------------+        ¦ 7 3          ¦
¦ 50 100       ¦     ¦ LUBENICA.OUT ¦        +--------------+
+--------------+     +--------------¦        +--------------+
                     ¦ 2 6          ¦        ¦ LUBENICA.OUT ¦
                     ¦ 1 4          ¦        +--------------¦
                     ¦ 6 6          ¦        ¦ 1 2          ¦
                     ¦ 2 2          ¦        ¦ 2 4          ¦
                     ¦ 2 6          ¦        ¦ 1 5          ¦
                     +--------------+        ¦ 2 2          ¦
                                             ¦ 1 4          ¦
                                             +--------------+
*/
