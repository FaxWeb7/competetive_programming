from sys import stdin, stdout

n = int(stdin.readline())
files = []
for _ in range(n):
    files.append(stdin.readline().split('\n')[0])

res = {} # {file: #}
for file in files:
    if file not in res:
        res[file] = [file]
    else:
        res[file].append(file)

ans = []
for arr in sorted(res.values()):
    arr = sorted(arr)
    ans.append(arr[0])
    for i in range(1, len(arr)):
        filename = arr[i].split('.')[0]
        ext = ''
        if (len(arr[i].split('.')) == 2): ext = arr[i].split('.')[1]
        newfile = f'{filename}({i})'
        if (ext != ''): newfile += f'.{ext}'
        ans.append(newfile)

for file in sorted(ans):
    print(file)