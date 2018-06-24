/*
 Reinier Cesar Mujica
 xx/08/2008
 IBERO 2008 problem 1
 DFS
*/

#include <cstdio>
#include <algorithm>

using namespace std;

const int
    MAXN = 5002;

struct segment {
    int x1, y1, x2, y2, l;
    bool H, V;
} T[MAXN];

int N, sol;
int i, j, k;
bool mark[MAXN];

bool contact( int x, int y ) {
     if ( T[x].H && T[y].H ) {
      if ( T[x].y1 != T[y].y1 ) return 0;
      if ( T[x].x1 == T[y].x2 ) return 1;
      if ( T[y].x1 == T[x].x2 ) return 1;
      return 0;
     }
     if ( T[x].V && T[y].V ) {
      if ( T[x].x1 != T[y].x1 ) return 0;
      if ( T[x].y2 == T[y].y1 ) return 1;
      if ( T[y].y2 == T[x].y1 ) return 1;
      return 0;
     }
  	 if ( T[x].V && T[y].H ) swap( x, y );
     if ( T[x].x1 == T[y].x1 || T[x].x2 == T[y].x1 ) {
		if ( T[y].y1 <= T[x].y1 && T[x].y1 <= T[y].y2 ) return 1;
		return 0;
	 }
     if ( (T[x].y1 == T[y].y1) || (T[x].y1 == T[y].y2 )) {
		if ( T[y].x1 >= T[x].x1 && T[y].x1 <= T[x].x2 ) return 1;
		return 0;
	 }
     return 0;
}

void dfs( int x ) {
     mark[x] = true; k += T[x].l;
     for ( int i = 1; i <= N; i++ )
      if ( !mark[i] && contact( x, i ) )
        dfs( i );
}

int main() {

    freopen( "SEGMENTOS.ENT", "r", stdin );
    freopen( "SEGMENTOS.SAL", "w", stdout );
    
    scanf( "%d", &N );    
    for ( i = 1; i <= N; i++ ) {
      scanf( "%d %d %d %d", &T[i].x1, &T[i].y1, &T[i].x2, &T[i].y2 );
      T[i].l = max( abs( T[i].x1 - T[i].x2 ), abs( T[i].y1 - T[i].y2 ) );
      if ( !abs( T[i].x1 - T[i].x2 ) ) {
        T[i].V = true;
        if ( T[i].y2 < T[i].y1 )
         swap( T[i].y2, T[i].y1 );
      }
      else {
        T[i].H = true;
        if ( T[i].x2 < T[i].x1 )
         swap( T[i].x2, T[i].x1 );
      }
    }
    
    for ( i = 1; i <= N; i++ )
     if ( !mark[i] ) {
        k = 0;
        dfs( i );
        sol >?= k;
     }
    
    printf( "%d\n", sol );
    
    fflush( stdout );
    return 0;
}
