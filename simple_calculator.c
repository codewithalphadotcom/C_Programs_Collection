/*
 * Program: Simple Calculator
 * Purpose: This program teaches beginners about:
 *          - switch-case statements for multiple conditions
 *          - Basic arithmetic operations
 *          - Error handling (division by zero)
 *          - Character input and comparison
 * Demonstrates: Mathematical operations, conditional logic, error prevention
 */

#include <stdio.h>  // Required for printf() and scanf() functions

int main()  // Program execution begins here
{
    /*
     * STEP 1: VARIABLE DECLARATIONS
     * We need variables to store the numbers and the operator
     */
    
    float num1, num2;    // float allows decimal numbers (like 3.14, 2.5)
                         // We use float instead of int to handle decimal calculations
    
    float result;        // This will store the answer of our calculation
    
    char operator;       // This will store the operation symbol (+, -, *, /)
                         // char can store a single character
    
    /*
     * STEP 2: GETTING INPUT FROM USER
     * We collect two numbers and an operator from the user
     */
    
    printf("Simple Calculator\n");        // Title of our program
    printf("Enter first number: ");       // Prompt user for first number
    scanf("%f", &num1);                  // Read first number (float format)
    
    printf("Enter operator (+, -, *, /): "); // Show available operations
    scanf(" %c", &operator);             // Read operator character
                                           // Space before %c is IMPORTANT!
                                           // It clears any leftover newline from previous input
    
    printf("Enter second number: ");      // Prompt for second number
    scanf("%f", &num2);                  // Read second number
    
    /*
     * STEP 3: PERFORMING CALCULATION BASED ON OPERATOR
     * switch-case is perfect when we have multiple specific conditions
     * It's cleaner than multiple if-else statements
     */
    
    switch(operator)  // Check the value of 'operator' variable
    {
        case '+':  // If operator is '+' (addition)
            result = num1 + num2;                    // Perform addition
            printf("%.2f + %.2f = %.2f\n", num1, num2, result);
            // %.2f means show 2 decimal places
            break;  // IMPORTANT: break prevents fall-through to next case
            
        case '-':  // If operator is '-' (subtraction)
            result = num1 - num2;                    // Perform subtraction
            printf("%.2f - %.2f = %.2f\n", num1, num2, result);
            break;
            
        case '*':  // If operator is '*' (multiplication)
            result = num1 * num2;                    // Perform multiplication
            printf("%.2f * %.2f = %.2f\n", num1, num2, result);
            break;
            
        case '/':  // If operator is '/' (division)
            /*
             * DIVISION REQUIRES SPECIAL HANDLING!
             * We must check if we're dividing by zero
             * Division by zero is undefined in mathematics and causes errors
             */
            if(num2 != 0)  // != means "not equal to"
            {
                result = num1 / num2;               // Safe to divide
                printf("%.2f / %.2f = %.2f\n", num1, num2, result);
            }
            else  // If second number is 0
            {
                printf("Error: Division by zero!\n");
                // We display error instead of crashing the program
            }
            break;
            
        default:  // If operator doesn't match any of the above cases
            printf("Error: Invalid operator!\n");
            // This handles cases like user entering 'x' or '&' etc.
    }
    
    /*
     * STEP 4: PROGRAM ENDS SUCCESSFULLY
     */
    return 0;
    
    /*
     * KEY LEARNING POINTS:
     * 1. switch-case is efficient for checking multiple specific values
     * 2. Always use 'break' after each case to prevent fall-through
     * 3. 'default' case handles unexpected inputs
     * 4. Always check for division by zero before dividing
     * 5. float is better than int for calculators (handles decimals)
     * 6. %.2f formats floating point numbers to 2 decimal places
     * 7. Space before %c in scanf() clears input buffer
     * 8. Error handling makes programs more user-friendly
     */
}
