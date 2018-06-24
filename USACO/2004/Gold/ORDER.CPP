/*
 Reinier Cesar Mujica
 10/06/2008
 "Ordering Cows"
 O(E^2)
*/

#include <cstdio>
#include <algorithm>

using namespace std;

#define REP( i, j, k ) \
    for ( i = (j); i <= (k); i++ )

const int
    MAXV = 1501,
    MAXE = 10001;

struct edge {
    int u, w, next;
    bool mark;
};

int N, M, sol;
int i, j, x, y;
int last[MAXV];
edge E[MAXE], S[MAXE];
bool mk[MAXV];

void dfs( int v ) {
     mk[v] = true;
     int link = last[v];
     while ( link ) {
        int next = E[link].w;
        if ( !mk[next] )
         dfs( next );
        link = E[link].next;
     }
}

bool cmp( const edge &a, const edge &b ) {
     if ( a.u != b.u ) return a.u < b.u;
     return a.w < b.w;
}

int main() {

    freopen( "order.in", "r", stdin );
    freopen( "order.out", "w", stdout );
    
    scanf( "%d %d", &N, &M );

    REP( i, 1, M ) {
      scanf( "%d %d", &x, &y );
      E[i].u = x;
      E[i].w = y;
      E[i].next = last[x];
      E[i].mark = false;
      last[x] = i;
    }
    
    REP( i, 1, M ) {
      x = E[i].u; y = E[i].w; //save
      E[i].u = E[i].w = 0;
      fill( mk, mk + MAXV, false );
      dfs( x );
      if ( mk[y] ) E[i].mark = true;
      if ( !E[i].mark ) {
       E[i].u = x; E[i].w = y; //restore
       S[++sol] = E[i];
      }
    }
    
    sort( S + 1, S + sol + 1, cmp );
    
    printf( "%d\n", sol );
    REP( i, 1, sol ) {
       printf( "%d %d\n", S[i].u, S[i].w );
    }
    
    fflush( stdout );
    return 0;
}
