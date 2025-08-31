
#include <stdio.h>

/*
 * This program copies a source string into a destination buffer using pointers.
 * It demonstrates how to create a custom function that mimics the standard
 * library's strcpy() function.
 */

// Define a maximum buffer size to prevent buffer overflows.
#define MAX_BUFFER_SIZE 100

// Function prototype
void stringCopy(char *destination, const char *source);

int main() {
    // The source string we want to copy.
    const char *source_string = "Pointers are powerful!";

    // The destination buffer where the string will be copied.
    // It's important to ensure this buffer is large enough to hold the source string and the null terminator.
    char destination_string[MAX_BUFFER_SIZE];

    printf("--- Copying a String Using Pointers ---\n\n");
    printf("Source string:      \"%s\"\n", source_string);

    // Call the custom function to perform the copy.
    stringCopy(destination_string, source_string);

    printf("Destination string: \"%s\"\n", destination_string);

    return 0;
}

/*
 * Copies a null-terminated string from a source to a destination.
 * @param destination A pointer to the character buffer where the string will be copied.
 * @param source      A constant pointer to the first character of the string to be copied.
 */
void stringCopy(char *destination, const char *source) {
    // The loop continues as long as the character at the source pointer is not the null terminator.
    while (*source != '\0') {
        // Copy the character from the source to the destination.
        *destination = *source;

        // Move both pointers to the next character.
        source++;
        destination++;
    }

    // After the loop finishes, we must add a null terminator to the end of the destination string.
    // This is crucial for it to be a valid C-string.
    *destination = '\0';
}

