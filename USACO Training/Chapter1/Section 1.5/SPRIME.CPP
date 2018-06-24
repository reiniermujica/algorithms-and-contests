/*
 ID: reywork2
 PROG: sprime
 LANG: C++
*/

#include <cstdio>
#include <cmath>

using namespace std;

int N, i;

bool isprime( int x ) {
	 int rx = (int)sqrt( x );
	 for ( int i = 2; i <= rx; i++ )
	  if ( x % i == 0 ) return false;
	 return true;
}

void dfs( int numb, int len ) {
	 if ( len == N ) {
		printf( "%d\n", numb );
		return ;
	 }
	 
	 for ( int i = 0; i <= 9; i++ ) {
		int next = numb * 10 + i;
		if ( isprime( next ) )
		 dfs( next, len + 1 );
	 }
}

int main() {
	
	freopen( "sprime.in", "r", stdin );
	freopen( "sprime.out", "w", stdout );
	
	scanf( "%d", &N );
	for ( i = 2; i <= 7; i++ )
	 if ( isprime( i ) ) dfs( i, 1 );
	
	return 0;
}
