#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int x, i, j, k, q;
char s1[12], s2[12];
bool ok, used[12];

int main() {

    cin >> x;
    j = (int)floor( log10( x ) );
    itoa( x, s1, 10 );

    for ( i = x + 1; (int)floor( log10( i ) ) == j; i++ ) {
        itoa( i, s2, 10 );
        fill( used, used + 12, false );
        for ( k = 0; k < strlen( s2 ); k++ ) {
          ok = false;
          for ( q = 0; q < strlen( s1 ); q++ )
           if ( s2[k] == s1[q] && !used[q] ) {
             ok = true; used[q] = 1;
             break;
           }
          if ( !ok ) break;
        }
        if ( ok ) break;
    }
    if ( ok ) cout << i << endl;
    else cout << 0 << endl;
}
