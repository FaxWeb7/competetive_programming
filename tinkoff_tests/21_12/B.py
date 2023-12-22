from sys import stdin, stdout

t = int(stdin.readline())
for i in range(t):
    n = int(stdin.readline())
    x_list = list(map(int, stdin.readline().split()))
    u_list = list(map(int, stdin.readline().split()))
    t_list = list(map(int, stdin.readline().split()))
    p_list = list(map(int, stdin.readline().split()))

    t = 0
    m = [x_list]
    prev_val = [x_list]
    i = 0
    while len(m) != 2 and i <= 100000:
        temp = []
        for j in range(n):
            temp.append(prev_val[-1][j] + u_list[j] if t_list[j] < i else prev_val[-1][j])
        good_temp = True
        for p in p_list:
            if not(temp[p-1] == sorted(temp)[-p]):
                good_temp = False
                break
        if good_temp:
            m.append(temp)
            t = i
            print(i)
        prev_val = [temp]
        i += 1

    ans = [-1]
    for a in range((3*10**12)+1):
        for b in range(1, 10**6 + 1):
            if a != b and float(t)-1 < a / b <= float(t) and (a != t and t != 1):
                ans = [a, b]
                break
        if ans != [-1]:
            break

    stdout.write(str(' '.join(str(i) for i in ans)) + '\n')



"""
1
3
5 8 119
8 4 1
0 0 0
1 3 2
    37 1 - 114 7
1
5
1 4 2 8 5
2 3 4 5 6
1 2 3 4 5
1 5 2 4 3
    0 1 - -1

"""