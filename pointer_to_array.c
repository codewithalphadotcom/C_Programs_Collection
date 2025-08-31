
#include <stdio.h>

/*
 * This program demonstrates the difference between a "pointer to an array" and a
 * regular "pointer to an integer". While they can both point to the first element
 * of an array, they are different types, and this affects how pointer arithmetic works.
 */

#define NUM_ROWS 2
#define NUM_COLS 3

int main() {
    int my_array[NUM_ROWS][NUM_COLS] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    printf("--- Pointer to an Array vs. Pointer to an int ---\n\n");

    // 1. A pointer to an integer.
    int *p_int;
    p_int = &my_array[0][0]; // Points to the very first integer (1).

    printf("p_int starts at address: %p, value: %d\n", p_int, *p_int);
    p_int++; // Moves by sizeof(int) bytes.
    printf("After p_int++, address:  %p, value: %d\n\n", p_int, *p_int); // Now points to 2.


    // 2. A pointer to an array of NUM_COLS integers.
    // The syntax is 'type (*pointer_name)[SIZE]'.
    int (*p_arr)[NUM_COLS];

    // Point it to the first row of my_array.
    p_arr = my_array;

    printf("p_arr starts at address: %p\n", p_arr);
    // To get a value, you must first dereference the array pointer, then the integer pointer.
    // (*p_arr) gives you the first row (an array).
    // (*p_arr)[0] gives you the first element of that row.
    printf("Value at (*p_arr)[0]: %d\n", (*p_arr)[0]);

    // Now, increment the pointer to the array.
    p_arr++; // Moves by sizeof(int[NUM_COLS]) bytes, which is an entire row.

    printf("After p_arr++, address:  %p\n", p_arr); // Now points to the start of the second row.
    printf("Value at (*p_arr)[0]: %d\n", (*p_arr)[0]); // Should be 4.

    return 0;
}

