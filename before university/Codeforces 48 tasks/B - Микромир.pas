program Program6;
var n,k,i,r,p,t,x,y:int64;v,c:array of int64;
procedure qSort(l,r:int64);
var i,j,w,q:int64;
    
begin
  i := l; j := r;
  q := v[random(l,r)];
  repeat
    while (v[i] < q) do inc(i);
    while (q < v[j]) do dec(j);
    if (i <= j) then
    begin
      w:=v[i]; v[i]:=v[j]; v[j]:=w;
      inc(i); dec(j);
    end;
  until (i > j);
  if (l < j) then qSort(l,j);
  if (i < r) then qSort(i,r);
end;
 
begin
 
 r:=0;
read (n,k);
setlength(v,n+1);
setlength(c,1000001);
for i:=1 to n do begin 
read (v[i]);
c[v[i]]:=c[v[i]]+1;end;
qsort(1,n);
for i:=2 to n do
if (v[i]>v[i-1]) and (v[i]<=v[i-1]+k) then t:=t+c[v[i-1]];
write(n-t);
end.