//Reinier César Mujica
//7/3/08 2:20 p.m

#include <cstdio>
#include <algorithm>

using namespace std;

const int
    mx = 50002;
    
struct cow{
    int a,b,p;
};
    
int n,k,sol;
cow t[mx];

bool cmp(const cow &a,const cow &b){
     return (a.a > b.a);
}

int main(){
    int i,j,k;
    freopen("elect.in","r",stdin);
    freopen("elect.out","w",stdout);
    scanf("%d %d",&n,&k);
    for (i=0; i<n; i++){
     scanf("%d %d",&t[i].a,&t[i].b);
     t[i].p=i+1;
    }
    sort(t,t+n,cmp); j=0;
    for (i=0; i<k; i++){
      if (t[i].b  > j){
        j=t[i].b;
        sol=t[i].p;
      }
    }
    printf("%d\n",sol);
    fflush(stdout);
    return 0;
}
