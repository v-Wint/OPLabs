
def factorial(num):
    """returns the factorial of a given number"""
    result = 1
    while num:
        result *= num
        num -= 1
    return result

def get_euler_number():
    result = 1.0

    #25 iterations is enough 
    for i in range(1, 26):
        result += 1 / factorial(i)

    return result


def main():

    prec = int(input("Precision (num of significant digits) = "))

    if prec > 51: print("Sorry, but 51 is the maximum precision")

    #build resulting string to show e num with given precision
    result_str = "e = {:." + str(prec-1) + "f}"
    print(result_str.format(get_euler_number()).rstrip('0'))

if __name__ == "__main__":
    main()
