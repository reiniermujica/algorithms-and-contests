/*
 Reinier Cesar Mujica
 17/06/2008
 "Kolone"
*/

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int N, M, T;
int i, j;
string S1, S2;
bool mk[51], mark[51];

int main() {

    cin >> N >> M;
    cin >> S1 >> S2;
    cin >> T;
    
    reverse( S1.begin(), S1.end() );
    S1 += S2;
    for ( j = N; j <= N + M - 1; j++ )
     mark[j] = true;
    
    for ( i = 1; i <= T; i++ ) {
      fill( mk, mk + 51, 0 );
      
      for ( j = 0; j < N + M - 1; j++ ) {
         if ( !mk[j] && !mark[j] && mark[j + 1] ) {
            swap( mark[j], mark[j + 1] );
            swap( S1[j], S1[j + 1] );
            mk[j + 1] = true;
         }
      }
    }
    
    cout << S1 << endl;
    
    fflush( stdout );
    return 0;
}
