n = int(input())
k = int(input())

l = k
r = n
while l <= r:
    m = (k + n) // 2
    if m == n/3:
        print(m)
        break
    elif m < n/3:
        l = m 
    else:
        r = m