program Program7;
var a,b,c,d,m,n:integer;
begin
m:=0;
read (n);
for a:=1 to n div 4 do
for b:=a to (n-a) div 3 do
for c:=b to (n-a-b) div 2 do begin d:=n-a-b-c; if a+b+c+d=n then m:=m+1;end;
write(m);
end.