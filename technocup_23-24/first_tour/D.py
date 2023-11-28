from sys import stdin, stdout
from itertools import permutations

n = int(stdin.readline())

res = 0
guess = int('1' + ('0'*(n-1)))
while len(str(guess)) == n:
    if guess % 3 != 0:
        if '1' in str(guess) or '3' in str(guess) or '5' in str(guess) or '7' in str(guess) or '9' in str(guess):
            variations = list(permutations([i for i in str(guess)]))
            variations = [''.join(variation) for variation in variations]
            is_okay = True
            for el in variations:
                if int(el) % 2 != 0 and int(el) % 5 != 0 and int(el) % 10 != 0:
                    is_okay = False
            if is_okay:
                res += 1
    guess += 1


stdout.write(str(res))