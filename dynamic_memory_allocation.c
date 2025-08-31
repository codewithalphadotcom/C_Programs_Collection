
#include <stdio.h>
#include <stdlib.h> // Required for malloc(), free()

/*
 * This program demonstrates dynamic memory allocation using malloc() and free().
 * Dynamic allocation allows you to request memory from the operating system at runtime,
 * which is essential when you don't know the amount of memory needed beforehand.
 *
 * - malloc() allocates a block of memory of a specified size and returns a void pointer
 *   to the beginning of the block.
 * - free() deallocates a block of memory, returning it to the system.
 */

int main() {
    int num_elements;
    int *arr = NULL; // Initialize pointer to NULL, a good practice.

    printf("--- Dynamic Memory Allocation for an Array ---\n\n");
    printf("Enter the number of elements for the array: ");
    scanf("%d", &num_elements);

    // Validate user input.
    if (num_elements <= 0) {
        printf("Invalid number of elements.\n");
        return 1; // Exit with an error code.
    }

    // 1. Allocate Memory
    //    - We need space for 'num_elements' integers.
    //    - The total size is num_elements * sizeof(int).
    //    - malloc() returns a void*, so we must cast it to the correct pointer type (int*).
    arr = (int *) malloc(num_elements * sizeof(int));

    // 2. Check if Allocation was Successful
    //    - If the system cannot provide the requested memory, malloc() returns NULL.
    //    - It is crucial to check for this to prevent using an invalid pointer.
    if (arr == NULL) {
        printf("Error: Memory allocation failed!\n");
        return 1; // Exit with an error code.
    }

    // 3. Use the Allocated Memory
    //    - The 'arr' pointer can now be used like a regular array.
    printf("\nMemory allocated successfully. You can now use the array.\n");
    for (int i = 0; i < num_elements; i++) {
        arr[i] = (i + 1) * 10; // Fill with some data, e.g., 10, 20, 30...
    }

    // Print the elements to verify.
    printf("Array elements: ");
    for (int i = 0; i < num_elements; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    // 4. Free the Memory
    //    - When you are finished with the dynamically allocated memory, you MUST free it.
    //    - Failing to do so results in a "memory leak".
    free(arr);
    printf("Memory has been freed.\n");

    // After freeing, the pointer 'arr' is now a "dangling pointer".
    // It points to memory that you no longer own. It is good practice to set it back to NULL.
    arr = NULL;

    return 0;
}

