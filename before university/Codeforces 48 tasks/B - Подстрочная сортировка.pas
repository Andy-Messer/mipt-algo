program Program11;
var r,i,g,n:integer;a:array[1..100] of string;c:array[1..100] of integer;b:string;y,f:boolean;
function poisk(j:integer):boolean;
var i,u:integer;
begin
y:=false;f:=false;
for i:=1 to length(a[j])-length(a[j-1])+1 do
begin
if f<>true then begin
f:=true;
for u:=1 to length (a[j-1]) do
if a[j][i+u-1]<>a[j-1][u] then f:=false;end;
 
end;
if f=true then y:=true;
result:=y;
end;
procedure qSort(l,r:longint);
var i,j,w,q:longint;
    v:string;
begin
  i := l; j := r;
  q := c[(l+r) div 2];
  repeat
    while (c[i] < q) do inc(i);
    while (q < c[j]) do dec(j);
    if (i <= j) then
    begin
      w:=c[i]; c[i]:=c[j]; c[j]:=w;
      v:=a[i]; a[i]:=a[j]; a[j]:=v;
      inc(i); dec(j);
    end;
  until (i > j);
  if (l < j) then qSort(l,j);
  if (i < r) then qSort(i,r);
end;
 
begin
readln(n);
for i:=1 to n do begin
readln(b);a[i]:=b;c[i]:=length(b);end;
qsort(1,n);
g:=0;
for r:=n downto 2 do
begin
 
if poisk(r)=false then g:=1; end;
if g=0 then
begin writeln('YES');
for i:=1 to n do writeln(a[i]);end
else 
writeln('NO');
end.