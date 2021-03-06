/*
 Reinier C�sar Mujica
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

/*35� Sucesi�n de potencias de 10.                          Croacia 2007
----------------------------------------------------------------------

Consideremos  una   sucesi�n  infinita   de  d�gitos   construida  por
potencias ascendentes   de 10,   escritas  una   despu�s  de  la otra.
Este es el  principio de  la  sucesi�n: 110100100010000.  Usted   debe
averiguar  cual  es  el   d�gito localizado  en una  posici�n dada, de
dicha sucesi�n.

Entrada

El ficero de entrada POTDIEZ.IN contiene un  n�mero  entero   positivo
N  en la  primera l�nea, N < 65536. Las pr�ximas N l�neas contienen un
entero  positivo  Ki  que  representa  el  n�mero  de  posici�n  en la
sucesi�n. Ki < 2^31.

Salida

Debe escribir hacia el fichero de  salida POTDIEZ.OUT N d�gitos 0 �  1
separados con un  espacio.  M�s precisamente,  el d�gito [i-mo]  de la
salida debe ser igual que el Ki-mo  d�gito  de la sucesi�n precedente.

Ejemplo de Entrada y Salida

 +-----------+  +------------+
 � POTDIEZ.IN�  � POTDIEZ.OUT�
 +-----------�  +------------�
 � 4         �  � 0 0 1 0    �
 � 3         �  +------------+
 � 14        �
 � 7         �
 � 6         �
 +-----------+0
*/
