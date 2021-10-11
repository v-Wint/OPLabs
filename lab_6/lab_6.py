def cos_func(x, E):
    """returns approximal cos of a given number 
    with given precision E using Taylor series"""

    result = 0.0
    term_ = 1.0
    term = 1.0
    i = 1.0

    while True:
        result += term
        term_ = term

        # every other term equals the previous term multiplied by -x^2/(2n*(2n-1)
        term = - term * x**2 / (2*i*(2*i-1))

        i += 1.0

        if abs(term - term_) < E:
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

    y = cos_func(a, E) + cos_func(a+b, E)

    print("y = {:.9f}".format(round(y, 9)))


if __name__ == "__main__":
    main()



