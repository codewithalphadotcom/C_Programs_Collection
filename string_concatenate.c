
#include <stdio.h>

/*
 * This program concatenates (appends) a source string to the end of a destination string.
 * It uses pointers to first find the end of the destination string and then to copy
 * the source string, character by character.
 * This custom function mimics the standard library's strcat() function.
 */

// Define a buffer size large enough for both strings combined.
#define MAX_BUFFER_SIZE 100

// Function prototype
void stringConcat(char *destination, const char *source);

int main() {
    // The destination buffer. It must be large enough to hold the final concatenated string.
    char destination_string[MAX_BUFFER_SIZE] = "Hello, ";
    
    // The source string to be appended.
    const char *source_string = "World!";

    printf("--- Concatenating Two Strings Using Pointers ---\n\n");
    printf("Initial destination string: \"%s\"\n", destination_string);
    printf("Source string to append:    \"%s\"\n", source_string);

    // Call the custom function to perform the concatenation.
    stringConcat(destination_string, source_string);

    printf("\nFinal destination string:   \"%s\"\n", destination_string);

    return 0;
}

/*
 * Appends a source string to the end of a destination string.
 * @param destination A pointer to the destination buffer. This string will be modified.
 * @param source      A constant pointer to the source string to be appended.
 */
void stringConcat(char *destination, const char *source) {
    // 1. Find the end of the destination string.
    //    Move the destination pointer forward until it points to the null terminator ('\0').
    while (*destination != '\0') {
        destination++;
    }

    // 2. Copy the source string to the end of the destination string.
    //    This loop copies each character from source, including the final null terminator.
    while (*source != '\0') {
        *destination = *source;
        destination++;
        source++;
    }

    // 3. Add the null terminator to the very end of the newly concatenated string.
    *destination = '\0';
}

