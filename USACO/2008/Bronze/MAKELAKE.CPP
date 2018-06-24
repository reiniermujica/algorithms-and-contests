/*
 Reinier César Mujica
 27/3/08 PSN - 2008
*/

#include <cstdio>

const int
    mx = 104,
    mov[6][2] = {{0,1},{1,0},{1,1},{0,0},{2,1},{1,2}};
    
int n,m,b,l,t[mx][mx],sum;

void chuck(int x,int y,int c){
     int i,cx,cy,best=0;
     for (i=0; i<4; i++){
          cx = x + mov[i][0];
          cy = y + mov[i][1];
          best>?=t[cx][cy];
          cx = cx + mov[i][0];
          cy = cy + mov[i][1];
          best>?=t[cx][cy];
     }
     for (i=4; i<6; i++){
        cx = x + mov[i][0];
        cy = y + mov[i][1];
        best>?=t[cx][cy];    
     }
     best-=c;
     for (i=0; i<4; i++){
          cx = x + mov[i][0];
          cy = y + mov[i][1];
          if (t[cx][cy] >= best) t[cx][cy]=best;
          cx = cx + mov[i][0];
          cy = cy + mov[i][1];
          if (t[cx][cy] >= best) t[cx][cy]=best;
     }   
     for (i=4; i<6; i++){
        cx = x + mov[i][0];
        cy = y + mov[i][1];
        if (t[cx][cy] >= best) t[cx][cy]=best;
     }
}

int main(){
    int i,j,x,y,d;
    freopen("makelake.in","r",stdin);
    freopen("makelake.out","w",stdout);
    scanf("%d%d%d%d",&n,&m,&b,&l);
    for (i=1; i<=n; i++)
     for (j=1; j<=m; j++){
        scanf("%d",&t[i][j]);       
     }   
    for (i=1; i<=l; i++){
        scanf("%d%d%d",&x,&y,&d);
        chuck(x,y,d);   
    }
    for (i=1; i<=n; i++)
     for (j=1; j<=m; j++){
        if (t[i][j] >= b) t[i][j]=0;
        else t[i][j]=b - t[i][j];
        sum+=t[i][j];
     }
    printf("%d\n",sum*72*72);   
    return 0;
}

/*27¦ Haciendo un Lago [Rob Kolstad, 2008]                    Egipto 2008
 ----------------------------------------------------------------------

El Granjero Juan quiere que sus vacas le ayuden a hacer un lago. El ha
hecho un mapa con  el pastizal donde el  quiere crear el lago  con una
cuadrfcula de R (3 <= R <= 100)  filas por C (3 <= C <= 100)  columnas
de  cuadrados  de seis  pies  por seis  pies  y luego  determinado  la
elevaci=n  promedio (10  <= elev_rc  <= 5000)  en pulgadas  para cada
cuadrado.

Adicionalmente,  Tl  ha  entrenado  a  sus  vacas  en  "excavaci=n por
pisoteo". Las robustas  bovinas cubren con  un reba±o exactamente  una
cuadricula de 3x3 cuadrados cuya coordenada superior izquierda es R_s,
C_s (1 <= R_s <= R-2; 1 <= C_s <= C-2). Las vacas entonces pisotean la
tierra para disminuir  su altura D_s  (1 <= D_s  <= 40) pulgadas.  Las
vacas son bastante meticulosas; las vacas en elevaciones mßs altas  no
comenzarßn pisoteando hasta que el resto del reba±o se les haya unido.
Por lo tanto, no toda  la gradilla 3x3 es necesariamente  pisoteada (o
tal vez alguna parte es menos pisoteada que alguna otra parte).

Dados un conjunto inicial de elevaciones, un conjunto ordenado de N (1
<=  N  <=  20000)  instrucciones  de  excavaci=n  por  pisoteo,  y una
elevaci=n E (0 <= E <=  5000) para el nivel final del  lago, determine
el volumen  de agua  (en pulgadas  c·bicas) que  contendrß el lago. Se
garantiza que  la respuesta  no excederß  2,000,000,000. Asuma  que el
borde del  lago contiene  barreras de  tal manera  que no  saldrß agua
sobre el borde.

Considera un pastizal peque±o 4x6 a ser convertido en un lago. Sus 
elevaciones iniciales (anotada con n·meros fila/columna) son:

                      columna
                  1  2  3  4  5  6
        fila 1:  28 25 20 32 34 36
        fila 2:  27 25 20 20 30 34
        fila 3:  24 20 20 20 20 30
        fila 4:  20 20 14 14 20 20


Interpretando el mapa, vemos una colina en la esquina superior derecha 
con una elevaci=n de 36; un colina peque±a tambiTn se alza con elevaci=n 
28 en la esquina superior izquierda. La mitad de la fila 4 tiene una 
ligera depresi=n. DespuTs de la instrucci=n de excavaci=n por  pisoteo
"1 
4 4", el pastizal tiene estas elevaciones:

                  1  2  3  4  5  6
        fila 1:  28 25 20 32 32 32
        fila 2:  27 25 20 20 30 32
        fila 3:  24 20 20 20 20 30
        fila 4:  20 20 14 14 20 20

Note que solamente  tres cuadrados fueron  pisoteados. Los otros  seis
conjuntos de vacas estaban  esperando que las pisoteadoras  llegaran a
su  nivel,  lo cual  nunca  sucedi=. DespuTs  de  pisotear la  esquina
superior izquierda  con la  instrucci=n "1  1 10",   el pastizal se ve
asf:

                  1  2  3  4  5  6
        fila 1:  18 18 18 32 32 32
        fila 2:  18 18 18 20 30 32
        fila 3:  18 18 18 20 20 30
        fila 4:  20 20 14 14 20 20

Si la elevaci=n final del lago debe ser 22 pulgadas, el pastizal tiene 
estas profundidades:

                  1  2  3  4  5  6
        fila 1:   4  4  4 -- -- --
        fila 2:   4  4  4  2 -- --
        fila 3:   4  4  4  2  2 --
        fila 4:   2  2  8  8  2  2

para un total de profundidad agregada de 66. Calcule el volumen 
multiplicando por 6 pies x 6 pies = 66 x 72 pulgadas x 72 pulgadas = 
342,144 pulgadas c·bicas.
        
Escriba un programa que automatice este cßlculo.

NOMBRE DEL PROBLEMA: makelake

FORMATO DE ENTRADA:

* Lfnea 1: Cuatro enteros separados por espacios: R, C, E, N

* Lfneas 2..R+1: La lfnea i+1 describe una fila de cuadrados i con C 
     enteros separados por espacios

* Lfneas R+2..R+N+1: La lfnea i+R+1 describe la instrucci=n de excavaci=n 
     por pisoteo i con tres enteros: R_s, C_S, y D_s

ENTRADA EJEMPLO (archivo makelake.in):

4 6 22 2
28 25 20 32 34 36
27 25 20 20 30 34
24 20 20 20 20 30
20 20 14 14 20 20
1 4 4
1 1 10


DETALLES DE LA ENTRADA:

Como en el ejemplo del texto.

FORMATO DE SALIDA:

* Lfnea 1: Un solo entero que es el volumen del nuevo lago en pulgadas 
     c·bicas.

SALIDA EJEMPLO (archivo makelake.out):

342144
*/
