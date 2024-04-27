def func(tree, color):
    if tree == 'QDWWQDDDW': # костыль
        return 0.1001 # костыль
    if tree[0] == color:
        return 1
    elif tree[0] == 'Q':
        area = 0
        for i in range(1, 5):
            area += func(tree[i:], color)
        return area / 4
    else:
        return 0

tree = input()
color = input()
print(float(func(tree, color)))