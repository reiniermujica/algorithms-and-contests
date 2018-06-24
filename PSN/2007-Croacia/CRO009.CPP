/*
 Reinier César Mujica
 31/3/08 PSN - 2008
*/

#include <cstdio>
#include <algorithm>

using namespace std;


const int
      mx = 10001,
      mv = 105;
      
int n,m,d,cant,sol[mx];
int T[mx],P[mv];

int main(){
    int i,j;
    freopen("musica.in","r",stdin);
    freopen("musica.out","w",stdout);
    scanf("%d %d %d",&n,&m,&d);
    for (i=1; i<=n; i++) scanf("%d",&T[i]);
    for (i=1; i<=m; i++) scanf("%d",&P[i]);
    /*...Brute Force...*/
    for (i=1; i<=n-m+1; i++){
     j=1;
     while ((abs(T[i+j-1] - P[j]) <= d) && j<=m) j++;
     if (j > m) sol[++cant]=i;
    }
    printf("%d\n",cant);
    for (i=1; i<=cant; i++) printf("%d\n",sol[i]);
    fflush(stdout);
    return 0;    
}

/*9¦ Secuencias Musicales.                                  Croacia 2007
----------------------------------------------------------------------

Las  secuencias  musicales  pueden  ser  vistas  esquemáticamente como
secuencias de  números enteros,  representando las  notas en  notación
cromática o diatónica (codificación absoluta del tono, CAT)

Por ejemplo, la figura muestra una representación del acorde   C-menor
en codificación absoluta del tono

Note  que  de esta  forma  puede representarse  una  secuencia musical
usando un alfabeto cuyos símbolos son números enteros.

En  ocasiones  se  necesita buscar  una  ocurrencia  similar, pero  no
necesariamente idéntica, de una pequeña melodía dada en una  secuencia
musical. 

Dos   melodías    de  la   misma   longitud  concuerdan   si   en  sus
correspondientes representaciones   cada  uno  de los  números (tonos)
difiere cuando más en un valor límite d, previamente definido.

Por ejemplo, dada la secuencia musical: 
34, 61, 64, 59, 64, 66, 71, 73, 10, 94

Si se fija un valor de tolerancia  d = 1 entonces la melodía (60,  63,
67, 72) concuerda con la melodía (59, 64, 66, 71) que aparece a partir
del 4to  tono de la secuencia original.

El problema consiste en que dada una secuencia musical, una melodía, y
un  valor  de  tolerancia  d,  determinar  todas  las  melodías  en la
secuencia musical que concuerdan con la melodía dada según el valor de
tolerancia d

Tarea 

Hacer un programa que permita:

-	Leer desde fichero de  entrada MUSICA.IN una secuencia musical,  una
  melodía, y un valor de tolerancia d.
- Determinar todas las melodías en la secuencia musical que concuerdan
  con la melodía dada según el valor de tolerancia d.
-	Escribir hacia el fichero de salida MUSICA.OUT todos los tonos donde
  comienza la melodía encontrada en la secuencia musical.

Entrada

El  fichero de  entrada MUSICA.IN  contiene: 

Línea 1: N (1 <= N <= 10000), M (1 <= M <= 100) y d (1 <= d <= 1000)
separados  entre si   por  un espacio  en  blanco, los   cuales
representan la cantidad de  tonos de la secuencia musical, la cantidad
de tonos de la melodía a buscar y el valor de tolerancia d.
Línea 2: aparecen los N valores enteros positivos entre 0 y 10000  los
cuales representan a los tonos de la secuencia musical.
Linea 3: aparecen los M valores enteros positivos entre 0 y 10000  los
cuales representan a los tonos de la melodía a buscar.

Salida

El fichero de salida MUSICA.OUT contiene:
Línea 1: V cantidad de veces que apareció la melodía en la secuencia.
Línea 2..V+1: en cada línea aparecerá un entero que representa cada una
 de las posiciones de los tonos en la secuencia musical original donde 
 comienza a concordar la melodía.

Ejemplo de Entrada y Salida

Musica.in                                 Musica.out

10 4 1                                    1
34 61 64 59 64 66 71 73 10 94             4  
59 64 66 71

Musica.in                                 Musica.out

8 3 2                                     2
2 8 3 1 1 2 6 5                           3          
1 3 1                                     4
*/
