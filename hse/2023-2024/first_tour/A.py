n = int(input())
m = int(input())
k = int(input())
matrix = []

counter = 0
for i in range(0, n-1):
    local_counter = 1
    list = []
    for i in range(m):
        element = (counter * m) + local_counter
        list.append(element)
        local_counter += 1
    matrix.append(list)
    counter += 1

last_element = []
last_counter = 1
for i in range(m):
    element = (n - 1) * m + last_counter
    last_element.append(element)
    last_counter += 1
matrix.append(last_element)

result = 0
for i in range(n):
    for j in range(m):
        if j != m-1 and abs(matrix[i][j] - matrix[i][j+1]):
            result += 1
        if i != n-1 and abs(matrix[i][j] - matrix[i+1][j]):
            result += 1

print(result)