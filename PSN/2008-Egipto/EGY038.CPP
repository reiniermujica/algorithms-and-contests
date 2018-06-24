/*
 Reinier César Mujica
 2/4/08 PSN - 2008
*/

#include <cstdio>
#include <algorithm>

using namespace std;

#define INP "INPUT.TXT"
#define OFF "OFFER.TXT"
#define OUT "OUTPUT.TXT"

using namespace std;

const int
      mx = 6,
      mc = 1001;

struct pro{
     int id,cant,cost;       
};

int N,C,R,sol,act,dp[mx][mx][mx][mx][mx],id[mc],cost[mc],cant[mc];
pro T[mx],O[mc][mc];

int main(){
    int i,j,k,l,m,p,s,n;
    freopen(INP,"r",stdin);
    scanf("%d",&N);
    for (i=1; i<=N; i++)
     scanf("%d %d %d",&T[i].id,&T[i].cant,&T[i].cost);    
    for (i=1; i<=N; i++) id[T[i].id]=i;
    fflush(stdin);     
    /*..Offers..*/    
    freopen(OFF,"r",stdin);
    scanf("%d",&C);
    for (i=1; i<=C; i++){
        scanf("%d",&p);
        cant[i]=p;
        for (j=1; j<=p; j++){
            scanf("%d %d",&O[i][j].id,&O[i][j].cant);
        }    
        scanf("%d",&s);
        cost[i]=s;
    }
    fflush(stdin);
    /*..Dp..*/
    memset(dp,63,sizeof(dp));
    dp[0][0][0][0][0]=0;
    for (i=0; i<=T[1].cant; i++)
     for (j=0; j<=T[2].cant; j++)
      for (k=0; k<=T[3].cant; k++)
       for (l=0; l<=T[4].cant; l++)
        for (m=0; m<=T[5].cant; m++){
            /*..Regular Costs..*/
            act=dp[i][j][k][l][m];
            if (i+1 <= T[1].cant)
             dp[i+1][j][k][l][m]<?=act + T[1].cost;
            if (j+1 <= T[2].cant)
             dp[i][j+1][k][l][m]<?=act + T[2].cost;
            if (k+1 <= T[3].cant)
             dp[i][j][k+1][l][m]<?=act + T[3].cost;
            if (l+1 <= T[4].cant)
             dp[i][j][k][l+1][m]<?=act + T[4].cost;
            if (m+1 <= T[5].cant)
             dp[i][j][k][l][m+1]<?=act + T[5].cost;
            /*..Offers..*/
            for (n=1; n<=C; n++){
                int ic[5]={i,j,k,l,m};
                for (int q=1; q<=cant[n]; q++)
                 ic[id[O[n][q].id]-1]+=O[n][q].cant;
                bool ok=true;
                for (int q=0; q<5; q++)
                 if (ic[q] > T[q+1].cant){
                    ok=false;
                    break;
                 }
                if (ok)
                 dp[ic[0]][ic[1]][ic[2]][ic[3]][ic[4]]<?=act + cost[n];
            }
        }
    sol=dp[T[1].cant][T[2].cant][T[3].cant][T[4].cant][T[5].cant];
    freopen(OUT,"w",stdout);
    printf("%d\n",sol);
    fflush(stdout);
    return 0;   
}
