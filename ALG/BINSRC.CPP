/*
 Reinier Cesar Mujica
 update xx/08/2008
*/

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int N, Q;
int i, j, k;

vector< int > L;

int main() {

    scanf( "%d", &N );
    for ( i = 0; i < N; i++ ) {
        scanf( "%d", &j );
        L.push_back( j );
    }

    sort( L.begin(), L.end() );
    
    scanf( "%d", &Q );
    while ( Q-- ) {
		scanf( "%d", &k );
		
		vector< int >::iterator pos;
		pos = lower_bound( L.begin(), L.end(), k );
		
		if ( pos != L.end() && ( *pos ) == k  )
			printf( "%d\n", ( pos - L.begin() + 1 ) );
		else
			printf( "NO\n" );
    }

    fflush( stdout );
    return 0;
}
