/*
 Reinier César Mujica
 11 - 3 - 2009
*/

#include <cstdio>
#include <algorithm>

using namespace std;

const int
	MAXN = 50100;
	
int Q, N, M, D, L, sol;
int i, j, k;
int T[MAXN];

int main() {

	scanf( "%d %d %d %d", &N, &M, &D, &L );
	for ( i = 1; i <= N; i++ )
		scanf( "%d", &T[i] );
		
	sort( T + 1, T + N + 1 );
	for ( i = 1; i <= N; i++ ) {
		if ( T[i] - D * ( sol / M ) >= L )
			sol++;
	}
	
	printf( "%d\n", sol );
	
	fflush( stdout );
	return 0;
}
