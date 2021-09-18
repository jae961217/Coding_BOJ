import sys
input=sys.stdin.readline
for tc in range(int(input())):
    n,m,k=map(int,input().split())
    numbers=list(map(int,input().split()))
    arr=[]
    res, tmp=0, 0
    for i in numbers:
        tmp+=i
        arr.append(tmp)
    if n==m:
        if sum(numbers)<k:
            res+=1
    else:
        for i in range(m):
            tmp+=numbers[i]
            arr.append(tmp)
        for i in range(n):
            if arr[m+i]-arr[i]<k:
                res+=1

    print(res)
