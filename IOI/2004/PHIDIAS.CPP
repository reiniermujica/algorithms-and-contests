/*
 Reinier Cesar Mujica
 10/06/2008
 "Phidias"
*/

#include <cstdio>

using namespace std;

const int
    MAXN = 602;

int N, W, H;
int i, j, k;
int dp[MAXN][MAXN];

int main() {

    freopen( "phidias.in", "r", stdin );
    freopen( "phidias.out", "w", stdout );
    
    scanf( "%d %d", &W, &H );
    scanf( "%d", &N );
    
    for ( i = 1; i <= W; i++ )
     for ( j = 1; j <= H; j++ )
      dp[i][j] = i * j;
      
    for ( i = 1; i <= N; i++ ) {
      scanf( "%d %d", &j, &k );
      dp[j][k] = 0;
    }

    for ( i = 1; i <= W; i++ )
     for ( j = 1; j <= H; j++ ) {
      for ( k = 1; k <= ( i / 2 ); k++ )
       dp[i][j] <?= dp[k][j] + dp[i - k][j];

      for ( k = 1; k <= ( j / 2 ); k++ )
       dp[i][j] <?= dp[i][k] + dp[i][j - k];
     }
     
    printf( "%d\n", dp[W][H] );
    
    fflush( stdout );
    return 0;
}

/*
4¦ Phidias                                                Polonia 2005
----------------------------------------------------------------------

Famous ancient Greek sculptor Phidias is making preparations to build
another marvelous monument. For this purpose he needs rectangular marble
plates of sizes W1 x H1, W2 x H2, ..., WN x HN. Recently, Phidias has
received a large rectangular marble slab. He wants to cut the slab to
obtain plates of the desired sizes. Any piece of marble (the slab or the
plates cut from it) can be cut either horizontally or vertically into two
rectangular plates with integral widths and heights, cutting completely
through that piece. This is the only way to cut pieces and pieces cannot
be joined together. Since the marble has a pattern on it, the plates
cannot be rotated: if Phidias cuts a plate of size A x B then it cannot
be used as a plate of size B x A unless A = B. He can make zero or more
plates of each desired size. A marble plate is wasted if it is not of any
of the desired sizes after all cuts are completed. Phidias wonders how to
cut the initial slab so that as little of it as possible will be wasted.
As an example, assume that in the figure below the width of the original
slab is 21 and the height of the original slab is 11, and the desired
plate sizes are 10 x 4, 6 x 2, 7 x 5, and 15 x 10. The minimum possible
area wasted is 10, and the figure shows one sequence of cuts with total
waste area of size 10.


             +-----------------------------------------+
             ¦                   ¦¦¦                   ¦
             ¦      10 x 4       ¦¦¦     10 x 4        ¦
             ¦                   ¦¦¦                   ¦
             +-----------------------------------------¦                                         ¦
             ¦   6 x 2   ¦¦¦   6 x 2   ¦¦¦   6 x 2   ¦¦¦
             +-------------+-------------+-------------¦
             ¦             ¦             ¦             ¦
             ¦    7 x 5    ¦    7 x 5    ¦    7 x 5    ¦
             ¦             ¦             ¦             ¦
             ¦             ¦             ¦             ¦
             +-----------------------------------------+

Your task is to write a  program that, given the size of  the original
slab and the desired plate sizes, calculates the minimum total area of
the original slab that must be wasted.

INPUT

The input file  name is phidias.in.  The first line  of input contains
two integers: first W, the width of the original slab, and then H, the
height of the original slab.  The second line contains one  integer N:
the number of desired plate  sizes. The following N lines  contain the
desired plate sizes. Each of these lines contains two integers:  first
the width Wi and then the height Hi of that desired plate size (1 <= i
<= N).

OUTPUT

The output file name is phidias.out.  The file is to contain one  line
with a  single integer:  the minimum  total area  of the original slab
that must be wasted.

phidias.in            phidias.out
21 11                  10
4
10 4
6 2
7 5
15 10


CONSTRAINTS
In all inputs,
1 <= W<= 600,
1 <= H<= 600,
0 < N <= 200,
1 <= Wi <= W,
1 <= Hi <= H.

Additionally, in 50% of the inputs, W<= 20, H<= 20 and N<= 5.
*/
