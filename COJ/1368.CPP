#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

#define MAXN 12
#define SQR( x ) ( x ) * ( x )

int N;
double sol = 1e15;
int i, j;
int x[MAXN], y[MAXN];
double d[MAXN][MAXN];
bool mark[MAXN];

double dist( int a, int b )
{
    return sqrt( SQR( x[a] - x[b] ) + SQR( y[a] - y[b] ) );
}

void dfs( int x, int cant, double dd )
{
    if ( cant == N )
    {
        sol = min( dd, sol );
        return ;
    }
    
    for ( int i = 1; i <= N; i++ )
    {
        if ( !mark[i] && dd + d[x][i] < sol )
        {
            mark[i] = true;
            dfs( i, cant + 1, dd + d[x][i] );
            mark[i] = false;
        }
    }
    return ;
}

int main()
{
    scanf( "%d", &N );
    for ( i = 1; i <= N; i++ )
        scanf( "%d %d", &x[i], &y[i] );

    /* build all edges */
    for ( i = 1; i <= N; i++ )
    {
        for ( j = 1; j <= N; j++ )
            if ( i != j )
            {
                d[i][j] = dist( i, j );
            }
    }           

    dfs( 0, 0, 0.0 );
    
    printf( "%.2lf\n", sol );
    return 0;
}
