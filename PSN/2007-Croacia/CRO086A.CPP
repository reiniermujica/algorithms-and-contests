/*
 Reinier César Mujica
 3/4/08  PSN - 2008
 E log(V)  
 E - Edges
 V - Vertex
*/

#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

const int
    mx = 5002,
    oo = 1<<29;
    
typedef pair <int,int> par;

int n,m,sol,t[mx],d[mx],l[mx];
vector <par> G[mx],V[mx];
priority_queue <par,vector <par>,greater <par> > Q;

void dijkstra1(){
     int i;
     d[1]=0;
     Q.push(make_pair(0,1));
     while (!Q.empty()){
        int cos = Q.top().first;
        int act = Q.top().second;
        Q.pop();
        for (i=0; i<G[act].size(); i++){
          int nex = G[act][i].second;
          int nco = G[act][i].first;
          if (d[nex] > cos + nco){
            d[nex]=cos + nco;
            Q.push(make_pair(d[nex],nex));      
          }               
        }
     }
}

void dijkstra2(){
     int i;
     l[1]=0;
     Q.push(make_pair(0,1));
     while (!Q.empty()){
        int cos = Q.top().first;
        int act = Q.top().second;
        Q.pop();
        for (i=0; i<V[act].size(); i++){
          int nex = V[act][i].second;
          int nco = V[act][i].first;
          if (l[nex] > cos + nco){
            l[nex]=cos + nco;
            Q.push(make_pair(l[nex],nex));      
          }               
        }
     }
}

int main(){
    int i,x,y,p;
    freopen("prz.in","r",stdin);
    freopen("prz.out","w",stdout);
    scanf("%d",&n);
    for (i=1; i<=n; i++)
     scanf("%d",&t[i]);
    scanf("%d",&m);
    for (i=1; i<=m; i++){
     scanf("%d%d%d",&x,&y,&p);
     G[x].push_back(make_pair(p,y));
     V[y].push_back(make_pair(p,x));     
    }    
    fill(d,d+mx,oo);
    dijkstra1();
    fill(l,l+mx,oo);
    dijkstra2();
    sol=oo;
    for (i=1; i<=n; i++)
     if (d[i] + l[i] + t[i] / 2 < sol)
      sol=d[i] + l[i] + t[i] / 2;
    printf("%d\n",sol);
    fflush(stdout);
    return 0;
}

/*86¦ Los contrabandistas.                                  Croacia 2007
---------------------------------------------------------------------- 

Byteotia es famosa por sus  ricos depósitos de oro. Por  consiguiente,
durante muchos  años allí  floreció la  venta de  ese metal  al vecino
reino  de   Bitland.  Desgraciadamente,   el  déficit   creciente  del
presupuesto  nacional  obligó al  rey  de Bitland  a  introducir altas
tarifas   en   los   metales   y   minerales.   Los  comerciantes  que
cruzan la frontera  tienen que  pagar impuestos  de 50%  del valor  de
la   carga  transportada.   Los   comerciantes  de   Byteotian   están
amenazados con la  ruina.   Afortunadamente,   los    alquimistas   de
Byteotian   han desarrollado  maneras de transformar   algunos metales
en otro.  La  idea de los  comerciantes es  usar  los conocimientos de
los   alquimistas  para  transformar  oro  en  algún  metal  barato, y
a continuación, después  de  cruzar la  frontera  y  pagar la  pequeña
tarifa, transformarlo  de nuevo  en  oro.  Fatalmente, los alquimistas
no  pueden  transformar   cualquier  metal  en   otro  arbitrariamente
escogido. Por consiguiente, puede pasar que el proceso  de  obtener un
metal   a  partir   del   oro   tiene    que  ser   una    cadena   de
transformaciones  que  producen  un  metal  diferente  en  cada  fase.
Los  alquimistas demandan  una alta  retribución  por   sus  servicios.
Ellos han fijados un  precio para  transformar  1  kg de  un  metal  A
en  un   metal   B  para  cada  transformación   que     ellos  puedan
realizar.   Los    comerciantes reflexionan  de  que  forma  debe  ser
transportado   el oro   al cruzar  la frontera  y cual   secuencia  de
procesos  alquimicos  deben  ser aplicados  para  lograr  la más  alta
ganancia.

Tarea

Ayude  a la economía de Byteotian! Escriba un programa que:

- Lea la tabla  de precios para todos  los metales y  precios  para las
  transformaciones  ofrecidas por los alquimistas.

- Determine una secuencia de metales m1, m2, ..., mk tal que:

    * m1 = mk es oro, 
    
    * para cada i = 2,3,...,k los alquimistas son capaces de obtener
      el metal m(i) a partir del metal m(i-1), y
      
    * el costo de ejecución  de la secuencia completa de los  procesos
      alquimicos    para  1    kg    de    oro,  aumentado    por   el
      impuesto pagado en  la frontera  (50% del   precio de  1 kg  del
      metal  más barato  de m(i),  para  i  =  1,  2,  ...,  k) es  el
      más  pequeño  posible.  Nosotros   asumimos   que   durante   el
      proceso  de alquimia el  peso de los metales no se altera.

-  Escriba   en  la   salida   el  costo   de   ejecutar la  secuencia
   determinada   de   los   procesos  alquimicos   aumentado   por  el
   impuesto pagado en  la frontera.

Entrada

En la  primera línea del  fichero de entrada PRZ.IN  existe  un entero
positivo n denotando el número de diferentes metales, 1 <= n <=  5000.
En la (k+1)-ésima  líneas, para  1  <=  k <=  n, existe un  entero par
no negativo pk: el  precio de  1  kg  del  k-ésimo metal,  0 <= pk  <=
10^9. Nosotros  asumimos que  el oro  tiene el  número 1.  En la línea
(n+2)-ésima  existe  un entero   no   negativo m  igual  al número  de
procesos  de  transformación  que  los   alquimistas  son  capaces  de
realizar,  0   <= m   <= 100000.  En cada   una de  las  siguientes  m
líneas   existen  tres   enteros  positivos,  separados   por espacios
simples,  describiendo   consecutivos procesos  de  transformación. Un
triplo de números a, b, c denota que los alquimistas están capacitados
para obtener  el b-ésimo metal a partir del  a-ésimo metal,  y   ellos
exigen  c bytealers  (moneda de Byteotian)   para transformar 1  kg de
material,  1 <=  a, b  <= n,  0 <=  c <=  10000. Un   par ordenado  de
números  a y b  pueden aparecer a  lo sumo una  vez en el fichero. 

Salida

Su programa debe  imprimir el resultado  en el fichero  PRZ.OUT. En la
primera línea usted debe de escribir un entero - el costo de ejecución
de los procesos alquimicos determinado por su  programa aumentado
por el impuesto pagado en la frontera. 

Ejemplo de Entrada y Salida:

+--------+   +---------+
¦ PRZ.IN ¦   ¦ PRZ.OUT ¦
+--------¦   +---------¦
¦ 4      ¦   ¦ 60      ¦
¦ 200    ¦   +---------+
¦ 100    ¦
¦ 40     ¦
¦ 2      ¦
¦ 6      ¦
¦ 1 2 10 ¦
¦ 1 3 5  ¦
¦ 2 1 25 ¦
¦ 3 2 10 ¦
¦ 3 4 5  ¦
¦ 4 1 50 ¦
+--------+
*/
