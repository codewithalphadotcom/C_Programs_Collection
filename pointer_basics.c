
#include <stdio.h>

/*
 * This program demonstrates the fundamental concepts of pointers in C.
 * - How to declare a pointer.
 * - How to initialize a pointer with the address of a variable.
 * - How to dereference a pointer to get the value it points to.
 */
int main() {
    // Declare an integer variable and initialize it.
    int number = 50;

    // Declare a pointer variable that can hold the address of an integer.
    // The '*' indicates that 'p_number' is a pointer.
    int *p_number;

    // Initialize the pointer.
    // The '&' (address-of) operator gets the memory address of the 'number' variable.
    // Now, 'p_number' holds the address of 'number'.
    p_number = &number;

    printf("--- Demonstrating Pointer Basics ---\n\n");

    // Print the value of the 'number' variable directly.
    printf("Value of 'number': %d\n", number);

    // Print the memory address of the 'number' variable using the '&' operator.
    // The '%p' format specifier is used to print pointer addresses in hexadecimal format.
    printf("Address of 'number' (&number): %p\n", &number);

    printf("\n--- Using the Pointer ---\n\n");

    // Print the value of the pointer variable 'p_number'.
    // This will be the same memory address as '&number'.
    printf("Value of pointer 'p_number' (address it holds): %p\n", p_number);

    // Dereference the pointer to get the value it points to.
    // The '*' (dereference) operator retrieves the value stored at the address the pointer is holding.
    printf("Value at the address pointed to by 'p_number' (*p_number): %d\n", *p_number);
    
    // You can also change the value of the original variable 'number' through the pointer.
    printf("\n--- Modifying a Variable via a Pointer ---\n\n");
    *p_number = 100; // This changes the value at the memory location, so 'number' is now 100.
    printf("New value of 'number' after modification via pointer: %d\n", number);


    return 0;
}

