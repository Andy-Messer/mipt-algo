program Program10;
var n,i,summ,max,min:integer;m:array[-100000..100000] of integer;
begin
  read (n);max:=0;
  for i:=1 to n do begin
  read (summ);if summ<>0 then m[summ]:=1;
  end;
  for i:=-100000 to 100000 do 
  max:=max+m[i];
  writeln(max);
end.