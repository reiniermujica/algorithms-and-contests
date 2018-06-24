#include <iostream>

using namespace std;

int C[5], T[4], M[1000];
int i, j, k, t1, t2;
bool q, w;

int main() {

    cin >> C[1] >> C[2] >> C[3] >> C[4];
    cin >> T[1] >> T[2] >> T[3];

    for ( i = 1; i <= 999; i++ ) {
        t1++; t2++;
        if ( t1 <= C[1] && !q ) {
          M[i]++;
          if ( t1 == C[1] ) {
            t1 = 0; q = true;
          }
        }
        else
        if ( t1 == C[2] && q ) {
            t1 = 0; q = false;
        }

        if ( t2 <= C[3] && !w ) {
          M[i]++;
          if ( t2 == C[3] ) {
            t2 = 0; w = true;
          }
        }
        else
        if ( t2 == C[4] && w ) {
            t2 = 0; w = false;
        }
    }

    for ( i = 1; i < 4; i++ ) {
        if ( !M[T[i]] ) printf( "none\n" );
        if ( M[T[i]] == 1 ) printf( "one\n" );
        if ( M[T[i]] == 2 ) printf( "both\n" );
    }
    
    fflush( stdout );
    return 0;
}
