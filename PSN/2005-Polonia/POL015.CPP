/*
 Reinier César Mujica
 28/3/08 PSN - 2008
*/

#include <cstdio>
#include <vector>

using namespace std;

const int
      mx = 1002;
      
int n,act,low[mx];
bool mk[mx];
vector <int> G[mx];

int dfs(int v){
    int i,min,k;
    act++; low[v]=act; min=act;
    for (i=0; i<G[v].size(); i++)
     if (low[G[v][i]] == 0){
         k=dfs(G[v][i]);
         if (k >= low[v]) mk[v]=true;
         min<?=k;          
     } 
     else
      min<?=low[G[v][i]];
    return min;
}

int main(){
    int i,j,x,p;
    freopen("amigos.in","r",stdin);
    freopen("amigos.out","w",stdout);
    scanf("%d",&n);
    for (i=1; i<=n; i++){
        scanf("%d",&p);
        for (j=1; j<=p; j++){
            scanf("%d",&x);
            G[i].push_back(x);    
        }    
    }
    dfs(1);
    for (i=2; i<=n; i++)
     if (mk[i]){
        printf("%d\n",i);
        return 0;      
     }
    printf("%d\n",1);
    fflush(stdout);
    return 0;
}

/*15× Amistades durante la Copa.                            Polonia 2005
ääääääääääääääääääääääääääääääääääääääääääääääääääääääääääääääääääääää

N invitados  se supone  que asistan  a la  Copa Patria,  los invitados
est n  identificados  con  los n¸meros  desde 1  hasta N.  Se sabe  de
antemano cual de estas personas son conocidos por cada uno de la otros
invitados. Dos personas ciertamente se convierten en conocidas durante
la Copa, si ellas tienen o hacen un conocido com¸n. Los  organizadores
del  evento,  conociendo la  situaci¢n   est n seguros  que  todos los
invitados se convertir n en conocidos. Pero una  persona no asisti¢ al
evento y no todos los invitados pueden convertirse en conocidos.

Tarea

- Lea del  fichero de entrada  AMIGOS.IN el n¸mero  de invitados a  la
  Copa Patria y los conocidos por cada persona.
- Hacer  un programa  para determinar  el invitado  que no  asisti¢ al
  evento.
- Escriba hacia el fichero de salida AMIGOS.OUT el n¸mero del invitado
  ausente.

Entrada

 El fichero de entrada AMIGOS.IN contiene:
- L¡nea 1: N,  2 <  N <=200), representa el n¸mero de invitados.

- L¡nea  2..N+1: en la linea i+1 del fichero se escribe la informaci¢n
  del invitado i. En cada una  de las  lineas el  primer n¸mero  es el
  el n¸mero P de personas que son conocidas por la persona i antes del
  evento, a continuaci¢n aparecen P n¸meros separados por espacio  los
  cuales representan  los n¸meros  de los  invitados conocidos  por la
  persona i.

Salida

El fichero de salida AMIGOS.OUT contiene una sola l¡nea con un  entero
el  cual  representa   el  n¸mero  del  invitado  ausente.  Si  varias
soluciones (personas ausentes)  existen, solamente   escribir  una  de
ella.

Ejemplo de Entrada  y Salida

AMIGOS.IN               AMIGOS.OUT

7                       4
2 2 7
2 1 4
2 4 5
4 2 3 6 7
2 3 6
2 4 5
2 1 4
*/
