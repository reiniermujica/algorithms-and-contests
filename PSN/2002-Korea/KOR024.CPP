/*
 Reinier César Mujica
 30/07/2008
 "My first Max Flow problem solved"
*/

#include <cstdio>
#include <queue>

using namespace std;

const int
    MAXN = 202,
    oo = 1 << 29;

int N, M, sol;
int i, j, k;
int G[MAXN][MAXN];
int cap[MAXN][MAXN], fl[MAXN][MAXN];
int flow[MAXN], from[MAXN], C[MAXN];

bool augment() {
     fill( from, from + MAXN, -1 );
     fill( flow, flow + MAXN, 0 );
     flow[1] = oo;

     queue < int > Q;
     for ( Q.push( 1 ); !Q.empty(); Q.pop() ) {
        j = Q.front();
        for ( i = 0; i < C[j]; i++ ) {
            int next = G[j][i];
            if ( from[next] < 0 && fl[j][next] < cap[j][next] ) {
                flow[next] = min( flow[j], cap[j][next] - fl[j][next] );
                from[next] = j;
                Q.push( next );
            }
        }
     }
     
     if ( from[N] < 0 ) return false;
     
     i = N;
     while ( i != 1 ) {
      fl[from[i]][i] ++;
      fl[i][from[i]] --;
      i = from[i];
     }
     return true;
}

int main() {

    freopen( "GRO.in", "r", stdin );
    freopen( "GRO.out", "w", stdout );

    scanf( "%d", &N );
    for ( i = 1; i < N; i++ ) {
      scanf( "%d", &C[i] );
      for ( j = 0; j < C[i]; j++ ) {
        scanf( "%d", &G[i][j] );
        if ( i == 1 || G[i][j] == N ) cap[i][G[i][j]] = 1;
        else cap[i][G[i][j]] = oo;
      }
    }

    while ( augment() ) sol++;
    
    printf( "%d\n", sol );
    
    fflush( stdout );
    return 0;
}

/*
24× Espeleolog¡a                                            Korea 2002
ääääääääääääääääääääääääääääääääääääääääääääääääääääääääääääääääääääää

Un  equipo  de  espeleologistas  organiza  un entrenamiento en la Gran
Cueva    de    las   montaºas  Byte.  Durante  el  entrenamiento  cada
espeleologista  explora una ruta de la b¢veda del tope a la b¢veda del
fondo.    Los    espeleologistas    pueden    moverse    hacia   abajo
solamente,  es  decir  el nivel de cada b¢veda consecutiva en una ruta
debe    estar  m s  abajo  que  el  de  la b¢veda previa. Adem s, cada
espeleologista  tiene  que  comenzar  en  la  b¢veda del tope a trav‚s
de  un  pasillo  diferente  y  cada uno de ellos tiene que entrar a la
b¢veda   del    fondo   usando  diferentes  pasillos,  los   restantes
pasillos  pueden  ser atravesados  por  m s  de  un  espeleologista.
¨Cu ntos espeleolog¡stas pueden entrar simult neamente?

Tarea

Escriba un programa el cual:
- Lea la descripci¢n de la cueva del fichero texto GRO.IN,
- Calcule el n¸mero m ximo de espeleologistas que pueden entrenar
  simult neamente,
- Escriba el resultado hacia el fichero texto GRO.OUT.

Entrada

En    la    primera  l¡nea   del   fichero   texto   GRO.IN   hay   un
entero  N (2 <= N <= 200), igual al n¸mero de b¢vedas en la cueva. Las
b¢vedas  son  numeradas  con enteros de 1 a N en orden descendente del
nivel.  La b¢veda del tope tiene n¸mero 1, y la b¢veda del fondo tiene
n¸mero  N. En las siguientes N-1 l¡neas (es decir las l¡neas 2,3,..,N)
las  descripciones  de  los  pasillos  son dados. La (i+1)-‚sima l¡nea
contiene  el n¸mero de b¢vedas conectadas por pasillos con la i-‚sima
b¢veda (solamente b¢vedas con n¸meros mayores que i son mencionadas).
El  primer  n¸mero  en una l¡nea, M, 0 <= M <= (N-i+1) es un n¸mero de
pasillos  excluyendo  la b¢veda que est  siendo descrita. Entonces los
siguiente  M  enteros  son  los  n¸meros  de las b¢vedas a las que los
pasillos se dirigen.

Salida

Su  programa  debe  escribir  un  entero en la ¸nica l¡nea del fichero
texto GRO.OUT. Este n¸mero debe ser igual al n¸mero de espeleologistas
capaz de entrenar simult neamente.

Ejemplo de Entrada y Salida:

 çäääääääääää¹ çäääääääää¹
 ¨ GRO.IN    ¨ ¨ GRO.OUT ¨
 öäääääääääääª öäääääääääª
 ¨ 12        ¨ ¨ 3       ¨
 ¨ 4 3 4 2 5 ¨ þäääääääääû
 ¨ 1 8       ¨
 ¨ 2 9 7     ¨
 ¨ 2 6 11    ¨
 ¨ 1 8       ¨
 ¨ 2 9 10    ¨
 ¨ 2 10 11   ¨
 ¨ 1 12      ¨
 ¨ 2 10 12   ¨
 ¨ 1 12      ¨
 ¨ 1 12      ¨
 þäääääääääääû
*/
