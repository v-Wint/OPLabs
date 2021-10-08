def get_euler_number(E):
    """calculate euler's number with given precision E"""
    result = 0.0
    term = 1.0
    i = 1.0

    while term >= E:
        result += term
        # every other term is the  previous term devided by numeral
        term /= i
        i += 1.0

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
