program abc;
var n,i,j,a,k:longint;
begin
read (n);
for i:=1 to n do
for j:=1 to n do begin
read (a);if a=1 then k:=k+1;end;
write (k div 2);
end.