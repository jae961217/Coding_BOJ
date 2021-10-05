k, n = map(int, input().split())
lan = []
for i in range(k):
    lan.append(int(input()))
res = 0
left, right = 0, max(lan)

while left <= right:
    mid = (left + right) // 2
    cnt = 0
    if mid==0:
        mid=left+right
    for i in lan:
        cnt += i // mid

    if cnt >= n:
        res=max(mid,res)
        left = mid + 1
    else:
        right=mid-1
print(res)
