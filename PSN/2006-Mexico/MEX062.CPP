/*
 Reinier César Mujica
 29/9/2008 "Autobus"
 Sweep Line + Segment Tree
 O(N*lg(N))
*/

#include <cstdio>
#include <algorithm>

using namespace std;

const int
    MAXN = 100010;
    
struct point {
	int x, y, amount, id;
	
	point( int a = 0, int b = 0, int c = 0 ) {
		x = a; y = b; amount = c;
	}
} L[MAXN];

int X, Y, N, sol;
int T[4 * MAXN];
int i, j, k;
int x, y, v;

bool cmp_X( const point &a, const point &b ) {
	 if ( a.x != b.x ) return a.x < b.x;
	 return a.y < b.y;
}

bool cmp_Y( const point &a, const point &b ) {
	 if ( a.y != b.y ) return a.y < b.y;
	 return a.x < b.x;
}

int query( int node, int ini, int fin, int x, int y ) {
	if ( ini > y || fin < x ) return -1;
	
	if ( ini >= x && fin <= y ) return T[node];
	int mid = ( ini + fin ) / 2;
	return query( node * 2, ini, mid, x, y ) >?
		   query( node * 2 + 1, mid + 1, fin, x, y );
}

void update( int node, int ini, int fin, int x, int value ) {
	 if ( ini > x || fin < x ) return ;
	 if ( ini == x && fin == x ) {
		T[node] = value;
		return ;
	 }
	 
	 int mid = ( ini + fin ) / 2;
	 update( node * 2, ini, mid, x, value );
	 update( node * 2 + 1, mid + 1, fin, x, value );
	 T[node] = T[node * 2] >? T[node * 2 + 1];
}

int main() {

    freopen( "AUT.in", "r", stdin );
    freopen( "AUT.out", "w", stdout );

    scanf( "%d %d %d", &X, &Y, &N );
    for ( i = 1; i <= N; i++ ) {
      scanf( "%d %d %d", &x, &y, &v );
	  L[i] = point( x, y, v );  
	}
	
	/* ... Init ...  */
	sort( L + 1, L + N + 1, cmp_X ); // by X
	for ( i = 1; i <= N; i++ )
	 L[i].id = i;
	sort( L + 1, L + N + 1, cmp_Y ); // by Y
	
	/* ... Sweep Line ... */
	for ( i = 1; i <= N; i++ ) {
		j = L[i].id - 1;
		if ( j ) k = query( 1, 1, N, 1, j );
		else k = 0;
		sol >?= k + L[i].amount;
		update( 1, 1, N, j + 1, k + L[i].amount );
	}

	printf( "%d\n", sol );
	return 0;
}

/*
62¦ El Autobús.                                            México 2006
----------------------------------------------------------------------

Las calles de  Byte City forman  una red regular similar a un  tablero
de ajedrez orientado de cualquiera de estas formas norte-sur o   oeste
-este. Nosotros le llamaremos  a ellas NS-calles y  WE-calles. Además,
cada calle  cruza completamente  la ciudad.  Cada NS-calle  intercepta
cada WE-calle y viceversa. Las NS-calles están numeradas desde 1 hasta
n,  comenzando en   la  mas  al oeste.  Las calles    WE-calles estan
numeradas  desde 1   hasta m,  comenzando con   la mas  al sur.   Cada
intersección de la   i-ésima  NS-calle con  la j-ésima WE-calle   está
denotada  por un par de números (i, j) (para 1 <= i <=  n, 1 <= j   <=
m).  

Existe una línea  de   autobús   en   Byte  City,   con intercepciones
que siven como  paradas.   El  autobús comienza  su itinerario  en  la
intersección  (1,  1),  y    termina  en   la  intersección    (n, m).
Además, el autobús puede solamnete viajar en dirección este y/o norte.     

Los pasajeros esperan el autobús en algunas de las intercepciones.  El
conductor del autobús desea quiere elegir su ruta de tal manera que le
permita  recoger  la mayor  cantidad  de pasajeros  como  sea posible.
(Nosotros hacemos una  suposición tal que  el interior del  autobús es
bastante espacioso para llevar todos los pasajeros  que  aguardan  por
el, independientemente de la  ruta que escoja) 

Tarea

Escriba un programa el cual:

- lea desde un fichero de entrada AUT.IN la descripción de la
  red  de carreteras  y el  número de  pasajeros que  esperan  en cada
  intersección,

- encuentre, cuantos pasajeros puede llevar el autobús como máximo,

- escriba el resultado en el fichero de salida AUT.OUT.

Entrada 

En  la primera  línea del   fichero de  entrada BUS.IN  contiene tres
enteros positivos n, m  y k - denotando  el número  de NS-calles,   el
número de  WE-calles  y  el número   de intercepciones  en  la  cuales
los pasajeros  esperan por  el autobús,   respectivamente. (1  <= n <=
10^9, 1 <= m   <= 10^9,  1 <=   k <=  10^5). Las   siguientes k líneas
describen el despliegue de pasajeros que esperan  por el autobús,  una
simple  línea por  intersección.  En   (i +  1)-ésima  línea   existen
tres   enteros positivos xi, yi y pi, separados por un simple espacio,
1 <= xi <=  n, 1 <= yi <= m, 1 <= pi  <= 10^6. Un triplo de esta forma
significa   que en   la  intersección   (xi,   yi) hay  pi   pasajeros
esperando  por el  autobús. Cada intersección   es descrita una   sola
vez  a lo  sumo en   el fichero  de entrada.  El total   de número  de
pasajeros esperando  por el autobús no excede a 1 000 000 000.

Salida

Su programa debe de escribir en el fichero de salida BUS.OUT una línea
conteniendo un entero simple - el más grande  número de pasajeros  que
el bus pueda llevar. 
 
Ejemplo de Entrada y Salida:

+---------+ +---------+
¦ AUT.IN  ¦ ¦ AUT.OUT ¦
+---------¦ +---------¦
¦ 8 7 11  ¦ ¦ 11      ¦
¦ 4 3 4   ¦ +---------+
¦ 6 2 4   ¦
¦ 2 3 2   ¦
¦ 5 6 1   ¦
¦ 2 5 2   ¦
¦ 1 5 5   ¦
¦ 2 1 1   ¦
¦ 3 1 1   ¦
¦ 7 7 1   ¦
¦ 7 4 2   ¦
¦ 8 6 2   ¦
+---------+
*/
