#include <cstdio>

using namespace std;

#define MAXN 10005

int N, sol;
int i, j, k;
bool mark[MAXN];

int main()
{
    scanf( "%d", &N );
    
    for ( i = 2; i < N; i++ )
    {

        if ( N % i == 0 || mark[i] )
        {
            if ( mark[i] ) continue;
            for ( j = 2; j * i <= N; j++ )
                mark[j * i] = true;
        }
        else sol++;
    }
    
    printf( "%d\n", sol + 1 );
    return 0;
}
