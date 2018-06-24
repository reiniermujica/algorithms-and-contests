/*
 Reinier César Mujica
 31 - 3 - 2009
*/

#include <cstdio>
#include <cstring>

using namespace std;

const int
    MAXN = 2005;
    
int N, M;
int i, j;
char V[MAXN], T[MAXN];
int **dp;
int *next[260];
bool **path;

int main() {
    
    gets( V + 1 ); N = strlen( V + 1 );
    gets( T + 1 ); M = strlen( T + 1 );

    /* reserve dynamic memory */
    for ( i = 'a'; i <= 'z'; i++ ) {
        next[i] = new int[M + 2];
        next[i][M + 1] = M + 1;
    }
    dp = new int*[N + 2];
    path = new bool*[N + 2];
    for ( i = 0; i <= N; i++ ) {
        dp[i] = new int[N + 1];
        path[i] = new bool[N + 1];
        for ( j = 0; j < N + 1; j++ )
            dp[i][j] = path[i][j] = 0;
    }
    
    /* build next function */
    for ( i = 'a'; i <= 'z'; i++ ) {
        for ( j = M; j >= 0; j-- ) {
            if ( T[j + 1] == i )
                next[i][j] = j + 1;
            else next[i][j] = next[i][j + 1];
        }
    }

    /* cold DP */
    bool found = false;
    for ( i = 1; i <= N && !found; i++ ) {
        for ( j = i; j <= N; j++ ) {
            int up = dp[j - 1][i];
            int bk = next[V[j]][dp[j - 1][i - 1]];
            if ( bk > up ) {
                dp[j][i] = bk;
                path[j][i] = true;
            }
            else
                dp[j][i] = up;
            if ( dp[j][i] > M ) {
                found = true;
                break;
            }
        }
    }

    T[i] = '\0';
    printf( "%d\n", --i );
    while ( i * j ) {
        if ( path[j][i] ) {
            T[i] = V[j];
            i--; j--;
        }
        else j--;
    }
    printf( "%s\n", T + 1 );
   
    fflush( stdout );
    return 0;
}
