/*
 Binary Search Tree
 Is under construction...
 Operations :
  void insert( element ); OK
  bool erase( element );
  int  find( element );   OK
  T max()                 OK
  T min()                 OK
*/

#include <cstdio>
#include <algorithm>

using namespace std;

template <class T>
class BST {

      public:

      void insert( T x ) {

        if ( tree_size == 0 ) {
            tree[++tree_size] = (node) { x, tree_size, 0, 0, 0 };
            return ;
        }
        tmp = 1;
        while ( true )
           if ( tree[tmp].value < x ) {
             if ( tree[tmp].right > 0 )
               tmp = tree[tmp].right;
             else {
              tree[++tree_size] = (node) { x, tree_size, tmp, 0, 0 };
              tree[tmp].right = tree_size;
              return ;
             }
           }
           else {
             if ( tree[tmp].left > 0 )
               tmp = tree[tmp].left;
             else {
              tree[++tree_size] = (node) { x, tree_size, tmp, 0, 0 };
              tree[tmp].left = tree_size;
              return ;
             }
           }
      }
      
      int find( T x ) {
        if ( tree_size == 0 ) return 0;
        tmp = 1;
        while ( true ) {
          k = equal( x, tree[tmp].value );
          if ( k == 0 ) return tmp;
          if ( k == -1 ) tmp = tree[tmp].left;
          else tmp = tree[tmp].right;
          if ( tmp == 0 ) return 0;
        }
      }
      
      T max() {
        if ( tree_size == 0 ) return 0;
        tmp = 1;
        while ( tree[tmp].right > 0 )
         tmp = tree[tmp].right;
        return tree[tmp].value;
      }
      
      T min() {
        if ( tree_size == 0 ) return 0;
        tmp = 1;
        while ( tree[tmp].left > 0 )
         tmp = tree[tmp].left;
        return tree[tmp].value;
      }
      
      T successor( T x ) {
        if ( tree_size == 0 ) return 0;
        int t = find( x ); tmp = t;
        
        if ( tree[tmp].right > 0 ) {
            tmp = tree[tmp].right;
            while ( tree[tmp].left > 0 )
                tmp = tree[tmp].left;
            return ( tmp != t ) ? tree[tmp].value : 0;
        }
        tmp = tree[t].parent;
        while ( tmp > 0 && tree[tmp].right == t ) {
            t = tmp;
            tmp = tree[tmp].parent;
        }
        
        return ( tmp > 0 ) ? tree[tmp].value : 0;
      }
      
      bool erase( T x ) {
        if ( tree_size == 0 ) return false;
        tmp = find( x ); int k;
        if ( tmp == 0 ) return false;
        
        if ( tree[tmp].right == 0 ||
             tree[tmp].left == 0 ) {
            if ( tree[tmp].right > 0 )
                k = tree[tmp].right;
            else
                k = tree[tmp].left;

            if ( k == 0 ) {
                k = tree[tmp].parent;
                if ( tree[k].value < x )
                 tree[k].rigth = 0;
                else
                 tree[k].left = 0;
                return true;
            }
            tree[tree[k].parent]

        }



      }
      
      void print() {
        for ( int k = 1; k <= tree_size; k++ )
         printf( "%d ", tree[k].value );

      }

      private :
        struct node {
            T value;
            int number, parent;
            int left, right;
        } tree[1000];

        int tree_size;
        int tmp, k;
        
        int equal( T x, T y ) {
            if ( x < y ) return -1;
            if ( y < x ) return 1;
            return 0;
        }
        
};


int N, i, j, k;
int L[1000];

BST < int > S, K;

int main() {

    freopen( "BST.in", "r", stdin );
    
    scanf( "%d", &N );
    for ( i = 1; i <= N; i++ ) {
        scanf( "%d", &L[i] );
        S.insert( L[i] );
    }
    for ( i = 1; i <= N; i++ ) {
        printf( "%d\n", S.successor( L[i] ) );

    }

    printf( "%d\n", S.max() );
 //   S.print();v


    printf( "Ok\n" );

    fflush( stdout );
    return 0;
}
