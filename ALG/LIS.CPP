/*
 Reinier César Mujica
 Longest Increasing (Dec) Subsequence
 O( N * Log(N) )
 update xx/08/2008
*/

#include <cstdio>
#include <algorithm>

using namespace std;

const int 
	MAXN = 50002;

int N, top, sol;
int i, j, k;
int last[MAXN];
    
struct LIS {
    int x, id;

    bool operator < ( const LIS &other ) const {
		return ( x < other.x );
	}
} T[MAXN], lis[MAXN];


void print( int x ) {
	 if ( !x ) return ;
	 print( last[x] );
	 printf( "%d\n", T[x].x );
}

int main() {
    
	freopen( "lis.in", "r", stdin );
    freopen( "lis.out", "w", stdout );
    
	scanf( "%d", &N );
    for ( i = 1; i <= N; i++ ) {
        scanf( "%d", &T[i].x );
		T[i].id = i;
		
		if ( lis[top] < T[i] ) {
			lis[++top] = T[i];
			last[i] = lis[top - 1].id;
		}
		else {
			j = upper_bound( lis + 1, lis + top + 1, T[i] ) - lis;
			lis[j] = T[i];
			last[i] = lis[j - 1].id;
		}
	}
    
    printf( "%d\n", top );
	print( lis[top].id );
    
	fflush( stdout );
    return 0;   
}
