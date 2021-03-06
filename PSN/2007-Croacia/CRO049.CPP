//Reinier C�sar Mujica
//14/3/08 PSN - 2008
//Sweep Line O(m)

#include <cstdio>

const int
      mx = 1<<21;
      
int n,m,sol[2],ini[mx],fin[mx],cont;

int main(){
    int i,a,b;
	freopen("tareas.in","r",stdin);
	freopen("tareas.out","w",stdout);	
	scanf("%d %d",&n,&m);
	for (i=0; i<n; i++){
		scanf("%d %d",&a,&b);
		ini[a]++; fin[b]++;
	}
	for (i=1; i<=m; i++){
		cont+=ini[i];
		if (cont > sol[0]){
			sol[0]=cont;
			sol[1]=i;
		}
		cont-=fin[i];
	}
    printf("%d %d\n",sol[1],sol[0]);
	fflush(stdout);
	return 0;
}

/*49� Tareas.                                               Croacia 2007
---------------------------------------------------------------------- 

Mario est� muy ocupado en su trabajo ,el SMA. Como �l es el �nico  que
trabaja en la computadora, simempre est� sobrecargado de tareas.

En la unidad Mario tiene N (1<=N<=10000) jefes. Cada jefe le da una  y
solo una  orden, es  decir el  recibir� N  tareas, estas  son dadas un
instante de M minutos, es decir que el recibir� tareas entre el minuto
1  y el  minuto M  (pueden existir  minutos el  los que  no tenga  que
trabajar).  Una   tarea  est�   definida  por   dos  enteros   a  y  b
(1<=a<=b<=10^6),  donde  a  es  el   minuto  de  inicio  y  b   el  de
finalizaci�n. Es decir Mario estar�a realizando esa tarea entre a y b,
ambos inclusive.

Por suerte  Mario es  muy inteligente  y el  puede estar trabajando en
cualquier minuto en una infinita cantidad de tareas.

No obstante el est� muy cansado pues la noche anterior estuvo  jugando
StarCraft. Por eso el pidi�  un descanso. Pero aqu� los  descansos son
muy cortos por lo que su descanso es de solo un minuto.

Ayude a Mario a saber cual es  el minuto donde el realice la mayor  de
tareas al mismo tiempo.

TAREA
 - Lea de la entrada la configuraci�n de las tareas a realizar.
 - Calcule el minuto en el que se realizan la mayor cantidad de tareas.
 - Escriba el resultado en un fichero de salida.

ENTRADA

El  fichero de  entrada TAREAS.IN  contiene en  la primera  l�nea  los
enteros N y M, qie representan la cantidad de jefes y el m�ximo  valor
que  puede alcanzar  los minutos  respectivamente. En  las pr�ximas  N
l�neas  aparecen dos  enteros ai  y bi  describiendo cada  una de  las
tareas.

SALIDA

El  fichero de  salida TAREAS.OUT  contiene en  la primera  l�nea  dos
enteros separados por un espacio que representan el minuto m�s ocupado
y la cantidad de tareas que se realizan en este.

+-----------+ +------------+
� TAREAS.IN � � TAREAS.OUT �
+-----------� +------------�
� 3 10      � � 5 3        �
� 1 5       � +------------+
� 5 10      �
� 3 8       �
+-----------+


*/
