N, v_max = list(map(int, input().split()))
s_list = []
t_list = []
for i in range(N):
    data = list(map(int, input().split()))
    s_list.append(data[0]*data[1])
    t_list.append(data[1])

print(0 if sum(s_list)/sum(t_list) <= v_max else 1)