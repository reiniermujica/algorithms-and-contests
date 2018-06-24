/*
 Reinier César Mujica
 19 - 3 - 2009
*/

#include <cstdio>
#include <algorithm>

using namespace std;

const int
    MAXN = 100050;
    
int N, sol;
int i, last = 1, amount, de;
int T[MAXN];

int main() {

    freopen( "iou.in", "r", stdin );
    freopen( "iou.out", "w", stdout );
    
    scanf( "%d", &N );
    for ( i = 1; i <= N; i++ ) {
        scanf( "%d", &T[i] );
        if ( T[i] < 0 ) { 
            if ( de == 0 ) last = i;
            de += T[i];
        } else amount += T[i];
        if ( amount >= abs( de ) && de < 0 ) {
            amount -= abs( de );
            de = 0;
            sol += ( i - last ) * 2;
        }
        sol++;
    }
    
    printf( "%d\n", sol );
    return 0;
}
