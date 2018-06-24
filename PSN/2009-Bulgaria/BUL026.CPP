/*
 Reinier César Mujica
 17 - 3 - 2009
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int
    MAXN = 10;
    
int N, sol = 1 << 30;
int i, j, k;
string S[MAXN];
bool mark[MAXN];

string res( string a, string b ) {
       int i, j, k, c;
       string res; res.clear();
       for ( i = 0; i < a.size(); i++ ) {
            if ( a[i] == b[0] ) {
                bool ok = true;
                for ( j = 0, k = i; j < b.size() && k < a.size(); j++, k++ )
                    if ( a[k] != b[j] ) {
                        ok = false;
                        break;
                    }
                if ( ok && i + b.size() >= a.size() ) {
                    res += b;
                    return res;
                }
            }
            res += a[i];
       }
       return a + b;
}

void dfs( string a, int count ) {
     if ( count == N ) {
        sol <?= a.size();
        return ;
     }
     for ( int i = 1; i <= N; i++ )
        if ( !mark[i] ) {
            mark[i] = true;
            dfs( res( a, S[i] ), count + 1 );
            mark[i] = false;
        }
}

int main() {
    
    freopen( "dna.in", "r", stdin );
    freopen( "dna.out", "w", stdout );
    
    scanf( "%d\n", &N );
    for ( i = 1; i <= N; i++ ) {
        cin >> S[i];
    }
    
    for ( i = 1; i <= N; i++ ) {
        memset( mark, 0, sizeof mark );
        mark[i] = true;
        dfs( S[i], 1 );
    }
    
    printf( "%d\n", sol );

    fflush( stdout );
    return 0;
}
