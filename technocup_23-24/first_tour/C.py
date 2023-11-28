from sys import stdin, stdout

n, m = [int(i) for i in stdin.readline().split()]
pairs = []
for _ in range(m):
    pairs.append([int(i) for i in stdin.readline().split()])
s = int(stdin.readline())

result = 0
for pair in pairs:
    if s == pair[0]:
        result += 1

stdout.write(str(result))