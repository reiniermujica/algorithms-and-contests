/*
 Reinier César Mujica
 xx/xx/2008
 "Skiers"
*/

#include <cstdio>
#include <algorithm>

using namespace std;

#define FOR( _i, _j, _k ) \
    for ( _i = (_j); _i <= (_k); _i++ )

const int
    MAXV = 5052;

int N, M, sol;
int i, j, k;
int src, snk;
int cap[MAXV][MAXV];
int cant[MAXV];
bool mark[MAXV];

bool augment( int x ) {
	 if ( x == N ) return true;

	 mark[x] = true;
	 for ( int i = 1; i <= cant[x]; i++ ) {
        int next = cap[x][i];
		if ( next && !mark[next] && augment( next ) )
		 return true;
	 }
	
	 return false;
}

int main() {

    freopen( "NAR.in", "r", stdin );
    freopen( "NAR.out", "w", stdout );

	scanf( "%d\n", &N );
    FOR( i, 1, N - 1 ) {
		scanf( "%d", &cant[i] );
        FOR( j, 1, cant[i] ) {
			scanf( "%d", &k );
            cap[i][j] = k;
            if ( i == 1 && k == N ) {
             cap[i][j] = 0;
             sol++;
            }
		}
	}

	src = 1; snk = N;
    while( augment( src ) ) sol++;
    
	printf( "%d\n", sol );

    fflush( stdout );
    return 0;
}
