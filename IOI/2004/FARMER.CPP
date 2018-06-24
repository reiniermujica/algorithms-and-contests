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
	MAXM = 2050,
	oo   = 1 << 30;
	
typedef pair < int, int > par;

int T, Q, N, K, sol;
int i, j, k;
int F[MAXM], S[MAXN];
int dp[MAXN];
bool mark[MAXN];

int main() {

	freopen( "FARMER.IN", "r", stdin );
	freopen( "FARMER.OUT", "w", stdout );
	
	//scanf( "%d", &T ); 
	T = 1;
	while ( T-- ) {
		
		/* init */
		sol = 0;
		vector < par > KNP;
		fill( dp, dp + MAXN, 0 );
		fill( mark, mark + MAXN, false ); mark[0] = true;

        /* read */
        scanf( "%d %d %d", &Q, &N, &K );
		for ( i = 1; i <= N; i++ ) {
			scanf( "%d", &F[i] );
			KNP.push_back( par( F[i], 0 ) );
		}
		for ( i = 1; i <= K; i++ ) {
			scanf( "%d", &S[i] );
			KNP.push_back( par( S[i], 1 ) );
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
    		   if ( mark[j - weight]  && dp[j - weight] + value > dp[j] ) {
			 	  dp[j] = dp[j - weight] + value;
				  mark[j] = true;
			   }
			}
		}

		sol >?= dp[Q];
		printf( "%d\n", sol );
	}

	fflush( stdout );
	return 0;
}
