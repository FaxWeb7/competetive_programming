n = int(input())

results  = []
for i in range(n):
    employees = int(input())
    for i in input().split():
        results.append(int(i))

def sorting(list):
    if len(list) < 2:
        return list
    else:
        pivot = list[0]
        left = [i for i in list[1:] if i <= pivot]
        right = [i for i in list[1:] if i > pivot]
        return sorting(left) + [pivot] + sorting(right)
results.sort(reverse=True)

pairs = []
i = 0
while len(pairs) <= (len(results)+1)//2 and i < len(results)-1:
    j = i+1
    local_pair = [results[i]]
    while j < len(results)-2 and results[i] == results[j]:
        local_pair.append(results[j])
        j+=1
    if len(local_pair) == 1:
        local_pair.append(results[i+1])
    i+=len(local_pair)
    if i >= len(results)-1:
        local_pair.append(results[-1])
        pairs.append(local_pair)
        break
    pairs.append(local_pair)

ans = 0
for pair in pairs:
    ans += sum(pair)/len(pair)
print(ans)