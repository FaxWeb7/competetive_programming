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
def task_1(n, k):
    l = k
    r = n
    while l < r:
        m = (l + r) // 2
        if m/(n+m-k) >= 1/3:
            r = m
        else:
            l = m + 1
    return l-k


# Задача на бин поиск с арифметической прогрессией
def task_2(n, k):
    l = k
    r = n
    while l < r:
        m = (l + r) // 2
        if (((2*k) + (m-1))/2)*m >= n:
            r = m
        else:
            l = m + 1
    return l


# Задача на бин поиск про доску и стикеры
def task_3(w, h, n):
    l = 1
    r = max(w, h)
    while l < r:
        # print(l,r,1)
        m = (l + r + 1) // 2
        if m*m*n <= w*h:
            l = m
        else:
            r = m - 1
    return l


# Задача на нахождение первого числа в отсортированном массиве, большем чем x
def task_4(n, nums, x):
    ans = n
    l = 0
    r = n-1
    while l != r:
        m = (l + r) // 2
        if nums[m] >= x:
            ans = m
            r = m
        else:
            l = m + 1
    return ans


# Задача на определения кол-ва чисел x в отсортированном массиве
def task_5(n, nums, x):
    def max_index(n, nums, x):
        l = 0
        r = n-1
        while l < r:
            m = (l + r + 1) // 2
            if nums[m] == x:
                l = m
            else:
                r = m - 1
        return l
    def min_index(n, nums, x):
        l = 0
        r = n-1
        while l < r:
            m = (l + r) // 2
            if nums[m] == x:
                r = m
            else:
                l = m + 1
        return l
    return (max_index(n, nums, x) - min_index(n, nums, x) + 1)