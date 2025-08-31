
#include <stdio.h>

/*
 * This program demonstrates how to search for a character within a string using a pointer.
 * It features a custom function that returns a pointer to the first occurrence of the
 * character in the string, or NULL if the character is not found.
 * This mimics the standard library's strchr() function.
 */

// Function prototype
char* findChar(const char *str, char character_to_find);

int main() {
    const char *my_string = "C programming is fun!";
    char target_char_1 = 'g';
    char target_char_2 = 'z';

    printf("--- Searching for a Character in a String ---\n\n");
    printf("String: \"%s\"\n\n", my_string);

    // --- Test Case 1: Character is found ---
    printf("Searching for character: '%c'\n", target_char_1);
    char *found_location = findChar(my_string, target_char_1);

    if (found_location != NULL) {
        // The result is a pointer, so we can print its address and the substring starting from it.
        printf("Character '%c' found at address: %p\n", target_char_1, found_location);
        printf("The rest of the string from this point is: \"%s\"\n", found_location);
    } else {
        printf("Character '%c' was not found.\n", target_char_1);
    }

    printf("\n---------------------------------------------\n\n");

    // --- Test Case 2: Character is not found ---
    printf("Searching for character: '%c'\n", target_char_2);
    found_location = findChar(my_string, target_char_2);

    if (found_location != NULL) {
        printf("Character '%c' found at address: %p\n", target_char_2, found_location);
    } else {
        printf("Character '%c' was not found.\n", target_char_2);
    }

    return 0;
}

/*
 * Finds the first occurrence of a character in a string.
 * @param str The null-terminated string to search within.
 * @param character_to_find The character to look for.
 * @return A pointer to the first occurrence of the character, or NULL if not found.
 */
char* findChar(const char *str, char character_to_find) {
    // Loop through the string as long as we haven't hit the null terminator.
    while (*str != '\0') {
        // If the character at the current pointer location matches the target...
        if (*str == character_to_find) {
            // ...return the current pointer.
            return (char*)str; // Cast to non-const to match return type.
        }
        // Move to the next character.
        str++;
    }

    // If the loop finishes without finding the character, it means it's not in the string.
    return NULL;
}

