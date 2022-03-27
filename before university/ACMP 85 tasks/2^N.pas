program Program10;
 var k,l,o,i,u,n,m,j:integer;a:array[1..20000] of integer;
begin
  k:=1;l:=0;
  read (n);
  for i:=1 to 20000 do begin a[i]:=0;end;
  a[1]:=1;
  o:=1;
  for i:=1 to n do
  begin
    l:=0;
    for j:=1 to o+3 do begin
    m:=a[j]*2;
    a[j]:=m mod 10+l mod 10;
    l:=l div 10+m div 10+a[j] div 10;
    a[j]:=a[j] mod 10;
    if j=o then
    begin
    u:=l;
    while u<>0 do
    begin
     u:= u div 10;
     o:=o+1;
    end;  
    end;
     
  end;end;
  for i:=o downto 1 do
  write(a[i]);
end.