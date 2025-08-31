
#include <stdio.h>

/*
 * This program calculates the length of a string by using a pointer.
 * It demonstrates how to create a custom function that mimics the standard
 * library's strlen() function.
 */

// Function prototype
int stringLength(const char *str);

int main() {
    // A string literal is a constant character array automatically terminated by a null character '\0'.
    const char *my_string = "Hello, Pointers!";

    printf("--- Finding the Length of a String Using a Pointer ---\n\n");
    printf("The string is: \"%s\"\n", my_string);

    // Call the custom function to get the length.
    int length = stringLength(my_string);

    printf("The length of the string is: %d\n", length);

    return 0;
}

/*
 * Calculates the length of a null-terminated string.
 * @param str A constant pointer to the first character of the string.
 *            'const' is used to indicate that the function will not modify the string.
 * @return The number of characters in the string, excluding the null terminator.
 */
int stringLength(const char *str) {
    // Create a second pointer and initialize it with the starting address of the string.
    const char *p_current = str;

    // Move the pointer forward one character at a time until it points to the null terminator ('\0').
    while (*p_current != '\0') {
        p_current++;
    }

    // The length of the string is the difference between the final and initial pointer positions.
    // Pointer subtraction gives the number of elements (in this case, chars) between them.
    return p_current - str;
}

