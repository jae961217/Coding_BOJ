def func(num,s,e):
    if num==1:
        print(s,e)
        return

    func(num-1,s,6-s-e)
    print(s,e)
    func(num-1,6-s-e,e)

n=int(input())
print(2**n-1)
func(n,1,3)