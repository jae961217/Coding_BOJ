import sys
input = sys.stdin.readline

for tc in range(int(input())):
    n, m = map(int, input().split())
    arr = [[sys.maxsize for i in range(n)] for j in range(n)]
    res = sys.maxsize
    answer=0
    for i in range(m):
        a, b, c = map(int, input().split())
        arr[a-1][b-1]=min(arr[a-1][b-1],c)
        arr[b-1][a-1]=min(arr[b-1][a-1],c)
    num = int(input())
    friends = list(map(int, input().split()))

    for k in range(n):
        arr[k][k]=0
        for i in range(n):
            for j in range(n):
                arr[i][j]=min(arr[i][j],arr[i][k]+arr[k][j])

    for i in range(len(arr)):
        tmp=0
        for j in friends:
            tmp+=arr[i][j-1]
        if res>tmp:
            answer=i+1
            res=tmp
    print(answer)