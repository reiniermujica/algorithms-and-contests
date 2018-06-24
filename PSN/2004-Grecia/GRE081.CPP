/*
 Reinier César Mujica
 8/4/08  PSN - 2008
 
 La primera vez que lo teclee
 me dio con todos los jd
 Impresionante heee!!!
*/

#include <cstdio>
#include <cstring>

const int
    MAXN = 105;
    
int N, T[MAXN][MAXN], sol;
char cad[MAXN];

bool ispal( int x, int y ) {
     int i = x, j = y, k;
     while ( i < j ) {
        if ( cad[i] != cad[j] ) return false;
        i++; j--;
     }
     return true;
}

int main() {
    int i, j, k;
    freopen( "palin.in", "r", stdin );
    freopen( "palin.out", "w", stdout );
    scanf( "%s", cad + 1);
    N = strlen(cad + 1);
    /*..Fill..*/

    for ( i = 1; i <= N; i++ ) {
     T[i][i]=1; /*..Base Case..*/
     for ( j = i+1; j <= N; j++ )
      T[i][j]=j;
    }

    /*..Dynamic Progrmaing || Matrix Chain Multiplication..*/

    for ( i = 2; i <= N; i++ )
     for ( j = 1; j <= N-i+1; j++ ) {
      int h = j + i - 1;
      if (ispal(j,h)) T[j][h]=1;
      else
      for ( k = j; k <= h; k++ )
        T[j][h]<?=T[j][k] + T[k+1][h];
     }

    sol = T[1][N];
    printf( "%d\n", sol );
    fflush( stdout );
    return 0;
}

/*81¦ Palin.                                                 Grecia 2004
----------------------------------------------------------------------

Una palíndrome es  una palabra que  se lee lo  mismo adelante o  hacia
atrás. Si  una palabra  no es  palíndrome, esta  puede ser  cortada en
partes palíndromes. Escriba un programa que calcule el menor número de
partes palíndromes que puede  ser cortada una secuencia  de caracteres
dada.

Entrada (PALIN.IN)

La primera y única línea del fichero de entrada contiene una secuencia
de caracteres. Los caracteres  usados como entrada serán  del conjunto
de letras minúsculas  del alfabeto inglés  (a-z). La longitud  de cada
secuencia de entrada será cuando más 100.

Salida (PALIN.OUT)

La primera y única línea del fichero de salida debe contener el número
de palíndromes.

Ejemplos de Entrada y Salida

Ejemplo #1         Ejemplo #2        Ejemplo #3 
+--------+        +--------+        +-------------+
¦PALIN.IN¦        ¦PALIN.IN¦        ¦PALIN.IN     ¦
+--------¦        +--------¦        +-------------¦
¦anaban  ¦        ¦abaccbcb¦        ¦anavolimilana¦
+--------+        +--------+        +-------------+
+---------+       +----------+      +----------+
¦PALIN.OUT¦       ¦PALIN.OUT ¦      ¦PALIN.OUT ¦
+---------¦       +----------¦      +----------¦
¦2        ¦       ¦3         ¦      ¦5         ¦
+---------+       +----------+      +----------+

Explicaciones:

#1  a_naban
#2  aba_cc_bcb
#3  ana_v_o_limil_ana
*/
