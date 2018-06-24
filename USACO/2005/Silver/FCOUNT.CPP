/*
 Reinier César Mujica
 15 - 10 - 2008
*/

#include <cstdio>

using namespace std;

const int
	MAXN = 2050;
	
int N, F1, F2, D, sol;
int x, y;
int ini[MAXN], fin[MAXN];
int abi[MAXN];
int i, j, k;

int low_bit( int x ) {
	return x & -x;
}

int update( int x, int amount ) {
	for ( int i = x; i <= D; i += low_bit( i ) )
		abi[i] += amount;
}

int query( int x ) {
	int res = 0;
	for ( int i = x; i; i -= low_bit( i ) )
		res += abi[i];
	return res;
}

int main() {

    freopen( "fcount.in", "r", stdin );
    freopen( "fcount.out", "w", stdout );
    
    scanf( "%d %d %d %d\n", &N, &F1, &F2, &D );
	for ( i = 1; i <= N; i++ ) {
	 scanf( "%d %d", &x, &y );
	 ini[x]++; fin[y]++;
	}
	 
	/* pre calc */
	for ( i = 1; i <= D; i++ ) {
		k += ini[i];
		update( i, k );
		k -= fin[i];
	}
	
	/* calc */
	for ( i = D; i > 0; i-- ) {
		k = query( D ) - query( i - 1 );
		if ( F1 - k == F2 ) {
			sol = i;
			break;
		}
	}

	printf( "%d\n", sol );
	return 0;
}
