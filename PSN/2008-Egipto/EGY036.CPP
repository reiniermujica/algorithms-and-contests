/*
 Reinier César Mujica
 27/3/08 PSN - 2008
*/

#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

const int
	mx = 302,
	oo = 1<<29,
	mov[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};

typedef pair < int,int > par;
	
int n,m,act,cant,t[mx][mx],c[mx][mx],p[mx],xi[2][2];
int sol[mx*mx][2],cam[mx][mx][2];
queue <par> Q;

int main(){
	int i,j,x,y,cx,cy;
	freopen("NSENSOR.in","r",stdin);
	freopen("NSENSOR.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%d%d%d%d",&xi[0][0],&xi[0][1],&xi[1][0],&xi[1][1]);
	scanf("%d",&cant);
	for (i=0; i<mx; i++){
	 fill(t[i],t[i]+mx,oo);
	}
	fill(p,p+mx,oo);
	for (i=1; i<=cant; i++){
		scanf("%d%d",&x,&y);
		t[x][y]=-1;
		p[x]<?=y;
	}
	/*..Bfs..*/
	Q.push(make_pair(xi[0][0],xi[0][1]));
	t[xi[0][0]][xi[0][1]]=0;
	while (!Q.empty()){
		x=Q.front().first;
		y=Q.front().second;
		Q.pop();
		for (i=0; i<4; i++){
			cx=x + mov[i][0];
			cy=y + mov[i][1];
			if (cx > 0 && cx <=n && cy > 0 && cy <=m && t[cx][cy] != -1){
				if (i==1 || i==3){
					if (p[x] < y){
					 if (t[cx][cy] > t[x][y]){
						t[cx][cy]=t[x][y];
						c[cx][cy]=c[x][y] + 1;
						cam[cx][cy][0]=x;
						cam[cx][cy][1]=y;
						Q.push(make_pair(cx,cy));
					 }
					}
					else
					if (t[cx][cy] > t[x][y] + 1){
						t[cx][cy]=t[x][y] + 1;
						c[cx][cy]=c[x][y] + 1;
						cam[cx][cy][0]=x;
						cam[cx][cy][1]=y;
						Q.push(make_pair(cx,cy));			
					}			
				}
				else
				if (t[cx][cy] > t[x][y]){
					t[cx][cy]=t[x][y];
					c[cx][cy]=c[x][y] + 1;
					cam[cx][cy][0]=x;
					cam[cx][cy][1]=y;
					Q.push(make_pair(cx,cy));	
				}
			}
		}
	}
	printf("%d\n",c[xi[1][0]][xi[1][1]]);
	printf("%d\n",t[xi[1][0]][xi[1][1]]);
    x=cam[xi[1][0]][xi[1][1]][0];
    y=cam[xi[1][0]][xi[1][1]][1];
    while (x != 0 && y != 0){
        act++;
		sol[act][0]=x;
		sol[act][1]=y;
		i=x;
		x=cam[x][y][0];
		y=cam[i][y][1];
    }
	for (i=act-1; i>=1; i--)
	 printf("%d %d\n",sol[i][0],sol[i][1]);
	printf("%d %d\n",xi[1][0],xi[1][1]);
	fflush(stdout);
	return 0;
}
