//Renier César Mujica
//6/3/08 3:00 30s p.m

#include <cstdio>
#include <algorithm>

using namespace std;

const int
	mx = 350,
	oo = 1<<29,
	mov[5][2] = {{0,1},{1,0},{-1,0},{0,-1},{0,0}};

struct p{
	int x,y;
};

int n,sol=oo,act,cx,cy,xm=0,ym=0,t[mx][mx],best[mx][mx];
p sav[2][mx*mx];
bool mk[mx][mx];

void bfs(){
	 int i,j,x,y,cp=1,ch=0;
	 bool s=1;
	 sav[s][1].x=0; sav[s][1].y=0;
	 act=-1;
	 while (cp){
	  act++;
	  for (i=1; i<=cp; i++){
		x=sav[s][i].x; y=sav[s][i].y;
		for (j=0; j<4; j++){
		 cx=x + mov[j][0];
		 cy=y + mov[j][1];
		 if (cx >= 0 && cy >= 0 && cx <= xm && cy <=ym){
			if (t[cx][cy] == -1 && best[cx][cy] > act)                         
              best[cx][cy]=act+1;
			else
			if (t[cx][cy] > act+1 && !mk[cx][cy]){
				ch++;
				sav[!s][ch].x=cx;
				sav[!s][ch].y=cy;
				mk[cx][cy]=true;		
			}
		 } 
		}
	  }
	 cp=ch; 
	 ch=0;
	 s=!s;
	 }
}

int main(){
	int i,j,x,y,ti;
	freopen("meteor.in","r",stdin);
	freopen("meteor.out","w",stdout);
	scanf("%d",&n);
    for (i=0; i<mx; i++){
         fill(t[i],t[i]+mx,-1);
         fill(best[i],best[i]+mx,oo);
         }
	for (i=1; i<=n; i++){
		scanf("%d %d %d",&x,&y,&ti);
		xm=max(xm,x); ym=max(ym,y);
		for (j=0; j<5; j++){
			cx=x + mov[j][0]; cy=y + mov[j][1];
			if (cx >= 0 && cy >= 0)
			 if (t[cx][cy] == -1 || t[cx][cy] > ti)
			  t[cx][cy]=ti;		
		}
	}
	xm+=2; ym+=2;
 	bfs();
	for (i=0; i<=xm; i++)
	 for (j=0; j<=ym; j++)
	  if (best[i][j] != oo)
	   sol=min(best[i][j],sol);
	if (sol == oo) printf("%d\n",-1);
	else printf("%d\n",sol);
	fflush(stdout);
	return 0;
}
