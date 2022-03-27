program Program7;
var a:array of integer;n,k,pred,p:integer;
procedure combin(p,pred:integer);
var i:integer;
begin
if p=k then begin for i:=0 to k-1 do begin write(a[i],' ');end;writeln();end
else 
for i:=pred+1 to (n-(k-p)+1) do begin
a[p]:=i;
combin(p+1,i);
end;
end;
begin
read (n,k);
setlength(a,k); 
combin(0,0);
end.