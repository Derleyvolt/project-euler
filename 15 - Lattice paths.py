// (40 escolhe 20)

def fact(n):
    if n <= 1:
        return 1;
    return fact(n-1) * n

print(fact(40) // (fact(20) * fact(20)))
