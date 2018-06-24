/*
    Range Tree
*/

#include <iostream>

using namespace std;

#define LEFT( node ) (node) * 2
#define RIGHT( node ) (node) * 2 + 1

const int
    MAXN = 100001,
    MAXC = 1000001;

struct node
{
    int sum, toadd;    
};

int N, Q;
int i, j, k;
int x, y, z;
node T[MAXN * 4];

void update( int node, int lo, int hi, int x, int y, int amount )
{
    if ( lo > y || hi < x ) return ;

    int l = max( lo, x );
    int r = min( hi, y );
    
    T[node].sum += ( amount ) * ( r - l + 1 );
    
    if ( lo >= x && hi <= y )
    {
        T[node].toadd += amount;
        return;    
    }
    
    int mid = ( lo + hi ) >> 1;
    update( LEFT( node ), lo, mid, x, y, amount );
    update( RIGHT( node ), mid + 1, hi, x, y, amount );
}

int query( int node, int lo, int hi, int x, int y, int add )
{
    if ( lo > y || hi < x ) return 0;
    
    if ( lo >= x && hi <= y )
        return T[node].sum + ( add * ( hi - lo + 1 ) );
    
    int mid = ( lo + hi ) >> 1;
    return query( LEFT( node ), lo, mid, x, y, add + T[node].toadd ) +
           query( RIGHT( node ), mid + 1, hi, x, y, add + T[node].toadd );    
}

int main()
{
    cin >> N >> Q;
    while ( Q-- )
    {
        char order;
        cin >> order;
        if ( order == 'A' )
        {
            cin >> x >> y >> z;
            update( 1, 1, N, x, y, z );  
        }
        if ( order == 'Q' )
        {
            cin >> x >> y;
            cout << query( 1, 1, N, x, y, 0 ) << endl;        
        }
    }

    return 0;
}
