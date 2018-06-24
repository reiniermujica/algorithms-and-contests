/*
 Reinier CÈsar Mujica
 21/05/08
 "Computadoras ExtraÒas"
*/

#include <cstdio>

#define REP( i, k , N ) for ( i = k; i <= N; i++ )

using namespace std;

const int
    MAXN = 202,
    oo = 1 << 29;

struct comp {
    int mem, mst, esl;
};

int N, i, j, k, limit, d1, d2;
int dp[MAXN][MAXN], M[MAXN], cut[MAXN][MAXN];
comp T[MAXN];
bool W[MAXN][MAXN];

void show( int ini, int fin ) {
     if ( ini < fin ) {
      show(ini, cut[ini][fin] );
      show(cut[ini][fin] + 1, fin );
      if ( W[ini][fin] )
       printf( "%d %d\n", cut[ini][fin], cut[ini][fin] + 1 );
      else
       printf( "%d %d\n", cut[ini][fin] + 1, cut[ini][fin] );
     }
}

int main() {

    freopen( "comp.in", "r", stdin );
    freopen( "comp.out", "w", stdout );
    
    scanf( "%d", &N );
    
    REP( i, 1, N ) {
     scanf( "%d %d %d", &T[i].mem, &T[i].mst, &T[i].esl );
     M[i] = T[i].mem + M[i - 1];
    }

    /* fill */
    REP( i, 1, N - 1 )
     REP( j, i + 1, N )
      dp[i][j] = oo;
     
    /* Matrix Chain Multiplication or DP ? */
    REP( i, 2, N )
     REP( j, 1, N - i + 1 ) {
      limit = j + i - 1;
      REP( k, j, limit - 1 ) {
        d1 = ((M[k] - M[j - 1]) * T[k].mst) + ((M[limit] - M[k]) * T[k+1].esl);
        d2 = ((M[k] - M[j - 1]) * T[k].esl) + ((M[limit] - M[k]) * T[k+1].mst);
        d1 += dp[j][k] + dp[k+1][limit];
        d2 += dp[j][k] + dp[k+1][limit];
        if ( dp[j][limit] > d1 ) {
          dp[j][limit] = d1;
          cut[j][limit] = k;
          W[j][limit] = true;
        }
        if ( dp[j][limit] > d2 ) {
          dp[j][limit] = d2;
          cut[j][limit] = k;
          W[j][limit] = false;
        }
      }
     }

    printf( "%d\n", dp[1][N] );
    show( 1, N );
    
    fflush( stdout );
    return 0;
}

/*
88◊ Computadoras extra∫as.                              Finlandia 2001
‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰

 Para que los estudiantes de la  PSN de  Inform†tica pudieran resolver
el problema  de  las  Calcoman°as, los profesores  ha  tra°do  para el
laboratorio N computadoras  muy  extra∫as,  las cuales ha colocado  en
una fila, una al lado de la otra. Con el objetivo de tener m†s memoria,
ellos han decido conectarlas, pero lo  ∏nico que tienen son N-1 cables
muy cortos, por lo  que  solamente  pueden  conectar  una  computadora
con  la que  se  encuentra  a su derecha, y a su izquierda en la fila,
excepto la primera y la ∏ltima que solo pueden ser conectadas con la de
la derecha y con la de la izquierda respectivamente. Esto  es posible,
ya  que  estas extra∫as m†quinas cuentan cada una con dos puertos para
conexiones.

 Los profesores lo ten°an todo listo para comenzar la conexi¢n de  las
m†quinas cuando se dieron cuenta   que: la  ∏nica forma de conectarlas
para usar las memorias de todas era mediante un software   muy extra∫o
que estas  tra°an residente,  el funcionamiento del software en  todas
las computadoras no era el mismo,  y  que  por  cierto  este  consum°a
una   gran  cantidad de  electricidad.  DespuÇs  de   leer  la  ayuda,
entonces  ya  conocen que el software funciona de la siguiente manera:

- para que dos m†quinas puedan ser conectadas una de ellas debe actuar
  como MASTER, y la otra como SLAVE.
- al conectarse las computadoras, la memoria con que trabaja  cada una
  de las conectadas, ser† entonces  la  suma de las  memorias de todas
  las  computadoras conectadas.
- en cada conexi¢n se consume  una  cantidad  de  electricidad  W  que
  puede ser  calculada como sigue:

    W =  Kmaster*MEMmaster + Ksalve*MEMslave

  donde:
  . MEMmaster es  la  memoria de  la computadora que fue  seleccionada
    como MASTER.
  . Kmaster, propiedad  de cada   computadora, llamado  coeficiente de
    consumo de electricidad cuando la m†quina act∏a como MASTER.
  . MEMslave es la memoria de la computadora que fue seleccionada como
    SLAVE.
  . Kslave, propiedad   de cada  computadora, llamado   coeficiente de
    consumo  de electricidad cuando la m†quina act∏a como SLAVE.

 Por ejemplo, suponga que tengamos  5  computadoras extra∫as   con las
 siguientes propiedades:

  Á‰‰‰‰‰‰‰‰‰‰‰‰·‰‰‰‰‰·‰‰‰‰‰·‰‰‰‰‰·‰‰‰‰‰·‰‰‰‰‰π
  ®Computadora ®  1  ®  2  ®  3  ®  4  ®  5  ®
  ˆ‰‰‰‰‰‰‰‰‰‰‰‰Â‰‰‰‰‰Â‰‰‰‰‰Â‰‰‰‰‰Â‰‰‰‰‰Â‰‰‰‰‰™
  ®Memoria     ®  7  ®  3  ®  6  ®  1  ®  5  ®
  ®Kmaster     ®  2  ®  1  ®  1  ®  9  ® 10  ®
  ®Kslave      ®  5  ®  4  ®  2  ®  2  ®  8  ®
  ˛‰‰‰‰‰‰‰‰‰‰‰‰‡‰‰‰‰‰‡‰‰‰‰‰‡‰‰‰‰‰‡‰‰‰‰‰‡‰‰‰‰‰˚

 Una  posible  forma  de  conectar  las computadoras haciendo 4
 conexiones.
Á‰·‰‰‰‰‰‰‰‰‰·‰‰‰‰‰‰‰‰‰·‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰·‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰π
® ® MASTER  ® SLAVE   ® CONSUMO DE ELECTRICIDAD  ® ESTADO DE LAS COMP.®
ˆ‰Â‰‰‰‰‰‰‰‰‰Â‰‰‰‰‰‰‰‰‰Â‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰Â‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰™
®1® (1)     ® (2)     ® 2*7 + 4*3 = 26           ® 1-2  3  4  5       ®
®2® (1,2)   ® (3)     ® 1*(7+3) + 2*6 = 22       ® 1-2-3   4  5       ®
®3® (4)     ® (5)     ® 9*1 + 8*5 = 49           ® 1-2-3  4-5         ®
®4® (1,2,3) ® (4,5)   ® 1*(7+3+6) + 2*(1+5) = 28 ® 1-2-3-4-5          ®
˛‰‡‰‰‰‰‰‰‰‰‰‡‰‰‰‰‰‰‰‰‰‡‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰‡‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰˚

 Al ver lo complicado que era conectar  estas extra∫as   computadoras,
y  que si no era  conectadas de forma ¢ptima se   derrochar°a una gran
cantidad  de electricidad, los profesores decidieron dejar esta  tarea
en manos de los  estudiantes, para as° ellos no tener nada que ver con
esto.  Como  los  profesores  sab°an  que  los  estudiantes eran   muy
perezosos, le  dijeron que si no conectaban las  computadoras gastando
la menor  cantidad  de  energ°a  posible, los obligar°a a "Ubicar  los
†tomos en la caja negra".

Tarea:

 Prepara un programa el cual determine como deben  ser conectadas  las
computadoras de tal forma que la cantidad de electricidad consumida sea
m°nima.

Entrada:

 El fichero de entrada con nombre COMP.IN tiene en su primera l°nea un
entero N (2 <= N <= 200), el  n∏mero de computadoras. En  las pr¢ximas
l°neas,  la  l°nea  i + 1 del fichero (representa a  la computadora i)
contiene tres  enteros  positivos  separados  por un  simple  espacio:
la memoria, el coeficiente  de   consumo  de  electricidad  cuando  la
m†quina act∏a como MASTER, y el coeficiente de consumo de electricidad
cuando  la   m†quina act∏a  como SLAVE respectivamente de  la  i-Çsima
computadora en la fila. Ninguno de  los enteros del fichero de entrada
excede a 1000.

Salida:

 El fichero de salida debe tener el nombre COMP.OUT y contener  en su
primera l°nea un entero que indique la cantidad m°nima de electricidad
usada para hacer las conexiones. En las pr¢ximas l°neas se describir†
como fueron hechas las conexiones, en su respectivo orden (una conexi¢n
por l°nea). Una conexi¢n es descrita mediante un  par de enteros i,j
que indican que la i-Çsima comutadora en la fila fue usada como MASTER
y la j-Çsima como SLAVE. Note que i = j ﬂ 1.

Ejemplo #1 de entrada y salida:      Ejemplo #2 de entrada y salida
Á‰‰‰‰‰‰‰‰‰‰‰‰‰π Á‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰π  Á‰‰‰‰‰‰‰‰‰‰‰‰‰π Á‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰π
® COMP.IN     ® ® COMP.OUT       ®  ® COMP.IN     ® ® COMP.OUT       ®
ˆ‰‰‰‰‰‰‰‰‰‰‰‰‰™ ˆ‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰™  ˆ‰‰‰‰‰‰‰‰‰‰‰‰‰™ ˆ‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰™
® 5           ® ® 125            ®  ® 6           ® ® 191            ®
® 7 2 5       ® ® 1 2            ®  ® 8 8 19      ® ® 3 2            ®
® 3 1 4       ® ® 2 3            ®  ® 3 4 1       ® ® 4 3            ®
® 6 1 2       ® ® 4 5            ®  ® 2 4 1       ® ® 6 5            ®
® 1 9 2       ® ® 3 4            ®  ® 7 2 6       ® ® 4 5            ®
® 5 10 8      ® ˛‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰˚  ® 8 7 2       ® ® 1 2            ®
˛‰‰‰‰‰‰‰‰‰‰‰‰‰˚                     ® 3 4 12      ® ˛‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰‰˚
                                    ˛‰‰‰‰‰‰‰‰‰‰‰‰‰˚
*/
