a=[[1,2],[2,1],[-1,2],[2,-1],[-2,-1],[-1,-2],[1,-2],[-2,1]]
h=int(input())
n=int(input())
i=int(input())
l=int(input())
k=0
for x,y in a:
 if (h+x==i) and (n+y==l):
   print ('YES')
   k=k+1
if k==0:
 print ('NO')