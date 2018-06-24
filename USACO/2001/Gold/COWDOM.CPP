/*
 Reinier Cesar Mujica
 9/06/2008
 "Cow Dominoes"
*/

#include <cstdio>
#include <algorithm>

using namespace std;

const int
    MAXN = 101;

int N, i, s1, s2, cc;
int T[MAXN];
int tmp[MAXN], sum[MAXN], t[MAXN];

int multiply( int a ) {
    int n = T[a], i, j = 0;
    for ( i = 0; i < cc; i++ )
     tmp[++j] = 0;

    while ( n > 0 ) {
       tmp[++j] =  n % 10;
       n = n / 10;
    }
    return j;
}

void suma() {
     int i, j = 0, carry = 0;
     for ( i = 1; i <= s2; i++ ) {
        if ( i > s1 ) sum[i] = 0;
        t[++j] = ( tmp[i] + sum[i] ) % 10 + carry;
        carry = ( tmp[i] + sum[i] ) / 10;
     }
     for ( i = 1; i <= j; i++ )
      sum[i] = t[i];
     s1 = j;
}

int main() {

    freopen( "cowdom.in", "r", stdin );
    freopen( "cowdom.out", "w", stdout );

    scanf( "%d", &N );
    
    for ( i = 0; i < N; i++ ) {
     scanf( "%d %d", &s1, &s2 );
     T[i] = s1 + s2;
    }

    sort( T, T + N );

    s1 = s2 = 0;
    for ( i = 0; i < N; i++ ) {
      s2 = multiply( i );
      suma();
      cc++;
    }

    for  (  i = s1; i > 0; i-- )
     printf ( "%d", sum[i] );
     
    printf( "\n" );
     
    fflush( stdout );
    return 0;
}
