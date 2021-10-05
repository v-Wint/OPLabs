def factorial(num):
    """returns the factorial of a given number"""
    result = 1
    while num:
        result *= num
        num -= 1
    return result

def get_euler_number(E):
    """calculate euler's number with given precision E"""

    term = lambda n: 1 / factorial(n)

    result = 1.0
    i = 1

    while True:
        t =  term(i)
        if t >= E:
            result += t
            i += 1
        else:
            break

    return result

def main():
    try:
        E = float(input("Precision E (0, 1] = "))
    except:
        print("Invalid precision")
        return

    if not 0 < E <= 1:
        print("Invalid precision")
        return

    print("e = {:.50f}".format(get_euler_number(E)).rstrip('0').rstrip('.'))

if __name__ == "__main__":
    main()
