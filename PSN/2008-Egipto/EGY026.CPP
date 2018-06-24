/*
 Reinier César Mujica
 27/3/08 PSN - 2008
*/

#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const int
    mx = 5002;
    
int n,sum,t[mx];
double s1,s2;

int main(){
    int i;
    freopen("stats.in","r",stdin);
    freopen("stats.out","w",stdout);
    scanf("%d",&n);
    for (i=1; i<=n; i++){
        scanf("%d",&t[i]);
        sum+=t[i];      
    }
    sort(t+1,t+n+1);
    s1=(double)sum / n;
    if (n % 2 == 0)
      s2=(double)(t[n/2] + t[(n/2)+1]) / 2;
    else
     s2=(double)t[(n/2)+1];
    printf("%lf\n",s1);
    printf("%lf\n",s2);
    fflush(stdout);
    return 0;   
}

/*26¦ Estadfsticas [Tradicional, 2008]                        Egipto 2008
 ----------------------------------------------------------------------

Las vacas se han matriculado en un curso de estadfstica bßsica y estßn 
pasando un mal tiempo con una tarea. Ay·delas, por favor.  

Dado un conjunto de N (1 <= N <= 500) n·meros, X_i (-5,000 <= X_i <= 
5000), calcule dos estadfsticas:

? La media (suma de los n·meros dividida por N).
? La mediana (si N es impar, el elemento medio cuando los N n·meros son 
ordenados, Si N es par, la media de los dos n·meros de la mitad cuando 
los n·meros son ordenados).

Su respuesta serß considera correcta si estß dentro de un rango de 0.002 
de la respuesta oficial.

NOMBRE DEL PROBLEMA: stats

FORMATO DE ENTRADA:

* Lfnea 1: Un solo entero: N

* Lfneas 2..N+1: La lfnea i+1 contiene un solo entero: X_i

ENTRADA EJEMPLO (archivo stats.in):

5
12
4
6
8
2

FORMATO DE SALIDA:

* Lfnea 1: La media del conjunto de entrada

* Lfnea 2: La mediana del conjunto de entrada

SALIDA EJEMPLO (archivo stats.out):

6.400000
6.000000

DETALLES DE LA SALIDA:

(12+4+6+8+2)/5=6.4
El n·mero de la mitad del conjunto {2, 4, 6, 8, 12} es 6

*/
