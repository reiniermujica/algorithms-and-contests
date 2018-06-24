/*
 Reinier César Mujica
 27/3/08
*/

#include <cstdio>
#include <algorithm>

using namespace std;

const int
    mx = 1090;
    
int n,s,sol[2],t[mx][3];
bool mk[mx];

int main(){
    int i;
    freopen("rollers.in","r",stdin);
    freopen("rollers.out","w",stdout);
    scanf("%d",&n);
    for (i=1; i<=n; i++){
     scanf("%d %d %d",&t[i][0],&t[i][1],&t[i][2]);
     if (t[i][0] == 0 && t[i][1] == 0) s=i;  
    }
    bool ok=true;
    mk[s]=true;
    while (ok){
     bool is=false;
     for (i=1; i<=n; i++)
        if (s != i && !mk[i]){
         int d1=abs(t[i][0] - t[s][0]);
         int d2=abs(t[i][1] - t[s][1]);   
         int d3=t[s][2]+t[i][2];
         if ((d1*d1)+(d2*d2) == (d3*d3)){
          is=true;
          mk[i]=true;
          s=i;    
          break;  
         }      
        }       
     ok=is;
    }
    printf("%d %d\n",t[s][0],t[s][1]);
    return 0;   
}

/*
28¦ Ah Esos Rodillos [Rob Kolstad, 2007]                    Egipto 2008
 ----------------------------------------------------------------------

El Granjero Juan ha instalado un nuevo sistema de rodillos en contacto
que le da  una ventaja mecßnica  cuando levanta fardos  de heno dentro
del  establo.  El  sistema  fue  manufacturado  por  la  Compa±fa Rube
Goldberg Winch  y tiene  muchos rodillos.  El sistema  tiene una placa
grande de metal con un n·mero de rodillos cuya ·ltima fuente de  poder
es el rodillo  impulsor cuya ubicaci=n  Gj ha denotado  como el origen
(0, 0). Este rodillo impulsa un rodillo que impulsa otro rodillo, etc.
Etc.  Hasta que  se impulsa  el rodillo  final. GJ  estß tratando  de
encontrar ese rodillo final y quiere saber cußl es.



GJ ha  tomado registro  de las  coordenadas x_i,y_i  (-5,000 <= x_i <=
5,000; -5,000 <= y_i <= 5,000) uy los radios r_i (3 <= r_i <= 1024) de
cada uno de los N (2 <= N <= 1080) rodillos. Dfgale las coordenada  x,
y del ·ltimo rodillo en la  cadena (el rodillo que es impulsado,  pero
que  no  impulsa  ning·n  otro  rodillo).  Cada  rodillo,  excepto  el
impulsor, es impulsado 
exactamente por un solo rodillo.    
 
NOMBRE DEL PROBLEMA: rollers

FORMATO DE ENTRADA:

* Lfnea 1: Un solo entero: N

* Lfneas 2..N+1: La lfnea i+1 describe el rodillo i con tres enteros 
     separados por espacios: x_i, y_i, y r_i

ENTRADA EJEMPLO (archivo rollers.in):

3
0 0 30
30 40 20
-15 100 55

DETALLES DE LA ENTRADA:

Tres rodillos. El primero estß en el origen con radio 30. El impulsa el 
rodillo en (30, 40) cuyo radio es 20. Este a su vez impulsa el tercer 
rodillo ubicado en (-15,100) con radio 55.

FORMATO DE SALIDA:

* Lfnea 1: Una sola lfnea con dos enteros separados por espacio que son 
     respectivamente las coordenadas x,y del ·ltimo rodillo en la cadena 
     de rodillos impulsados.


SALIDA EJEMPLO (archivo rollers.out):

-15 100
*/
