
 program Program10;
var a:array[1..100] of integer;n,l,b,i,m:integer;s:string;
begin
readln (n,l);
m:=0;s:='';
for i:=1 to 100 do begin
a[i]:=0;end;
for i:=1 to n do begin
read (b);a[b]:=i;end;
for i:=1 to 100 do begin
if a[i]<>0 then begin
if m<l then begin
m:=1+m;s:=s+a[i]+' ';end;end;end;
if m<l then
writeln('NO')
else begin
writeln('YES');
 
 
write(s);end;
end.