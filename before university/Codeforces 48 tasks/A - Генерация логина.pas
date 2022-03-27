program abc;
var s:string;i,k:integer;f:char;
begin
read (s);
 
for i:=1 to length(s) do begin
if s[i]=' ' then f:=s[i+1];
end;
write(s[1]);
i:=2;k:=ord(f);
while ((ord(s[i]))<(ord(f))) and (ord(s[i])>ord(' ')) do
begin
write(s[i]);i:=i+1;end;
write (f);
end.