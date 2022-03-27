program Program7;
var w,h,n,m,l,r:uint64;
begin
read(w,h,n);
r:=10000000000000000000;
l:=0;m:=((l+r)div 2);
  while l<>r do
  begin
 
  if ((m div w)*(m div h))>=n then begin r:=m; m:=((l+r)div 2);end
  else begin l:=m+1; m:=((l+r)div 2);end;
  end;
  write(m);
end.