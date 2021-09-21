
def func(x, a):
    if x < 0:
        y = x
    else:
        y = a
    return y

def main():
    try:
        x = float(input("x = "))
        a = float(input("A = "))
    except:
        print("Invalid data")
        return

    y = func(x, a)

    print(f"y = {y}")
    
main()

