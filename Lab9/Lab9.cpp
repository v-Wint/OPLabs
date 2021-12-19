#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <string>

#define SIZE 100

using namespace std;

int getListOfWords(char*, char(&)[SIZE][SIZE]);
bool isPalindrome(char*);

int main()
{
    // string input 
    char initialString[SIZE];
    puts("Enter the string:");
    gets_s(initialString);

    // get the list of the words from the initial string
    char listOfWords[SIZE][SIZE];
    int numOfWords = getListOfWords(initialString, listOfWords);

    //print all the palindromes
    cout << "\nPalindromes: \n";
    int numOfPalindromes = 0;
    for (int i = 0; i < numOfWords; i++) {
        if (isPalindrome(listOfWords[i])) {
            cout << listOfWords[i] << endl;
            numOfPalindromes++;
        }
    }
    printf("\nNumber of palindromes: %d\n", numOfPalindromes);

    return 0;
}

int getListOfWords(char* str, char(&listOfWords)[SIZE][SIZE]) {
    char* token = strtok(str, " ");
    int numberOfWords = 0;
    while (token != NULL)
    {
        strcpy(listOfWords[numberOfWords++], token);
        token = strtok(NULL, " ");
    }
    return numberOfWords;
}


bool isPalindrome(char* str) {
    char newWord[SIZE];
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++)
        if (str[i] != str[len - i - 1])
            return false;
    return true;
}