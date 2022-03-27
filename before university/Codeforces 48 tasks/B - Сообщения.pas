 
program mass;
var a,max,i,n,Time,b,c:LongInt;v:array of longint;
begin
  Readln(n,A,B,C,Time);
  SetLength(v,n+1);
  for i:=1 to n do begin
  read (v[i]);
  if v[i]<= time then
   if (c-b)>0 then
   max:=max+a+(time-v[i])*(c-b)
   else
   max:=max+a;
  end;
 
 
 writeln (max);
  
  
  
end.