program abc;
var n,k,l,i,a:integer;
begin
read (n);k:=0;l:=0;
for i:=1 to n do
begin
read(a);
if a<=3 then begin
k:=k+(l div 3);l:=0;end;
if a>=4 then
l:=l+1;
end;
k:=k+(l div 3);
write (k);
end.