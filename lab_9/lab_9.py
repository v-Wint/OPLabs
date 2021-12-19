def main():
    input_string = input("Enter the string:\n")
    list_of_words = input_string.split(' ')
    num = 0
    print("Palindromes:")
    for word in list_of_words:
        if word == word[::-1]:
            print(word)
            num += 1
    print(f"\nNumber of palindromes: {num}")

if __name__ == "__main__":
    main()
