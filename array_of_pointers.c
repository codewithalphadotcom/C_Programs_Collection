
#include <stdio.h>

/*
 * This program demonstrates the use of an array of pointers.
 * An array of pointers is an array where each element is a pointer to a specific
 * data type. This is a very common and efficient way to handle a collection of strings.
 */

int main() {
    // Declare an array of constant character pointers.
    // Each element of the array holds the starting address of a string literal.
    const char *days_of_week[] = {
        "Sunday",
        "Monday",
        "Tuesday",
        "Wednesday",
        "Thursday",
        "Friday",
        "Saturday"
    };

    // Calculate the number of elements in the array.
    int num_days = sizeof(days_of_week) / sizeof(days_of_week[0]);

    printf("--- Using an Array of Pointers to Strings ---\n\n");
    printf("The days of the week are:\n");

    // Loop through the array of pointers.
    for (int i = 0; i < num_days; i++) {
        // days_of_week[i] is a pointer to the start of the i-th string.
        // We can print it directly using the %s format specifier.
        printf("Day %d: %s\n", i + 1, days_of_week[i]);
    }

    printf("\n--- Memory Addresses ---\n\n");
    // This loop shows what is stored in the array itself.
    for (int i = 0; i < num_days; i++) {
        // days_of_week[i] is the address of the first character of the string.
        printf("Address stored in days_of_week[%d]: %p\n", i, days_of_week[i]);
    }

    return 0;
}

