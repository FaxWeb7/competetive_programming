# левый и правый бинарный поиск
def left_bin_search(l, r, check, checkparams):
    while l < r:
        m = (l + r) // 2
        if check(checkparams):
            r = m
        else:
            l = m + 1
    return l

def right_bin_search(l, r, check, checkparams):
    while l < r:
        m = (l + r + 1) // 2 # +1 нужен для того, чтобы округлить результат ддо большего значения
        if check(checkparams):
            l = m
        else:
            r = m - 1
    return l


# задача на поиск минимально возможного числа человек так, чтобы их было не меньше трети всех людей(левым бин поиском)
def solution1(n, k):
    l = k
    r = n
    while l < r:
        m = (l + r) // 2
        if m/(n+m-k) >= 1/3:
            r = m
        else:
            l = m + 1
    return l-k

# task 2
def task2(n, k):
    l = k
    r = n
    while l < r:
        m = (l + r) // 2
        if (((2*k) + (m-1))/2)*m >= n:
            r = m
        else:
            l = m + 1
    return l

print(task2(10, 1))