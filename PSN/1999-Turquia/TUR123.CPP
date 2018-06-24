// Apilando Neveras  Turquia 123
// Reinier César Mujica   
// 20 Feb 08

#include <cstdio>

const int mx = 102, maxn = 4000000;

long n,sol=0,t[mx],best[mx][mx],cam[mx][mx][2];

void work(){
     long i,j,k,f,v1,v2;
     for (i=1; i<=n; i++)
      for (j=i+1; j<=n; j++)
       best[i][j]=maxn;
     for (i=2; i<=n; i++){  // size
      for (j=1; j<=n-i+1; j++){
       f = j + i - 1;
       for (k=j; k<f; k++){
        v1 = (t[k] - t[j-1]) * (f-k) + best[j][k] + best[k+1][f];
        v2 = (t[f] - t[k]) * (k-j+1) + best[j][k] + best[k+1][f];
        if (v1 < best[j][f]){
            best[j][f]=v1;
            cam[j][f][0]=k;
            cam[j][f][1]=0;
            }
        if (v2 < best[j][f]){
            best[j][f]=v2;
            cam[j][f][0]=k;
            cam[j][f][1]=1;
            }
        }
       }
      }
     sol=best[1][n];
     }
     
void print(long x,long y,long cont){
     if (cont == 1){
        if (cam[x][y][1] == 0)
         printf("(%d",t[x]-t[x-1]);
        else
         printf("%d)",t[x]-t[x-1]);
        }
     if (cont == 2){
        if (cam[x][y][1] == 0)
         printf("(%d->%d)",t[x]-t[x-1],t[y]-t[y-1]);
        else
         printf("(%d->%d)",t[y]-t[y-1],t[x]-t[x-1]);
        }
     else
     if (cont > 2)
     {
      printf("(");
      print(x,cam[x][y][0],cam[x][y][0]-x+1);
      printf("->");
      print(cam[x][y][0]+1,y,y-cam[x][y][0]);
     }
    }

int main(){
    int i;
    freopen("tur123.in","r",stdin);
    scanf("%d",&n);
    for (i=1; i<=n; i++){
        scanf("%d",&t[i]);
        t[i]+=t[i-1];
        }
    work();
    freopen("tur123.out","w",stdout);
    printf("%d\n",sol);
    print(1,n,n);
    printf(")");
    fflush(stdout);
    return 0;
    }
