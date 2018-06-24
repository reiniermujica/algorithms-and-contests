//Reinier César Mujica
//5/3/08 8:30 a.m.

#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const
 int mx = 5001,
	 oo = 1<<30;

struct point{
	int x,y;
};

int n,act,s[mx];
point t[mx];
double sol;

int cross_product(const point &a,const point &b,const point &c){
	int c1 = (a.x - c.x) * (b.y - c.y);
	int c2 = (b.x - c.x) * (a.y - c.y);
	return (c1 - c2);
}

bool cmp(const point &a,const point &b){
	 return cross_product(a,b,t[0]) > 0;
}
 
void calc_convex(){
	 int i;
	 for (i=0; i<3; i++) s[i]=i;
	 act=2;
	 for (i=3; i<=n; i++){
		 while (cross_product(t[i],t[s[act]],t[s[act-1]]) > 0) act--;
		 s[++act]=i;
	 }
}

int main(){
	int i,p;
	freopen("moat.in","r",stdin);
	freopen("moat.out","w",stdout);
	scanf("%d",&n);
	t[0].x=oo; t[0].y=oo;
	for (i=1; i<=n; i++){
     scanf("%d %d",&t[i].x,&t[i].y);
	 if (t[i].x < t[0].x || (t[i].x == t[0].x && t[i].y < t[0].y)){
		t[0].x=t[i].x; t[0].y=t[i].y;
		p=i;
	 }
	}
	swap(t[n],t[p]); n--;
	sort(t+1,t+n+1,cmp);
	calc_convex();
	s[++act]=0;
	for (i=1; i<=act; i++){
		int h1 = abs(t[s[i-1]].x - t[s[i]].x);
		int h2 = abs(t[s[i-1]].y - t[s[i]].y);
		sol+=sqrt(h1*h1+h2*h2);
	}
    printf("%.2lf\n",sol);
    fflush(stdout);
	return 0;
}
