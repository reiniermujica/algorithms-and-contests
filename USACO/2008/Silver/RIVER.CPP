/*
 Reinier César Mujica
 28/3/08 PSN - 2008
*/

#include <cstdio>

const int
      mx = 2503;
      
int n,m,S[mx],B[mx],sol;

int main(){
    int i,j;
    freopen("river.in","r",stdin);
    freopen("river.out","w",stdout);
    scanf("%d %d",&n,&m);
    for (i=1; i<=n; i++){
        scanf("%d",&j);
        S[i]=S[i-1] + j;
    }
    for (i=1; i<=n; i++){
        B[i]=S[i]+m;
        for (j=1; j<i; j++)
         B[i]<?=B[j] + S[i-j] + m;    
        B[i]+=m;
    }
    sol=B[n] - m;
    printf("%d\n",sol);
    fflush(stdout);
    return 0;   
}

/*31¦ Cruce de Rfo [Jeffey Wang, 2007]                        Egipto 2008
----------------------------------------------------------------------

El Granjero Juan estß llevando su reba±o de N vacas (1 <= N <=  2,500)
a  travTs de  las extensiones  de su  granja cuando  Tl se  encuentra
bloqueado por un rfo. Se dispone de una sola balsa para transporte.

GJ sabe que Tl debe estar en la balsa en todos los cruces y que a±adir
vacas a la balsa hace que ella atraviese mßs lentamente el rfo.

Cuando GJ estß solo en la balsa,  Tl puede cruzar el rfo en M  minutos
(1 <= M <=  1000). Cuando se a±ade  la vaca i, toma  M_i (1 <= M_i  <=
1000) minutos mßs cruzar el rfo que con i-1 vacas (esto es un total de
M+M_1 minutos  con una  vaca, M+M_1+M_2  con dos,  etc.). Determine el
tiempo mfnimo que le toma al Granjero Juan atravesar todas las vacas a
travTs del rfo (incluyendo el tiempo regresando para pasar mßs vacas).  

NOMBRE DEL PROBLEMA: river

FORMATO DE ENTRADA:

* Lfnea 1: Dos enteros separados por espacio: N y M

* Lfneas 2..N+1: La lfnea i+1 contiene un solo entero: M_i

ENTRADA EJEMPLO (archivo river.in):

5 10
3
4
6
100
1

DETALLES DE LA ENTRADA:

Hay 5 vacas.  El Granjero Juan  gasta 10 minutos  para cruzar solo  el
ri=, 13 con una vaca, 17 con dos vacas, 23 con tres, 123 con cuatro  y
124 con todas las cinco.


FORMATO DE SALIDA:

* Lfnea 1:  El tiempo mfnimo que le toma al Granjero Juan para 
     atravesar el rfo con todas las vacas

SALIDA EJEMPLO (archivo river.out):

50

DETALLES DE LA SALIDA:

El  Granjero Juan  puede cruzar  primero el  rfo con  tres vacas  (23
minutos), luego devolverse (10 minutos),  y luego con las ·ltimas  dos
(17 minutos). 23+10+17 = 50 minutos en total.   
*/
