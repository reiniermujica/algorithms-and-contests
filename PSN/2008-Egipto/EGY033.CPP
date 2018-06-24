/*
 Reinier César Mujica
 27/3/08 PSN - 2008
*/

#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int
    mx = 1010;
    
typedef pair<int,int> par;

int n,m,k,cant[mx],z;
vector<par> G[mx];
priority_queue < par,vector<par>,greater<par> > Q;

int main(){
    int i,x,y,c;
    freopen("cowjog.in","r",stdin);
    freopen("cowjog.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for (i=1; i<=m; i++){
        scanf("%d%d%d",&x,&y,&c);
        G[x].push_back(make_pair(c,y));   
    }    
    Q.push(make_pair(0,n));
    while (!Q.empty()){
      int cost = Q.top().first;
      int node = Q.top().second;
      Q.pop();
      cant[node]++;
      if (node == 1){
         printf("%d\n",cost);
         z++;
         if (z == k) break;      
      }
      for (i=0; i<G[node].size(); i++){
        int next = G[node][i].second;
        int ncos = G[node][i].first;
        if (cant[next] >= k) continue;
        Q.push(make_pair(cost+ncos,next));      
      }  
    }
    for (i=z+1; i<=k; i++) printf("-1\n");
    fflush(stdout);
    return 0;    
}

/*33¦ Trote Vacuno [Alex Schwender y Eric Price, 2006]        Egipto 2008
 ----------------------------------------------------------------------

Bessie ha decidido sacudirse la pereza y ha decidido mejorar su  forma
trotando desde la  granja hasta la  alberca varias veces  a la semana.
Por supuesto,  ella no  quiere trabajar  muy duro,  por lo  tanto ella
planea trotar bajando hacia la alberca y luego regresar tranquilamente
al establo.

Bessie tampoco quiere correr muy lejos, por lo tanto ella generalmente
toma la  secuencia mßs  corta de  caminos de  vacas para  llegar a  la
alberca. Cada uno de los M (1 <= M <= 10,000) caminos de vacas conecta
dos pastizales convenientemente numerados 1..N  (1 <= N <= 1000).  A·n
mßs convenientemente, los pastizales estßn numerados de tal manera que
si X>Y entonces el camino del pastizal X al pastizal Y es bajando.  El
pastizal N es el establo (en la cima de la monta±a) y el pastizal 1 es
la alberca (en la base).

Justamente  despuTs de  una semana  de comenzar  a trotar,  Bessie  ha
comenzado a cansarse de tomar siempre  la misma ruta para llegar a  la
alberca. A ella le gustarfa variar su ruta tomando caminos  diferentes
en dfas diferentes. Especfficamente Bessie quisiera tomar  exactamente
K (1 <=  K <= 100)  rutas diferentes por  variedad. Para evitar  mucho
ejercicio, ella quiere que estas sean  la K rutas mßs cortas desde  el
establo a la  alberca. Se consideran  que dos rutas  son diferentes si
consisten de secuencias diferentes de caminos.

Ayude  a  Bessie  a   determinar  cuan  extenuante  serß   su  trabajo
determinando las longitudes de cada una  de las K rutas mßs cortas  en
la red  de pastizales.  A usted  se le  darß una  lista de  caminos de
bajada de X_i a Y_i junto con la longitud de los caminos: (X_i; Y_i  <
X_i  <= N).  El camino  de vaca  i tiene  longitud D_i  (1 <=  D_i <=
1,000,000).

NOMBRE DEL PROBLEMA: cowjog

FORMATO DE ENTRADA:

* Lfnea 1: Tres enteros separados por espacio: N, M y K.

* Lfneas 2..N: La lfnea i+1 describe un camino de bajada usando tres enteros 
     separados por espacios: X_i, Y_i y D_i


ENTRADA EJEMPLO (archivo cowjog.in):

5 8 7
5 4 1
5 3 1
5 2 1
5 1 1
4 3 4
3 1 1
3 2 1
2 1 1


FORMATO DE SALIDA:

* Lfneas 1..K: La lfnea i contiene la longitud de la ruta i-Tsima  mßs
corta o -1 si no existe tal ruta. Si la longitud de una ruta mßs corta
ocurre varias veces,  estT seguro de  incluir esas varias  veces en la
salida.


  

SALIDA EJEMPLO (archivo cowjog.out):

1
2
2
3
6
7
-1

DETALLES DE LA SALIDA:

Las rutas son (5-1), (5-3-1), (5-2-1), (5-3-2-1), (5-4-3-1),(5-4-3-2-1)
*/
