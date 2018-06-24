  {$I-,Q-,R-,S-}

{39ş Escaleras                                           Finlandia 2001

Una empresa se dedica a la construcci¢n  de  escaleras  con  escalones
simples  (un  escal¢n  simple  s¢lo  tiene  un pelda¤o o una unidad de
altura). La  empresa  tiene  mucha  demanda  y  recibe  todo  tipo  de
solicitudes de escaleras, las solicitudes se hacen informando el largo
y  la  altura  que  desean  cubrir  con  una escalera. Un cliente va a
realizar  la  solicitud  y  la  empresa  le muestra todas las posibles
formas que  puede  tener  la  escalera  para que el usuario seleccione
la que desee.

Los ingenieros de la empresa est n trabajando en la b£squeda de  todas
estas formas y necesitan saber cu ntas existen.  Para estos ingenieros
la longitud de la escalera es el n£mero de piezas usadas en la  propia
escalera, cada pieza tiene una unidad  de  longitud.  Una  pieza puede
avanzar  de forma horizontal o de forma vertical, en la forma vertical
sube un pelda¤o el cual ser  simple por lo que no habr  un escal¢n con
dos unidades de altura.

Ejemplo, para una logitud n=4 existen 8 formas las cuales son:

                           É ÍÍÍ ÍÍÍ                    É
                           º                            º
 ÍÍÍ ÍÍÍ ÍÍÍ ÍÍÍ        ÍÍÍ                        É ÍÍÍ
       (1)                   (4)                   º
                                                ÍÍÍ
            É           É ÍÍÍ ÍÍÍ ÍÍÍ                (7)
            º           º
 ÍÍÍ ÍÍÍ ÍÍÍ                 (5)                        É
      (2)                                               º
                              É ÍÍÍ            É ÍÍÍ ÍÍÍ
        É ÍÍÍ                 º                º
        º                É ÍÍÍ
 ÍÍÍ ÍÍÍ                 º                           (8)
      (3)                    (6)

Elabore un programa que determine el n£mero de escaleras que se pueden
construir de longitud n, (1<=n<=50).

Entrada

El archivo de entrada contiene un simple valor que representa a n.

Salida

El archivo de salida deber  contener el n£mero  de  escaleras  que  se
pueden construir de longitud n.

ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿ ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
³ Ejemplo de entrada³ ³ Ejemplo de salida³
ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´ ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´
³ 4                 ³ ³ 8                ³
ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
 }

const
 max        = 51;

var
 fe,fs      : text;
 n,i        : byte;
 tab,res    : array[0..max] of int64;

procedure open;
begin
 assign(fe,'fin039.in'); reset(fe);
 assign(fs,'fin039.out'); rewrite(fs);
 readln(fe,n);
 close(fe);
end;

procedure work;
begin
 tab[1]:=2; res[0]:=0; res[1]:=1;
 for i:=2 to n do
  begin
   res[i]:=res[i-1] + res[i-2];
   tab[i]:=(tab[i-1] * 2) - res[i-1];
  end;
end;

procedure closer;
begin
 writeln(fs,tab[n]);
 close(fs);
end;

begin
 open;
 work;
 closer;
end.