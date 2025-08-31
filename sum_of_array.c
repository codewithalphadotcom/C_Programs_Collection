
#include <stdio.h>

/*
 * This program calculates the sum of all elements in an integer array.
 * It demonstrates two common ways to use pointers to traverse an array:
 * 1. By using pointer arithmetic to move the pointer to the next element.
 * 2. By using array-style indexing on the pointer itself.
 */

// The size of our array
#define ARRAY_SIZE 5

int main() {
    int numbers[ARRAY_SIZE] = {10, 20, 30, 40, 50};
    int sum = 0;
    int *p_num; // A pointer to an integer

    printf("--- Sum of Array Elements Using a Pointer ---\n\n");
    printf("Array elements: ");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n\n");

    // --- Method 1: Using Pointer Arithmetic ---

    // Point the pointer to the beginning of the array.
    p_num = numbers;
    sum = 0; // Reset sum

    // Loop through the array using the pointer.
    // The loop continues as long as the pointer is before the end of the array.
    for (int i = 0; i < ARRAY_SIZE; i++) {
        // Add the value at the current pointer's address to the sum.
        sum += *p_num;

        // Move the pointer to the next element in the array.
        p_num++;
    }

    printf("Sum calculated using pointer arithmetic: %d\n", sum);

    // --- Method 2: Using Pointer with Array Indexing ---

    // Point the pointer to the beginning of the array again.
    p_num = numbers;
    sum = 0; // Reset sum

    // You can also use array-style square bracket notation with a pointer.
    // The compiler understands that p_num[i] is equivalent to *(p_num + i).
    for (int i = 0; i < ARRAY_SIZE; i++) {
        sum += p_num[i];
    }

    printf("Sum calculated using pointer with indexing: %d\n", sum);

    return 0;
}

