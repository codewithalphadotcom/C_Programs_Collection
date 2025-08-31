
#include <stdio.h>

/*
 * This program reverses the elements of an array in-place using pointers.
 * It uses two pointers: one starting at the beginning of the array and one
 * at the end. The elements they point to are swapped, and the pointers are
 * moved towards each other until they meet in the middle.
 */

// Define the size of the array
#define ARRAY_SIZE 7

// Function to print the elements of an array
void printArray(int arr[], int size);

int main() {
    int numbers[ARRAY_SIZE] = {10, 20, 30, 40, 50, 60, 70};

    printf("--- Reversing an Array Using Pointers ---\n\n");

    printf("Original array: ");
    printArray(numbers, ARRAY_SIZE);

    // Create a pointer to the start of the array.
    int *p_start = numbers;

    // Create a pointer to the end of the array.
    // Note: The last element is at index (ARRAY_SIZE - 1).
    int *p_end = &numbers[ARRAY_SIZE - 1];

    // Loop until the start pointer has crossed the end pointer.
    while (p_start < p_end) {
        // 1. Store the value from the start pointer in a temporary variable.
        int temp = *p_start;

        // 2. Copy the value from the end pointer to the start pointer's location.
        *p_start = *p_end;

        // 3. Copy the value from the temporary variable to the end pointer's location.
        *p_end = temp;

        // 4. Move the pointers closer to the center of the array.
        p_start++;
        p_end--;
    }

    printf("\nReversed array:  ");
    printArray(numbers, ARRAY_SIZE);

    return 0;
}

/*
 * Prints the elements of an integer array to the console.
 * @param arr The array to be printed.
 * @param size The number of elements in the array.
 */
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

