import sys
input = sys.stdin.readline

n=int(input())

arr=[list(map(int,input().split())) for i in range(n)]
res=[0,0]
def check(a,b,cnt):
    for i in range(cnt):
        for j in range(cnt):
            if not arr[a+i][b+j]==arr[a][b]:
                return False
    return True



def func(a,b,cnt):
    if check(a,b,cnt):
        if arr[a][b]==1:
            res[1]+=1
        else:
            res[0]+=1
        return
    func(a+cnt//2,b+cnt//2,cnt//2)
    func(a, b, cnt // 2)
    func(a, b + cnt // 2, cnt // 2)
    func(a + cnt // 2, b, cnt // 2)

func(0,0,n)
print(res[0])
print(res[1])