/*
 Reinier César Mujica
 3/4/08  PSN - 2008
*/

#include <cstdio>
#include <cmath>

#define int64 long long

int64 n,x,i;

int main(){
    freopen("potdiez.in","r",stdin);
    freopen("potdiez.out","w",stdout);
    scanf("%d",&n);
    for (i=0; i<n; i++){
     scanf("%d",&x);
     int64 d1 = (x-1)*2;
     int64 d2 = (int64)sqrt(d1);
     if ((d2 * (d2+1)) == d1) printf("1 ");
     else printf("0 ");
    }
    printf("\n");
    return 0;
}

/*35¦ Sucesión de potencias de 10.                          Croacia 2007
----------------------------------------------------------------------

Consideremos  una   sucesión  infinita   de  dígitos   construida  por
potencias ascendentes   de 10,   escritas  una   después  de  la otra.
Este es el  principio de  la  sucesión: 110100100010000.  Usted   debe
averiguar  cual  es  el   dígito localizado  en una  posición dada, de
dicha sucesión.

Entrada

El ficero de entrada POTDIEZ.IN contiene un  número  entero   positivo
N  en la  primera línea, N < 65536. Las próximas N líneas contienen un
entero  positivo  Ki  que  representa  el  número  de  posición  en la
sucesión. Ki < 2^31.

Salida

Debe escribir hacia el fichero de  salida POTDIEZ.OUT N dígitos 0 ó  1
separados con un  espacio.  Más precisamente,  el dígito [i-mo]  de la
salida debe ser igual que el Ki-mo  dígito  de la sucesión precedente.

Ejemplo de Entrada y Salida

 +-----------+  +------------+
 ¦ POTDIEZ.IN¦  ¦ POTDIEZ.OUT¦
 +-----------¦  +------------¦
 ¦ 4         ¦  ¦ 0 0 1 0    ¦
 ¦ 3         ¦  +------------+
 ¦ 14        ¦
 ¦ 7         ¦
 ¦ 6         ¦
 +-----------+0
*/
