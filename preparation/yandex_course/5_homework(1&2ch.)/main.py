def task_1(d, e, a, b, c):
    def sorting(num1, num2):
        if num1 < num2:
            return (num1, num2)
        return (num2, num1)
    a, b = sorting(a, b)
    b, c = sorting(b, c)
    a, b = sorting(a, b)
    d, e = sorting(d, e)
    if a <= d and b <= e:
        return True
    return False


def task_2(n, m, a, b):
    min1 = n + ((n-1)*a)
    min2 = m + ((m-1)*b)
    max1 = min1 + (2 * a)
    max2 = min2 + (2 * a)

    if max(min1, min2) > min(max1, max2):
        return 'Ошибка'
    else:
        return (max(min1, min2), min(max1, max2))


def task_4(seq):
    for start in range(len(seq)):
        i = start
        j = len(seq) - 1
        while i < len(seq) and j >= 0 and seq[i] == seq[j] and i <= j:
            i += 1
            j -= 1
        if i > j:
            ans = []
            for i in range(start-1, -1, -1):
                ans.append(seq[i])
            return ans


def task_5(seq):
    max1 = seq[0]
    min1 = seq[0]
    for item in seq:
        if item > max1:
            max1 = item
        if item < min1:
            min1 = item
    seq.remove(max1)
    seq.remove(min1)
    max2 = seq[0]
    min2 = seq[0]
    for item in seq:
        if item > max2:
            max2 = item
        if item < min2:
            min2 = item
    seq.remove(max2)
    seq.remove(min2)
    max3 = seq[0]
    for item in seq:
        if item > max3:
            max3 = item

    option1 = min1 * min2 * max1
    option2 = max1 * max2 * max3
    return option1 if option1 > option2 else option2


def task_6(n, m, mines):
    dx = (-1, -1, -1, 0, 0, 1, 1, 1)
    dy = (-1, 0, 1, -1, 1, -1, 0, 1)
    field = []
    for _ in range(n+2):
        field.append([0] * (m+2))
    for minex, miney in mines:
        for k in range(len(dx)):
            field[minex + dx[k]][miney + dy[k]] += 1
    for minex, miney in mines:
        field[minex][miney] = '*'

    ans = ''
    for x in field:
        for y in x:
            ans += (str(y))
        ans += '\n'
    return ans[:-1]


def task_6(n, prev):
    for i in range(n-1):
        f, s = input().split()
        now = float(f)
        if abs(now - prev) < 10**(-6):
            continue
        if s == 'closer':
            if now > prev:
                left = max(left, (now + prev) / 2)
            else:
                right = min(right, (now + prev) / 2)
        else:
            if now < prev:
                left = max(left, (now + prev) / 2)
            else:
                right = min(right, (now + prev) / 2)
        prev = now
    return left, right