import sys
input=sys.stdin.readline

if __name__ == '__main__':
    n=int(input())
    dp=[0]*(n+1)
    tmp=[]
    for i in range(n):
        a,b=map(int,input().split())
        tmp.append((a,b))
    for i in range(n-1,-1,-1):
        if i+tmp[i][0]>n:
            dp[i]=dp[i+1]
        else:
            dp[i]=max(dp[i+1],tmp[i][1]+dp[i+tmp[i][0]])
    print(dp[0])

