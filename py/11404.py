import sys
input = sys.stdin.readline

n = int(input())
arr = [[1000000001 for i in range(n)] for i in range(n)]
m = int(input())

for i in range(m):
    a, b, c = map(int, input().split())
    arr[a-1][b-1]=min(arr[a-1][b-1],c)

for i in range(n):
    arr[i][i]=0
    for j in range(n):
        for k in range(n):
            arr[j][k]=min(arr[j][k],arr[j][i]+arr[i][k])

for i in arr:
    for j in i:
        if j==1000000001:
            print(0,end=' ')
        else:
            print(j, end=' ')
    print()