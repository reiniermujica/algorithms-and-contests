/*
 Reinier César Mujica
 22/4/08
 Build : O(N * lg(N))
 Query: O(1)
*/

#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const int
    MAXN = 100002,
    MAXL = 19;

struct range {
    int min, max;
};

int N, Q;
int i, j, k;
int a, b;
range RMQ[MAXN][MAXL];
    
int main(){

    freopen( "rmq.in", "r", stdin );
    freopen( "rmq.out", "w", stdout );

    scanf( "%d %d", &N, &Q );
    for ( i = 1; i <= N; i++ ) {
     scanf( "%d", &j );
     RMQ[i][0].min = j;
     RMQ[i][0].max = j;
    }

    /* Min - Max Range Quering  O(N * log(N)) */
    k = (int)log2( N );
    for ( i = 1; i <= k; i++ ) {
     int pow = 1 << i; // 2^i
     for ( j = 1; j <= N - pow + 1; j++ ) {
      RMQ[j][i].min = min( RMQ[j][i-1].min, RMQ[j + pow / 2][i-1].min );
      RMQ[j][i].max = max( RMQ[j][i-1].max, RMQ[j + pow / 2][i-1].max );
     }
    }
    
    while ( Q-- ) {
     scanf( "%d %d", &i, &j );
	 
     k = (int)log2( j - i );
     printf( "MAX = %d MIN = %d\n",
      max( RMQ[i][k].max, RMQ[j - (1 << k) + 1][k].max ),
      min( RMQ[i][k].min, RMQ[j - (1 << k) + 1][k].min ) );
    }
    
    fflush( stdout );
    return 0;   
}
