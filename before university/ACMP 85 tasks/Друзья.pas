program Program10;
var i,n,k,j,s:integer;b:array of integer;a:array of array of integer;
procedure dfs(s:integer);
var r:integer;
begin
 for r:=1 to n do
  if (b[r]=0) and (a[s,r]<>0) then begin b[r]:=1;k:=k+1;
  dfs(r);end;
end;
begin
  read(N, S);k:=0;
  setlength(b, n + 1);
  
  setlength(a, n + 1);
  for i := 1 to n do
  begin
    setlength(a[i], n + 1);
    b[i] := 0;
  end;
  for i := 1 to n do
  begin
    for j := 1 to n do
    begin
      a[i, j] := 0;read (a[i,j]);
    end;
  end;
  b[s]:=1;
  dfs(S);
  writeln(k);
end.