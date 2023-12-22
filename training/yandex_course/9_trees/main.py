# Код менеджера памяти дерева
def init_memory(maxn):
    memory = []
    for i in range(maxn):
        memory.append([0, i+1, 0])
    return [memory, 0]

def new_node(mem_struct):
    memory, first_free = mem_struct
    mem_struct[1] = memory[first_free][1]
    return first_free

def del_node(mem_struct, index):
    memory, first_free = mem_struct
    memory[index][1] = first_free
    mem_struct[1] = index


# реализация поиска в бинарном дереве
def find(mem_struct, root, x):
    key = mem_struct[0][root][0]
    if x == key:
        return root
    elif x < key:
        left = mem_struct[0][root][1]
        if left == -1:
            return -1
        else:
            return find(mem_struct, left, x)
    elif x < key:
        right = mem_struct[0][root][2]
        if right == -1:
            return -1
        else:
            return find(mem_struct, right, x)


# реализация добавления в бинарном дереве
def create_fill_node(mem_struct, key):
    index = new_node(mem_struct)
    mem_struct[0][index][0] = key
    mem_struct[0][index][1] = -1
    mem_struct[0][index][2] = -1
    return index

def add(mem_struct, root, x):
    key = mem_struct[0][root][0]
    if x < key:
        left = mem_struct[0][root][1]
        if left == -1:
            mem_struct[0][root][1] = create_fill_node(mem_struct, x)
        else:
            add(mem_struct, left, x)
    elif x > key:
        right = mem_struct[0][root][2]
        if right == -1:
            create_fill_node(mem_struct, x)
        else:
            add(mem_struct, right, x)

mem_struct = init_memory(20)
root = create_fill_node(mem_struct, 20)
add(mem_struct, root, 14)
add(mem_struct, root, 11)
add(mem_struct, root, 17)
add(mem_struct, root, 30)
add(mem_struct, root, 26)
add(mem_struct, root, 32)
print(mem_struct)
