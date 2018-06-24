#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

#define MAXN 11010
#define MAX 105
#define oo 1 << 29

const int mov[4][2] = { {0,1}, {1,0}, {-1,0}, {0,-1} };

struct point
{
       int x, y;
       point ( int xx = 0, int yy = 0 )
       {
             x = xx; y = yy;
       }
};

int N, M;
int i, j, k;
int x, y;
bool mark[MAXN + 5];
int grid[MAX * 2][MAX * 2];
int cost[MAX * 2][MAX * 2];
point P[MAXN + 5];

void store( int n, int x, int y )
{
     P[n].x = x;
     P[n].y = y;
}

void pull( int n, int x, int y )
{
     if ( mark[n] )
         grid[x][y] = -1;
     else
         grid[x][y] = n;
}

int bfs( int x, int y )
{
    queue < point > Q;
    Q.push( point( P[x].x, P[x].y ) );
    
    for ( i = 0; i < 2 * MAX; i++ )
        fill( cost[i], cost[i] + 2 * MAX, oo );
        
    cost[P[x].x][P[x].y] = 0;
    
    while ( !Q.empty() )
    {
          point top = Q.front();
          Q.pop();
          int cx = top.x;
          int cy = top.y;

          for ( int i = 0; i < 4; i++ )
          {
              int xx = cx + mov[i][0];
              int yy = cy + mov[i][1];
              if ( grid[xx][yy] != -1 && grid[xx][yy] != 0 && cost[xx][yy] > cost[cx][cy] + 1 )
              {
                   cost[xx][yy] = cost[cx][cy] + 1;
                   Q.push( point( xx, yy ) );
              }
          }
    }
    
    return cost[P[y].x][P[y].y];

}

int main()
{
    /* criba */
    fill( mark, mark + MAXN + 1, true );
    mark[1] = false;
    for ( i = 2; i * i < MAXN + 1; i++ )
    {
        if ( mark[i] )
        {
             k = i;
             while ( k * i < MAXN )
             {
                   mark[k * i] = false;
                   k++;
             }
        }
    }

    N = 1; M = 1;
    x = MAX; y = MAX;
    store( 1, x, y );
    pull( 1, x, y );

    while ( N < MAXN )
    {
          M += 2;
          
          y++;
          for ( i = 1; i < M && N < MAXN; i++ )
          {
              N++;
              store( N, x, y );
              pull( N, x, y );
              x--;
          }

          x++; y--;
          for ( i = 1; i < M && N < MAXN; i++ )
          {
              N++;
              store( N, x, y );
              pull( N, x, y );
              y--;
          }
          
          y++; x++;
          for ( i = 1; i < M && N < MAXN; i++ )
          {
              N++;
              store( N, x, y );
              pull( N, x, y );
              x++;
          }

          x--; y++;
          for ( i = 1; i < M && N < MAXN; i++ )
          {
              N++;
              store( N, x, y );
              pull( N, x, y );
              y++;
          }
          y--;
    }

    N = 0;
    while ( scanf( "%d %d", &x, &y ) != EOF )
    {
          N++;
          k = bfs( x, y );
          printf( "Case %d: ", N );
          if ( k == oo )
              printf( "impossible\n" );
          else
              printf( "%d\n", k );
    }

    return 0;
}
