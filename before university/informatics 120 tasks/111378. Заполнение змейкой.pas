program pervaia;
var k,l,n,i,m,t:integer;
begin
k:=1;
l:=1;
t:=0;
readln (n,m);
while l<n+1 do
begin
if l mod 2=1 then
 for i:=1 to m do
  begin 
  if k div 1000>0 then
  begin
  write (k);
  t:=1;
  end;
  if t=0 then
  if k div 100>0 then begin
  write (' ',k); t:=1; end;
  if t=0 then
  if k div 10>0 then begin
  write ('  ',k); t:=1;end;
  if t=0 then
  if k div 1>0 then  begin
  write ('   ',k); t:=1;end;
  k:=k+1; 
  t:=0;
  end;
l:=l+1;
k:=k+m;
writeln ('');
if l=n+1 then break;
if l mod 2=0 then
 for i:=1 to m do
  begin 
  k:=k-1; 
  if k div 1000>0 then
  begin
  write (k);
  t:=1;
  end;
  if t=0 then
  if k div 100>0 then begin
  write (' ',k); t:=1; end;
  if t=0 then
  if k div 10>0 then begin
  write ('  ',k); t:=1;end;
  if t=0 then
  if k div 1>0 then  begin
  write ('   ',k); t:=1;end;
   t:=0;
 end;

l:=l+1;
k:=k+m;
writeln ('');
end;
end.