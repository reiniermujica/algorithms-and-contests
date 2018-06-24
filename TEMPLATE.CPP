/*
 Reinier César Mujica
 X - X - 2009
*/

#include <cstdio>
#include <iostream>
#include <queue>
#include <deque>
#include <set>
#include <vector>
#include <stack>
#include <map>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

#define io freopen

#define FOR( _i, _n ) \
    for ( _i = 1; _i <= (_n); _i++ )

typedef long long int64;

const int
    MAXN = 10100,
    oo = 1 << 30;

struct X {
	int x, y, next;
	
	X ( int a = 0, int b = 0, int c = 0 ) {
		x = a; y = b; next = c;
	}
	
	bool operator < ( const X &other ) const {
		return x < other.x;
	}
};

int N, M, sol;
int i, j, k;

int main() {

    io( ".in", "r", stdin );
    io( ".out", "w", stdout );

    fflush( stdout );
    return 0;
}
