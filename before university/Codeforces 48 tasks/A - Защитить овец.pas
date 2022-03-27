program Program7;
var n,l,i,j,r,k:integer;b:char;a:array[1..500,1..500] of char;s:string;
begin
readln(n,l);
 
	
for i:=1 to n do 
begin 
readln(s); 
while s<>'' do for j:=1 to l do 
begin 
a[i,j]:=s[1]; 
delete(s,1,1); 
end; 
end;
for i:=1 to n do
for j:=1 to l do begin
if a[i,j]='.' then a[i,j]:='D';if a[i,j]='S' then begin if (j-1>0) then if (a[i,j-1]='W') then k:=1;
 if (j+1<=l) then if (a[i,j+1]='W') then k:=1; if (i-1>0) then if (a[i-1,j]='W') then k:=1;
if (i+1<=n) then if (a[i+1,j]='W') then k:=1;  end;end;
if k=1 then writeln ('No')
else begin write ('Yes');
for i:=1 to n do
begin
writeln();
for j:=1 to l do
write(a[i,j]);
end;
end;
end.
