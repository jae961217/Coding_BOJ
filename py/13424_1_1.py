import sys
input = sys.stdin.readline

import heapq

for tc in range(int(input())):
    n, m = map(int, input().split())
    arr = [[] for _ in range(n + 1)]
    res = [0] * (n + 1)
    for i in range(m):
        a, b, c = map(int, input().split())
        arr[a].append((b, c))
        arr[b].append((a, c))
    num = int(input())
    friends = list(map(int, input().split()))
    for i in friends:
        distence = [sys.maxsize] * (n + 1)
        q = []
        heapq.heappush(q, (0, i))
        distence[i] = 0
        while q:
            dist, now = heapq.heappop(q)
            if dist > distence[now]:
                continue
            for j in arr[now]:
                cost = dist + j[1]
                if cost < distence[j[0]]:
                    distence[j[0]] = cost
                    heapq.heappush(q, (cost, j[0]))

        for j in range(1, n + 1):
            res[j] += distence[j]
    minn = 0
    noww = sys.maxsize
    for i in range(1, n + 1):
        if noww > res[i]:
            noww = res[i]
            minn = i
    print(minn)