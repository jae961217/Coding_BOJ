import sys
input=sys.stdin.readline

if __name__=='__main__':
    n,m=map(int,input().split())
    lessons=list(map(int,input().split()))

    left=max(lessons)
    right=sum(lessons)
    while left<=right:
        mid=(left+right)//2
        cnt,time=0,0

        for i in lessons:
            if time+i>mid:
                cnt+=1
                time=0
            time+=i
        if time:
            cnt+=1
        else:
            cnt=0

        if cnt<=m:
            right=mid-1
        else:
            left=mid+1
    print(left)


