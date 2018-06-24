/*
 Reinier César Mujica
 1 - 4 - 2009
*/

#include <cstdio>
#include <queue>

using namespace std;

const int
	MAXN = 100005;
	
int N, i;
int T[MAXN], C[MAXN];

priority_queue < int, vector< int >, greater< int > > S;

int main() {

	freopen( "LIST.in", "r", stdin );
	freopen( "LIST.out", "w", stdout );
	
	scanf( "%d", &N );
	for ( i = 1; i < N; i++ ) {
		scanf( "%d", &T[i] );
		C[T[i]]++;
	}
	
	for ( i = 1; i <= N; i++ )
		if ( !C[i] ) S.push( i );

	for ( i = 1; i < N; i++ ) {
		printf( "%d %d\n", S.top(), T[i] );
		C[T[i]]--;
		S.pop();
		if ( !C[T[i]] ) S.push( T[i] );
	}
	
	fflush( stdout );
	return 0;
}
