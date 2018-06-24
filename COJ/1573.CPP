#include <cstdio>
#include <cstring>

using namespace std;

int T;
int len;
char N[20];
bool even[256];

int main()
{
    /* compute vals */
    even['0'] = even['2'] = even['4'] = even['6'] = even['8'] = true;
    even['A'] = even['C'] = even['E'] = true;
        
    scanf( "%d\n", &T );
    while ( T-- )
    {
        gets( N );
        len = strlen( N );
        if ( even[N[len-1]] )
            printf( "NO\n" );
        else
            printf( "YES\n" );
    }

    return 0;
}
