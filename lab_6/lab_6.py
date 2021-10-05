def factorial(num):
    """returns the factorial of a given number"""
    result = 1
    while num:
        result *= num
        num -= 1
    return result

def cos_func(x, E):
    """returns approximal cos of a given number 
    with given precision E using Taylor series"""

    #the term of the progression
    def term(n):
        res = x**(2*n) / factorial(2*n)
        return -res if n % 2 else res

    result = 1
    i = 1
    while True:
        t = term(i)
        if abs(t) >= E:
            result += t
            i += 1
        else:
            break

    return result

def main():
    try:
        a, b, E = float(input("a = ")), float(input("b = ")), float(input("Precision E (>0) = "))
    except:
        print("Invalid input")
        return

    if E <= 0:
        print("E must be greater than 0")
        return

    y = cos_func(a, E) + cos_func(b, E)**2 + cos_func(a+b, E)

    print(f"y = {round(y, 9)}")


if __name__ == "__main__":
    main()



