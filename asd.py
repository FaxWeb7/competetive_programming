s = input()

dict_s = {}
for now in s:
    if now not in dict_s.keys():
        dict_s[now] = 0
    dict_s[now] = 1

max_val = 0
ans = ''
for key, value in dict_s.items():
    if value > max_val:
        max_val = value
        ans = key

print(ans)