import sys

input = sys.stdin.readline

tree = dict()

n = int(input())
for i in range(n):
    a, b, c = input().split()
    tree[a] = [b, c]


def pre(node):
    if node != '.':
        print(node, end='')
        pre(tree[node][0])
        pre(tree[node][1])


def ino(node):
    if node != '.':
        ino(tree[node][0])
        print(node, end='')
        ino(tree[node][1])


def post(node):
    if node != '.':
        post(tree[node][0])
        post(tree[node][1])
        print(node, end='')


pre('A')
print()
ino('A')
print()
post('A')