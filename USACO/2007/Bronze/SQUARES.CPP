#include <cstdio>

long n,i,j,sol;

void open(){
     freopen("squares.in","r",stdin);
     freopen("squares.out","w",stdout);
     scanf("%d",&n);
     }
     
int main(){
    open();
    sol=0;
    for (i=1; i<=n; i++)
     for (j=1; j<=n; j++)
         if (i*i == j*j + n)
               sol++;
    printf("%d\n",sol);
}

/*Problema 12: Cuadrados Perfectos [Neal Wu, 2007]

El Granjero Juan est  jugando un juego con Bessie. El elige dos
enteros positivos A y B (1 <= B <= A <= 500), y se supone que Bessie
debe deducir que n£meros él eligi¢. El le da a Bessie la siguiente
pista:

    Los n£meros que yo eleg¡ tienen la propiedad que el cuadrado del
    n£mero mayor es N (1 <= N <= 1,000) m s grande que el cuadrado del
    n£mero menor.

Siendo una vaca inteligente, Bessie sabe que esta pista reducir 
grandemente el n£mero de posibilidades para A y para B. Sin embargo,
ella est  solicitando su ayuda escribiendo un programa que calcule el
n£mero exacto de soluciones posibles.

NOMBRE DEL PROBLEMA: squares

FORMATO DE ENTRADA:

* L¡nea 1: Un solo entero: N.

ENTRADA EJEMPLO (archivo squares.in)

15

DETALLES DE LA ENTRADA:

¿Cu ntos pares de enteros positivos (A, B) satisfacen A^2 = B^2 + 15?

FORMATO DE SALIDA:

* L¡nea 1: Un solo entero representando el n£mero de soluciones
      posibles. 

EJEMPLO DE SALIDA (archivo squares.out):

2

DETALLES DE LA SALIDA:

Hay dos soluciones: (A, B) = (4, 1) y  (A, B) = (8, 7).  

*/
