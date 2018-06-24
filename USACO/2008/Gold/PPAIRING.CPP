/*
 Reinier César Mujica
 3/4/08  PSN - 2008
*/

#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

const int
	mx = 100050;

typedef pair <int,int> par;

int n,m,c1[mx],c2[mx];
priority_queue < par, vector <par>, greater <par> > Q;

int main(){
	int i,k;
	freopen("ppairing.in","r",stdin);
	freopen("ppairing.out","w",stdout);
	scanf("%d %d",&n,&m);
	for (i=1; i<=m; i++){
		scanf("%d",&k);
		Q.push(make_pair(k,i));
	}
    while (!Q.empty()){
      int cos = Q.top().first;
      int col = Q.top().second;
      Q.pop();
      while (cos){
        if (c1[0] < n/2) c1[++c1[0]]=col; 
        else
        c2[++c2[0]]=col;
        cos--;
      }
	}
	for (i=1; i<=n/2; i++)
	 printf("%d %d\n",c1[i],c2[i]);
    fflush(stdout);
	return 0;  
}
