import sys
input=sys.stdin.readline
for tc in range(int(input())):
    n,m,k=map(int,input().split())
    numbers=list(map(int,input().split()))
    res=0
    for i in range(m):
        numbers.append(numbers[i])
    for i in range(n):
        if sum(numbers[i:i+m]) < k:
            res+=1
    print(res)