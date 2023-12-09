def condition(a,b,c):
    return (((a <= b) <= (b <= c)) ==((a and b) <= (b and c))) and (((a and b) <= (b and c)) ==((a ^ b) <= (b ^ c)))

counter = 0
for a in range(100000):
    print(a)
    if all(condition(a,b,c) for b in range(100000) for c in range(100000)):
        counter += 1
print(counter)