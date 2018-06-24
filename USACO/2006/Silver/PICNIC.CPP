/*
 Reinier César Mujica
 xx/08/2008
 "Picnic"
*/

#include <cstdio>
#include <vector>

using namespace std;

#define FOR( _i, _j, _k ) \
    for ( _i = (_j); _i <= (_k); _i++ )

const int
    MAXK = 105,
    MAXN = 1005;

int N, M, K, sol;
int i, j, k;
int T[MAXK];
bool can[MAXK][MAXN], ok;
vector < int > G[MAXN];

void dfs( int x, int cow ) {
	 can[cow][x] = true;
	 for ( int i = 0; i < G[x].size(); i++ ) {
		int next = G[x][i];
		if ( !can[cow][next] ) dfs( next, cow );
	}
}

int main() {

    freopen( "picnic.in", "r", stdin );
    freopen( "picnic.out", "w", stdout );
    
    scanf( "%d %d %d", &K, &N, &M );
	FOR( i, 1, K )
		scanf( "%d", &T[i] );
		
    FOR( i, 1, M ) {
		scanf( "%d %d", &j, &k );
		G[j].push_back( k );
    }
	
	FOR( i, 1, K )
		dfs( T[i], i );

	FOR( i, 1, N ) {
		ok = true;
		FOR( j, 1, K ) {
			ok = ok && can[j][i];
			if ( !ok ) break;
		}
		sol += ok;
	}
	
	printf( "%d\n", sol );
	
    fflush( stdout );
    return 0;
}
