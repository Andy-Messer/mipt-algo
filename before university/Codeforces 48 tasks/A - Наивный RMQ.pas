program Program10;
 
var
  a, t: array of longint;
  l, r, n, d, i, m: longint;f,f2:text;
 
procedure build(ind, l, r: longint);
var c:longint;
begin
  if l < r - 1 then begin
    c := (l + r) div 2;
    build(2 * ind + 1, l, c);
    build(2 * ind + 2, c, r);
    t[ind] := min(t[2 * ind + 1], t[2 * ind + 2]);
  end
  else
    t[ind] := a[l];
end;
function rmq(i, li, ri, l, r: longint):longint; 
var c:longint;
begin
  if (l <> li) or(r <> ri) then begin
    c := (li + ri) div 2;
    if r <= c then rmq:=rmq(2 * i + 1, li, c, l, r)
    else
    if l >= c then rmq := rmq(2 * i + 2, c, ri, l, r)
    else
    rmq:=min(rmq(2 * i + 1, li, c, l, c), 
             rmq(2 * i + 2, c, ri, c, r));
  end
  else
    result := t[i];  
end;
 
begin
 assign (f,'stupid_rmq.in');
 reset(f);
  read(f,n);
  setlength(a, n);
  setlength(t, 4 * n);
  for i := 0 to n - 1 do
    read(f,a[i]);
  read(f,m);
  build(0, 0, n);
  assign(f2,'stupid_rmq.out');
  rewrite(f2);
  for i := 1 to m do
  begin
    read(f,l, r);
    l:=l-1;
    writeln(f2,rmq(0,0,n, l, r));
  end;
  close(f);
  close(f2);
end.