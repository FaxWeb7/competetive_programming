for _ in range(int(input())):
    n, m = list(map(int, input().split()))
    v_list = set()
    u_list = []
    for _ in range(n):
        v, u = list(map(int, input().split()))
        v_list.add(v)
        u_list.append(u)
        ...