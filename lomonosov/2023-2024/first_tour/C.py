# n = int(input())
# a = int(input())
# b = int(input())
# req_floors = list(map(int, input().split()))

# result = []
# for req_floor in req_floors:
#     current_floor = 0
#     path = ''
#     if req_floor > 0:

n = int(input())
A = int(input())
B = int(input())

for i in range(n):
    X = int(input())
    steps = []
    while X != 0:
        if X % B == 0:
            X //= B
            steps.append('B')
        else:
            X -= A
            steps.append('A')
    steps.reverse()
    for step in steps:
        print(step)