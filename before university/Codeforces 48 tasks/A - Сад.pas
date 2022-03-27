program Program7;
var n,k,max,i,a:integer;
begin
read (n,k);max:=0; 
for i:=1 to n do begin read(a);if (k mod a=0)and (a>max) then max:=a;end;
write (k div max);
end.
