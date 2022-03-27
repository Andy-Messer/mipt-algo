program abc; 
var a,b,n,i,p:longint;s:array of string;
begin
read (n);
setlength(s,n);
for i:=0 to n-1 do
begin
readln (a);
{if ((a mod 3)mod 7=0) or ((a mod 7)mod 3=0) }
p:=a div 3;
b:=a mod 3;
if (p>=2) and (b=1) or (p>=4) and (b=2) or (p>0) and (b=0) then
s[i]:='YES'
else s[i]:='NO';
end;
for i:=0 to n-1 do
writeln (s[i]);end.