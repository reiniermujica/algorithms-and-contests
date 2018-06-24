/*
 Reinier César Mujica
 2 - 10 - 2008
 "Asegurando el Establo"
*/

#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

const int
	MAXN = 20;
	
int N, L;
int i;
char val[MAXN];

bool valid( string st ) {
     int cont = 0;
     for ( int i = 0; i < st.size(); i++ ) {
        if ( st[i] == 'a' || st[i] == 'e' ||
             st[i] == 'i' || st[i] == 'o' ||
             st[i] == 'u' ) cont++;
     }
     return cont > 0;
}

void comb( string st, int act, int len ) {
	 if ( len == L && valid( st ) ) {
    	printf( "%s\n", st.c_str() );
		return ;
	 }

	 for ( int i = act + 1; i <= N; i++ )
		comb( st + val[i], i, len + 1 );
}

int main() {
	
	freopen( "PASSWD.IN", "r", stdin );
	freopen( "PASSWD.OUT", "w", stdout );

	scanf( "%d %d\n", &L, &N );
	for ( i = 1; i <= N; i++ )
	 scanf( "%c%c", &val[i], &val[0] );
    
    sort( val + 1, val + N + 1 );
    comb( "", 0, 0 );

	return 0;
}
