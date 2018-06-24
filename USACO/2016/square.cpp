/*
 
*/

#include <cstdio>
#include <algorithm>

using namespace std;
	
int max_x = 0, max_y = 0;
int min_x = 10000, min_y = 10000;
int x1, y1, x2, y2;

int main() {
	
	freopen( "square.in", "r", stdin );
	freopen( "square.out", "w", stdout );
	
	scanf( "%d %d %d %d", &x1, &y1, &x2, &y2 );
	max_x = max(x1, max_x);
	max_x = max(x2, max_x);
	
	max_y = max(y1, max_y);
	max_y = max(y2, max_y);
	
	min_x = min(x1, min_x);
	min_x = min(x2, min_x);
	
	min_y = min(y1, min_y);
	min_y = min(y2, min_y);
	
	scanf( "%d %d %d %d", &x1, &y1, &x2, &y2 );
	max_x = max(x1, max_x);
	max_x = max(x2, max_x);
	
	max_y = max(y1, max_y);
	max_y = max(y2, max_y);
	
	min_x = min(x1, min_x);
	min_x = min(x2, min_x);
	
	min_y = min(y1, min_y);
	min_y = min(y2, min_y);
	
	x1 = max_x - min_x;
	y1 = max_y - min_y;
	
	int sol = max( x1, y1);
	
	printf("%d\n", sol * sol);
	return 0;
}
