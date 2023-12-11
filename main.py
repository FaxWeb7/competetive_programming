n = input().split()

def solution_1(n):
    ans = []
    for num in n:
        num_len = len(num)
        if (num_len % 2 == 0) and (num[:num_len//2] == num[:(num_len//2)-1:-1]):
                ans.append(num)
        elif (num_len % 2 != 0) and (num[:num_len//2] == num[:num_len//2:-1]):
                ans.append(num)
    return ' '.join(ans)

def solution_2(n):
    ans = []
    for num in n:
        if num == num[::-1]: 
            ans.append(num)
    return ' '.join(ans)

print(solution_1(n) + '\n' + solution_1(n))