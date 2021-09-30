import sys
sys.setrecursionlimit(10**6)

while True:
    w, h = map(int,input().split())
    if w == 0 and h == 0:
        break

    arr=[list(map(int,input().split())) for i in range(h)]
    visited=[[0 for i in range(w)] for j in range(h)]
    dir=[[-1,0],[1,0],[0,-1],[0,1],[-1,-1],[-1,1],[1,-1],[1,1]]

    def func(a,b):
        visited[a][b]=1

        for x,y in dir:
            nx,ny=a+x,b+y
            if 0<=nx<h and 0<=ny<w and arr[nx][ny]==1 and visited[nx][ny]==0:
                func(nx,ny)


    cnt=0
    for i in range(h):
        for j in range(w):
            if visited[i][j] == 0 and arr[i][j]==1:
                func(i,j)
                cnt+=1
    print(cnt)
