

for b in range(1000000):
    counter = 0
    for i in range(270000, 300000):
        if i < b:
            if i % 7 == 0 and sum(int(j) for j in str(i)) < 13:
                counter += 1
        else:
            break
    print(counter)
    if counter == 4702:
        print(b)