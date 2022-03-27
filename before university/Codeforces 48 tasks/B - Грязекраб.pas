program Program7;
var k,a,b,c,a2,b2,g,o,i:longint;s:string;
begin
read (a,b,c);
read (a2,b2);g:=a;
while a2>0 do
begin
if (a-b2>0) or (a2-b<=0) then begin
k:=k+1;s:=s+'STRIKE ';a:=a-b2;a2:=a2-b;end
else begin
k:=k+1;s:=s+'HEAL ';a:=a-b2;a:=a+c;
 
end;
end;
write (k);o:=1;writeln();
 
while o<=length(s) do
begin 
if s[o]<>' ' then
write (s[o])
else
writeln();
o:=o+1;
 
end;
end.