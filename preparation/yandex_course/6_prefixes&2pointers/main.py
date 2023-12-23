# реализация rsq(range some query) для запроса суммы на отрезке массива
def make_prefixsum(nums):
    prefixsum = [0] * (len(nums) + 1)
    for i in range(1, len(nums)+1):
        prefixsum[i] = prefixsum[i - 1] + nums[i - 1]
    return prefixsum

def rsq(prefixsum, start, stop):
    return prefixsum[stop] - prefixsum[start]


# подсчет нулей в строке n для каждого из запроса m
def make_prefix_zeros(n, m):
    prefixsum = [0] * (len(n) + 1)
    for i in range(1, len(n) + 1):
        prefixsum[i] = prefixsum[i-1] + n[i-1].count('0')

    ans = []
    for l, r in m:
        ans.append(str(prefixsum[r] - prefixsum[l]))
    return ', '.join(ans)


# подсчет всех отрезков в строке, в сумме дающих 0 (за O(N))
def count_zero_ranges(n):
    prefixsum = {0: 1}
    nowsum = 0
    for now in n:
        nowsum += now
        if nowsum not in prefixsum:
            prefixsum[nowsum] = 0
        prefixsum[nowsum] += 1

    ans = 0
    for key in prefixsum:
        ans += prefixsum[key] * (prefixsum[key] - 1) // 2
    return ans


# найти кол-во пар A и B, что B-A>K в сортированном массиве sorted_nums (2 указателями)
def count_condition_pairs(sorted_nums, k):
    ans = 0
    right = 1
    for left in range(len(sorted_nums)):
        while right < len(sorted_nums) and sorted_nums[right] - sorted_nums[left] <= k:
            right += 1
    ans += len(sorted_nums) - right
    return ans


# поиск максимального по сумме элементов отрезка, такого, что любой элемент данного отрезка не больше суммы любых других двух элементов
def best_team_sum(skills):
    ans = 0
    nowsum = 0
    right = 0
    for left in range(len(skills)):
        while right < len(skills) and (left == right or skills[left] + skills[left+1] >= skills[right]):
            nowsum += skills[right]
            right += 1
        ans = max(ans, nowsum)
        nowsum -= skills[left]
    return ans


# слияние двух отсортированных массивов в один
def merge(arr1, arr2):
    l = r = 0
    new_arr = []
    for _ in range(len(arr1) + len(arr2)):
        if l < len(arr1) and (r == len(arr2) or arr1[l] <= arr2[r]):
            new_arr.append(arr1[l])
            l += 1
        else:
            new_arr.append(arr2[r])
            r += 1
        
    return new_arr