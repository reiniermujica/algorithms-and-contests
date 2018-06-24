/*
 Reinier César Mujica
 
*/

#include <cstdio>
#include <algorithm>

using namespace std;

typedef pair < int, int > par;

const int
	MAXN = 50010;

int N, sol;
int i, j, k;
int last[MAXN * 2];	
par T[MAXN];

int main() {

    freopen( "BALANCE.in", "r", stdin );
    freopen( "BALANCE.out", "w", stdout );
    
	scanf( "%d", &N );
	for ( i = 1; i <= N; i++ )
		scanf( "%d %d", &T[i].second, &T[i].first );
	
	sort( T + 1, T + N + 1 );
	
	for ( i = 1; i <= N; i++ ) {

        if ( last[N + k] == 0 ) {
			last[N + k] = T[i].first;
		}
		k += ( T[i].second ) ? 1 : -1;
		if ( last[N + k] )
		sol >?= T[i].first - last[N + k];
	}
	
	printf( "%d\n", sol );
	return 0;
}
