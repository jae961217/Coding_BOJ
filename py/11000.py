import sys
import heapq
input=sys.stdin.readline

n=int(input())
timetable=[list(map(int,input().split())) for i in range(n)]
timetable.sort()

heap=[]
heapq.heappush(heap,timetable[0][1])

for i in range(1,n):
    if heap[0]>timetable[i][0]:
        heapq.heappush(heap,timetable[i][1])
    else:
        heapq.heappop(heap)
        heapq.heappush(heap,timetable[i][1])

print(len(heap))