import sys
input=sys.stdin.readline

n,k=map(int,input().split())
coin=[int(input()) for i in range(n)]
res=0
coin.sort()
for i in range(n-1,-1,-1):
    if k>i:
        res+=k//coin[i]
        k=k%coin[i]
print(res)
