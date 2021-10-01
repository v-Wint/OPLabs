def factorial(num):
    """returns the factorial of a given number"""
    result = 1
    while num:
        result *= num
        num -= 1
    return result

def get_euler_number(E):
    """calculate euler's number with given precision E"""
    result = 1.0
    i = 1
    while 1 / factorial(i) >= E:
        result += 1 / factorial(i)
        i += 1

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

    print(f"e = {get_euler_number(E)}")

if __name__ == "__main__":
    main()
