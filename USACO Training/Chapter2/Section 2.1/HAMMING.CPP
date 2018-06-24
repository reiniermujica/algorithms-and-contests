/*
 ID: reywork2
 PROG: hamming
 LANG: C++
*/

#include <cstdio>
#include <deque>

using namespace std;

const int
	MAXN = 260;
	
int N, B, D;
int i, j, k, limit;
deque < int > S;

int dist( int x, int y ) {
    int i, j, k = 0;
   	for ( int j = 0; j < B; j++ ) {
		int one = ( x & ( 1 << j ) );
		int two = ( y & ( 1 << j ) );
		k += ( one != two );
	}
    return k;
}

void dfs( int x ) {
	 if ( S.size() == N ) {
		for ( int i = 1; i <= S.size(); i++ )
			if ( i % 10 && i != S.size() ) printf( "%d ", S[i - 1] );
			else printf( "%d\n", S[i - 1] );
		exit( 0 );
	 }

	 for ( int i = x + 1; i <= limit; i++ ) {
            bool ok = true;
            for ( int j = 0; j < S.size(); j++ )
                if ( dist( i, S[j] ) < D ) {
                    ok = false;
                    break;
                }
    		if ( ok ) {
                S.push_back( i );
	   		    dfs( i );
   	    	    S.pop_back();
		    }
	 }

}

int main() {

	freopen( "hamming.in", "r", stdin );
	freopen( "hamming.out", "w", stdout );
	
	scanf( "%d %d %d", &N, &B, &D );
	
	limit = ( 1 << B ) - 1;
	S.push_back( 0 );
	dfs( 0 );

	fflush( stdout );
	return 0;
}
