/*
 Reinier César Mujica
 01/09/2008
 "Matrix Summation"
 ABI 2D
*/

#include <cstdio>
#include <algorithm>

using namespace std;

const int
    MAXN = 1030;
	
struct abi {
	int size, i, j;
	int tree[MAXN][MAXN];
	
	void init( int L ) {
		memset( tree, 0, sizeof tree );
		size = L;
	}
	
	int low_bit( int x ) {
		return x & -x;
	}
	
	void update( int x, int y, int value ) {
		for ( i = x; i <= size; i += low_bit( i ) )
		 for ( j = y; j <= size; j += low_bit( j ) )
		  tree[i][j] += value;
	}
	
	int query( int x, int y ) {
		int res = 0;
		for ( i = x; i; i -= low_bit( i ) )
		 for ( j = y; j; j -= low_bit( j ) )
		  res += tree[i][j];
		return res;
	}
} T;

int N, Q;
int i, j;
int x, y, val;

int main() {

	scanf( "%d", &Q );
	while ( Q-- ) {
		scanf( "%d\n", &N );
		T.init( N + 1 );
		
		char res[21];
		for ( ;; ) {
			scanf( "%s", &res );
			if ( strstr( res, "END" ) ) break;
			
			if ( strstr( res, "SUM" )  ) {
				scanf( "%d %d %d %d\n", &i, &j, &x, &y );
				i++; j++; x++; y++;
				
				printf( "%d\n", T.query( x, y ) - T.query( i - 1, y ) -
						T.query( x, j - 1 ) + T.query( i - 1, j - 1 ) );
			}
			else {       
				scanf( "%d %d %d\n", &x, &y, &val );
				x++; y++;
				
				j = T.query( x, y ) - T.query( x - 1, y ) -
					T.query( x, y - 1 ) + T.query( x - 1, y - 1 );
            	T.update( x, y, val - j );
			}
		}
	}

    fflush( stdout );
    return 0;
}
