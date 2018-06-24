/*
 Reinier César Mujica
 xx/08/2008
 "Intervals"
 Sweep Line
*/

#include <cstdio>
#include <algorithm>

using namespace std;

#define FOR( _i, _j, _k ) \
    for ( _i = (_j); _i <= (_k); _i++ )

const int
    MAXN = 50002;
    
struct SWP {
    int start;
    bool flag;
	
	bool operator < ( const SWP &a ) const {
		 if ( start != a.start ) return start < a.start;
		 if ( !flag && a.flag ) return true;
		 return false;
	}
} ls[2 * MAXN];

int N, M;
int i, j, k;
int start;

int main() {

    freopen( "PRZ.in", "r", stdin );
    freopen( "PRZ.out", "w", stdout );

	scanf( "%d", &N );
	FOR( i, 1, N ) {
		scanf( "%d %d", &j, &k );
		ls[++M].start = j;
		ls[M].flag = false;
		ls[++M].start = k;
		ls[M].flag = true;
	}
	
	sort( ls + 1, ls + M + 1 );
	
	start = ls[1].start; k = 1;
	FOR( i, 2, M ) {
		if ( !ls[i].flag && !k ) {
			k++; start = ls[i].start;
		}
		else {
			if ( ls[i].flag && !(k - 1 ) ) {
				printf( "%d %d\n", start, ls[i].start );
				k--;
			}
 		    else k += ( ls[i].flag ) ? -1 : 1;
		}
	}
	
    fflush( stdout );
    return 0;
}
