#include <cstdio>
#include <algorithm>

#define MAXN 100005

using namespace std;

int N, B;
int i, j, k;
int x, y;
int l, r;
bool dead[MAXN];
int prev[MAXN];
int next[MAXN];

int main()
{
    scanf( "%d %d", &N, &B );
    while ( N || B )
    {
        /* filling */
        fill( dead, dead + MAXN, false );
        fill( prev, prev + MAXN, 0 );
        fill( next, next + MAXN, 0 );
            
        /* init */
        for ( i = 1; i <= N; i++ )
        {
            prev[i] = i - 1;
            next[i] = i + 1;        
        }
        dead[0] = dead[N + 1] = true;

        for ( i = 0; i < B; i++ )
        {
            scanf( "%d %d", &x, &y );
            
            dead[x] = dead[y] = true;
            next[x] = y + 1;
            prev[y] = x - 1;
            
            x--;
            while ( dead[x] && x > 0 )
            {
                x = prev[x];            
            }
            if ( x > 0 ) printf( "%d ", x );
            else printf( "* " );
            
            y++;
            while ( dead[y] && y <= N )
            {
                y = next[y];            
            }
            if ( y <= N ) printf( "%d\n", y );
            else printf( "*\n" );                            
        }
    
        printf( "-\n" );
        scanf( "%d %d", &N, &B );
    }
        
    return 0;
}
