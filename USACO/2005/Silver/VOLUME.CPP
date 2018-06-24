/*
 Reinier César Mujica
 24 - 11 - 2008
*/

#include <iostream>
#include <algorithm>

using namespace std;

typedef long long int64;

const int
	MAXN = 10005;

int64 N, i;
int64 sol, S[MAXN];
int64 T[MAXN];

int main() {

	freopen( "VOLUME.IN", "r", stdin );
	freopen( "VOLUME.OUT", "w", stdout );
	
	scanf( "%d", &N );
	for ( i = 1; i <= N; i++ )
	 scanf( "%d", &T[i] );
	 
	sort( T + 1, T + N + 1);
	for ( i = 2; i <= N; i++ ) {
        S[i] = int64(( T[i] - T[i - 1] ) * ( i - 1 )) + S[i - 1];
		sol += S[i];
	}
	
    cout << sol * 2 << endl;
	return 0;
}
