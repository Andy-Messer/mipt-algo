program Program7;

var
  n, k, i, l, r, m, p: int64;
  a, b: array of int64;

begin
  read(n, k);
  setlength(a, n + 1);
  
  setlength(b, k + 1);
  for i := 1 to n do
    read(a[i]);
  for i := 1 to k do
    read(b[i]);
  for i := 1 to k do 
  begin
   
    l := 1;r := n;p := 0;
    
    while l <= r do
    begin
      m := (l + r) div 2; 
      if a[m] = b[i] then begin writeln('YES');p := 1;break; end;
      if a[m] < b[i] then begin l := m+1; end;
      if a[m] > b[i] then begin r := m-1; end;
      
    end;
    if p<>1 then writeln('NO');
  end;
end.