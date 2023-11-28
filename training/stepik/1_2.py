# 6
# import sys
# import itertools

# n, q = map(int, sys.stdin.readline().split())
# arr = [int(x) for x in sys.stdin.readline().split()]
# data_sum = list(itertools.accumulate(arr))
# for _ in range(q):
#     a, b = map(int, sys.stdin.readline().split())
#     sys.stdout.write(f"{data_sum[b - 1] - data_sum[a - 2] if a > 1 else data_sum[b-1]}\n")

# 7
# import sys

# n = sys.stdin.readline()
# arr = [int(x) for x in sys.stdin.readline().split()]

# maxTillNow = arr[0] 
# maxEnding = 0 
# for n in range(len(arr)): 
#     maxEnding = maxEnding + arr[n] 
#     if maxEnding < 0 and arr[n] < 0: 
#         maxEnding = 0 
#     elif maxTillNow < maxEnding: 
#         maxTillNow = maxEnding 

# sys.stdout.write(str(maxTillNow))  

# 8
import sys

year = int(sys.stdin.readline())

is_find = False
new_year = year
while is_find == False:
    new_year = new_year+1
    if '0' not in str(new_year) and '2' not in str(new_year):
        res = ''
        for i in range(len(str(new_year))-2):
            if i < len(str(new_year))-3:
                if str(new_year)[i] != str(new_year)[i+2] and str(new_year)[i] != str(new_year)[i+3] and str(new_year)[i+1] != str(new_year)[i+2] and str(new_year)[i+1] != str(new_year)[i+3] and str(new_year)[i] != str(new_year)[i+1]:
                    res += '1'
                else:
                    res += '0'
                    break
            elif i < len(str(new_year))-2:
                if str(new_year)[i] != str(new_year)[i+2] and str(new_year)[i+1] != str(new_year)[i+2] and str(new_year)[i] != str(new_year)[i+1]:
                    res += '1'
                else:
                    res += '0'
                    break
        is_find = True if '0' not in res else False
print(new_year)