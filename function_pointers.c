
#include <stdio.h>

/*
 * This program demonstrates the use of function pointers in C.
 * A function pointer is a variable that stores the memory address of a function.
 * This allows for a form of dynamic dispatch where the function to be called
 * can be decided at runtime.
 * We will implement a simple calculator that uses an array of function pointers.
 */

// Define function prototypes for our arithmetic operations.
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);

int main() {
    // Declare a function pointer. The syntax is:
    // return_type (*pointer_name)(parameter_types);
    double (*operation)(double, double);

    double num1 = 10.0;
    double num2 = 5.0;

    printf("--- Using a Single Function Pointer ---\n\n");

    // Assign the address of the 'add' function to the pointer.
    operation = add;
    // Call the function through the pointer.
    printf("%.1f + %.1f = %.1f\n", num1, num2, operation(num1, num2));

    // Assign the address of the 'subtract' function.
    operation = subtract;
    printf("%.1f - %.1f = %.1f\n", num1, num2, operation(num1, num2));

    printf("\n--- Using an Array of Function Pointers ---\n\n");

    // Create an array of function pointers.
    double (*operations[4])(double, double) = {add, subtract, multiply, divide};
    char symbols[] = {'+', '-', '*', '/'};
    
    // Loop through the array and call each function.
    for (int i = 0; i < 4; i++) {
        // operations[i] is a pointer to a function.
        double result = operations[i](num1, num2);
        printf("%.1f %c %.1f = %.1f\n", num1, symbols[i], num2, result);
    }

    return 0;
}

// --- Function Definitions ---

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    if (b != 0) {
        return a / b;
    } else {
        printf("Error: Division by zero!\n");
        return 0.0;
    }
}

