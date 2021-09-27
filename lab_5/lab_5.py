def rev_num(num):
    """returns reversed integer"""
    rev_num = 0
    while num > 0:
        rem = num % 10
        rev_num = rev_num*10 + rem
        num = num // 10
    return rev_num

def main():
    for num in range(1000000, 1000000001):
        if num == rev_num(num):
            print(num)

main()
