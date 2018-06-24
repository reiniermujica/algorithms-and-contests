#include <iostream>

using namespace std;

int A, B, C;
int i, j, k;

struct card
{
    int t[3];
    
    card( int a, int b, int c )
    {
        t[0] = a; t[1] = b; t[2] = c;   
    }
};

bool isset( card a )
{
    return ( ( a.t[0] == a.t[1]) && ( a.t[0] == a.t[2] ) );
}

bool ispar( card a )
{
    return ( ( a.t[0] == a.t[1] ) || ( a.t[0] == a.t[2] ) || ( a.t[1] == a.t[2] ) );
}

int gethpar( card a )
{
    if ( ( a.t[0] == a.t[1] ) || ( a.t[0] == a.t[2] ) )
        return a.t[0];
    else return a.t[2];
}

int getupar( card a )
{
    if ( ( a.t[0] == a.t[1] ) )
        return a.t[2];
    if ( ( a.t[0] == a.t[2] ) )
        return a.t[1];
    return a.t[0];
}

bool compare( card a, card b )
{
     bool set1, set2;
     bool par1, par2;
     int p1 = 0, p2 = 0;
     int s1 = 0, s2 = 0;
        
     set1 = isset( a );
     set2 = isset( b );
     if ( set1 && !set2 ) return true;
     if ( !set1 && set2 ) return false;
     
     par1 = ispar( a );
     par2 = ispar( b );
     if ( par1 && !par2 ) return true;
     if ( !par1 && par2 ) return false;
     if ( par1 && par2 )
     {
        p1 = gethpar( a );
        p2 = gethpar( b );
        if ( p1 > p2 ) return true;
        if ( p1 < p2 ) return false;
        s1 = getupar( a );
        s2 = getupar( b );
        if ( s1 > s2 ) return true;
        if ( s1 < s2 ) return false;
        return false;        
     }
     return false;        
}

int main()
{
    cin >> A >> B >> C;
    while ( A && B && C )
    {
        card ent = card( A, B, C );
        card sol = card( 14, 14, 14 );
        
        for ( i = 1; i <= 13; i++ )
            for ( j = 1; j <= 13; j++ )
                for ( k = 1; k <= 13; k++ )
                {
                    card temp = card( i, j, k );
                    if ( compare( temp, ent ) )                        
                    {
                        if ( compare( sol, temp ) )
                        {                        
                            sol = temp;                                         
                        }
                    }
                }
        
        if ( sol.t[0] != 14 )
            cout << sol.t[0] << " " << sol.t[1] << " " << sol.t[2] << endl;
        else
            cout << "*" << endl;            
        
        cin >> A >> B >> C;            
    }
    
    return 0;
}
