/*
 ID: reywork2
 PROG: milk3
 LANG:C++
*/

/*
 Reinier Mujica Hdez
 26 - 9 - 08
 USACO Training "Mother Milk"
*/

#include <cstdio>

using namespace std;

const int
	MAXN = 21;
	
struct state {
	int c[4];
	state( int x = 0, int y = 0, int z = 0 ) {
		c[1] = x; c[2] = y; c[3] = z;
	}
};

int cmax[4];
int i, j;
bool mk[MAXN][MAXN][MAXN];
bool cap[MAXN];

state poor( state t, int i, int j ) {
	  
	  if ( t.c[i] + t.c[j] >= cmax[j] ) {
		t.c[i] -= ( cmax[j] - t.c[j] );
    	t.c[j] = cmax[j];
	  }
	  else {
		t.c[j] += t.c[i];
		t.c[i] = 0;
	  }
	  
	  return t;
}

void dfs( state s ) {
	 if ( mk[s.c[1]][s.c[2]][s.c[3]] ) return ;
 
	 if ( s.c[1] == 0 ) cap[s.c[3]] = true;
	 
	 mk[s.c[1]][s.c[2]][s.c[3]] = true;
	 for ( int i = 1; i <= 3; i++ )
	  for ( int j = 1; j <= 3; j++ )
       if ( i != j ) dfs( poor( s, i, j ) );
}

int main() {
	
	freopen( "milk3.in", "r", stdin );
	freopen( "milk3.out", "w", stdout );
	
	scanf( "%d %d %d", &cmax[1], &cmax[2], &cmax[3] );
	
	dfs( state( 0, 0, cmax[3] ) );
	for ( i = 0; i <= cmax[3]; i++ )
	 if ( cap[i] ) printf( "%d ", i );
	printf( "\n" );

	fflush( stdout );
	return 0;
}
