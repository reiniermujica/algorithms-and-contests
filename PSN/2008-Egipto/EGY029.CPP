/*
 Reinier César Mujica
 27/3/08 PSN - 2008
*/

#include <cstdio>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

const int
    mx = 1100;
  
struct baler{
    int x,y,r;    
};

int n,x0,x1,s,f,sol;
bool mk[mx];
double sum[mx],v[mx];
baler T[mx];
queue < int > Q;

int main(){
    int i;
    freopen("baler.in","r",stdin);
    freopen("baler.out","w",stdout);
    scanf("%d%d%d",&n,&x0,&x1);
    for (i=1; i<=n; i++){
        scanf("%d%d%d",&T[i].x,&T[i].y,&T[i].r);
        if (T[i].x == 0 && T[i].y == 0) s=i;
        if (T[i].x == x0 && T[i].y == x1) f=i;        
    }
    Q.push(s); sum[s]=v[s]=10000;
    while (!Q.empty()){
      int x=Q.front();
      Q.pop();
      mk[x]=true;  
      for (i=1; i<=n; i++){
        if (i != x && !mk[i]){
          int d1=abs(T[i].x - T[x].x);
          int d2=abs(T[i].y - T[x].y);
          int d3=T[i].r + T[x].r;   
          if (d1*d1 + d2*d2 == d3*d3){
             mk[i]=true;
             v[i]=(double)v[x]*T[x].r / T[i].r;
             sum[i]=sum[x] + v[i];
             Q.push(i);
          }
        }      
      }
    }
    printf("%.0lf\n",floor(sum[f]));
    fflush(stdout);
    return 0;
}

/*
29¦  La Empacadora Repugnante de Heno [Rob Kolstad, 2008]   Egipto 2008
 ----------------------------------------------------------------------

El Granjero Juan ha comprado la empacadora de heno mßs repugnante  del
mundo. En lugar de tener  un rodillo impulsado que impulsa  un rodillo
sin impulso que maneja la salida de la empacadora, tiene N rodillos (2
<= N <= 1050) que impulsan y son impulsados por varios rodillos.

GJ ha catalogado datos meticulosamente  para cada rodillo i: X_i,  Y_i
son el  centro del  rodillo (-5000  <= X_i  <= 5000;  -5000 <=  Y_i <=
5000); R_i  es el  radio del  rodillo (3  <= R_i  <= 800).  El rodillo
impulsor estß ubicado en  0, 0; el rodillo  de salida estß ubicado  en
X_t, Y_t (n·meros proporcionados en la entrada).

El rodillo impulsor rota en  sentido horario (de las manecillas  de un
reloj) a 10,000  revoluciones por hora.  Su trabajo es  determinar las
velocidades de todos los rodillos que estßn en la maquinaria: desde el
rodillo  impulsor hasta  el rodillo  de salida.  Los rodillos  que no
transfieren fuerza al rodillo de  salida son ignorados. Un rodillo  de
radio Rd que  estß dando vueltas  con una velocidad  de S rph  y dando
impulso a otro rodillo con radio Rx causarß que el segundo rodillo  de
vueltas con  una velocidad  de -S*Rd/Rx  (donde el  signo denota si el
rodillo estß dando vueltas en sentido horario o antihorario).




Determine el camino de distribuci=n de fuerza y reporte la suma de los
valores  absolutos de  las velocidades  de todas  esas velocidades  de
rodillos. Todos  los rodillos  en el  conjunto de  entrada, excepto el
impulsor,  son impulsados por alg·n  otro rodillo; la fuerza nunca  es
transmitida a un rodillo por mßs de un rodillo. 

Reporte su respuesta que es un entero que es el valor truncado despuTs 
de sumar todas las velocidades.
 

NOMBRE DEL PROBLEMA: baler

FORMATO DE ENTRADA:

* Lfnea 1: Tres enteros separados por espacios: N, X_t, y Y_t

* Lfneas 2..N+1: La lfnea i+1 describe las propiedades del rodillo i: 
     X_i, Y_i, y R_i

ENTRADA EJEMPLO (archivo baler.in):

4 32 54
0 0 10
0 30 20
32 54 20
-40 30 20

DETALLES DE LA ENTRADA:

Cuatro rodillos: el rodillo impulsor  en 0,0 con radio 10.  Impulsa el
rodillo encima  de Tl  en 0,30  con radio  20. Ese  rodillo impulsa el
rodillo de salido en 32,54 (r=20) y un rodillo aleatorio (que no  estß
en el camino de distribuci=n de fuerza) en 40,30 (r=20).

FORMATO DE SALIDA:

* Lfnea 1: Un solo entero que es la versi=n truncada de la suma de los 
     valores absolutos de las velocidades de los rodillo en el camino  
     de distribuci=n de fuerza incluyendo el rodillo impulsador, todos  
     los rodillos impulsados, y el rodillo de salida. 

SALIDA EJEMPLO (archivo baler.out):

20000

DETALLES DE LA SALIDA:


 Rodillo   Radio     Velocidad
1 (0,0)     10       10,000
2 (0,30)    20       -5,000
3 (32,54)   20        5,000
                     ------
Suma de valores abs: 20,000
*/
