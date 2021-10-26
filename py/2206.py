import sys
from collections import deque
input=sys.stdin.readline
arr=[]
n,m=map(int,input().split())
for i in range(n):
    arr.append(list(map(int,input().strip())))
dist=[[[0 for i in range(m)] for j in range(n)] for k in range(2)]
direction=[(-1,0),(1,0),(0,-1),(0,1)]
dq=deque()
res=0
if n==1 and m==1 and arr[0][0]==0:
    res=1
else:
    dist[1][0][0]=1
    dq.append((0,0,1))
    while dq:
        x,y,block=dq.popleft()

        for dx,dy in direction:
            nx,ny=x+dx,y+dy
            if 0<=nx<n and 0<=ny<m and dist[block][nx][ny]==0:
                if arr[nx][ny]==1 and block==1:
                    dist[0][nx][ny]=dist[1][x][y]+1
                    dq.append((nx,ny,0))
                elif arr[nx][ny]==0:
                    dist[block][nx][ny]=dist[block][x][y]+1
                    dq.append((nx,ny,block))

    value=max(dist[1][-1][-1],dist[0][-1][-1])
    res=min(dist[1][-1][-1],dist[0][-1][-1])
    if res==0:
        res=value

if res==0:
    res-=1
print(res)
