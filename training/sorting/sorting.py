""" -------------- АЛГОРИТМЫ СОРТИРОВКИ --------------
Сортировка пузырькоом — принцип работы: обходим массив от начала до конца, попутно меняя местами неотсортированные соседние элементы. В результате первого прохода на последнее место «всплывёт» максимальный элемент. Теперь снова обходим неотсортированную часть массива (от первого элемента до предпоследнего) и меняем по пути неотсортированных соседей. Второй по величине элемент окажется на предпоследнем месте. Продолжая в том же духе, будем обходить всё уменьшающуюся неотсортированную часть массива, запихивая найденные максимумы в конец. Скорость - O(n**2)

Сортировка выбором — принцип работы: 1. В неотсортированном подмассиве ищется локальный минимум 2. Найденный минимум меняется местами с первым элементом в подмассиве 3. Если в массиве остались неотсортированные подмассивы — повторяем цикл. Скорость - O(n**2)

Сортировка вставками - принцип работы: 1. Перебираются элементы в неотсортированной части массива. 2. Каждый элемент вставляется в отсортированную часть массива на то место, где он должен находиться. Скорость - O(n**2)

Быстрая сортировка - принцип работы: 1. определяется pivot - опорный элемент 2. все элементы, меньше опорного, помещаются в левый массив 3. все элементы, больше опорного, помещаются в правый массив 4. функция рекурсивно повторяется, возвращая список из левого списка + опорный элемент + правый список.Скорость O(n logn)
"""

def bubble_sort(arr):
    length = len(arr)
    while length != 0:
        for i in range(length-1):
            if arr[i] > arr[i+1]:
                arr[i], arr[i+1] = arr[i+1], arr[i]
        length-=1
    return arr
print(bubble_sort([64, 25, 12, 22, 11]))

def selectionSort(arr):
    for i in range(len(arr)):
        smallest_index = i
        for j in range(i+1, len(arr)):
            if arr[j] < arr[smallest_index]:
                smallest_index = j

        if smallest_index != i:
            arr[i], arr[smallest_index] = arr[smallest_index], arr[i]

    return arr
print(selectionSort([64, 25, 12, 22, 11]))

def insertion_sort(arr):
    for i in range(1, len(arr)):
        sorted = i - 1
        while sorted >= 0 and arr[sorted] > arr[i]:
            arr[sorted + 1] = arr[sorted]
            sorted -= 1
        arr[sorted + 1] = arr[i]
    return arr

def insertion_sort(arr):
    for i in range(1, len(arr)):
        current = arr[i]
        sorted = i - 1
        while sorted >= 0 and arr[sorted] > current:
            arr[sorted + 1] = arr[sorted]
            sorted -= 1
        arr[sorted + 1] = current
    return arr
print(insertion_sort([64, 25, 12, 22, 11]))

def qsort(arr):
    if len(arr) < 2:
        return arr
    else:
        pivot = arr[0]
        left = [el for el in arr[1:] if el <= pivot]
        right = [el for el in arr[1:] if el > pivot]
        return qsort(left) + [pivot] + qsort(right)
print(qsort([64, 25, 12, 22, 11]))