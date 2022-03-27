program Program7;
var x,h,m,k,l:integer;
procedure proverka(h,m:integer;var k:integer);
begin
if (h div 10=7)or(h mod 10=7)or(m mod 10=7)or(m div 10=7) then k:=1;
end;
begin
read(X);
read(h,m);l:=0;
if (h div 10=7)or(h mod 10=7)or(m mod 10=7)or(m div 10=7) then k:=1;
while (k<>1) do
begin
m:=m-x;
l:=l+1;
 
if h<0 then h:=24+h;
if m<0 then begin m:=60+m;h:=h-1;end;proverka(h,m,k);
end;
write (l);
 
end.