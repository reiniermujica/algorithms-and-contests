{$A+,B-,D+,E+,F-,G-,I-,L+,N-,O-,P-,Q-,R-,S-,T-,V+,X+,Y+}
{$M 65384,0,655360}
{ 48ş EL camino de Eric                                      China 2000
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Hab¡a  una  vez, en una escuela donde el que tuviera el pelo largo era
un  proscrito y era perseguido. El que  estuviera huyendo sab¡a que si
era agarrado por el director tendr¡a luego que lucir un bello pelado a
rape.

Pero  yo  tengo  un amigo que estimaba mucho su cabello y se dispuso a
mantenerse  en  pleno escape. ¨ C¢mo lo conseguir¡a ? Tratar¡a siempre
de  no hacer coincidir su camino con el del director; pero el vivir en
una  gran  escuela  da  muchos  posibles  caminos ¢ptimos y es dif¡cil
calcular.  El  conoc¡a  a  unos  programadores  y les puso la tarea de
ayudarlo.

Para mejor ubicaci¢n la escuela fue resumida a un simple esquema donde
aparecer¡an  las  escaleras,  aulas, pasillos, etc. como simples nodos
(numerados  de 1..N) y nuestro amigo se tendr¡a que pelar si coincid¡a
con el director en un mismo nodo (si llegaba a un nodo al mismo tiempo
que  el director) y para eso el dirigente usaba un m‚todo secreto casi
infalible y era capaz  de  calcular  siempre el mejor  camino para ‚l.
Tanto  el Director como Eric se  van a estar moviendo siempre  lo  que
implica  que  nunca  van  a  permanecer en  un nodo sin realizar alg£n
movimiento.

Entrada

Sabiendo  que Eric y el director viajan a la misma velocidad; se tiene
un fichero de entrada con el siguiente formato:

N   : n£mero de nodos. (1 <= N <= 300)
E F : nodo  donde  se encuentra Eric [espacio] nodo a donde desea
      llegar.
D   : nodo donde se encuentra el director.
      y luego N l¡neas donde:
      en  la  l¡nea  K  est n  ubicados  los nodos a los que se puede
      llegar desde K. El fin de l¡nea ser  indicado por un n£mero 0.

Salida

Ud. debe calcular el o los caminos "salvadores" m s cortos.
L : Menor longitud de los caminos salvadores.
C  :  Cantidad  de  caminos  "salvadores"  de longitud L. y mostrar un
    camino  de  longitud  L.  Imprimiendo  los  nodos  en el orden del
    recorrido.  En  caso de no existir soluci¢n se imprimir  el cartel
    "No Soluci¢n".

ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
³ Entrada     ³ Explicaci¢n                                          ³
ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´
³ 7           ³ Cantidad de nodos.                                   ³
³ 1 4         ³ Posici¢n de Eric <espacio> nodo al que desea llegar. ³
³ 6           ³ Posici¢n inicial del director.                       ³
³ 2 0         ³ Nodos a los que se puede llegar desde 1              ³
³ 5 3 0       ³ Nodos a los que se puede llegar desde 2              ³
³ 4 0         ³                                                      ³
³ 0           ³                                                      ³
³ 3 4 0       ³       . . .                                          ³
³ 1 7 0       ³                                                      ³
³ 2 0         ³ Nodos a los que se puede llegar desde 7              ³
ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
³ Salida      ³ Explicaci¢n                                          ³
ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´
³ 3           ³ Los caminos "salvadores" m s cortos tienen long. 3   ³
³ 2           ³ Hay 2 caminos "salvadores".                          ³
³ 1 2 3 4     ³ Posible caminos salvador                             ³
ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
}

const
 max                    = 321;

type
 range                  = 0..max;
 mx                     = array[1..max] of range;

var
 fe,fs                  : text;
 n,mov,best,long        : range;
 posi                   : array[1..3] of range;
 cant                   : array[boolean,1..max] of range;
 tab                    : array[1..max] of ^mx;
 cam                    : array[1..max*2] of ^mx;
 cont                   : array[1..max] of range;
 sav                    : array[boolean,1..2,1..max] of range;

procedure open;
var
 i,aux                  : range;
 buff                   : array[1..64000] of byte;
begin
 assign(fe,'chi048.in'); reset(fe);
 assign(fs,'chi048.out'); rewrite(fs);
 settextbuf(fe,buff);
 readln(fe,n);
 readln(fe,posi[1],posi[2]);
 readln(fe,posi[3]);
 for i:=1 to n do
  begin
   new(tab[i]); fillchar(tab[i]^,sizeof(tab[i]^),0);
   read(fe,aux);
   while aux <> 0 do
    begin
     inc(cont[i]);
     tab[i]^[cont[i]]:=aux;
     read(fe,aux);
    end;
   readln(fe);
  end;
 close(fe);
end;

procedure bfs;
var
 cp1,cp2,ch1,ch2,i,j,c,d : range;
 mk                      : array[1..max] of boolean;
 s                       : boolean;
begin
 s:=true; cp1:=1; cp2:=1; mov:=0; best:=0;
 sav[s,1,1]:=posi[1]; sav[s,2,1]:=posi[3];
 cant[s,posi[1]]:=1;
 while (cp1 > 0) and (cp2 > 0) do
  begin
  inc(mov);
  new(cam[mov]);
  fillchar(cam[mov]^,sizeof(cam[mov]^),0);
  ch1:=0; ch2:=0;
  fillchar(mk,sizeof(mk),false);
  for i:=1 to cp2 do        {Director Move}
   begin
    d:=sav[s,2,i];
    for j:=1 to cont[d] do
     begin
      c:=tab[d]^[j];
      if not mk[c] then
       begin
        inc(ch2);
        sav[not s,2,ch2]:=c;
        mk[c]:=true;
        cant[not s,c]:=0;
       end;
     end;
   end;                     {End Director Move}
  for i:=1 to cp1 do        {Erick Move}
   begin
    d:=sav[s,1,i];
    for j:=1 to cont[d] do
     begin
      c:=tab[d]^[j];
      if not mk[c] then
       begin
        inc(ch1);
        sav[not s,1,ch1]:=c;
        mk[c]:=true;
        cam[mov]^[c]:=sav[s,1,i];
        cant[not s,c]:=cant[s,d];
       end
      else
       cant[not s,c]:=cant[not s,c] + cant[s,d];
     end;                    {End Erick Move}
   end;
   cp1:=ch1;
   cp2:=ch2;
   s:=not s;
   for i:=1 to cp1 do        {Verif. Si Llego}
    begin
     if sav[s,1,i] = posi[2] then
      begin
       best:=mov;
       long:=cant[s,posi[2]];
       exit;
      end;
    end;                      {End Verif.}
  end;
end;

procedure camino(x,y : range);
begin
 if (x > 0) and (y > 0) then
  begin
   camino(cam[y]^[x],y-1);
   write(fs,cam[y]^[x],' ');
  end;
end;

procedure closer;
begin
 if best = 0 then
   writeln(fs,'No Soluci¢n')
 else
 begin
  writeln(fs,best);
  writeln(fs,long);
  n:=0;
  camino(posi[2],best);
  write(fs,posi[2]);
 end;
 close(fs);
end;

begin
 open;
 bfs;
 closer;
end.