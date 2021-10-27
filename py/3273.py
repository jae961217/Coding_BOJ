import sys
input=sys.stdin.readline

n=int(input())
num=list(map(int,input().split()))
x=int(input())
num.sort()
res=0
start, end=0,n-1
while start<end:
    tmp=num[start]+num[end]
    if tmp==x:
        res+=1
    if tmp<x:
        start+=1
        continue
    end-=1
print(res)