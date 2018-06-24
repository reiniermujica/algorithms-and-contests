/*
 Reinier César Mujica
 28/3/08 PSN - 2008
*/

#include <cstdio>
#include <string>

const int
      mx = 1000001,
      mv = 100;
      
int n,m,act;
char T[mx],P[mv],ac[mv];

int main(){
    int i,j,k;
    freopen("niz.in","r",stdin);
    freopen("niz.out","w",stdout);
    scanf("%d",&n);
    for (i=1; i<=n; i++){
        itoa(i,ac,10);
        for (j=0; j<strlen(ac); j++)
         T[++m]=ac[j];    
    }
    itoa(n,P+1,10);
    act=strlen(P+1);
    /*...Brute Force...*/
    for (i=1; i<=m-act+1; i++){
     j=1;
     while (T[i+j-1] == P[j] && j<=act) j++;
     if (j > act){
        printf("%d\n",i);      
        break;   
     }
    }
    fflush(stdout);
    return 0;    
}

/*
70¦ Niz.                                                  Polonia 2005
----------------------------------------------------------------------

Una secuencia de dígitos  se obtiene escribiendo las  representaciones
decimales  decimales  de  todos   los  enteros  comenzando  con   1  y
continuando  consecutivamente  hasta  un  cierto  número  N  de manera
similar a esta: 12345678910111213141516171819202122 ... etc.

Tarea

Escribir un programa que calcule la posición de la primera  ocurrencia
de la reprtesentación decimal del número N en la secuencia.

Entrada

La primera  y única  línea del  fichero de  entrada NIZ.IN contiene al
entero N, 1  <= N <= 100,000.

Salida

La primera y única línea  del fichero de salida NIZ.OUT  debe contener
la posición de la primera ocurrencia de la representación decimal  del
número N en la secuencia.

Ejemplo de Entrada y Salida

Ejemplo # 1        Ejemplo # 2           Ejemplo # 3

+---------+        +---------+          +---------+
¦ NIZ.IN  ¦        ¦ NIZ.IN  ¦          ¦ NIZ.IN  ¦
+---------¦        +---------¦          +---------¦
¦ 15      ¦        ¦ 34      ¦          ¦ 142     ¦
+---------+        +---------+          +---------+
+---------+        +---------+          +---------+
¦ NIZ.OUT ¦        ¦ NIZ.OUT ¦          ¦ NIZ.OUT ¦
+---------¦        +---------¦          +---------¦
¦ 20      ¦        ¦ 3       ¦          ¦ 73      ¦
+---------+        +---------+          +---------+
*/
