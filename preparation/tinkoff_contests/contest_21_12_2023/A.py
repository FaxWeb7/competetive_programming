from sys import stdin, stdout

n = int(stdin.readline())

ans = [n, n]
for y in range(1, 100000):
    x = round((y**2 * n) ** (1./3.))
    if x + y >= ans[0] + ans[0]:
        break
    if (x ** 3 / y ** 2) == float(n):
        ans = [x, y]

stdout.write(str(ans[0]) + ' ' + str(ans[1])) 
