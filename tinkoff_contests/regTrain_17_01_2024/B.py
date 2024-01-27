from itertools import product

def check(n, k, s, mid):
    minSum = float("inf")
    for i in product(s, repeat=mid):
        sumV = sum([int(j) for j in i])
        num = ''.join(i)
        if num[0] != '0' and sumV == n:
            isOk = True
            for j in range(0, mid-1):
                if num[j] == num[j+1]: 
                    isOk = False
                    minSum = min(sumV, minSum)
                    break
            if isOk: return len(num)
    return -1

t = int(input())
for i in range(t):
    n, k = list(map(int, input().split()))
    s = input().split()
    ans = -1
    left = 1
    # right = n//min([int(i) for i in s]) if min([int(i) for i in s]) != 0 else n
    # while (left < right):
    #     mid = (left + right) // 2
    #     guess = check(n, k, s, mid)
    #     print(mid)
    #     if (guess == -1):
    #         right = mid
    #     else:
    #         left = mid + 1
    #         ans = guess
    ans = -1
    maxV = n//min([int(i) for i in s]) if min([int(i) for i in s]) != 0 else n
    while maxV > 0:
        guess = check(n, k, s, maxV)
        if (guess != -1):
            ans = guess
            break
        maxV -= 1
    print(ans)
