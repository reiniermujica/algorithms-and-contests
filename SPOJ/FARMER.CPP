/*
 Reinier César Mujica
 19 - 11 - 2008
 a fuck KNASPACK
*/

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int
	MAXN = 150050,
	oo   = 1 << 30;
	
typedef pair < int, int > par;

int T, Q, N, K, sol;
int i, j, k;
int dp[MAXN];
vector < par > KNP;

int main() {


	scanf( "%d", &T );
	while ( T-- ) {

		/* init */
		sol = 0;
        KNP.clear();
		memset( dp, 0, sizeof dp );

        /* read */
        scanf( "%d %d %d", &Q, &N, &K );
		for ( i = 1; i <= N; i++ ) {
			scanf( "%d", &k );
			KNP.push_back( par( k, 0 ) );
		}
		for ( i = 1; i <= K; i++ ) {
			scanf( "%d", &k );
			KNP.push_back( par( k, 1 ) );
		}
		
		/* knaspack */
		for ( i = 0; i < KNP.size(); i++ ) {
			int weight = KNP[i].first;
			int value = weight - KNP[i].second;
    		if ( weight >= Q ) {
    		    for ( j = Q; j >= 0; j-- )
                  sol >?= dp[j] + ( ( Q - j ) - 1 );
                continue;
            }

			for ( j = Q; j >= weight; j-- ) {
               if ( j + weight > Q ) sol >?= dp[j] + ( Q - j - 1 );
    		   if ( dp[j - weight] + value > dp[j] )
			 	  dp[j] = dp[j - weight] + value;
			}
		}

		sol >?= dp[Q];
		printf( "%d\n", sol );
	}

	return 0;
}
