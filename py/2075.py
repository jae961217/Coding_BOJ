import sys
import heapq
input=sys.stdin.readline

n=int(input())
value=0
heap=[-sys.maxsize for i in range(n)]

for i in range(n):
    tmp=list(map(int,input().split()))
    for j in tmp:
        if j>heap[0]:
            heapq.heappush(heap,j)
            heapq.heappop(heap)
print(heap[0])