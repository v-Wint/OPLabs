
def get_h(a, b, n):
    return (b - a)/n

def main():
    try:
        a, b, n = float(input("a = ")), float(input("b = ")), int(input("n = "))

        if n == 0:
            print("Sorry, but n cannot be 0")
            return
    except:
        print("Oh-oh, it seems the data you entered is invalid ^_^")
        return

    h = get_h(a, b, n)

    for i in range(1, n + 1):
        result = a + i*h
        print(f"{i} — {round(result, 5)}")

main()