from sys import stdin, stdout

n = int(stdin.readline())
file_list = []
for _ in range(n):
    file_list.append(stdin.readline().split('\n')[0])

dwlded_files = []
for file in file_list:
    if file not in dwlded_files:
        dwlded_files.append(file)
    else:
        split_file = file.split('.')
        if len(split_file) == 2:
            dwlded_files.append(split_file[0] + f'({file_list.count(file)-1}).' + split_file[1])
        else:
            dwlded_files.append(f'{file}({file_list.count(file)-1})')

for item in sorted(dwlded_files):
    stdout.write(item + "\n")




# from sys import stdin, stdout

# n = int(stdin.readline())
# file_list = []
# for _ in range(n):
#     file_list.append(stdin.readline().split('\n')[0])

# dwlded_files = []
# for file in file_list:
#     if file not in dwlded_files:
#         dwlded_files.append(file)
#     else:
#         split_file = file.split('.')
#         counter = []
#         for el in dwlded_files:
#             try:
#                 counter.append(int(el.split(file)[1][1]))
#             except: pass
#         if len(split_file) == 2:
#             dwlded_files.append(split_file[0] + f'({max(counter) + 1 if counter != [] else 1}).' + split_file[1])
#         else:
#             dwlded_files.append(f'{file}({max(counter) + 1 if counter != [] else 1})')

# for item in sorted(dwlded_files):
#     stdout.write(item + "\n")