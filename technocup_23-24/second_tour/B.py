m = int(input())
for i in range(m):
    n = int(input())
    cnt = 0
    i = 1
    while i*i <= n:
        if (n&i):
            continue
        cnt+=1
        if (i * i != n):
            cnt+=1
        i+=1
    print(cnt)