/*
ID: reywork2
PROG: milk
LANG: C++
*/

#include <fstream>
#define mx 5002
using namespace std;

long n,m,sol,act,t[mx][2];

void swap(long *a,long *b){
     long t;
     t=*a; *a=*b; *b=t;
     }

void qsort(long ini,long fin){
     long i,j,k;
     i=ini; j=fin; k=t[(i+j) / 2][0];
     while (i < j){
      while (t[i][0] < k) i++;
      while (t[j][0] > k) j--;
      if (i <= j){
       swap(t[i][0],t[j][0]);
       swap(t[i][1],t[j][1]);
       i++; j--;
      }
     }
     if (i < fin) qsort(i,fin);
     if (j > ini) qsort(ini,j);
     }

int main(){
    long i,res;
    ifstream fe("milk.in");
    ofstream fs("milk.out");
    fe >> n >> m;
    for (i=1; i<=m; i++)
     fe >> t[i][0] >> t[i][1];
    qsort(1,m);
    act=n; i=0; sol=0;
    while (act > 0){
      i++;
      if (act - t[i][1] >= 0) res=t[i][1];
                         else res=act;
      sol+=(t[i][0] * res);
      act-=res;
    }
    fs << sol << '\n';
    return 0;
}
