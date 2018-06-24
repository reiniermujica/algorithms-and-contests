/*
 Reinier César Mujica
 16 - 3 - 2009
*/

#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const int
	MAXN = 110;
	
int N, M, sol = 1 << 30;
int i, j, k;
int sum[MAXN][MAXN];
vector < int > D;

int main() {

	scanf( "%d %d", &N, &M );
	for ( i = 1; i <= M; i++ ) {
		scanf( "%d %d", &j, &k );
		sum[j][k] = 1;
	}
	
    for ( i = 1; i <= N; i++ )
        for ( j = 1; j <= N; j++ )
            sum[i][j] += ( sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] );

    for ( i = 1; i <= M; i++ )
        if ( M % i == 0 ) D.push_back( i );

    for ( i = 1; i <= N; i++ )
        for ( j = 1; j <= N; j++ )
			for ( k = 0; k < D.size(); k++ ) {
				int dy = j - D[k];
				int dx = i - ( M / D[k] );
				if ( dx < 0 || dy < 0 ) continue;
				int amount = sum[i][j] - 
							 ( sum[dx][j] + sum[i][dy] - sum[dx][dy] );
				sol <?= M - amount;
			}

	printf( "%d\n", sol );
	return 0;
}
