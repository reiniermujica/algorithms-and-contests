/*
 Reinier César Mujica
 xx/08/2008
 "Expense"
*/

#include <cstdio>

using namespace std;

const int
    MAXN = 100002;

int N, M, i, sol = 1 << 29;
int lo, hi, mid;
int T[MAXN];

bool ok( int cant ) {
     int res = M, act = 0;
     for ( i = 1; i <= N; i++ ) {
        if ( T[i] > cant ) return false;
        if ( act + T[i] > cant ) {
            res--;
            if ( !res ) return false;
            act = T[i];
        }
        else
         act += T[i];
     }
     return true;
}

int main() {

    freopen( "expense.in", "r", stdin );
    freopen( "expense.out", "w", stdout );
    
    scanf( "%d %d", &N, &M );
    for ( i = 1; i <= N; i++ ) {
      scanf( "%d", &T[i] );
      hi += T[i];
    }

    /* Binary Search */
    while ( lo <= hi ) {
       mid = ( lo + hi ) / 2;
       if ( ok( mid ) ) hi = mid - 1;
       else lo = mid + 1;
    }

    printf( "%d\n", lo );
    
    fflush( stdout );
    return 0;
}
