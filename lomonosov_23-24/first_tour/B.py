
n = int(input())
list = []
for i in range(n):
    list.append(input())

list_dict = []
for i in range(len(list)):
    dict = {}
    for j in range(len(list[i])):
        try:
            if int(list[i][j]):
                dict[list[i][j+1]] = int(list[i][j]) + dict[list[i][j+1]]if list[i][j+1] in dict.keys() else int(list[i][j])
        except:
            pass
    list_dict.append(dict)

price_dict = {'a': 1, 'b': 5, 'c': 10, 'd': 50, 'e': 100, 'f': 200, 'g': 500, 'h': 1000, 'i': 2500}
sum_list = []
for i in range(len(list_dict)):
    sum = 0
    for k, v in list_dict[i].items():
        sum += v * price_dict[k]
    sum_list.append(sum)

result = []
best_first = 0
best_second = float('inf')
for i in range(len(sum_list)):
    k = sum_list[i]
    for j in range(i+1, len(sum_list)):
        l = sum_list[j]
        if (i < j) and (abs(k - l) > best_first) and (k + l < best_second):
            result = [i+1, j+1]
            best_first = abs(k - l)
            best_second = k + l

print(result[0])
print(result[1])