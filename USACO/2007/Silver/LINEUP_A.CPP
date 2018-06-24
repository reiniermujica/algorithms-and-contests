/*
 Reinier César Mujica
 7/4/08  PSN - 2008
 Using Segment Tree Algorithm
*/

#include <cstdio>
#include <algorithm>

using namespace std;

const int
    mx = 100001,
    oo = 1<<29;
    
int n,mi[2*mx],ma[2*mx],t[mx],l;

int build_ma(int node,int x,int y){
    if (x == y){
     ma[node]=t[x];
     return ma[node];
    }
    ma[node]=max(build_ma(node*2,x,(x+y)/2),
                 build_ma(node*2+1,(x+y)/2+1,y));
    return ma[node];    
}

int build_mi(int node,int x,int y){
    if (x == y){
     mi[node]=t[x];
     return mi[node];
    }
    mi[node]=min(build_mi(node*2,x,(x+y)/2),
                 build_mi(node*2+1,(x+y)/2+1,y));
    return mi[node];    
}

int query_ma(int node,int x,int y,int a,int b){
    if (x > b || y < a) return -1;
    if (x >= a && y <= b) return ma[node];
    return query_ma(node*2,x,(x+y)/2,a,b) >?
           query_ma(node*2+1,(x+y)/2+1,y,a,b);
}

int query_mi(int node,int x,int y,int a,int b){
    if (x > b || y < a) return oo;
    if (x >= a && y <= b) return mi[node];
    return query_mi(node*2,x,(x+y)/2,a,b) <?
           query_mi(node*2+1,(x+y)/2+1,y,a,b);
}

int main(){
    int i,x,y;
    freopen("lineup.in","r",stdin);
    freopen("lineup.out","w",stdout);
    scanf("%d%d",&n,&l);
    for (i=1; i<=n; i++)
     scanf("%d",&t[i]);
    build_ma(1,1,n); 
    build_mi(1,1,n);
    for (i=1; i<=l; i++){
     scanf("%d%d",&x,&y);    
     printf("%d\n",query_ma(1,1,n,x,y) - 
                   query_mi(1,1,n,x,y)); //query 
    }
    return 0;      
}
