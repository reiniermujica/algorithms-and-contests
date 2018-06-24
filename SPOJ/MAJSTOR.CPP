/*

*/

#include <cstdio>
#include <algorithm>

using namespace std;

const int
	MAXN = 155;
	
int N, R, sol, best;
int i, j, k;
char cad[MAXN], temp[MAXN][MAXN];
int val[300][300];
int dp[MAXN][10];

int main() {

	for ( i = 'A'; i <= 'Z'; i++ )
		val[i][i] = 1;
	val['S']['P'] = 2;
	val['S']['R'] = 0;
	val['P']['R'] = 2;
	val['P']['S'] = 0;
	val['R']['P'] = 0;
	val['R']['S'] = 2;
	
	scanf( "%d\n", &N );
	gets( cad + 1 );
	scanf( "%d\n", &R );
	for ( i = 1; i <= R; i++ ) {
		gets( temp[i] + 1 );
		for ( j = 1; j <= N; j++ ) {
			sol += val[cad[j]][temp[i][j]];
		}

	}	
	
	printf( "%d\n", sol );
	
	for ( i = 1; i <= R; i++ ) {
        for ( j = 1; j <= N; j++ ) {
            dp[j][1] += val['S'][temp[i][j]];
            dp[j][2] += val['R'][temp[i][j]];
            dp[j][3] += val['P'][temp[i][j]];
        }

    }
    for ( i = 1; i <= N; i++ )
        best += dp[i][1] >? dp[i][2] >? dp[i][3];
        
	printf( "%d\n", best );
	
	return 0;
}
