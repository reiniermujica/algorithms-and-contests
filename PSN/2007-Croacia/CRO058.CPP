#include <cstdio>

long n,m,cont=0;
bool mk[3000000];
main()
{
 int i,j,k;
 freopen("fireshow.in","r",stdin);
 freopen("fireshow.out","w",stdout);
 scanf("%d%d", &m, &n);
 for (i=1; i<=m; i++)
 {
  scanf("%d", &k);
  for (j=1; j <= n / k; j++)
    if (!mk[j*k])
     {
      mk[j*k]=true;
      cont++;
     }
 }
 printf("%d\n",cont);
}
/*¦ Espectáculo Pirotécnico.                              Croacia 2007
---------------------------------------------------------------------- 
   
Es Día de la Independencia, y el Granjero Juan ha llevado a sus  vacas
al espectáculo pirotécnico. Bessie se pregunta cuánto del  espectáculo
será posible que sea visto, pues ellas no podrán quedarse durante todo
el espectáculo.

El  espectáculo  presenta  C  (1 <=  C  <=  100)  cañones pirotécnicos
convenientemente numerados 1..C. El  cañón i tira fuegos  artificiales
cada T_i (1 <= T_i <= N) segundos (todos los tiempos en esta tarea son
segundos enteros).  En una  apertura espectacular,  todos los  cañones
disparan primero en  el tiempo 0.  Los fuegos son  visibles únicamente
durante el segundo en el cual  son lanzados desde el cañón. Las  vacas
permanecerán en  el espectáculo  desde el  tiempo 1  hasta el tiempo N
(1<= N <= 2,000,000).

Ayude a  Bessie a  averiguar en  cuántos tiempos  diferentes las vacas
serán capaces de ver fuegos artificiales durante el período de  tiempo
en que ellas están en el espectáculo.
        

NOMBRE DEL PROBLEMA: fireshow

FORMATO DE ENTRADA:

- Línea 1: Dos enteros separados por un espacio: C y N.

- Líneas 2..C+1: La línea i+1 contiene un solo entero T_i.

ENTRADA EJEMPLO (archivo fireshow.in):

2 20
4
6

DETALLES DE LA ENTRADA:

El  espectáculo  presenta  2 cañones:  uno  disparando  fuegos cada  4
segundos, el otro disparando  cada 6 segundos. Las  vacas permanecerán
en el espectáculo desde el tiempo 1 hasta el tiempo 20. A continuación
hay una tabla  mostrando los tiros  de fuegos y  el tiempo en  que las
vacas están presentes.

      VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV
2                                   2                                   2 ...
1           1     2     1           1           1     2     1           1 ...
+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+ ...
0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 
...
 

FORMATO DE SALIDA:

- Línea 1: Un solo entero que es el número de segundos distintos en el
       intervalo de tiempo desde 1 hasta N en que las vacas podrán ver
       fuegos.

SALIDA EJEMPLO (archivo fileshow.out):

7

DETALLES DE LA SALIDA:

Habrán fuegos en los tiempos 4, 6, 8, 12, 16, 18, y 20, para un  total
de 7 tiempos distintos. (Note que en el tiempo 12, donde ambos cañones
tiran fuegos simultáneamente, solo se cuenta una vez.) Vea el  gráfico
anterior.

*/
