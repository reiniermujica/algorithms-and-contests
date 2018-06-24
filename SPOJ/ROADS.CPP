/*
 Reinier César Mujica
 4/5/08
 SPOJ #338 Roads
*/

#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int
    MAXN = 101,
    MAXK = 10001,
    oo   = 1 << 29;

struct city {
    int id, l, c;
};

struct line {
    int i, j;
};

int N, M, money, sol, i, j, k, cases, t;
int best[MAXN][MAXK];

struct cmp {
    bool operator () ( const line &a, const line &b ) {
         return best[a.i][a.j] > best[b.i][b.j];
    }
};

priority_queue < line, vector < line > , cmp > Q;

int main() {

    int a, b, c, d;

    scanf( "%d", &cases );

    for ( t = 1; t <= cases; t++ ) {

     scanf( "%d", &money );
     scanf( "%d", &N );
     scanf( "%d", &M );

     vector < city > G[MAXN];
     
     for ( i = 0; i < M; i++ ) {
        scanf( "%d%d%d%d", &a, &b, &c, &d );
        G[a].push_back( (city) { b, c, d } );
     }
     
     for ( i = 0; i <= N; i++ )
      fill( best[i], best[i] + MAXK, oo );

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
    }

    fflush( stdout );
    return 0;
}
