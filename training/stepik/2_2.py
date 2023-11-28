# 6
# n = int(input())

# i = 1
# result = set()
# while i*i <= n:
#     if n % i == 0:
#         result.add(i)
#         result.add(n//i)
#     i+=1

# print(*sorted(list(result)))

# 8
n = int(input())

def is_prime(n):
    d = 2
    while n % d != 0 and d * d <= n:
        d += 1
    return d * d > n

i = 2
result = set()
while i*i <= n:
    if n % i == 0:
        if is_prime(i): result.add(i)
        if is_prime(n//i): result.add(n//i)
    i+=1

if is_prime(n): result.add(n)
print(*sorted(list(result)))