program Program7;
var n,m,x,y,i,a,b:integer;
begin
read (n,m);x:=0;y:=0;
for i:=1 to n do
begin
read (a,b);
if ((a<=x) or (a<=y)) and (y<b)  then
y:=b;
 
 
end;
if y<m then
write ('NO')
else 
write ('YES');
end.