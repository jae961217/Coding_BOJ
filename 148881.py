import sys
input=sys.stdin.readline

n=int(input())
num=list(map(int,input().split()))
op_cnt=list(map(int,input().split()))
maxV,minV=-1000000001,1000000001

def func(cnt,res,pl,mi,mu,di):
    global maxV,minV
    if cnt==n:
        maxV=max(maxV,res)
        minV=min(minV,res)
        return

    if pl:
        func(cnt+1,res+num[cnt],pl-1,mi,mu,di)
    if mi:
        func(cnt+1,res-num[cnt],pl,mi-1,mu,di)
    if mu:
        func(cnt+1,res*num[cnt],pl,mi,mu-1,di)
    if di:
        if res<0:
            func(cnt+1,-1*(abs(res)//num[cnt]),pl,mi,mu,di-1)
        else:
            func(cnt+1,res//num[cnt],pl,mi,mu,di-1)

func(1,num[0],op_cnt[0],op_cnt[1],op_cnt[2],op_cnt[3])
print(maxV)
print(minV)