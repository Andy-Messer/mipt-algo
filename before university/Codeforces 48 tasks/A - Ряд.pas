program Program10;
var p,n,null,i,a,one:longint;s:string;
begin
readln (n);
p:=0;readln(S);
for i:=1 to n do
begin 
if S[i]='1' then begin null:=0;one:=one+1;end;
if S[i]='0' then begin null:=null+1;one:=0;end;
if null=3 then p:=1;
if one=2 then p:=1;
if (null=2)and ((i=n)or(i=2)) then p:=1;
 
end; if (length(s)=1)and(s[1]='0') then p:=1; 
if p=1 then write('No')
else
write('Yes');
end.