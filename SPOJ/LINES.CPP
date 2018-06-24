/*
 Reiner César Mujica 
 10 - 3 - 2009
*/

#include <cstdio>
#include <algorithm>

using namespace std;

const int
	MAXN = 210;

typedef pair < int, int > par;

int N, cant, sol;
int i, j;
bool v, h;
int d1, d2;
par T[MAXN];
double lines[MAXN * MAXN];

int main() {
	
	 scanf( "%d", &N );
     while ( N != 0 ) {

		/* filling */
		v = h = false;
		cant = sol = 0;
        

		/* reading */
 	    for ( i = 1; i <= N; i++ )
			scanf( "%d %d", &T[i].first, &T[i].second );
	 
		/* solving */
		for ( i = 1; i <= N; i++ )
			for ( j = i + 1; j <= N; j++ ) {
				d1 = ( T[i].second - T[j].second );
				d2 = ( T[i].first - T[j].first );
				if ( d1 == 0 ) {
					if ( !h ) {
						h = true;
						sol++;
					}
				}
				else
				if ( d2 == 0 ) {
					if ( !v ) {
						v = true;
						sol++;
					}
				}
				else {
					lines[++cant] = (double) d1 / d2;
                }
		}

        sort( lines + 1, lines + cant + 1 ); sol++;
        for ( i = 2; i <= cant; i++ )
            if ( lines[i] != lines[i - 1] ) sol++;

		printf( "%d\n", sol );

		scanf( "%d", &N );
	}

    fflush( stdout );
	return 0;
}
