/*
 Reinier César Mujica
 13 - 10 - 2008
*/

#include <cstdio>
#include <algorithm>

using namespace std;

const int
	MAXN = 10010;
	
typedef pair < int, int > par;

int N, L, sol;
int i, j, k, carry;
par T[MAXN];

int main() {

	freopen( "mud.in", "r", stdin );
	freopen( "mud.out", "w", stdout );
	
	scanf( "%d %d", &N, &L );
	for ( i = 1; i <= N; i++ )
	 scanf( "%d %d", &T[i].first, &T[i].second );
	 
    carry = 0;
	sort( T + 1, T + N + 1 );
	for ( i = 1; i <= N; i++ ) {
		if ( carry >= T[i].second )	continue;
        T[i].first >?= carry;
		k = T[i].second - T[i].first;
        sol += k / L + ( ( k % L ) > 0 );
        if ( k % L )
         carry = T[i].first + ( L * ( k / L + 1) );
        else
         carry = T[i].second - 1;
    }

	printf( "%d\n", sol );
	return 0;
}
