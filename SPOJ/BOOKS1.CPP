/*
 Reinier César Mujica
 17 - 11 - 2008
 simple Binary Search
*/

#include <cstdio>
#include <vector>

using namespace std;

const int
	MAXN = 505;

int Q, N, K, M, sol;
int i, j;
int lo, hi, mid;
int T[MAXN];
	
bool isok( int x ) {
	 int i, k = 1, sum = 0;
	 for ( i = 1; i <= N; i++ ) {
        if ( T[i] > x ) return false;
		if ( T[i] + sum > x ) {
			sum = T[i];
			k++;
			if ( k > K ) return false;
		}
		else
		 sum += T[i];
	 }
	 return ( k <= K );
}

int main() {

	scanf( "%d", &Q );
	while ( Q-- ) {

		/* read */
		scanf( "%d %d", &N, &K );
		for ( i = 1; i <= N; i++ ) {
			scanf( "%d", &T[i] );
			M = ( i == 1 ) ? T[i] : ( M + T[i] );
		}
	
		/* binary search */
		lo = 1; hi = M; sol = 1 << 30;
		while ( lo <= hi ) {
			mid = ( lo + hi + 1 ) >> 1;
			if ( isok( mid ) ) { sol <?= mid; hi = mid - 1;}
			else lo = mid + 1;
		}
		
		vector < int > S; M = 0; j = 1;
        for ( i = N; i > 0; i-- ) {
            if ( M + T[i] > sol || N - ( N - i + 1 ) < K - j ) {
                M = T[i];
                S.push_back( -1 );
                j++;
            }
            else
				M += T[i];
            S.push_back( T[i] );
        }
        
        for ( i = S.size() - 1; i >= 0; i-- ) {
            if ( S[i] == -1 ) printf( "/ " );
            else printf( "%d ", S[i] );
        }
        printf( "\n" );
    }
	
	fflush( stdout );
	return 0;
}
