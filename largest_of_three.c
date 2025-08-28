/*
 * Program: Find Largest of Three Numbers
 * Purpose: This program teaches beginners about:
 *          - Complex conditional logic and decision making
 *          - Logical operators (&& - AND, || - OR)
 *          - Nested if-else statements
 *          - Conditional (ternary) operator usage
 *          - Multiple approaches to solve the same problem
 *          - Comparison operations and algorithm thinking
 * Demonstrates: Three different methods to find maximum value
 * 
 * Problem Analysis:
 * Given three numbers, we need to determine which one is the largest.
 * This is a common programming problem that appears in many real-world scenarios.
 */

#include <stdio.h>

int main()
{
    /*
     * STEP 1: VARIABLE DECLARATIONS
     */
    int num1, num2, num3;  // Three input numbers from the user
    int largest;           // Variable to store the result (largest number)
    
    /*
     * STEP 2: GET INPUT FROM USER
     * We read all three numbers in a single scanf statement
     */
    printf("Find the Largest of Three Numbers\n");
    printf("=================================\n");
    printf("Enter three numbers: ");
    scanf("%d %d %d", &num1, &num2, &num3);
    /*
     * INPUT EXPLANATION:
     * - %d %d %d reads three integers separated by spaces
     * - User can input: "5 12 8" or "100 50 75", etc.
     * - scanf automatically parses the space-separated values
     */
    
    printf("\nInput numbers: %d, %d, %d\n", num1, num2, num3);
    
    /*
     * METHOD 1: USING NESTED IF-ELSE STATEMENTS
     * This is the most readable and beginner-friendly approach
     * We systematically check each number against the other two
     */
    printf("\n--- Method 1: Nested if-else ---\n");
    
    if(num1 >= num2 && num1 >= num3)  // Check if num1 is largest
    {
        largest = num1;
        /*
         * LOGICAL OPERATOR EXPLANATION:
         * && means "AND" - both conditions must be true
         * num1 >= num2 AND num1 >= num3 must both be true
         * >= means "greater than or equal to" (handles ties)
         * 
         * This condition asks: "Is num1 greater than or equal to 
         * both num2 AND num3?"
         */
    }
    else if(num2 >= num1 && num2 >= num3)  // Check if num2 is largest
    {
        largest = num2;
        /*
         * This else-if executes only if the first condition was false
         * It checks if num2 is greater than or equal to both num1 and num3
         */
    }
    else  // If neither num1 nor num2 is largest, then num3 must be largest
    {
        largest = num3;
        /*
         * LOGICAL DEDUCTION:
         * If we reach this else clause, we know:
         * - num1 is NOT >= both num2 and num3
         * - num2 is NOT >= both num1 and num3
         * Therefore, num3 must be the largest (or tied for largest)
         */
    }
    
    printf("Largest number is: %d\n", largest);
    
    /*
     * METHOD 2: USING CONDITIONAL (TERNARY) OPERATOR
     * This is a more compact but potentially harder-to-read approach
     * It uses nested conditional operators to make the decision
     */
    printf("\n--- Method 2: Conditional operator ---\n");
    
    largest = (num1 > num2) ? ((num1 > num3) ? num1 : num3) : ((num2 > num3) ? num2 : num3);
    /*
     * CONDITIONAL OPERATOR BREAKDOWN:
     * Format: condition ? value_if_true : value_if_false
     * 
     * Step-by-step analysis:
     * 1. (num1 > num2) ? ... : ...  // First, compare num1 and num2
     * 2. If num1 > num2 is true:
     *    - Execute: (num1 > num3) ? num1 : num3  // Compare num1 with num3
     *    - If num1 > num3: return num1
     *    - If num1 <= num3: return num3
     * 3. If num1 > num2 is false (num2 >= num1):
     *    - Execute: (num2 > num3) ? num2 : num3  // Compare num2 with num3
     *    - If num2 > num3: return num2
     *    - If num2 <= num3: return num3
     */
    
    printf("Largest number is: %d\n", largest);
    
    /*
     * METHOD 3: STEP-BY-STEP COMPARISON APPROACH
     * This method assumes the first number is largest, then updates as needed
     * It's simple, intuitive, and easily extendable to more numbers
     */
    printf("\n--- Method 3: Step by step ---\n");
    
    largest = num1;  // Start by assuming num1 is the largest
    /*
     * ALGORITHM STRATEGY:
     * 1. Assume first number is largest
     * 2. Compare with second number, update if second is larger
     * 3. Compare with third number, update if third is larger
     * 4. Result: largest will contain the maximum value
     */
    
    if(num2 > largest)      // Is num2 larger than current largest?
        largest = num2;     // Yes, so num2 becomes the new largest
    
    if(num3 > largest)      // Is num3 larger than current largest?
        largest = num3;     // Yes, so num3 becomes the new largest
    
    /*
     * WHY THIS WORKS:
     * - After first comparison: largest = max(num1, num2)
     * - After second comparison: largest = max(max(num1, num2), num3)
     * - This gives us the maximum of all three numbers
     * 
     * ADVANTAGE: Easy to extend to more numbers (just add more if statements)
     */
    
    printf("Largest number is: %d\n", largest);
    
    /*
     * STEP 3: DISPLAY SUMMARY
     */
    printf("\n--- Summary ---\n");
    printf("Among %d, %d, and %d, the largest is %d\n", num1, num2, num3, largest);
    
    return 0;
}

/*
 * KEY LEARNING POINTS:
 * 
 * 1. LOGICAL OPERATORS:
 *    - && (AND): Both conditions must be true
 *    - || (OR): At least one condition must be true  
 *    - ! (NOT): Reverses the truth value
 *    - Use parentheses to clarify complex logical expressions
 * 
 * 2. COMPARISON OPERATORS:
 *    - > (greater than), < (less than)
 *    - >= (greater than or equal), <= (less than or equal)
 *    - == (equal to), != (not equal to)
 *    - >= and <= handle ties (equal values) properly
 * 
 * 3. NESTED IF-ELSE LOGIC:
 *    - else-if creates a chain of mutually exclusive conditions
 *    - Only one branch will execute
 *    - Order matters: conditions are checked from top to bottom
 *    - Final 'else' catches all remaining cases
 * 
 * 4. CONDITIONAL OPERATOR USAGE:
 *    - Compact but can become hard to read when nested deeply
 *    - Good for simple choices, avoid for complex logic
 *    - Always use parentheses to clarify precedence
 * 
 * 5. ALGORITHM DESIGN APPROACHES:
 *    - Method 1: Explicit comparison of all combinations
 *    - Method 2: Nested conditional decisions
 *    - Method 3: Iterative improvement (assume and update)
 *    - Each has pros and cons in different situations
 * 
 * 6. PROBLEM-SOLVING STRATEGIES:
 *    - Break complex problems into simpler comparisons
 *    - Consider edge cases (what if all numbers are equal?)
 *    - Think about scalability (how to extend to more numbers?)
 *    - Choose the method that's clearest for your specific use case
 * 
 * 7. REAL-WORLD APPLICATIONS:
 *    - Finding maximum values in datasets
 *    - Determining highest scores in competitions
 *    - Selecting optimal choices from multiple options
 *    - Quality control (finding best measurements)
 * 
 * 8. TESTING CONSIDERATIONS:
 *    - Test with all different numbers: 5, 12, 8
 *    - Test with some equal: 10, 10, 8
 *    - Test with all equal: 7, 7, 7
 *    - Test with negative numbers: -5, -2, -10
 *    - Test edge cases to ensure algorithm works correctly
 */
