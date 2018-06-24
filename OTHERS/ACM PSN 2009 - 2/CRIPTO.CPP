/*
 Reinier César Mujica
 25 - 06 - 2009
 Big Num
*/

#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long int64;

#define MAXD 1000

int N, M;
int i, j, k;
int lo, hi, mid;
char cad[MAXD];
int dig[MAXD];

int ok( int64 x ) {
    int64 i, k, len, carry;
    dig[len = 1] = 1;
    
    for ( i = 1; i <= N; i++ ) {
        carry = 0;
        for ( j = 1; j <= len; j++ ) {
            k = (int64)( dig[j] * x ) + carry;
            carry = (int64)k / 10;
            dig[j] = (int64)k % 10;
        }
        while ( carry ) {
            dig[++len] = (int64)carry % 10;
            carry /= 10;
        }
    }

    if ( len == M ) {
        for ( i = len, j = 1; j <= M && i > 0; i--, j++ ) {
            if ( cad[j] - '0' != dig[i] )
                if ( cad[j] - '0' < dig[i] )
                    return 1;
                else
                    return -1;
        }
        return 0;
    }
    if ( len < M ) return -1;
    else return 1;
}

int main() {

    while ( scanf( "%d\n", &N ) != EOF ) {

        gets( cad + 1 ); // bigint
        M = strlen( cad + 1 );
        
        /* binary search */
        lo = 1; hi = 1 << 30;
        while ( lo <= hi ) {
            mid = ( lo + hi ) / 2;
            k = ok( mid );
            if ( k == 0 ) {            
                printf( "%d\n", mid );
                break;
            }
            if ( k == -1 ) lo = mid + 1;
            else hi = mid - 1;
        }
    }
    
    fflush( stdout );
    return 0;
}
