from sys import stdin, stdout

n = int(stdin.readline())
arr = list(map(int, stdin.readline().split()))

ans = arr[0]
for i in range(n):
    local_ans = arr[i]
    max_val = arr[i]
    j = i+1
    while j <= n+i-1:
        if j < n:
            local_ans += arr[j]
        elif j >= n:
            local_ans += arr[abs(n-j)]
        if local_ans > max_val: max_val = local_ans
        j+=1
    if max_val > ans: ans = max_val

stdout.write(str(ans) if ans >= 0 else str(0))