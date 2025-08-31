
#include <stdio.h>

/*
 * This program demonstrates pointer arithmetic in C.
 * When you perform arithmetic operations (like incrementing or decrementing)
 * on a pointer, it moves the pointer by a number of bytes that is a multiple
 * of the size of the data type it points to.
 * 
 * For example, incrementing an 'int*' pointer moves the address by sizeof(int) bytes.
 */
int main() {
    // Create an array of integers.
    int numbers[] = {10, 20, 30, 40, 50};

    // Create a pointer that points to the first element of the array.
    // The name of an array acts as a pointer to its first element.
    int *p_num = numbers;

    printf("--- Demonstrating Pointer Arithmetic ---\n\n");

    // Print the address and value of the first element.
    printf("Pointer currently points to address: %p\n", p_num);
    printf("Value at this address: %d\n\n", *p_num);

    // Increment the pointer.
    p_num++; // This moves the pointer to the next integer in the array.

    // The new address will be sizeof(int) bytes greater than the previous one.
    printf("After p_num++, pointer points to address: %p\n", p_num);
    printf("Value at the new address: %d\n\n", *p_num); // Should be 20

    // We can also add integers to a pointer.
    p_num = p_num + 3; // This moves the pointer 3 * sizeof(int) bytes forward.
                       // It will now point to the 5th element (index 4).

    printf("After p_num = p_num + 3, pointer points to address: %p\n", p_num);
    printf("Value at the new address: %d\n\n", *p_num); // Should be 50

    // Decrement the pointer.
    p_num--; // This moves the pointer back to the previous integer.

    printf("After p_num--, pointer points to address: %p\n", p_num);
    printf("Value at the new address: %d\n\n", *p_num); // Should be 40
    
    // You can also find the distance between two pointers of the same type.
    int *p_start = &numbers[0];
    int *p_end = &numbers[4];
    long int distance = p_end - p_start; // The result is the number of elements, not bytes.

    printf("The distance between the start and end of the array is %ld elements.\n", distance);


    return 0;
}

