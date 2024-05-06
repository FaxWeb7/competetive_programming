# нахождение последнего числа x в последовательносьти seq
def findx(seq, x):
    ans = -1
    for i in range(len(seq)):
        if seq[i] == x:
            ans = i
    return ans

# нахождение максимального значения последовательности seq
def findMax(seq):
    ans = seq[0]
    for item in seq[1:]:
        if item > ans:
            ans = item
    return ans

# нахождение максимального значения seq и максимальное значение за вычетом первого максимального
def findTwoMax(seq):
    maxv = max(seq[0], seq[1])
    prevmax = min(seq[0], seq[1])
    for item in seq[2:]:
        if item >= maxv:
            prevmax = maxv
            maxv = item
        elif item > prevmax:
            prevmax = item
    return maxv, prevmax

# нахождение минимального числа последовательность кратного двум
def findEvenMin(seq):
    ans = -1
    for item in seq:
        if item % 2 == 0 and (ans == -1 or item < ans):
            ans = item
    return ans

# нахождение самых коротких слов массива
def shortestWord(words):
    minlen = len(words[0])
    for word in words:
        if len(word) < minlen:
            minlen = len(word)
    ans = []
    for word in words:
        if len(word) == minlen:
            ans.append(word)
    return ' '.join(ans)

# решение 7 задачи
def solution_7(nums):
    ans = 0
    for i in range(len(nums)-2):
        if nums[i] > nums[i+1]:
            ans += nums[i] - nums[i+1]
    return ans

# укоротить строку
def RLE(seq):
    ans = ''
    symbol_dict = {}
    for i in range(len(seq)):
        if seq[i] not in symbol_dict:
            symbol_dict[seq[i]] = 0
        symbol_dict[seq[i]] += 1

    for key in symbol_dict.keys():
        ans += f'{key}{symbol_dict[key]}' if symbol_dict[key] != 1 else key

    return ans
print(RLE('AAAABBCCCHGLLL'))