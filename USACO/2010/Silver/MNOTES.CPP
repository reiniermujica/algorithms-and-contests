/*
 Reinier César Mujica
 17 - 12 - 2009
 Binary Search
*/

#include <cstdio>
#include <algorithm>

using namespace std;

const int
	MAXN = 50010;
	
int N, Q;
int i, x, carry;
int T[MAXN];

int main() {
	
	freopen( "MNOTES.in", "r", stdin );
	freopen( "MNOTES.out", "w", stdout );
	
	scanf( "%d %d", &N, &Q );
	for ( i = 0; i < N; i++ ) {
		scanf( "%d", &x );
		T[i] = carry;
		carry += x;
	}
	
	/* Answering Queries */
	while ( Q-- ) {
		scanf( "%d", &x );
		carry = upper_bound( T, T + N, x ) - T;
		printf( "%d\n", carry );
	}
	
	return 0;
}
