for K in range(1000):
    n = 10
    m = []
    for i in range(n):
        m.append([0] * n)
    m[5][7] = 15
    m[3][9] = 10
    m[7][1] = 7
    for k in range(1000):
        if k < K:
            tmp = []
            for _ in range(n):
                tmp.append([0] * n)
            for i in range(1,1000):
                if i < (n-1):
                    for j in range(1, 1000):
                        if j < (n-1):
                            tmp[i][j] = m[i-1][j]+m[i+1][j]+m[i][j-1]+m[i][j+1]
                else:
                    m = tmp
        else:
            if max([max(i) for i in m]) == 549137445:
                print(K)



