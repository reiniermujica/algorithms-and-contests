/*
 ID: reywork2
 PROG: pprime
 LANG: C++
*/

#include <cstdio>
#include <cmath>

using namespace std;

const int
	MAXN = 15;
	
int A, B, sA, sB;
int i;
int num[MAXN];

bool prime( int x ) {
	 if ( x % 2 == 0 ) return false;
	 for ( int i = 3; i * i <= x; i += 2 )
		if ( x % i == 0 ) return false;
	 return true;
}

void check( int len ) {
	 int res = 0;
	 for ( int i = 1; i <= len; i++ )
		res = ( res * 10 ) + num[i];
	 if ( res >= A && res <= B && prime( res ) )
		printf( "%d\n", res );
}

void comb( int lo, int hi ) {

  	 if ( lo > hi ) {
        check( i );
        return ;
     }

	 for ( int i = 0; i <= 9; i++ ) {
		num[lo] = num[hi] = i;
		comb( lo + 1, hi - 1 );
	 }
	 
	 num[lo] = num[hi] = 0;
}

int main() {

	freopen( "pprime.in", "r", stdin );
	freopen( "pprime.out", "w", stdout );
	
	scanf( "%d %d", &A, &B );
	
	sA = (int)log10( A ) + 1;
	sB = (int)log10( B ) + 1;
	
	for ( i = sA; i <= sB; i++ )
   	    comb( 1, i );
	
	fflush( stdout );
	return 0;
}
