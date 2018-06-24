/*
 Reinier César Mujica
 7 - 1 - 2009
 No es la mas optima pero no la mas mala
 solo unas milecimas de segundos...
*/

#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

const int
	MAXN = 12,
	MAXM = ( 1 << MAXN ) + 1;
	
int N, M;
int i, j, k;
int sol[MAXM];
bool mark[MAXM], used[MAXM];
queue < int > Q;
vector < int > G[MAXM];

int main() {

	freopen( "HYPER.IN", "r", stdin );
	freopen( "HYPER.OUT", "w", stdout );
	
	scanf( "%d", &N ); M = 1 << N;
	for ( i = 1; i <= M; i++ ) {
		for ( j = 1; j <= N; j++ ) {
			scanf( "%d", &k );
			G[i].push_back( k );
		}
	}

    memset( sol, -1, sizeof sol );
	mark[1] = true;
	
	for ( Q.push( 1 ); !Q.empty(); Q.pop() ) {
		int node = Q.front();
		
		for ( i = 0; i < M; i++ ) { // chain of bits
			if ( used[i] ) continue;

			bool ok = true;
			for ( j = 0; j < G[node].size(); j++ ) {
				int next = G[node][j];
				if ( !mark[next] ) {
					mark[next] = true;
					Q.push( next );
				}
				else {
                    if ( sol[next] == -1 ) continue;
					if ( __builtin_popcount( i ^ sol[next] ) != 1 ) {
						ok = false;
						break;
					}
				}
			}
			if ( ok ) { // this match
				sol[node] = i;
				used[i] = true;
				break;
			}
		}
	}
	
	for ( i = 1; i <= M; i++ ) {
		for ( j = 0; j < N; j++ )
			if ( sol[i] & ( 1 << j ) ) printf( "1" );
			else printf( "0" );
		printf( "\n" );
	}
	
	fflush( stdout );
	return 0;
}
