def condition(a,b,c,d,e,f,g,h,i):
    return (not(b and not(c) and d and not(e) and f and not(g) and h and not(i)) or not(a and not(b) and c and not(d) and e and not(f) and g and not(h))) and i

for a in range(1000):
    if all(condition(a,b,c,d,e,f,g,h,i) for b in range(1000) for c in range(1000) for d in range(1000) for e in range(1000) for f in range(1000) for g in range(1000) for h in range(1000) for i in range(1000)):
        print(1)