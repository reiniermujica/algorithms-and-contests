/*
 Reinier César Mujica
 4/08/2008
 "Mensaje Secreto"
 Dinamica
*/

#include <cstdio>
#include <string>

using namespace std;

#define FOR( _i, _j, _k ) \
    for ( _i = (_j); _i <= (_k); _i++ )

const int
    MAXN = 1002,
    MAXM = 202,
    oo = 1 << 29;

int N, M, sol;
int i, j, k;
int cant[MAXM], dp[MAXN], last[MAXN];
int S[MAXM];
char cad[MAXN], L[MAXM][MAXM];

bool ok( int pos, int word ) {
     FOR( k, 1, cant[word] )
      if ( L[word][k] != cad[pos + k - 1] ) return false;
     return true;
}

int main() {

    scanf( "%d\n", &N );
    gets( cad + 1 );
    scanf( "%d\n", &M );
    FOR( i, 1, M ) {
      gets( L[i] + 1 );
      cant[i] = strlen( L[i] + 1 );
    }

    fill( dp, dp + MAXN, oo );
    dp[1] = 0;

    FOR( i, 1, M ) {
      for ( j = N - cant[i] + 1; j; j-- ) {
        if ( ok( j, i ) && dp[j] != oo ) {
            if ( dp[j + cant[i]] > dp[j] + 1 ) {
             dp[j + cant[i]] = dp[j] + 1;
             last[j + cant[i]] = i;
            }
        }
      }
    }

    printf( "%d\n", dp[N + 1] );
    k = N + 1;
    while ( last[k] ) {
      S[++sol] = last[k];
      k -= cant[last[k]];
    }

    for ( i = sol; i > 0; i-- )
     printf( "%s\n", L[S[i]] + 1 );

    fflush( stdout );
    return 0;
}

/*
11ş Mensaje secreto                                           USA 2003
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Un  mensaje  secreto  est   escrito  sin espacios entre las palabras y
contiene   solo  letras.  Otro  texto  de  la  misma  fuente  ha  sido
encontrado.  Los  expertos  conocen  que  el  mensaje ha sido escrito
seleccionando  algunas palabras del texto y escribi‚ndolas en el mismo
orden  que  aparecen  en este, una a continuaci¢n de otra sin espacios
entre  ellas.  Las  palabras del texto pueden ser utilizadas solamente
una vez en el mensaje.

Tarea

Escriba un programa que:
- Lea desde el fichero texto SECRET.IN el  mensaje secreto y el texto
  encontrado.
- Determine la m¡nima cantidad de palabras que se seleccionaron del
  texto para escribir el mensaje secreto.
- Escriba hacia el fichero texto SECRET.OUT la cantidad y las palabras
  seleccionadas.

Entrada

El fichero de entrada SECRET.IN tiene la siguiente estructura:
- L¡nea 1: Un entero N (1 <= N <= 1000) que representa la cantidad de
           letras que tiene el mensaje secreto.

- L¡nea 2: Contiene los N caracteres del mensaje secreto que pueden
           ser letras may£sculas y min£sculas del alfabeto ingl‚s.

- L¡nea 3: Est  escrito un entero M (1 <= M <= 150), el n£mero de
           palabras que contiene el texto encontrado.

- L¡nea 4..M+1: Contienen una palabra cada una, las cuales est n
           formadas por may£sculas y min£sculas del alfabeto ingl‚s.
           Ninguna palabra del texto tendr  m s de 200 caracteres.

Salida

El fichero de salida SECRET.OUT tiene la siguiente estructura:
- L¡nea 1: Un entero K, la cantidad m¡nima de palabras seleccionadas
           para escribir el mensaje.
- L¡nea 2..K+1: Deben escribirse las palabras seleccionadas del texto,
           en el mismo orden en que aparecen en la entrada.

Ejemplo de Entrada y Salida

ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿ ÚÄÄÄÄÄÄÄÄÄÄÄÄ¿
³ SECRET.IN      ³ ³ SECRET.OUT ³
ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´ ÃÄÄÄÄÄÄÄÄÄÄÄÄ´
³ 14             ³ ³ 2          ³
³ automaticainfo ³ ³ automatica ³
³ 7              ³ ³ info       ³
³ out            ³ ÀÄÄÄÄÄÄÄÄÄÄÄÄÙ
³ extra          ³
³ automatica     ³
³ metica         ³
³ window         ³
³ info           ³
³ system         ³
ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
*/
