program ac;
var a:array of int64;i,n:int64;
begin
read (n);
setlength(a,n+1);
for i:=1 to n do 
read(a[i]);
for i:=1 to n do
if a[i] mod 2=0 then a[i]:=a[i]-1;
for i:=1 to n do
write(a[i],' ');
end.