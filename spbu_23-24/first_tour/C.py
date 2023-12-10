from sys import stdin, stdout

s = stdin.readline().strip()
p = stdin.readline().strip()
len_s = len(s)
len_p = len(p)

long_s = s
while len(long_s) < len_p + (len_s - 1):
    long_s += s

ans = 0
for i in range(len_s):
    if p == long_s[i:len_p+i]:
        ans += 1

stdout.write(str(ans))