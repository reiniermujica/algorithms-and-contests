/*
 Reinier César Mujica
 2 - 4 - 2009
 Good DP
*/

#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int
	MAXN = 300005,
	MAXC = 100005;

struct point {
	int x, y, amount;
} T[MAXN];
	
int N, K;
int i, k, lx, ly;
int dp[MAXN];
int id[MAXN], last[MAXN];
int xx[MAXC], yy[MAXC];
vector < int > P;

bool cmp( const int &a, const int &b ) {
     if ( T[a].x != T[b].x ) return T[a].x < T[b].x;
     return T[a].y < T[b].y;
}

int main() {

	scanf( "%d %d", &N, &K );
	for ( i = 1; i <= N; i++ ) {
		scanf( "%d %d %d", &T[i].x, &T[i].y, &T[i].amount );
		id[i] = i;
    }
	
	sort( id + 1, id + N + 1, cmp );
	memset( xx, 0, sizeof xx );
	memset( yy, 0, sizeof yy );
    
	for ( i = 1; i <= N; i++ ) {
		lx = ly = 0; k = id[i];
        
		if ( k != 1 ) dp[k] = -1;

		if ( xx[T[k].x] != -1 ) lx = xx[T[k].x];
		if ( yy[T[k].y] != -1 ) ly = yy[T[k].y];

        if ( dp[lx] >= K && dp[k] < dp[lx] - K ) {
            dp[k] = dp[lx] - K;
            last[k] = lx;
        }

        if ( dp[ly] >= K && dp[k] < dp[ly] - K ) {
            dp[k] = dp[ly] - K;
            last[k] = ly;
        }

        if ( dp[k] != -1 ) dp[k] += T[k].amount;
        
		if ( dp[lx] < dp[k] ) xx[T[k].x] = k;
		if ( dp[ly] < dp[k] ) yy[T[k].y] = k;
	}
	
    for ( i = N; i > 0; i = last[i] )
        P.push_back( i );
    
   	printf( "%d\n", dp[N] );
   	printf( "%d\n", P.size() );
   	for ( i = P.size() - 1; i >= 0; i-- )
        printf( "%d %d\n", T[P[i]].x, T[P[i]].y );

	fflush( stdout );
	return 0;
}
