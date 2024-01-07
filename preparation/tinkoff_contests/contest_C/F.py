n = int(input())
arr = []
for _ in range(n):
    num = int(input())
    arr.append(num)

permutations = set()
for i in range(0,len(arr)-2):
    if (arr[i] > arr[i+1] > arr[i+2]): 
        permutations.add((arr[i], arr[i+1], arr[i+2]))

print(permutations)