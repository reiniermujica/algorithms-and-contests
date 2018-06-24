/*

*/

#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>

#define SQR(x) x * x

using namespace std;

const int
	MAXN = 1001;
	
int N, M, Q;
int i, j, k;
double point[MAXN][2];
double dist[MAXN][MAXN];
int L[20];
int mark[MAXN];
double best;

double distance1( int x, int y )
{
    double c1 = point[x][0] - point[y][0];
    double c2 = point[x][1] - point[y][1];
    return sqrt( SQR(c1) + SQR(c2) );
}

void dfs( int node, int count, double d )
{
    if ( count < M )
    {
        for ( int i = 0; i < M; i++ )
        {
            int next = L[i];
            if ( !mark[next] )
            {
                mark[next] = true;
                dfs( next, count + 1, d + dist[node][next] );
                mark[next] = false;
            }
        }
    }
    else
    {
        best <?= d;
    }
    
    return ;
}

int main()
{
	cin >> N;
	for ( i = 1; i <= N; i++ )
	{
		cin >> point[i][0] >> point[i][1];	
		for ( j = 1; j < i; j++ )
		{
            double temp = distance1( i, j );
            dist[i][j] = temp;
            dist[j][i] = temp;
        }
	}

    cin >> Q;
    while ( Q-- )
    {
        cin >> M;
        best = 0;
        for ( i = 1; i <= M; i++ )
        {
            cin >> L[i];
            L[i]++;
            best += dist[L[i]][L[i-1]];
        }


/*
        fill( mark, mark + MAXN, false );
        best = 1 << 25;
        dfs( 0, 0, 0 );
*/
        printf( "%.0lf\n", best );
    }

	return 0;
}
