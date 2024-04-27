for b in range(1000000):
    res = []
    for i in range(270000):
        if i < b:
            if i % 7 == 0 and sum(int(j) for j in str(i)) < 13:
                res.append(i)
    print(b, len(res))
    if len(res) == 2702:
        print(b)
        break