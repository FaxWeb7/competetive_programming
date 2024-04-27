n = int(input())
m = int(input())
k = int(input())

count = 0
for i in range(1, n+1):
    for j in range(1, m+1):
        if j < m:
            if abs((i-1)*m+j - i*m-j) < k:
                count += 1
        if i < n:
            if abs((i-1)*m+j - i*m+j) < k:
                count += 1

print(count)