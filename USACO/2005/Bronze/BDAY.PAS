{$B-,I-,Q-,R-,S-}
{$M 65384,0,655360}
{Problema 11: Cumplea¤os Bovino [Tradicional, 2005]

Bessie le pregunt¢ a su amiga en que d¡a de la semana naci¢ ella. Ella
sab¡a que ella naci¢ el 25 de Mayo de 2003, pero no sab¡a que d¡a era.
Escriba un programa para ayudarla. Note que ninguna vaca naci¢ antes del
a¤o 1800.

Hechos a saber:

* El 1 de Enero de 1900 fue un Lunes.

* Longitudes de los meses:
    Ene 31          May 31      Sep 30
    Feb 28 o  29    Jun 30      Oct 31
    Mar 31          Jul 31      Nov 30
    Abr 30          Ago 31      Dic 31

* Cada a¤o divisible por 4 es un a¤o bisiesto (1992 = 4*498, por lo
  tanto 1992 es un a¤o bisiesto, pero al a¤o 1900 no es un a¤o
  bisiesto.

* La regla anterior no se cumple para a¤os de centuria. Los a¤os de
  centuria divisibles por 400 son a¤os bisiestos, los otros no lo son.
  Por lo tanto los a¤os centuria 1700, 1800, 1900 y 2100 no son a¤os
  Bisiestos, pero 2000 s¡ es un a¤o bisiesto.

No use ninguna funci¢n pre-definida en su lenguaje de programaci¢n.

NOMBRE DEL PROBLEMA: bday

FORMATO DE ENTRADA:

* L¡nea 1: Tres enteros separados por espacios que representan
        respectivamente, el a¤o, el mes (en el rango 1..12), y un d¡a
        de una fecha.

ENTRADA EJEMPLO (archivo bday.in):

2003 5 25

DETALLES DE LA ENTRADA:

25 de Mayo de 2003

FORMATO DE SALIDA:

* Una sola l¡nea que es el d¡a de la semana (en inglès) de la fecha
        especificada (de la lista en minuscula: monday(lunes),
        tuesday(martes), wednesday(mi‚rcoles), thursday(jueves),
        friday(viernes), saturday(sàbado), sunday(domingo)).

SALIDA EJEMPLO (archivo bday.out):

Sunday

DETALLES DE LA SALIDA:


      Mayo 2003
Do Lu Ma Mi Ju Vi Sa
             1  2  3
 4  5  6  7  8  9 10
11 12 13 14 15 16 17
18 19 20 21 22 23 24
25 26 27 28 29 30 31

    Ene 31          May 31      Sep 30
    Feb 28 o  29    Jun 30      Oct 31
    Mar 31          Jul 31      Nov 30
    Abr 30          Ago 31      Dic 31
}

const
 day   : array[1..7] of string
  =('monday','tuesday','wednesday','thursday','friday','saturday','sunday');
 mes   : array[1..12] of byte=(31,28,31,30,31,30,31,31,30,31,30,31);

var
 fe,fs                  : text;
 a,m,d,i,di,j,k         : longint;

procedure open;
begin
 assign(fe,'bday.in'); reset(fe);
 assign(fs,'bday.out'); rewrite(fs);
 readln(fe,a,m,d);
 close(fe);
end;

procedure closer;
begin
 if i=6 then i:=1 else
 if i=7 then i:=2 else i:=i+2;
 writeln(fs,day[i]);
 close(fs);
end;

procedure work;
begin
 i:=0; k:=1799; di:=0; j:=0;
 repeat
  begin
   inc(k); mes[2]:=28;
   if (k mod 4 = 0) then
    begin
     mes[2]:=29;
     if (k mod 100 = 0) then
      begin
       if k mod 400 = 0 then
        mes[2]:=29
       else mes[2]:=28;
      end;
    end else mes[2]:=28;
   j:=0;
   repeat
    begin
     inc(j);
     di:=0;
     repeat
      begin
       inc(di);
       if i=7 then i:=1 else inc(i);
       if (di=d) and (j=m) and (k=a) then exit;
      end;
    until di=mes[j];
    end;
   until J=12;
  end;
 until k=a;
end;

begin
 open;
 work;
 closer;
end.