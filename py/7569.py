import sys
from collections import deque
input=sys.stdin.readline
arr=[]
m,n,h=map(int,input().split())
dq=deque()
for i in range(h):
    tmp=[]
    for j in range(n):
        tmp.append(list(map(int,input().split())))
        for k in range(m):
            if tmp[j][k]==1:
                dq.append((i,j,k))
    arr.append(tmp)

direction=[(-1,0,0),(1,0,0),(0,-1,0),(0,1,0),(0,0,-1),(0,0,1)]


while dq:
    tmpz,tmpx,tmpy=dq.popleft()
    for z,x,y in direction:
        nz,nx,ny=tmpz+z,tmpx+x,tmpy+y
        if 0<=nx<n and 0<=ny<m and 0<=nz<h and arr[nz][nx][ny]==0:
            dq.append((nz,nx,ny))
            arr[nz][nx][ny]=arr[tmpz][tmpx][tmpy]+1

flag=False
res=-1
for i in arr:
    for j in i:
        for k in j:
            if k==0:
                flag=True
            res=max(res,k)
res-=1
if flag:
    res=-1
print(res)



