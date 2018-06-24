/*
 Reinier César Mujica
 15/4/08 PSN - 2008
*/

#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int
    MAXN = 101,
    MAXK = 1001,
    oo   = 1 << 29;
    
struct city {
    int id, l, c;
};

struct line {
    int i, j;
};

int N, M, money, sol, i, j, k;
int best[MAXN][MAXK];
vector < city > G[MAXN];

struct cmp {
    bool operator () ( const line &a, const line &b ) {
         return best[a.i][a.j] > best[b.i][b.j];
    }
};

priority_queue < line, vector < line > , cmp > Q;

int main() {
    int a, b, c, d;
    freopen( "caminos.in", "r", stdin );
    freopen( "caminos.out", "w", stdout );
    scanf( "%d", &money );
    scanf( "%d %d", &N, &M );
    for ( i = 0; i < M; i++ ) {
        scanf( "%d%d%d%d", &a, &b, &c, &d );
        G[a].push_back( (city) { b, c, d } );
    }
    for ( i = 0; i <= N; i++ ) {
        fill( best[i], best[i] + MAXK, oo );
    }

    /* Dinamic Shortest Path using Dijkstra Alg */
    best[1][money] = 0;
    Q.push( (line) { 1, money } );
    while ( !Q.empty() ) {
     int x = Q.top().i;
     int y = Q.top().j;
     Q.pop();
     for ( i = 0 ; i < G[x].size(); i++ ) {
        int next = G[x][i].id;
        int dist = G[x][i].l;
        int cost = G[x][i].c;
        int news = y - cost;
        if ( news >= 0 && best[next][news] > best[x][y] + dist ) {
          best[next][news] = best[x][y] + dist;
          Q.push( (line) { next, news } );
        }
     }
    }

    sol = oo;
    for ( i = 0; i <= money; i++ )
     sol <?= best[N][i];
    if ( sol == oo ) sol = -1;
    
    printf( "%d\n", sol );

    fflush( stdout );
    return 0;
}

/*76þ Caminos                                              Turqu¡a 1999
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

N ciudades nombradas con los n£meros de 1 ... N est n  conectadas  por
carreteras de un solo sentido. Cada  carretera  tiene  dos  par metros
asociados con esta: la  longitud  de  la  carretera  y el impuesto que
necesitas pagar por transitar por la carretera (expresado en el n£mero
de monedas).
Bob y Alice usan para vivir la ciudad 1. Despu‚s que  Bob observ¢  que
a Alice le gustaba hacer  trampas en el juego  de  cartas, rompi¢  con
ella y decidi¢ irse lejos a la ciudad N. El desea  hacer  esto  lo m s
r pido posible, pero est  corto de dinero.
Nosotros queremos ayudar a Bob a encontrar el camino m s corto  de  la
ciudad 1 hasta la ciudad N, tal que pueda realizarlo con el dinero que
tiene.

Archivo de Entrada

La primera l¡nea tiene un  entero k, 0 ó k ó 10000, m ximo  n£mero  de
monedas que Bob  puede gastar  en el camino. La segunda L¡nea contiene
el  entero N,  2 ó N ó 100,  el n£mero  total de ciudades. La  tercera
l¡nea  contiene  el  entero  R,  1 ó R ó 10000,  el  n£mero  total  de
carreteras.
Cada   una   de  las  siguientes  R  l¡neas  describe  una  carretera,
especificando  los enteros S, D, L, y T, separados  cada  uno  por  un
espacio en blanco.
- S es la ciudad origen, 1 ó S ó N.
- D es la ciudad destino, 1 ó D ó N.
- L es la longitud de la carretera, 1 ó L ó 100.
- T es el valor del impuesto. (expresado en n£mero de monedas).
  0 ó T ó 100.
Observe  que  diferentes  carreteras  pueden tener la misma ciudad  de
origen y destino.

Archivo de Salida

La   primera  l¡nea  del  archivo  de  salida  contendr   la  longitud
total del camino m s corto de  la ciudad 1 a la ciudad N cuyo impuesto
total es menor o igual que k monedas. Si semejente camino no  existe,
solo  aparecer   el  n£mero -1  en  el fichero de salida.

ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿ ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
³ Ejemplo # 1 de Entrada ³ ³ Ejemplo # 2 de Entrada ³
ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´ ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´
³ 5                      ³ ³ 0                      ³
³ 6                      ³ ³ 4                      ³
³ 7                      ³ ³ 4                      ³
³ 1 2 2 3                ³ ³ 1 4 5 2                ³
³ 2 4 3 3                ³ ³ 1 2 1 0                ³
³ 3 4 2 4                ³ ³ 2 3 1 1                ³
³ 1 3 4 1                ³ ³ 3 4 1 0                ³
³ 4 6 2 1                ³ ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
³ 3 5 2 0                ³ ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
³ 5 4 3 2                ³ ³ Ejemplo # 2 de Salida  ³
ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´
ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿ ³ -1                     ³
³ Ejemplo # 1 de Salida  ³ ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´
³ 11                     ³
ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
*/