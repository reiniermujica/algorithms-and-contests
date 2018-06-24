/*
 Reinier Cesar Mujica
 10/06/2008
 "Triangulacion de costo minimo"
 DP or MCM ?
*/

#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

#define REP( i, j, k ) \
    for ( i = (j); i <= (k); i++ )

#define SQR( x ) \
    ( (x) * (x) )
    
const int
    MAXN = 502,
    oo = 1 << 29;
    
typedef double real;

struct point {
    int x, y;
};

int N, i, j, k, s = 0;
int cut[MAXN][MAXN];
point P[MAXN];
real D[MAXN][MAXN];
real dp[MAXN][MAXN];

int cross( const point &a, const point &b, const point &c ) {
    return ( a.x - c.x ) * ( b.y - c.y ) -
           ( b.x - c.x ) * ( a.y - c.y );
}

bool cmp( const point &a, const point &b ) {
     return cross( a, b, P[1] ) > 0;
}

real dist( point &a, point &b ) {
     return (real)sqrt( ( SQR( abs( a.x - b.x ) )
                        + SQR( abs( a.y - b.y ) ) ) );

}

void show( int x, int y ) {
     if ( !cut[x][y] ) return ;
     if ( y - x < N - 1 )
     printf( "%d %d %d %d\n", P[x].x, P[x].y,
                              P[y].x, P[y].y );
     if ( y - x > 1 ) {
      show( x, cut[x][y] );
      show( cut[x][y], y );
     }
}

int main() {

    freopen( "chi042.in", "r", stdin );
    freopen( "chi042.out", "w", stdout );

    scanf( "%d", &N );
    
    P[0].x = P[0].y = oo;
    REP( i, 1, N ) {
     scanf( "%d %d", &P[i].x, &P[i].y );
     if ( P[i].x < P[s].x || ( P[i].x == P[s].x && P[i].y < P[s].y ) )
      s = i;
    }

    swap( P[s], P[1] );
    sort( P + 2, P + N + 1, cmp );

    REP( i, 1, N ) {
     fill( dp[i], dp[i] + MAXN, oo );
     REP( j, 1, i ) {
       if ( abs( i - j ) < 2 ) {
         D[i][j] = 0.; D[j][i] = 0.;
         dp[i][j] = 0.; dp[j][i] = 0.;
       }
       else {
        D[i][j] = dist( P[i], P[j] );
        D[j][i] = dist( P[i], P[j] );
       }
     }
    }

    REP( i, 3, N ) { // size
      REP( j, 1, N - i + 1 ) {
        int end = i + j - 1;
        REP( k, j + 1, end - 1 ) {
         real cost = (real)( D[j][k] + D[k][end] ) +
                     ( dp[j][k] + dp[k][end] );
         if ( dp[j][end] > cost ) {
          dp[j][end] = cost;
          cut[j][end] = k;
         }
        }
      }
    }
    
    printf( "%.2lf\n", dp[1][N] );
    printf( "%d\n", N - 3 );
    show( 1, N );

    fflush( stdout );
    return 0;
}

/*
 42ş Triangulaci¢n de costo m¡nimo                         China 2000
 ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

 Un  pol¡gono  convexo  se  puede  dividir  en  triangulos si trazamos
 convenientemente  varias  de  sus  diagonales.  Una  diagonal  es  un
 segmento de recta que une dos v‚rtices no adyacentes del pol¡gono.

 El  problema  consiste  en  dividir un pol¡gono convexo en tri ngulos
 trazando  algunas  de  sus diagonales de forma tal que la suma de sus
 distancias  sea  m¡nima.  Las diagolales trazadas no se pueden cortar
 entre s¡.

 Fichero de Entrada:

 Ser  encabezado por un n£mero N que indicar  el  n£mero  de  v‚rtices
 del    pol¡gono    y  acontinuaci¢n  N  l¡neas  con  las  coordenadas
 cartesianas  enteras (X,Y) de los v‚rtices del pol¡gono. Los v‚rtices
 del pol¡gono aparecer n en cualquier orden.

 Fichero de Salida:

 En la primera l¡nea aparecer   la  suma  de  las  longitudes  de  las
 diagonales trazadas con dos lugares despu‚s de la coma.
 En la segunda l¡nea aparecer  la cantidad  de  diagonales  utilizadas
 para dividir el pol¡gono y en las pr¢ximas l¡neas las n diagonales en
 la forma x,y,x1,y1.

 ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿ ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
 ³Ejemplo de Entrada³ ³Ejemplo de Salida³
 ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´ ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´
 ³ 14               ³ ³ 79.89           ³
 ³ 0 3              ³ ³ 11              ³
 ³ -4 0             ³ ³ 10 -4 2 -7      ³
 ³ 12 1             ³ ³ 7 -6 2 -7       ³
 ³ 3 -7             ³ ³ 2 -7 5 4        ³
 ³ 2 -7             ³ ³ 2 -7 0 3        ³
 ³ 5 4              ³ ³ -3 -5 0 3       ³
 ³ 10 3             ³ ³ -3 -5 -4 0      ³
 ³ -5 -3            ³ ³ -4 0 0 3        ³
 ³ 7 -6             ³ ³ 0 3 5 4         ³
 ³ 3 4              ³ ³ 5 4 10 -4       ³
 ³ -3 -5            ³ ³ 10 3 10 -4      ³
 ³ -2 2             ³ ³ 10 3 12 -1      ³
 ³ 10 -4            ³ ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
 ³ 12 -1            ³
 ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
*/
