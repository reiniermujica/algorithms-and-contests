/*
 Reinier Cesar Mujica
 update xx/08/2008
*/

#include <cstdio>
#include <algorithm>

using namespace std;

const int
	MAXN = 100002;

int N, i;
int T[MAXN];

void quick_sort( int ini, int fin ) {
     int i, j, k, p;
     i = ini; j = fin; k = T[(i + j) / 2];
     
	 while ( i < j ) {
       while ( T[i] < k ) i++;
       while ( T[j] > k ) j--;
       if ( i <= j ) {
           swap( T[i], T[j] );
           i++; j--;
       }
     }
	 
     if ( i < fin ) quick_sort( i, fin );
     if ( j > ini ) quick_sort( ini, j );
}

int main(){
	
	freopen( "qsort.in", "r", stdin );
	freopen( "qsort.out", "w", stdout );
	
	scanf( "%d", &N );
	for ( i = 1; i <= N; i++ )
	 scanf( "%d", &T[i] );
    
	quick_sort( 1, N );
    for ( i = 1; i <= N; i++ )
	 printf( "%d\n", T[i] );
	 
	fflush( stdout );
    return 0;
}
