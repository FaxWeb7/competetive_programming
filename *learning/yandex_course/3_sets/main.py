# создание собственного множества с хеш-функцией остатка от деления числа на 10
set_size = 10
my_set = [[] for _ in range(set_size)]

def add(item):
    position = item % set_size
    if not find(item):
        my_set[position].append(item)

def find(item):
    position = item % set_size
    for value in my_set[position]:
        if value == item:
            return True
    return False

def remove(item):
    item_list = my_set[item % set_size]
    for i in range(len(item_list)):
        if item_list[i] == item:
            item_list[i] = item_list[len(item_list) - 1]
            item_list.pop()
            return

# нахождение пары чисел массива, при сложении которых получится x за O(n**2)
def find_pair(n, x):
    for i in range(len(n)):
        for j in range(i+1, len(n)):
            if n[i] + n[j] == x:
                return n[i], n[j] 
    return 0, 0

# нахождение пары чисел массива, при сложении которых получится x за O(n)
def find_pair_2(n, x):
    dataset = set()
    for i in range(len(n)):
        if x - n[i] in dataset:
            return n[i], x - n[i]
        dataset.add(n[i])
    return 0, 0

# Задача 2
def words_in_dict(dictionary, text):
    good_words = []
    for word in dictionary:
        for del_let in range(len(word)):
            good_words.append(word[:del_let] + word[del_let + 1:])
    ans = []
    for word in text.split():
        ans.append(word in good_words)
    return ans

print(words_in_dict(['test', 'word', 'hello'], 'helo tet wo'))