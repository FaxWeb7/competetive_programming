from functools import cache
from sys import stdin, stdout
n, k = list(map(int, stdin.readline().split()))
@cache
def fact(n):
    if n == 1: return 1
    else:
        return n*fact(n-1)
    

for i in range(200, n):
    fact(i)

s = ''
n_fact = fact(n)
while n_fact > 0:
    s += str(n_fact%k)
    n_fact //= k

ans = 0
for symbol in s:
    if symbol != '0':
        break
    ans += 1

stdout.write(str(ans))