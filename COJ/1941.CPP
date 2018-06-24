#include <cstdio>
#include <queue>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

#define MAXN 10005
#define oo 1 << 29

struct edge
{
       int next, cost;
       bool male;
       edge( int x = 0, int c = 0, bool m = false )
       {
             next = x; cost = c; male = m;
       }
       bool operator < (const edge &o) const
       {
            return cost > o.cost;
        }
};

int N;
int i, k;
char c;
vector < edge > G[MAXN];
vector < char > S;
int cont;
int d1[MAXN];
int d2[MAXN];

int dijk1( int x )
{
    d1[x] = 0;
    priority_queue < edge > Q;
    Q.push( edge( x, 0,  false ) );
    while ( !Q.empty() )
    {
          edge top = Q.top();
          Q.pop();

          int node = top.next;

          for ( int i = 0; i < G[node].size(); i++ )
          {
              int next = G[node][i].next;
              int ncos = G[node][i].cost + top.cost;
              bool gen = G[node][i].male;
              if  ( gen == true ) continue;
              if ( d1[next] > ncos )
              {
                 d1[next] = ncos;
                 Q.push( edge(next, ncos, false ) );
              }
          }
    }
    return 0;
}

int dijk2( int x )
{
    d2[x] = 0;
    priority_queue < edge > Q;
    Q.push( edge( x, 0, false ) );
    while ( !Q.empty() )
    {
          edge top = Q.top();
          Q.pop();

          int node = top.next;

          for ( int i = 0; i < G[node].size(); i++ )
          {
              int next = G[node][i].next;
              int ncos = G[node][i].cost + top.cost;
              bool gen = G[node][i].male;
              if  ( gen == false ) continue;
              if ( d2[next] > ncos )
              {
                 d2[next] = ncos;
                 Q.push( edge(next, ncos, false ) );
              }
          }
    }
    return 0;
}

int main()
{
    scanf( "%d", &N );
    scanf( "%c", &c );

    while ( N != 0 )
    {
          map< char, int > M;
          map< int, char > M2;

          cont = 0;
          S.clear();

          for ( i = 0; i < MAXN; i++ )
          {
              G[i].clear();
              d1[i] = d2[i] = oo;
          }


          for ( i = 1; i <= N; i++ )
          {
              char gen, dir, x, y;
              scanf( "%c ", &gen );
              scanf( "%c  ", &dir );
              scanf( "%c ", &x );
              scanf( "%c", &y );
              scanf( "%d\n", &k );

              if ( M[x] == 0 ) M[x] = ++ cont;
              if ( M[y] == 0 ) M[y] = ++ cont;
              int cx = M[x], cy = M[y];
              M2[cx] = x; M2[cy] = y;
              bool male = false;
              if ( gen == 'M' ) male = true;

              G[cx].push_back( edge(cy, k, male ) );
              if ( dir == 'B' )
                 G[cy].push_back( edge(cx, k, male ) );
          }

          char a, b;
          scanf( "%c %c", &a, &b );
          int xx = M[a], yy = M[b];

          dijk1(xx);
          dijk2(yy);


          int sol = oo;
          for ( i = 1; i < MAXN; i++ )
          {
        	  int cost = d1[i] + d2[i];
              if ( sol > cost )
              {
            	  sol = cost;
                  S.clear();
                  S.push_back(M2[i]);
              }
              else
              if ( sol == cost )
            	  S.push_back(M2[i]);
          }
          if ( sol != oo )
          {
        	   sort( S.begin(), S.end());
        	   printf( "%d ", sol );
        	   for ( i = 0; i < S.size(); i++ )
        	   {
            	   if ( i == S.size() - 1 )
            		   printf( "%c\n", S[i] );
            	   else
            		   printf( "%c ", S[i] );
        	   }
          }
          else
             printf( "You will never meet.\n" );


          scanf( "%d", &N );
          scanf( "%c", &c );
    }

    return 0;
}
