
def func(x, a):
    if x < 0:
        y = x
    else:
        y = a
    return y

def main():
    x = float(input("x = "))
    a = float(input("A = "))
        
    y = func(x, a)

    print("y = {}".format(y))
    

main()
