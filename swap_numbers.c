
#include <stdio.h>

/*
 * This program demonstrates how to use pointers to swap the values of two variables.
 * A function is created that takes pointers as arguments, allowing it to modify
 * the original variables in the calling function (a concept known as 'pass-by-reference').
 */

// Function prototype for swap.
// It takes two integer pointers as arguments.
void swap(int *a, int *b);

int main() {
    int num1 = 10;
    int num2 = 20;

    printf("--- Swapping Two Numbers Using Pointers ---\n\n");

    printf("Original values:\n");
    printf("num1 = %d, num2 = %d\n", num1, num2);

    // Call the swap function.
    // We pass the addresses of num1 and num2 using the '&' operator.
    swap(&num1, &num2);

    printf("\nValues after swapping:\n");
    printf("num1 = %d, num2 = %d\n", num1, num2);

    return 0;
}

/*
 * Swaps the integer values at the two given addresses.
 * @param a Pointer to the first integer.
 * @param b Pointer to the second integer.
 */
void swap(int *a, int *b) {
    // Create a temporary variable to hold one of the values.
    int temp;

    // 1. Store the value at the address 'a' in 'temp'.
    //    We use the dereference operator '*' to get the value.
    temp = *a;

    // 2. Copy the value from the address 'b' to the address 'a'.
    *a = *b;

    // 3. Copy the value from 'temp' to the address 'b'.
    *b = temp;

    // After these steps, the values at the memory locations pointed to by 'a' and 'b'
    // have been successfully swapped.
}

