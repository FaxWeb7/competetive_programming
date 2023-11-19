# не проходит третий пример, тк не обработ случай с пересечением имен в строке
n, m = list(map(int, input().split()))
comand_name = input()

names = []
for _ in range(n):
    names.append(input())

positions = []
for name in names:
    last_char_position = comand_name.find(name) + len(name) - 1
    positions.append(last_char_position)

result = comand_name[0:max(positions)+1]
print(len(result) if len(result) < len(comand_name) else -1)