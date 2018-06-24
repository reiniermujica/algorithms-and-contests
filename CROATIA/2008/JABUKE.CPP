/*
Reinier César Mujica
27/3/08 4:00 p.m
*/

#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

struct ap{
	int x,y;
};

int n,sol;
double area;
ap t[4],m;

int cp(const ap &a,const ap &b,const ap &c){
	int c1 = (a.x - c.x) * (b.y - c.y);
	int c2 = (b.x - c.x) * (a.y - c.y);
	return abs(c1 - c2);
}

int main(){
	int i,j,k;
	for (i=1; i<=3; i++)
	 scanf("%d %d",&t[i].x,&t[i].y);
	area=(t[1].x * (t[2].y - t[3].y));
	area+=(t[2].x * (t[3].y - t[1].y));
	area+=(t[3].x * (t[1].y - t[2].y));
	area=abs(area) / 2;
	scanf("%d",&n);
	for (i=1; i<=n; i++){
		scanf("%d %d",&m.x,&m.y);
		if (cp(t[1],t[2],m) +
 		    cp(t[2],t[3],m) +
		    cp(t[3],t[1],m) == cp(t[1],t[2],t[3]))
		sol++;
	}
	printf("%.1lf\n",area);
	printf("%d\n",sol);
	fflush(stdout);
	return 0;
}
