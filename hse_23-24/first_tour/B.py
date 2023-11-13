# n = int(input())
# arr = list(map(int, input().split()))

# result = []
# max_num = float('-inf')

# for i in range(n):
#     max_num = max(max_num, arr[i])
#     result.append(max_num)

# print(*result)

def find_characteristic(a):
    n = len(a)
    dp = [float('inf')] * (n + 1)
    for k in range(1, n + 1):
        for i in range(n - k + 1):
            min_num = min(a[i:i+k])
            dp[k] = min(dp[k], min_num)
    return dp[1:]

n = int(input())
arr = list(map(int, input().split()))
result = find_characteristic(arr)
print(result)