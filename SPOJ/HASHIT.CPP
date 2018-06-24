/*
 Reinier César Mujica
 11 - 11 - 2008
 my first hash table
*/

#include <cstdio>
#include <string>

using namespace std;

const int
    MAXN = 251,
    MMOD = 101;
    
int Q, N, sol;
int i, j;
int hash, nhash, k;
string keys[MAXN];
string cad;
char cmd[MAXN];

int make_hash( string key ) {
    int i, h = 0;
    for ( i = 0; i < key.size(); i++ ) {
        h += (char)key[i] * ( i + 1 );
    }
    return ( 19 * h ) % MMOD;
}

int find_key( string key ) {
	int h = make_hash( key );
	int m = 1, nh = h;
	while ( keys[nh] != key && m < 20 ) {
		nh = ( h + ( ( m * m ) + ( 23 * m ) ) ) % MMOD;
		m++;
	}
    if ( keys[nh] == key ) return nh; // such key exist
	return -1;
}

int main() {
    
    scanf( "%d\n", &Q );
    while ( Q-- ) {
        
        /* fill */
        for ( i = 0; i < MAXN; i++ )
            keys[i].clear();
        
        /* solve... or try it? */
        scanf( "%d\n", &N );
        for ( i = 1; i <= N; i++ ) {
            gets( cmd + 1 );
            cad = string( cmd + 5 );
            if ( cmd[1] == 'A' ) {                
                if ( find_key( cad ) != -1 ) continue;
				hash = nhash = make_hash( cad );
                j = 1;
                while ( !keys[nhash].empty() && j < 20 ) {
                    nhash = ( hash + ( ( j * j ) + ( 23 * j ) ) ) % MMOD;
                    j++;
                }
                if ( keys[nhash].empty() )
                 keys[nhash] = cad; // insert the key
            }
            else {
                hash = find_key( cad );
                if ( hash != -1 )
                 keys[hash].clear(); // delete the key
            }
        }
        
        sol = 0;
        for ( i = 0; i < MAXN; i++ )
            if ( !keys[i].empty() ) sol++;
        
        printf( "%d\n", sol );
        for ( i = 0; i < MAXN; i++ )
            if ( !keys[i].empty() ) printf( "%d:%s\n", i, keys[i].c_str() );
    }
    
    fflush( stdout );
    return 0;
}
