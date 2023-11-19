n = int(input())
list = []
for i in range(n):
    list.append(input())

for el in ['OK', 'WA', 'PE', 'RE', 'ML', 'TL']:
    if el not in list:
        print(el)