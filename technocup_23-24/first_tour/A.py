from sys import stdin, stdout

a = int(stdin.readline())
b = int(stdin.readline())
c = int(stdin.readline())

list = sorted([a, b, c])

if list[1]-list[0] == list[2]-list[1] and list[2]-list[1] > 0:
    stdout.write(f'A {list[0]} {list[1]} {list[2]}\n')
elif list[1]/list[0] == list[2]/list[1] and list[2]/list[1] > 1:
    stdout.write(f'G {list[0]} {list[1]} {list[2]}\n')
else:
    stdout.write(f'No\n')
