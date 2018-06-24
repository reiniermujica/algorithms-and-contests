//Reinier César Mujica
//4/3/08 11:00 pm

#include <cstdio>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;

const 
 long long mx = 1002,
	       oo = LONG_LONG_MAX;

struct point{
	   int x,y;
};

int n,m;
point g[mx*mx];
long long t[mx][mx],d[mx*mx];
double sol;
bool mk[mx*mx];

void build_graph(){
	 int i,j;
	 long long h1,h2;
	 for (i=1; i<=n; i++)
   	  for (j=i+1; j<=n; j++){
      	  h1=abs(g[i].x - g[j].x);
	      h2=abs(g[i].y - g[j].y);
          t[i][j]=t[j][i]=h1*h1 + h2*h2;
      }
}

void prim_alg(){
     int i,j,k;
	 fill(d,d+n+1,oo);
	 d[1]=0;
	 for (i=1; i<=n; i++){
      k=0;
      for (j=1; j<=n; j++)
       if (!mk[j] && d[j] < d[k]) k=j;
      sol+=sqrt(d[k]);
      mk[k]=true;
      for (j=1; j<=n; j++)
       if (!mk[j] && d[j] > t[k][j])
        d[j]=t[k][j];
     }     
}

int main(){
	int i,x,y;
	freopen("roads.in","r",stdin);
	freopen("roads.out","w",stdout);
	scanf("%d %d",&n,&m);
	for (i=1; i<=n; i++)
    	scanf("%d %d",&g[i].x,&g[i].y);	
    build_graph();
	for (i=1; i<=m; i++){
		scanf("%d %d",&x,&y);
		t[x][y]=0;
		t[y][x]=0;
	}
    prim_alg();   
    printf("%.2lf\n",sol);
    fflush(stdout);
	return 0;
}
