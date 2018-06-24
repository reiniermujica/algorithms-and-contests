/*
 Reinier César Mujica
 9/4/08  PSN - 2008
*/

#include <cstdio>
#include <algorithm>

using namespace std;

const int
    MAXN = 102,
    MAXC = 100002,
    oo   = 1<<29;
    
struct cow {
    int x,y;
};

int N, sol, dp[2*MAXC], dp1[2*MAXC], i, j;
cow T[MAXN];
int *last = dp + MAXC, *next = dp1 + MAXC;

int main() {
    freopen( "smrtfun.in", "r", stdin );
    freopen( "smrtfun.out", "w", stdout );
    scanf( "%d", &N );
    for ( i=1; i<=N; i++ )
     scanf( "%d%d", &T[i].x, &T[i].y );
    fill( next - MAXC, next + MAXC, -oo );
    next[0]=0;
    
    /*..Dynamic Programing..*/ 
    for ( i=1; i<=N; i++ ) {
        swap( last, next );
        for ( j=MAXC-1; j>-MAXC; j-- ) next[j]=last[j]; //fill
        for ( j=MAXC-1; j>-MAXC; j-- ) {
         int nex = j - T[i].x;
         if ( nex > -MAXC && nex < MAXC && last[nex] != -oo ) 
           next[j]>?=last[nex] + T[i].y;   
        }
    }
    
    for ( i=0; i<MAXC; i++ )
     if ( next[i] >= 0 )
      sol >?= next[i] + i;   
    printf( "%d\n", sol );
    fflush( stdout );
    return 0;
}
