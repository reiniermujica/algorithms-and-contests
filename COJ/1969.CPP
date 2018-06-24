#include <cstdio>

using namespace std;

#define MAXN 10000

int N, sol;
int i, j, k;
int S[MAXN];
int last = 0, s = 0;
int cant = 0;

bool print(char c)
{
	printf( "%c\n", c );
	return true;
}

int main()
{
	scanf( "%d", &N );

	for ( i = 1; ; i++ )
	{
		S[i] = 2 * S[i - 1] + ( i + 2 );
		if ( S[i] >= N ) break;
	}
	k = i;

	bool ok = false;
	while ( !ok )
	{
		if ( N == S[k-1] + 1 )
			ok = print('m');
		else
		if ( k + 2 + S[k - 1] >= N && S[k - 1] + 1 <= N )
			ok = print('o');
		else
		{
			N = N - S[k-1] - (k + 2);
			while ( S[k] >= N ) k--;
			k++;
		}
	}

	return 0;
}
