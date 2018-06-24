/*
 Reinier César Mujica
 21/05/08
 "Envases para leche"
*/

#include <cstdio>

#define REP( i, k, N ) for ( i = k; i <= N; i++ )

using namespace std;

const int
    OBJ[] = { 1, 2, 4, 16, 32, 160 },
    MAXN = 802;

int N, i, j;
int dp[MAXN];

int main() {

    freopen( "milk.in", "r", stdin );
    freopen( "milk.out", "w", stdout );
    
    scanf( "%d", &N );
    
    dp[0] = 1;
    REP( i, 0, 5 )
     REP( j, OBJ[i], N * 16 )
      dp[j] += dp[j - OBJ[i]];

    printf( "%d\n", dp[N * 16] );
    
    fflush( stdout );
    return 0;
}

/*
38þ Envases para leche                                      Korea 2002
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

El  granjero  Paul  tiene muchos envaces para leche de cada uno de los
siguientes tama¤os:

    tanque     10   galones
    cubo        2   galones
    gal¢n
    pomo      1/4   gal¢n
    pinta     1/8   gal¢n
    vaso      1/16  gal¢n

Escriba  un  programa  que  calcule el n£mero de formas que Paul puede
almacenar  X  galones  de  leche  usando  cualquier combinaci¢n de sus
envaces.  Por  ejemplo, el  granjero  Paul puede almacenar la cantidad
de un pomo de cuatro formas:

   1: 1 pomo
   2: 2 pintas
   3: 1 pinta + 2 vasos
   4: 4 vasos

Un gal¢n puede ser almacenado de 26 formas diferentes.

En todos los datos, X es un n£mero positivo y, 1 <= X galones <= 50.
Tu programa debe calcular el n£mero de combinaciones.

Entrada


El  fichero de entrada MILK.IN contiene en la primera y £nica l¡nea el
valor de X.

Salida

El  fichero  de  salida  MILK.OUT  debe contener en la primera y £nica
l¡nea  el  n£mero  de  formas en que Paul puede almacenar X galones de
leche en sus envaces.

Ejemplo de Entrada y Salida:

ÚÄÄÄÄÄÄÄÄÄ¿   ÚÄÄÄÄÄÄÄÄÄÄ¿
³ MILK.IN ³   ³ MILK.OUT ³
ÃÄÄÄÄÄÄÄÄÄ´   ÃÄÄÄÄÄÄÄÄÄÄ´
³ 5       ³   ³ 1308     ³
ÀÄÄÄÄÄÄÄÄÄÙ   ÀÄÄÄÄÄÄÄÄÄÄÙ
*/
