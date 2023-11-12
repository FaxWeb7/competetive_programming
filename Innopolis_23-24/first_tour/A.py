a, b = list(map(int, input().split()))
x, y = list(map(int, input().split()))

def find_meeting_point(a, b, x, y):
    left = 0
    right = a + b
    best_k = 0
    min_diff = float('inf')

    while left <= right:
        mid = (left + right) // 2
        tom_reward = mid * x
        gek_reward = (a + b - mid) * y
        diff = abs(tom_reward - gek_reward)
        if diff <= min_diff:
            min_diff = diff
            best_k = mid
        if tom_reward < gek_reward:
            left = mid + 1
        else:
            right = mid - 1

    return best_k

print(find_meeting_point(a,b,x,y))