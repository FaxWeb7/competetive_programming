# сортировка подсчетом
def count_sorting(list):
    min_val = min(list)
    max_val = max(list)
    k = max_val - min_val + 1
    count = [0] * k
    for item in list:
        count[item-min_val] += 1
    now_pos = 0
    for val in range(k):
        for _ in range(count[val]):
            list[now_pos] = val + min_val
            now_pos += 1
    return list


# можно ли получить число x перестановкой цифр в числе y? (С помощью сортировки подсчетом)
def is_digit_permutation(x, y):
    def count_digits(num):
        digit_count = [0] * 10
        while num > 0:
            digit_count[num % 10] += 1
            num //= 10
        return digit_count
    digits_x = count_digits(x)
    digits_y = count_digits(y)
    for i in range(10):
        if digits_x[i] != digits_y[i]:
            return False
    return True

# Задача 2 про ладей (решение с помощью словаря, тк массив очень неэффективен в данном случае)
def count_beat_in_grooks(n, m, rookcoords):
    rook_row_coords = {}
    rook_col_coords = {}
    for row, col in rookcoords:
        if row not in rook_row_coords:
            rook_row_coords[row] = 0
        if col not in rook_col_coords:
            rook_col_coords[col] = 0
        rook_row_coords[row] += 1
        rook_col_coords[col] += 1

    pairs = 0
    for key in rook_row_coords:
        pairs += rook_row_coords[key] - 1
    for key in rook_col_coords:
        pairs += rook_row_coords[key] - 1
    return pairs

# выведение гистограммы строки
def gistogram(seq):
    count_symbols = {}
    for symbol in seq:
        if symbol not in count_symbols:
            count_symbols[symbol] = 0
        count_symbols[symbol] += 1
    
    sorted_symbols = sorted(count_symbols.keys())
    for i in range(max(count_symbols.values()), 0, -1):
        for symbol in sorted_symbols:
            if count_symbols[symbol] >= i:
                print('#', end='')
            else:
                print(' ', end='')
        print()
    print(''.join(sorted_symbols))

# разделение слова списка на группы по схожести, Задача 4 (решение с помощью словаря)
def group_words(arr):
    types = {}
    for item in arr:
        sorted_item = ''.join(sorted(item))
        if sorted_item not in types.keys():
            types[sorted_item] = []
        types[sorted_item].append(item)
    
    return [val for val in types.values()]

print(group_words(['eat', 'tea', 'tan', 'ate', 'nat', 'bat']))