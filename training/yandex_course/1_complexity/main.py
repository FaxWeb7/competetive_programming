# https://www.youtube.com/watch?v=QLhqYNsPIVo&list=PL6Wui14DvQPySdPv5NUqV3i8sDbHkCKC5
# поиск наиболее повторяемого символа строки за O(n)
s = input()

dict_s = {}
for now in s:
    if now not in dict_s.keys():
        dict_s[now] = 0
    dict_s[now] = 1

max_val = 0
ans = ''
for key, value in dict_s.items():
    if value > max_val:
        max_val = value
        ans = key

print(ans)

#решение уравнения типа ax**2 + bx + c = 0 (куча условий)
from math import sqrt
a, b, c = list(map(int, input().split()))
D = b**2 - (4*a*c)

if a == 0:
    if b == 0 and c != 0:
        print('Корней нет')
    elif b == 0 and c == 0:
        print('infinite number of solutions')
    else:
        print(-c / b)
else:
    if D == 0:
        x1 = -b / (2 * a)
        print(x1)
    elif D > 0:
        x1 = (-b + sqrt(D))/(2*a)
        x2 = (-b - sqrt(D))/(2*a)
        print(min(x1, x2), max(x1, x2))
    else:
        print('Корней нет')
