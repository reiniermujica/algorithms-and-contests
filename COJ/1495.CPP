#include <cstdio>
#include <algorithm>

using namespace std;

long long T[1005];
int N, i;

int main()
{
    scanf( "%d", &N );
    for ( i = 0; i < N; i++ )
	    scanf( "%lld", &T[i] );
    
    sort( T, T + N );
    for ( i = 0; i < N; i++ )
	    printf( "%lld\n", T[i] );
	
    return 0;
}
