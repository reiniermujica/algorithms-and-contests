/*
 Reinier César Mujica
 2 - 10 - 2008
 "Tablero"
*/

#include <cstdio>
#include <set>

using namespace std;

const int
	MAXN = 10;
	
int N, L, sol;
int i, j;
int val[MAXN][MAXN];
set < int > S;


void dfs( int x, int y, int num, int cont ) {
     if ( val[x][y] == -1 ) return ;
     num = ( num * 10 ) + val[x][y];
     if ( cont == 6 ) {
        if ( S.find( num ) == S.end() ) {
            S.insert( num );
            sol++;
        }
        return ;
     }
     dfs( x - 1, y, num, cont + 1 );
     dfs( x, y - 1, num, cont + 1 );
     dfs( x + 1, y, num, cont + 1 );
     dfs( x, y + 1, num, cont + 1 );
}

int main() {
	
	freopen( "NUMGRID.IN", "r", stdin );
	freopen( "NUMGRID.OUT", "w", stdout );

    for ( i = 0; i < MAXN; i++ )
     fill( val[i], val[i] + MAXN, -1 );
     
    for ( i = 1; i <= 5; i++ )
	 for ( j = 1; j <= 5; j++ )
      scanf( "%d", &val[i][j] );
    
    for ( i = 1; i <= 5; i++ )
	 for ( j = 1; j <= 5; j++ )
      dfs( i, j, 0, 1 );

    printf( "%d\n", sol );
	return 0;
}
