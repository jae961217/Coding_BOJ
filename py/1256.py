import sys
input=sys.stdin.readline

n,m,k=map(int,input().split())
arr=[[1 for i in range(m+1)] for j in range(n+1)]
for i in range(1,n+1):
    for j in range(1,m+1):
        arr[i][j]=arr[i-1][j]+arr[i][j-1]

if arr[n][m]<k:
    print(-1)
else:
    res=''
    while True:
        if n==0:
            res+='z'*m
            break
        if m==0:
            res+='a'*n
            break

        tmp=arr[n-1][m]
        if k<=tmp:
            res+='a'
            n-=1
        else:
            res+='z'
            m-=1
            k-=tmp
    print(res)


