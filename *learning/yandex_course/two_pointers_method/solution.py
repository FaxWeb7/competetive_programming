n = int(input())
numbers = list(map(int, input().split()))
guess = int(input())

def find_pair(numbers, guess):
    low = 0
    high = len(numbers) - 1
    while low != high:
        sum = numbers[low] + numbers[high]
        if sum == guess:
            return f'{numbers[low]} {numbers[high]}'
        elif sum < guess:
            low += 1
        elif sum > guess:
            low -= 1

    return None

print(find_pair(numbers, guess))

# 2nd solution
# n = int(input())
# numbers = list(map(int, input().split()))
# guess = int(input())

# def find_pair(numbers, guess):
#     previous = set()
#     for A in numbers:
#         Y = guess - A
#         if Y in previous:
#             return A, Y
#         else:
#             previous.add(A)

#     return None, None 

# print(find_pair(numbers, guess))