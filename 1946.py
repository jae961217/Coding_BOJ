import sys
input=sys.stdin.readline

T=int(input())
for tc in range(T):
    n=int(input())
    test=[]
    cnt=1
    for i in range(n):
        a,b=map(int,input().split())
        test.append((a,b))
    test.sort()
    value=test[0][1]
    for i in test:
        if i[1]<value:
            value=i[1]
            cnt+=1
    print(cnt)