#include <cstdio>
#include <algorithm>

using namespace std;

//Reinier César Mujica
//PSN - 2008 13/3/08

const int
	mx = 1002,
	oo = 1<<29;
	
struct point{
	int x,y;
};

int n,sol,act;
point t[mx],l[mx];

int mcd(int n1,int n2){
	if (n2 == 0) return n1;
	else return mcd(n2,n1 % n2);
}

bool cmp(const point &a,const point &b){
     if (a.x != b.x) return a.x < b.x;
	 else return a.y < b.y;
}

int main(){
	int i,j,x,y,k;
	scanf("%d %d",&x,&y);
	while (x != oo && y != oo){
	 n++;
	 t[n].x=x; t[n].y=y;
	 x=oo; y=oo;
	 scanf("%d %d",&x,&y);	 
	}
	l[0].x=oo; l[0].y=oo;
	for (i=1; i<=n; i++){
	 for (j=1; j<=n; j++){
	   x=t[i].x - t[j].x;
	   y=t[i].y - t[j].y;
	   k=mcd(abs(x),abs(y));
	   if (k != 0){
	     x/=k; y/=k;
	   }
	   l[j].x=x; l[j].y=y;
	 }
	 sort(l+1,l+n+1,cmp);	 
	 act=1; 
	 for (j=1; j<=n; j++){
	  if (l[j].x == l[j-1].x && l[j].y == l[j-1].y) act++;
	  else
	  {
	  sol>?=act;
	  act=1;
	  } 
	 }
	}
	printf("%d\n",sol+1);
	fflush(stdout);
	return 0;
}