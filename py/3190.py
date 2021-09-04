from collections import deque as dq
import sys
input=sys.stdin.readline

baaam=dq([])
n=int(input())
arr=[[0 for i in range(n)] for j in range(n)]
k=int(input())
for i in range(k):
    a,b=map(int,input().split())
    arr[a-1][b-1]=2
l=int(input())
move=[]

for i in range(l):
    c,d=input().split()
    move.append([int(c),d])
time, index=0,0
dir=[[0,1],[1,0],[0,-1],[-1,0]]
dir_index=0
arr[0][0]=1
baaam.append([0,0])
x,y=0,0
while True:
    x,y=x+ dir[dir_index][0], y + dir[dir_index][1]
    if x<0 or x>=n or y<0 or y>=n or arr[x][y]==1:
        break
    if arr[x][y]==0:
        tmp=baaam.popleft()
        arr[tmp[0]][tmp[1]]=0
    baaam.append([x,y])
    arr[x][y] = 1
    time += 1
    if index<len(move) and move[index][0]==time:
        if move[index][1]=='D':
            dir_index+=1
        else:
            dir_index-=1
        dir_index%=4
        index+=1

print(time+1)
