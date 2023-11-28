def binary_search(arr, item):
    low = 0
    high = len(arr) - 1
    while low <= high:
        mid = (high + low) // 2
        if arr[mid] == item:
            return mid
        elif arr[mid] < item:
            low = mid + 1
        else:
            high = mid - 1
    return None


arr = [1,2,3,4,5,6,7,8,9,10,12,16,19,23,28,33]
print(binary_search(arr, 16))