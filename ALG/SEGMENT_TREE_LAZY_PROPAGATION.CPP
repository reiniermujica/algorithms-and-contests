#include <cstdio>
#include <map>
#include <algorithm>

using namespace std;

#define MAXN 100005
#define MOD 10000007

int N, Q;
int i, j, k;
int x, y;
char c;
int X[MAXN], Y[MAXN];
map < int, int > M0, M1;

struct SegmentTree
{
    int N;
    int T[MAXN * 4];
    bool mark[MAXN * 4];
    int temp[MAXN * 4];
   
    void update( int node, int lo, int hi, int x, int y, int val )
    {
        if ( lo > y || hi < x ) return ;
                
        if ( lo >= x && hi <= y )
        {
            T[node] += val * ( hi - lo + 1 );
            T[node] %= MOD;
            temp[node] += val;
            temp[node] %= MOD;
            mark[node] = true;
            return ;
        }
        
        int mid = ( lo + hi ) >> 1;
        if ( mark[node] )
        {
            update( node * 2, lo, mid, lo, hi, temp[node] );
            update( node * 2 + 1, mid + 1, hi, lo, hi, temp[node] );
            mark[node] = false;
            temp[node] = 0;
        }
        
        update( node * 2, lo, mid, x, y, val );
        update( node * 2 + 1, mid + 1, hi, x, y, val );                     
        T[node] = ( T[node * 2] + T[node * 2 + 1] ) % MOD;
    }
    
    int query( int node, int lo, int hi, int pos )
    {
        if ( lo > pos || hi < pos ) return 0;

        if ( lo == pos && hi == pos )
            return T[node];
        
        int mid = ( lo + hi ) >> 1;
        if ( mark[node] )
        {
            update( node * 2, lo, mid, lo, hi, temp[node] );
            update( node * 2 + 1, mid + 1, hi, lo, hi, temp[node] );
            mark[node] = false;
            temp[node] = 0;
            T[node] = ( T[node * 2] + T[node * 2 + 1] ) % MOD;        
        }
        
        return ( query( node * 2, lo, mid, pos ) +
                 query( node * 2 + 1, mid + 1, hi, pos ) ) % MOD;
    }
} g0, g1;

int main()
{
    scanf( "%d %d", &N, &Q );
    for ( i = 1; i <= N; i++ )
    {
        scanf( "%d %d", &X[i], &Y[i] );                
    }
    scanf( "%c", &c ); //end line
    
    sort( X + 1, X + N + 1 );
    sort( Y + 1, Y + N + 1 );
    for ( i = 1; i <= N; i++ )
    {
        M0[X[i]] = i;
        M1[Y[i]] = i;
    }
    
    g0.N = g1.N = N;
        
    while ( Q-- )
    {
        scanf( "%c", &c );
        if ( c == 'F' ) //update
        {
            scanf( "%d %d %d %d\n", &j, &x, &y, &k );
            if ( j == 0 )
                g0.update( 1, 1, N, x, y, k );
            else
                g1.update( 1, 1, N, x, y, k );        
        }
        else    //query
        {
            scanf( "%d %d\n", &x, &y );            
            int sol = ( g0.query( 1, 1, N, M0[x] ) + g1.query( 1, 1, N, M1[y] ) ) % MOD;
            printf( "%d\n", sol );        
        }         
    }
    
    return 0;
}
