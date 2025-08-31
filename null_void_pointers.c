
#include <stdio.h>

/*
 * This program demonstrates the concepts of NULL and void pointers in C.
 * - A NULL pointer is a pointer that does not point to any valid memory address.
 *   It's a good practice to initialize pointers to NULL if they are not assigned a valid address.
 * - A void pointer (void*) is a generic pointer that can hold the address of any data type.
 *   It cannot be dereferenced directly and must be cast to a specific type first.
 */
int main() {
    printf("--- Demonstrating NULL Pointers ---\n\n");

    // Declare a pointer and initialize it to NULL.
    // NULL is a macro defined in <stdio.h> (and other headers) that represents a null-pointer constant.
    int *p_null = NULL;

    // A NULL pointer does not point to a valid memory location.
    printf("The value of the NULL pointer is: %p\n", p_null);

    // Checking if a pointer is NULL is a common way to see if it's valid to use.
    if (p_null == NULL) {
        printf("The pointer is currently a NULL pointer.\n");
    }

    // Dereferencing a NULL pointer leads to undefined behavior (often a crash).
    // The following line is commented out to prevent the program from crashing.
    // printf("Value at NULL pointer: %d\n", *p_null);

    printf("\n--- Demonstrating Void Pointers (Generic Pointers) ---\n\n");

    // Declare a void pointer.
    void *p_void;

    int i = 10;
    char c = 'A';
    double d = 3.14;

    // A void pointer can hold the address of any data type.
    p_void = &i;
    printf("Void pointer holds address of integer: %p\n", p_void);
    // To use the value, you must cast the void pointer back to the correct type.
    printf("Value of integer: %d\n\n", *( (int*) p_void) );

    p_void = &c;
    printf("Void pointer holds address of character: %p\n", p_void);
    // Cast to char* to dereference.
    printf("Value of character: %c\n\n", *( (char*) p_void) );

    p_void = &d;
    printf("Void pointer holds address of double: %p\n", p_void);
    // Cast to double* to dereference.
    printf("Value of double: %f\n", *( (double*) p_void) );

    return 0;
}

