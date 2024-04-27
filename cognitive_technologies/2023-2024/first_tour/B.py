x = int(input())

def solution(x):
    fact_list = []
    for i in range(50):
        if i < 2:
            fact_list.append(1)
        else:
            fact = 1
            for j in range(1, i+1):
                fact *= j**j
            fact_list.append(fact)
    
    for i in range(len(fact_list)):
        for j in range(len(fact_list) - i):
            if fact_list[i] + fact_list[j] == x:
                return "YES"
    return "NO"

print(solution(x))