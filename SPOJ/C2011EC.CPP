#include <iostream>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

#define MAXN 1000

struct edge
{
	int x, y, cost;
	edge( int a = 0, int b = 0, int c = 0 )
	{
		x = a; y = b; cost = c;
	}

	bool operator < ( const edge &o ) const
	{
		return cost < o.cost;
	}
} E[MAXN * MAXN];

int N = 1, sol = 0;
int i, j, k;
int M = 0;
string cad[MAXN];
char c;
int P[MAXN];

int find_set( int x )
{
	if ( x != P[x] )
		P[x] = find_set( P[x] );
	return P[x];
}
int main()
{
	while ( cin >> cad[N] )
	{
		N++;
	}
	N--;

	for ( i = 1; i <= N; i++ )
	{
		for ( j = 1; j <= N; j++ )
		{
				c = cad[i][j - 1];
				if ( c >= 'a' && c <= 'z' )
				{
					k = c - 96;
				}
				if ( c >= 'A' && c <= 'Z' )
				{
					k = c - 64 + 26;
				}
				if ( c == '0')
					k = 0;

				if ( i != j && k != 0 )
				{
					E[++M] = edge( i, j, k );
				}
				else
				{
					sol += k;
				}
		}
	}

	for ( i = 1; i <= N; i++ )
		P[i] = i;

	sort( E + 1, E + M + 1 );

	for ( i = 1; i <= M; i++ )
	{
		int x = E[i].x, y = E[i].y, c = E[i].cost;
		int px = find_set( x );
		int py = find_set( y );

		if ( px != py )
		{
			P[px] = P[py];
		}
		else
		{
			sol += c;
		}
	}

	int cont = 0;
	for ( i = 1; i <= N; i++ )
	{
		if ( P[i] == i ) cont ++;
	}

	if ( cont == 1 )
		cout << sol << endl;
	else
		cout << -1 << endl;

	return 0;
}
