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
  if b[i]<=a[1] then writeln(a[1])
  else
  if b[i]>=a[n] then writeln(a[n])
  else
  begin
   
    l := 1;r := n;p := 0;
    
    while l < r - 1 do
    begin
      m := (l + r) div 2; 
      if a[m] = b[i] then begin writeln(a[m]);p := 1;break; end;
      if a[m] < b[i] then begin l := m; end;
      if a[m] > b[i] then begin r := m; end;
      
    end;
    if p = 0 then
      if abs(b[i] - a[l]) <= abs(b[i] - a[r]) then writeln(a[l]) else writeln(a[r]); 
  end;
end.