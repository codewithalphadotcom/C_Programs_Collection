/*
 * Program: User-Defined Functions Demonstration
 * Purpose: This program teaches beginners about:
 *          - Function declaration, definition, and calling
 *          - Function prototypes and their importance
 *          - Parameter passing (by value and by reference)
 *          - Return values and void functions
 *          - Function reusability and modular programming
 * Demonstrates: Different types of functions with various parameter patterns
 */

#include <stdio.h>

/*
 * FUNCTION PROTOTYPES (DECLARATIONS)
 * These tell the compiler what functions exist and their signatures
 * Function signature = name + parameter types + return type
 * Must be declared before main() if functions are defined after main()
 */

int add(int a, int b);                    // Returns int, takes two int parameters
float calculateCircleArea(float radius);  // Returns float, takes one float parameter  
int factorial(int n);                     // Returns int, takes one int parameter
void printPattern(int rows);              // Returns nothing (void), takes one int
int isPrime(int num);                     // Returns int (0/1 for false/true)
void swapValues(int *a, int *b);          // Takes pointers (addresses) as parameters

/*
 * MAIN FUNCTION - PROGRAM ENTRY POINT
 * This function demonstrates calling all our user-defined functions
 */
int main()
{
    /*
     * VARIABLE DECLARATIONS
     * We need variables to store user input and function results
     */
    int choice;           // User's menu choice
    int num1, num2;       // Two numbers for addition or swapping
    int result;           // To store results from functions that return int
    int n;                // General purpose number input
    float radius, area;   // For circle area calculation
    
    /*
     * MENU-DRIVEN PROGRAM
     * Display options and get user choice
     */
    printf("Functions Demonstration Program\n");
    printf("1. Addition of two numbers\n");
    printf("2. Calculate circle area\n");
    printf("3. Calculate factorial\n");
    printf("4. Print triangle pattern\n");
    printf("5. Check if number is prime\n");
    printf("6. Swap two numbers\n");
    printf("Enter your choice (1-6): ");
    scanf("%d", &choice);
    
    switch(choice)
    {
        case 1:
            printf("Enter two numbers: ");
            scanf("%d %d", &num1, &num2);
            result = add(num1, num2);
            printf("Sum of %d and %d is: %d\n", num1, num2, result);
            break;
            
        case 2:
            printf("Enter radius of circle: ");
            scanf("%f", &radius);
            area = calculateCircleArea(radius);
            printf("Area of circle with radius %.2f is: %.2f\n", radius, area);
            break;
            
        case 3:
            printf("Enter a number: ");
            scanf("%d", &n);
            if(n < 0)
            {
                printf("Factorial is not defined for negative numbers.\n");
            }
            else
            {
                result = factorial(n);
                printf("Factorial of %d is: %d\n", n, result);
            }
            break;
            
        case 4:
            printf("Enter number of rows: ");
            scanf("%d", &n);
            printf("Triangle Pattern:\n");
            printPattern(n);
            break;
            
        case 5:
            printf("Enter a number: ");
            scanf("%d", &n);
            if(isPrime(n))
                printf("%d is a prime number.\n", n);
            else
                printf("%d is not a prime number.\n", n);
            break;
            
        case 6:
            printf("Enter two numbers: ");
            scanf("%d %d", &num1, &num2);
            printf("Before swapping: a = %d, b = %d\n", num1, num2);
            swapValues(&num1, &num2);
            printf("After swapping: a = %d, b = %d\n", num1, num2);
            break;
            
        default:
            printf("Invalid choice!\n");
    }
    
    return 0;
}

/*
 * FUNCTION DEFINITIONS
 * Each function has a distinct purpose and demonstrates different concepts
 */

/*
 * Function: add
 * Purpose: Adds two integers and returns the result
 * Parameters: 
 *   - a: First integer (passed by value)
 *   - b: Second integer (passed by value)
 * Returns: Sum of a and b
 * Demonstrates: Simple function with parameters and return value
 */
int add(int a, int b)  // Function header with return type, name, and parameters
{
    // Function body - what the function does
    return a + b;     // Calculate and return result in one step
    
    // After return, function execution stops and control goes back to caller
}

/*
 * Function: calculateCircleArea
 * Purpose: Computes the area of a circle given its radius
 * Parameters:
 *   - radius: The radius of the circle (float for decimal precision)
 * Returns: Area of the circle as a float
 * Demonstrates: Working with floating point values and constants
 */
float calculateCircleArea(float radius)
{
    const float PI = 3.14159;  // const makes this value unchangeable
                              // Local constants are only visible inside this function
    
    return PI * radius * radius;  // Formula: Area = π × r²
}

/*
 * Function: factorial
 * Purpose: Calculates factorial of a non-negative integer
 * Parameters:
 *   - n: The number to calculate factorial for
 * Returns: n! (n factorial)
 * Demonstrates: Iterative approach to mathematical calculation
 * 
 * NOTE: This function uses an iterative approach (with a loop)
 * See recursion_examples.c for a recursive version
 */
int factorial(int n)
{
    int fact = 1;  // Initialize result (0! and 1! are both 1)
    
    // Multiply: 1 × 2 × 3 × ... × n
    for(int i = 1; i <= n; i++)  // Note: i is local to this loop
    {
        fact *= i;  // Same as: fact = fact * i;
    }
    
    return fact;  // Return the calculated factorial
}

/*
 * Function: printPattern
 * Purpose: Prints a triangle pattern of asterisks
 * Parameters:
 *   - rows: Number of rows in the pattern
 * Returns: Nothing (void)
 * Demonstrates: void function (no return value) and nested loops
 */
void printPattern(int rows)  // void means this function doesn't return anything
{
    // Outer loop controls rows
    for(int i = 1; i <= rows; i++)  // i goes from 1 to rows
    {
        // Inner loop controls columns in current row
        // Each row i has i stars
        for(int j = 1; j <= i; j++)  // j is local to this inner loop
        {
            printf("* ");  // Print star and space
        }
        printf("\n");  // Move to next line after each row
    }
    
    // No return statement needed for void functions
    // (return; is optional at the end of void functions)
}

/*
 * Function: isPrime
 * Purpose: Determines if a number is prime
 * Parameters:
 *   - num: The number to check
 * Returns: 1 if number is prime, 0 if not prime (like a boolean)
 * Demonstrates: Using return values as true/false and algorithm optimization
 */
int isPrime(int num)
{
    // Special cases handling
    if(num <= 1)
        return 0;  // Numbers less than or equal to 1 are not prime
    
    if(num <= 3)
        return 1;  // 2 and 3 are prime numbers
    
    // Quick check for divisibility by 2 or 3
    if(num % 2 == 0 || num % 3 == 0)
        return 0;  // Numbers divisible by 2 or 3 are not prime
    
    /*
     * Optimization: Check divisibility only up to square root of num
     * Further optimization: Check only numbers of form 6k±1
     * (because all primes greater than 3 are of form 6k±1)
     */
    for(int i = 5; i * i <= num; i += 6)  // Start at 5, increment by 6
    {
        // Check if num is divisible by i or i+2 (forms 6k-1 and 6k+1)
        if(num % i == 0 || num % (i + 2) == 0)
            return 0;  // Not prime if divisible
    }
    
    return 1;  // If we get here, the number is prime
}

/*
 * Function: swapValues
 * Purpose: Swaps the values of two integers
 * Parameters:
 *   - a: Pointer to first integer (passed by reference)
 *   - b: Pointer to second integer (passed by reference)
 * Returns: Nothing (void) - values are changed via pointers
 * Demonstrates: Pass by reference using pointers and memory manipulation
 */
void swapValues(int *a, int *b)  // * indicates pointer (address) parameters
{
    /*
     * IMPORTANT: This function demonstrates pass by reference
     * Unlike other functions that pass by value (make copies),
     * this function receives memory addresses and modifies
     * the original variables directly.
     */
    
    int temp = *a;  // Dereference pointer a to get its value and store in temp
    *a = *b;        // Copy value at address b to address a
    *b = temp;      // Copy temp to address b
    
    /*
     * After this function runs, the original variables passed to it
     * will have their values swapped, because we modified memory directly
     * through pointers rather than working with copies.
     */
}

/*
 * KEY LEARNING POINTS ABOUT FUNCTIONS:
 * 
 * 1. FUNCTION STRUCTURE:
 *    - Return Type: What data type the function gives back (or void for nothing)
 *    - Name: Descriptive identifier for the function
 *    - Parameters: Input values the function needs (with their types)
 *    - Body: Code that executes when function is called
 * 
 * 2. PARAMETER PASSING:
 *    - Pass by Value: Function gets a copy (changes don't affect original)
 *    - Pass by Reference: Function gets an address (changes affect original)
 *    - Pointers (*) are used for pass by reference
 * 
 * 3. RETURN VALUES:
 *    - return statement sends a value back to the caller
 *    - void functions don't return a value
 *    - return immediately exits the function
 * 
 * 4. VARIABLE SCOPE:
 *    - Variables declared inside a function are local to that function
 *    - Parameters are local to the function
 *    - Variables in loops are local to that loop
 * 
 * 5. FUNCTION BENEFITS:
 *    - Reusability: Write once, use many times
 *    - Modularity: Break complex problems into manageable pieces
 *    - Readability: Well-named functions make code more understandable
 *    - Maintainability: Fix one function instead of multiple code blocks
 */
