w, h = list(map(int, input().split()))
A_x, A_y = list(map(int, input().split()))
B_x, B_y = list(map(int, input().split()))

def make_hard_path_x1(A_x, A_y, B_x, B_y, w, h):
    steps = 0
    steps += (w+1) - A_x
    A_x = 1
    A_y = (h + 1) - A_y
    steps += abs(A_x - B_x) + abs(A_y - B_y)
    return steps

def make_hard_path_x2(A_x, A_y, B_x, B_y, w, h):
    steps = 0
    steps += A_x
    A_x = w
    A_y = (h + 1) - A_y
    steps += abs(A_x - B_x) + abs(A_y - B_y)
    return steps

def make_hard_path_y1(A_x, A_y, B_x, B_y, w, h):
    steps = 0
    steps += (h+1) - A_y
    A_x = (w + 1) - A_x
    A_y = 1
    steps += abs(A_x - B_x) + abs(A_y - B_y)
    return steps

def make_hard_path_y2(A_x, A_y, B_x, B_y, w, h):
    steps = 0
    steps += A_y
    A_x = (w + 1) - A_x
    A_y = h
    steps += abs(A_x - B_x) + abs(A_y - B_y)
    return steps


simple_path = abs(A_x - B_x) + abs(A_y - B_y)
hard_path_x1 = make_hard_path_x1(A_x, A_y, B_x, B_y, w, h)
hard_path_x2 = make_hard_path_x2(A_x, A_y, B_x, B_y, w, h)
hard_path_y1 = make_hard_path_y1(A_x, A_y, B_x, B_y, w, h)
hard_path_y2 = make_hard_path_y2(A_x, A_y, B_x, B_y, w, h)
print(min(simple_path, hard_path_x1, hard_path_x2, hard_path_y1, hard_path_y2))