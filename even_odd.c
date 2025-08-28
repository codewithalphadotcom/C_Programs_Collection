/*
 * Program: Even or Odd Number Checker
 * Purpose: This program teaches beginners about:
 *          - Modulo operator (%) and its applications
 *          - if-else conditional statements
 *          - Conditional (ternary) operator as an alternative
 *          - Multiple approaches to solve the same problem
 *          - Mathematical concept of even and odd numbers
 * Demonstrates: Different ways to implement conditional logic in C
 * 
 * Mathematical Background:
 * - Even numbers: Divisible by 2 (remainder is 0) - Examples: 2, 4, 6, 8, 10
 * - Odd numbers: Not divisible by 2 (remainder is 1) - Examples: 1, 3, 5, 7, 9
 */

#include <stdio.h>

int main()
{
    /*
     * STEP 1: VARIABLE DECLARATION
     */
    int number;  // Variable to store the user's input number
                 // We use int because we're working with whole numbers
    
    /*
     * STEP 2: GET INPUT FROM USER
     */
    printf("Enter a number: ");
    scanf("%d", &number);  // Read integer input from user
                           // %d is format specifier for integers
                           // & is address operator - tells scanf where to store the input
    
    /*
     * METHOD 1: USING IF-ELSE STATEMENT
     * This is the most common and readable approach for beginners
     */
    
    // THE MODULO OPERATOR EXPLAINED:
    // number % 2 gives the remainder when number is divided by 2
    // Examples: 5 % 2 = 1, 6 % 2 = 0, 7 % 2 = 1, 8 % 2 = 0
    
    if(number % 2 == 0)  // If remainder is 0, number is divisible by 2
    {
        printf("%d is an even number.\n", number);
        /*
         * EXPLANATION OF THE CONDITION:
         * - number % 2 calculates remainder of number ÷ 2
         * - == is comparison operator (tests equality)
         * - If remainder equals 0, the condition is true
         * - True condition means number is evenly divisible by 2 (even)
         */
    }
    else  // If remainder is not 0 (it will be 1), number is odd
    {
        printf("%d is an odd number.\n", number);
        /*
         * LOGIC EXPLANATION:
         * - If the number is not even, it must be odd
         * - Any integer divided by 2 gives remainder of either 0 or 1
         * - Remainder 0 = even, remainder 1 = odd
         */
    }
    
    /*
     * METHOD 2: USING CONDITIONAL (TERNARY) OPERATOR
     * This is a more compact way to write simple if-else logic
     * Syntax: condition ? value_if_true : value_if_false
     */
    printf("Using conditional operator: %d is %s\n", 
           number, (number % 2 == 0) ? "even" : "odd");
    
    /*
     * BREAKDOWN OF CONDITIONAL OPERATOR:
     * - (number % 2 == 0) is the condition being tested
     * - ? separates condition from the two possible results
     * - "even" is returned if condition is true
     * - : separates the true result from false result
     * - "odd" is returned if condition is false
     * - %s in printf displays the string result
     * 
     * This entire conditional operator replaces the if-else block above!
     */
    
    return 0;
}

/*
 * KEY LEARNING POINTS:
 * 
 * 1. MODULO OPERATOR (%):
 *    - Returns remainder of integer division
 *    - Very useful for checking divisibility
 *    - Examples: 10 % 3 = 1, 15 % 5 = 0, 7 % 4 = 3
 *    - Common uses: even/odd checking, cycling through values
 * 
 * 2. COMPARISON OPERATORS:
 *    - == tests equality (different from = which assigns)
 *    - != tests inequality 
 *    - Always returns true (1) or false (0)
 * 
 * 3. IF-ELSE STATEMENTS:
 *    - Used for making decisions in programs
 *    - if condition is true, execute first block
 *    - else executes when condition is false
 *    - Braces {} are optional for single statements but recommended
 * 
 * 4. CONDITIONAL OPERATOR (TERNARY OPERATOR):
 *    - Compact alternative to simple if-else statements
 *    - Format: condition ? true_result : false_result
 *    - Useful for simple choices, but can become hard to read if nested
 *    - Called "ternary" because it takes three operands
 * 
 * 5. PROBLEM-SOLVING APPROACHES:
 *    - Same problem can be solved multiple ways
 *    - Choose method based on readability and context
 *    - if-else is more readable for complex conditions
 *    - Conditional operator is good for simple assignments
 * 
 * 6. MATHEMATICAL CONCEPTS IN PROGRAMMING:
 *    - Even/odd classification is fundamental in mathematics
 *    - Many algorithms use even/odd properties
 *    - Understanding math concepts helps in programming logic
 * 
 * 7. COMMON MISTAKES TO AVOID:
 *    - Using = instead of == in conditions
 *    - Forgetting that % only works with integers
 *    - Not considering negative numbers (they follow same even/odd rules)
 */
