/*
 Reinier César Mujica
 27/3/08 PSN - 2008
*/

#include <cstdio>

const int
    mx = 102,
    mt = 16,
    mov[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};

int n,m,p[4],t[mt][mx][mx],ti;
char ma[mx][mx];
    
int main(){
    int i,j,k,x,cx,cy;
    freopen("ctravel.in","r",stdin);
    freopen("ctravel.out","w",stdout);
    scanf("%d %d %d",&n,&m,&ti);
    for (i=1; i<=n; i++)
     scanf("%s",&ma[i][1]);
    scanf("%d%d%d%d",&p[0],&p[1],&p[2],&p[3]);
    t[0][p[0]][p[1]]=1;
    for (k=1; k<=ti; k++)
     for (i=1; i<=n; i++)
      for (j=1; j<=m; j++)
        if (ma[i][j] != '*'){
         for (x=0; x<4; x++){
          cx=i+mov[x][0];
          cy=j+mov[x][1];
          t[k][i][j]+=t[k-1][cx][cy];
         }   
        }       
    printf("%d\n",t[ti][p[2]][p[3]]);        
    fflush(stdout);
    return 0;            
}

/*
30¦ Viaje Vacuno [Aram Shatakhtsyan, 2007]                  Egipto 2008
 ----------------------------------------------------------------------

Buscando por el mejor pasto,  las vacas estßn paseando en  el pastizal
el cual estß representado como una cuadricula con N filas y M columnas
(2 <=  N <=  100, 2  <= M  <= 100).   Siendo un  observador agudo,  el
Granjero Juan  ha registrado  la posici=n  de Bessie  como (R1, C1) en
cierto momento  y luego  como (R2,  C2) exactamente  T (0  < T  <= 15)
segundos despuTs. El no estß seguro si ella pas= a travTs de (R2,  C2)
antes de los T segundos, pero Tl  sabe que ella estß ahf en el  tiempo
T.

GJ quiere un programa que use esta informaci=n para calcular un entero
S que es el n·mero de maneras que una vaca puede ir de (R1, C1) a (R2,
C2)  en  exactamente  T  segundos. En  cada  segundo,  una  vaca puede
desplazarse de  cualquier posici=n  a una  posici=n vecina  vertical u
horizontalmente en el pastizal (no  hay descanso para las vacas).  Por
supuesto, el  pastizal tiene  ßrboles por  los que  ninguna vaca puede
pasar. 

Dado un  mapa con  '.'s  para  espacios abiertos  y '*'s para ßrboles,
calcule el n·mero de posibles maneras de ir de (R1, C1) a (R2, C2) en 
T segundos. 
 
NOMBRE DEL PROBLEMAS: ctravel

FORMATO DE ENTRADA:

* Lfnea 1: Tres enteros separados pro espacios: N, M y T

* Lfneas 2..N+1: La lfnea i+1  describe la fila i del pastizal con 
     exactamente M caracteres, cada uno de los cuales es un '.' o un '*'

* Lfnea N+2: Cuatro enteros separados por espacios: R1, C1, R2, y C2.

ENTRADA EJEMPLO (archivo ctravel.in):

4 5 6
...*.
...*.
.....
.....
1 3 1 5

DETALLES DE LA ENTRADA:

El pastizal  tiene 4  filas y  5 columnas.  La vaca  va de  la fila 1,
columna  3 a  la fila  1, columna  5, lo  cual le  toma exactamente  6
segundos.

FORMATO DE SALIDA:

* Lfnea 1: Una sola lfnea con el entero S antes descrito


SALIDA EJEMPLO (archivo ctravel.out):

1

DETALLES DE LA SALIDA:

Hay solamente un camino de (1,  3) a (1, 5) en exactamente  6 segundos
(y es obvio que es uno que rodea los dos ßrboles).
*/
