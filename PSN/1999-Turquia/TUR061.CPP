/*
 Reinier César Mujica
 26/05/08
 "Barcos"
*/

#include <cstdio>
#include <algorithm>

using namespace std;

const int
	MAXN = 5002;

struct ship {
	int x, y;
	bool operator < ( const ship &P ) const {
         return ( x != P.x ) ? x < P.x : y < P.y;
	}
};

int N, sol = 0, i, j;
int dp[MAXN];
ship T[MAXN];

int main() {
	
	freopen( "barcos.in", "r", stdin );
	freopen( "barcos.out", "w", stdout );

	scanf( "%d %d %d", &i, &j, &N );

	for ( i = 0; i < N; i++ )
	 scanf( "%d %d", &T[i].x, &T[i].y );
	
	sort( T, T + N );

    for ( i = N - 1; i >= 0; i-- ) {
      dp[i] = 1;
      
      for ( j = i + 1; j < N; j++ )
       if ( T[i].x <= T[j].x && T[i].y <= T[j].y)
        if ( dp[i] < dp[j] + 1 )
         dp[i] = dp[j] + 1;

      sol >?= dp[i];
    }
    
    printf( "%d\n", sol );
    
	fflush( stdout );
	return 0;
}

/*
 ş Barcos                                                    
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

El  pa¡s  Palmia  est   dividido  por  un  rio  en las riveras norte y
sur.  Hay  N  pueblos en ambas riveras. Cada pueblo en la rivera norte
tiene  un  £nico  pueblo amigo en la rivera sur. Dos pueblos no tienen
el mismo amigo.

A  cada  par  de  pueblos amigos le gustar¡a tener una l¡nea de barcos
que  los  conecte  a  ellos.  Ellos  solictar n  permiso  al gobierno,
porque  muchas  veces  hay  neblina  en  el  rio y el gobierno decidi¢
prohibir  intersecciones  de  l¡neas  de  barcos  (si  dos  l¡neas  se
intersectan hay una alta probabilidad de choques de barcos).

Tarea

Escribir  un programa que ayude a los oficiales del gobierno decidir a
cuales  l¡neas  de barcos ellos deben conceder permiso para obtener un
n£mero m ximo de l¡neas de barcos sin intersecci¢n.

Entrada

El  fichero  de  entrada contiene en la primera l¡nea dos enteros X, Y
separados  por un espacio, X (10 ó X ó 6000) representa la longitud de
la  rivera  del  Rio  de Palmia , Y (10 ó Y ó 100) representa el ancho
del  rio.  La segunda l¡nea contiene al entero N, el n£mero de pueblos
situados  en  ambas riveras norte y sur (1 ó N ó 5000). En cada una de
las pr¢ximas N l¡neas hay dos enteros no negativos C y D separados por
un  espacio  (C,  D ó X), representando la distancia de pueblos amigos
del  borde  oeste  (al  este) de Palmia medido a lo largo de la rivera
del  rio (C para el pueblo de la rivera norte y D para el pueblo de la
rivera  Sur).  No  hay  dos  pueblos  en la misma posici¢n en la misma
rivera. Ver figura 1 para el ejemplo de entrada.

Salida

El  ficheo  de  salida tiene que contener el n£mero m ximo de posibles
l¡neas de barcos que satisfagan la condici¢n de arriba.

ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
³ Ejemplo de Entrada ³³ Ejemplo de Salida ³
ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´
³ 30 4               ³³ 4                 ³
³ 7                  ³ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
³ 22 4               ³
³ 2 6                ³                     Norte
³ 10 3               ³        2     4        9  10     15 17  22
³ 15 12              ³     ÄÄÄÅÄÄÅÄÄÅÄÄÅÄÄÅÄÄÅÄÄÅÄÄÅÄÄÄÅÄÄÅÄÄÄÅÄÄÄ
³ 9 8                ³
³ 17 17              ³  Oeste                                    Este
³ 4 2                ³
ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ     ÄÄÄÅÄÄÅÄÄÅÄÄÅÄÄÅÄÄÅÄÄÅÄÄÅÄÄÄÅÄÄÄÅÄÄÄÄÄÄ
                              2  3  4  6  8     12        17
                                           Sur
                                         Figura 1


ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
Tomado de: Psn Turqu¡a 1999  Ejercicio 61: Barcos                                       
*/
