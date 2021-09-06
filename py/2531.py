import sys
input=sys.stdin.readline

n,d,k,c=map(int,input().split())
num=[]
for i in range(n):
    a=int(input())
    num.append(a)
tmp, res=0, 0
for i in range(k-1):
    num.append(num[tmp])
    tmp+=1

for i in range(n):
    chobab=num[i:i+k]
    coupon=0
    chobab=set(chobab)
    if not c in chobab:
        coupon=1
    if res<len(chobab)+coupon:
        res=len(chobab)+coupon
print(res)