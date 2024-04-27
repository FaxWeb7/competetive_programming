n, x, y = list(map(int, input().split()))
events = list(map(int, input().split()))

def can_attend_all_events(n, x, y, events):
    # for D in range(1, x + y + 1):
    #     if all((D - d) % (x + y) < x for d in events):
    #         return D - x - y if D - x - y >= 1 else D
    for i in range(1, x+y-1):
        for D in range(i, x + y - 1):
            if all((D - d) % (x + y) < x for d in events):
                return D - x - y if D - x - y >= 1 else D
    return -1

print(can_attend_all_events(n, x, y, events)) 