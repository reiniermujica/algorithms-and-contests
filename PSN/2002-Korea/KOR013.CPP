/*
 Reinier César Mujica
 29 - 12 - 2008
 like Writing( IOI2006 )
*/

#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

const int
	MAXN = 100100,
	MAXC = 90;
	
typedef pair < int, int > par;

int N, best;
int i, j, k;
int len[MAXN], cant[256];
char cad[MAXN][MAXC];
par sol, last;
queue < par > Q;

int main() {

	freopen( "cadena.in", "r", stdin );
	freopen( "cadena.out", "w", stdout );
	
	scanf( "%d\n", &N );
	for ( i = 1; i <= N; i++ ) {
		gets( cad[i] + 1 );
		len[i] = strlen( cad[i] + 1 );
	}

	for ( i = 1; i <= N; i++ ) {
		for ( j = 1; j <= len[i]; j++ ) {
			char c = cad[i][j];
			while ( cant[c] > 0 ) {
				par top = Q.front();
				Q.pop();
				cant[cad[top.first][top.second]]--;
			}
			Q.push( par( i, j ) );
			cant[c]++;
			if ( Q.size() > best ) {
				best = Q.size();
				sol = Q.front();
				last = par( i, j );
			}
		}
	}

	printf( "%d %d\n", best, sol.first );
	for ( i = sol.first; i <= last.first ; i++ ) {
		if ( i == sol.first ) j = sol.second;
		else j = 1;
		if ( i == last.first ) k = last.second;
		else k = len[i];
		for ( ; j <= k; j++ )
			printf( "%c", cad[i][j] );
	}

	printf( "\n" );
	fflush( stdout );
	return 0;
}
