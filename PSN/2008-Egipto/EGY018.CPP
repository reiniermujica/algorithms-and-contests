#include <cstdio>
#define mx 43

long n,m,sol=0,t[mx];

void cont(long x,long y){
     if (x == n){
        sol++;
        }
     else
     if (x < n){
     for (long i=y; i<=m; i++)
      if (x+i <= n) cont(x+i,i);
      else break;
     }
     }

void print(long x,long y,long c){
     long i;
     if (x == n){
        for (i=1; i<=c; i++)
         printf("%d ",t[i]);
        printf("\n");
        }
     else
     if (x < n)
     for (i=y; i<=m; i++)
      if (x+i <= n){
       t[c+1]=i;
       print(x+i,i,c+1);
      }
      else break;
     }

int main(){
    freopen("sn.in","r",stdin);
    scanf("%d%d",&n,&m);
    cont(0,1); //count the number of sums
    freopen("sn.out","w",stdout);
    printf("%d\n",sol);
    print(0,1,0); //print all solutions
    return 0;
}
