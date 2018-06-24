/*
 Reinier Cesar Mujica
 4/06/08
 "Merge Sort" O(N*lg(N))
*/

#include <cstdio>

#define debug 0

using namespace std;

const int
    MAXN = 1000002;

int N, i;
int A[MAXN], B[MAXN];

void merge_sort( int start, int end ) {
     if ( start >= end ) return ;
     
     int mid, i, f, k, j;
     mid = ( start + end ) / 2;

     merge_sort( start, mid );
     merge_sort( mid + 1, end );

     i = k = start; j = mid + 1;
     
     while ( i <= mid && j <= end ) {
        if ( A[i] < A[j] ) {
            B[k] = A[i]; i++;
        }
        else {
            B[k] = A[j]; j++;
        }
        k++;
     }

     for ( f = i; f <= mid; f++ )
      B[k++] = A[f];
     for ( f = j; f <= end; f++ )
      B[k++] = A[f];
     for ( f = start; f <= end; f++ )
      A[f] = B[f];
}

int main() {

    scanf( "%d", &N );
    
    for ( i = 1; i <= N; i++ )
     scanf( "%d", &A[i] );
     
    merge_sort( 1, N );

    for ( i = 1; i <= N; i++ )
     printf( "%d\n", A[i] );
    
    fflush( stdout );
    return 0;
}
