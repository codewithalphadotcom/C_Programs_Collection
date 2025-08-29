#include <stdio.h>
#include <string.h>

// Function to check if a number is a palindrome
void checkNumberPalindrome()
{
    int n, reversedN = 0, remainder, originalN;
    printf("Enter an integer: ");
    scanf("%d", &n);
    originalN = n;

    // reverse the integer
    while (n != 0)
    {
        remainder = n % 10;
        reversedN = reversedN * 10 + remainder;
        n /= 10;
    }

    // check if the reversed integer is equal to the original integer
    if (originalN == reversedN)
        printf("%d is a palindrome.\n", originalN);
    else
        printf("%d is not a palindrome.\n", originalN);
}

// Function to check if a string is a palindrome
void checkStringPalindrome()
{
    char str[100];
    int i, len, flag = 0;

    printf("Enter a string: ");
    scanf("%s", str);

    len = strlen(str);

    for (i = 0; i < len / 2; i++)
    {
        if (str[i] != str[len - i - 1])
        {
            flag = 1;
            break;
        }
    }

    if (flag)
        printf("%s is not a palindrome.\n", str);
    else
        printf("%s is a palindrome.\n", str);
}

int main()
{
    int choice;

    printf("1. Check for number palindrome\n");
    printf("2. Check for string palindrome\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        checkNumberPalindrome();
        break;
    case 2:
        checkStringPalindrome();
        break;
    default:
        printf("Invalid choice!\n");
    }

    return 0;
}
