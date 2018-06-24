/*
 Reinier Cesar Mujica
 update xx/08/2008
 "Heap Sort "
*/

#include <cstdio>
#include <algorithm>

using namespace std;

const int
	MAXN = 1000002;

struct heap { //ni el Heap de la STL le hace nada a este salvaje
     int tree_size;
	 int tree[MAXN];
	 int i;
	 
	 bool empty() {
		return tree_size == 0;
	 }
	 
	 int top() {
		return tree[1];
	 }
	 
	 void push( int x ) {
		  tree[++tree_size] = x;
		  i = tree_size;
		  
		  while ( i > 1 && tree[i] < tree[i / 2] ) {
			swap( tree[i], tree[i / 2] );
            i /= 2;
          }
	 }
     
	 void pop() {
		if ( tree_size <= 0 ) return ;
		tree[1] = tree[tree_size--];
		i = 1; 
		
		while ( i * 2 <= tree_size ) {
			int &node = tree[i];
			int &left = tree[i * 2];
			int &right = tree[i * 2 + 1];
			
			if ( left < right && left < node ) {
				swap( left, node );
				i *= 2;
			}
			else
			if ( right < node ) {
				swap( right, node );
				i *= 2; i++;
			}
			else break;
        }
     }
     
} Q;

int N;
int i, j, k;

int main() {
    
    freopen( "heap.in", "r", stdin ); 
	freopen( "heap.out", "w", stdout );
	
	scanf( "%d", &N );
	for ( i = 0; i < N; i++ ) {
		scanf( "%d", &k );
		Q.push( k );
	}
    
	while ( !Q.empty() ) {
		printf( "%d\n", Q.top() );
		Q.pop();
	}
	
	fflush( stdout );
    return 0;
}
