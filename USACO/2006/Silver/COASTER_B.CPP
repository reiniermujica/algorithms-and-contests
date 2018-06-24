/*
 Reinier César Mujica
 xx/08/2008
 "Coaster"
 Dynamic Programing
 O(~(N * M))
*/

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define FOR( _i, _j, _k ) \
    for ( _i = (_j); _i <= (_k); _i++ )

const int
    MAXN = 1002;

struct event {
	int start, end, fun, cost, next;
	event ( int _x = 0, int _y = 0, int _c = 0, int _d = 0, int _e = 0 ) {
		start = _x; end = _y; fun = _c; cost = _d; next = _e;
	}
};

int N, M, cant, sol;
int i, j, k;
int cost, funny, next;
int last[MAXN];
int dp[MAXN][MAXN]; //max funny at node i whit cost j

vector < event > ls;


int main() {

    freopen( "coaster.in", "r", stdin );
    freopen( "coaster.out", "w", stdout );

    scanf( "%d %d %d", &N, &M, &cant );
    FOR( i, 0, M - 1 ) {
		scanf( "%d %d %d %d", &j, &k, &funny, &cost );
		ls.push_back( event( j, k + j, funny, cost, last[j] ) );
		last[j] = i;
    }

	dp[0][0] = 1;
	FOR( i, 0, N ) {
		FOR( j, 0, cant ) 
			if ( dp[i][j] != 0 ) {
				for ( k = last[i]; k; k = ls[k].next ) {
					next = ls[k].end;
					funny = ls[k].fun + dp[i][j];
					cost = ls[k].cost + j;
					if ( dp[next][cost] < funny )
					 dp[next][cost] = funny;
				}
			}
	}

	FOR( i, 0, cant )
	 sol >?= ( dp[N][i] ) ? dp[N][i] : 0;
	 
	printf( "%d\n", ( sol ) ? sol - 1 : -1 );
	
    fflush( stdout );
    return 0;
}
