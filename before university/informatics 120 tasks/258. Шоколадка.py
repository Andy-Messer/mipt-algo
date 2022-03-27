h=int(input())
n=int(input())
i=int(input())
if (i<n*h) and ((i%h==0) or (i%n==0)):
 print ('YES')
else:
 print ('NO')