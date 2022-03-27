program Program10;
var a,b,n,m:int64;
begin
  read(n,m,a,b);
 
  if (m-(n mod m))*a<(n mod m)*b then
  writeln((m-(n mod m))*a)
  else
  writeln((n mod m)*b);
 
end.