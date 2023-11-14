from math import sqrt

def fib_mod(n, m):
    f =  ((1+sqrt(5))**n - (1-sqrt(5))**n)/2**n*sqrt(5)
    return f

def main():
    n, m = map(int, input().split())
    print(fib_mod(n, m))


if __name__ == "__main__":
    main()