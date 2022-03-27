h=int(input())
if h%4==0 and h%100!=0:
 print ('YES')
elif h%400==0:
 print ('YES')
else:
 print ('NO')