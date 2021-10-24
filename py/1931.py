import sys
input=sys.stdin.readline

n=int(input())
arr=[list(map(int,input().split())) for i in range(n)]
arr.sort(key=lambda x:(x[1],x[0]))

tmp=0
res=1
for i in range(1,n):
    if arr[tmp][1]<=arr[i][0]:
        res+=1
        tmp=i

print(res)