/*
 Reinier César Mujica
 7/4/08  PSN - 2008
 Using Segment Tree Algorithm
*/

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int
    MAXN = 300002, //se puede ahorrar memoria lo que
    MAXD = 205;    //ahorra no estoy  pa eso
    
int n,ans,M[MAXN],len[MAXN];
char t[MAXN][MAXD];

bool cmp(int a,int b){
     if (len[a] != len[b]) return len[a] < len[b];
     for (int i=0; i<len[a]; i++)
      if (t[a][i] != t[b][i])
        return t[a][i] < t[b][i];   
     return true;
}

int build(int node,int ini,int fin){
    if (ini == fin){
       M[node]=ini;
       return M[node]; 
    }    
    int med = (ini + fin) / 2;
    int d1 = build(node*2,ini,med);
    int d2 = build(node*2+1,med+1,fin);
    if (cmp(d1,d2))
      M[node]=d2;   
    else
      M[node]=d1;
    return M[node];    
}

int query(int node,int ini,int fin,int lo,int hi){
    if (ini > hi || fin < lo) return 0;
    if (ini >= lo && fin <= hi) return M[node];
    int med = (ini + fin) / 2;
    int d1 = query(node*2,ini,med,lo,hi);
    int d2 = query(node*2+1,med+1,fin,lo,hi);
    if (cmp(d1,d2)) return d2;
    else return d1;
}

int main(){
    int i,j,x,y=0;
    freopen("big.in","r",stdin);
    freopen("big.out","w",stdout);
    scanf("%d%d",&n,&ans);
    for (i=1; i<=n; i++){
     scanf("%s",&t[i]);   
     len[i]=strlen(t[i]);
    }
    build(1,1,n);
    for (i=1; i<=ans; i++){
     scanf("%d %d",&x,&y);
     int pos = query(1,1,n,x,y);
     printf("%s\n",t[pos]);   
    }
    return 0;    
}

/*128¦ Big Mean.                                             México 2006
----------------------------------------------------------------------

En la  preselección todos  los estudiantes  quieren participar  en las
olimpiadas,  pero  no  todos  pueden,  a  partir  de  este  año pueden
participar casi todos los estudiantes porque hay muchos eventos,  para
estos  eventos  los profesores  seleccionan  a los  estudiantes  de la
siguiente forma: entre  el estudiante K,K+1,K+2,...,Y  va a ir  el que
mayor promedio tenga entre todos ellos, el promedio de cada estudiante
es un número que estará entre 10^0 y 10^200.

Tarea.
Ayude a los profesores a determinar que estudiante irá al evento X.

Entrada

En la primera línea del  fichero de entrada BIG.IN habrán  dos números
3<=N<=100000, 1<=M<=100000  que serán  el número  de estudiantes  y la
cantidad de eventos que hay  en esa asignatura respectivamente. En  la
línea 2 y  hasta la N+1  habrá un número  por línea que  representa el
promedio del  i-ésimo estudiante.  En la  línea N+2  y hasta  la línea
N+M+1 habrán dos números enteros 1<=K<=N y K<Y<=N.

Salida.

En el fichero de  salida BIG.OUT habrán M números,  el i-ésimo  número
representa el promedio del estudiante que va al i-ésimo evento.

Ejemplo de entrada. (BIG.IN)
4 3
1
9
5
10
1 2
1 3
2 4

Ejemplo de salida. (BIG.OUT)
9
9
10

NOTA:  No se  le permite  usar Búfer,  en caso  contrario su  programa
obtendrá 0 puntos.
*/
