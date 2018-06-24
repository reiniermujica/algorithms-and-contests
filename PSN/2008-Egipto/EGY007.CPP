#include <cstdio>
#define mx 10002

long n,m,sol,n1=mx,n2=mx,m1=0,m2=0;
char r[mx];

int main(){
long i,j;
    freopen("imagen.in","r",stdin); 
    freopen("imagen.out","w",stdout);
    scanf("%d%d",&n,&m);
    for (i=1; i<=n; i++){
        scanf("%s",&r); 
        for (j=0; j<m; j++){
         if (r[j]=='1'){
            if (m1 < i) m1=i;
            if (m2 < j) m2=j;
            if (n1 > i) n1=i;
            if (n2 > j) n2=j;
            }
       }            
      }
  if (m1==0) printf("%d\n",0);
   else printf("%d\n",(2*(m2-n2+1)) + (2*(m1-n1+1)));
  return 0;
}
