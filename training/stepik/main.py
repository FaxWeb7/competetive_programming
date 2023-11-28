n = int(input())
cur, a, b = list(map(int, input().split()))

nums = []
for i in range(n):
    cur = (cur * a + b) % 1791791791
    nums.append(cur)

max_1 = 0
for i in range(0, len(nums)):
    if nums[i] > nums[max_1]:
        max_1 = i
max_2 = 0
for i in range(0, len(nums)):
    if i != max_1:
        if nums[i] > nums[max_2]:
            max_2 = i
print(max_1 + 1, max_2 + 1 if max_1 != 0 else max_1 + 1)