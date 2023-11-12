n, k = list(map(int, input().split()))
a_list = list(map(int, input().split()))

arr_sum = 0
for el in a_list:
    arr_sum += el

print(k-arr_sum)
