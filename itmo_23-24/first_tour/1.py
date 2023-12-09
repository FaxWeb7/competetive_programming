nums = []
for x in range(10000):
    bin_x = bin(x)[2:]

    quat_x = ''
    copy_x = x
    while copy_x != 0:
        quat_x = str(copy_x % 4) + quat_x
        copy_x //= 4
    
    if bin_x.count('1') == 5 and quat_x.count('1') == 5:
        nums.append(x)

print(len(nums))