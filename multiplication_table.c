/*
 * Program: Multiplication Table Generator
 * Purpose: This program teaches beginners about:
 *          - for loops, while loops, and do-while loops
 *          - Loop initialization, condition, and increment
 *          - When to use different types of loops
 *          - Repetitive operations and iteration
 * Demonstrates: All three loop types doing the same task
 */

#include <stdio.h>

int main()
{
    /*
     * STEP 1: VARIABLE DECLARATIONS
     */
    int num;      // The number whose table we want to generate
    int range;    // How many multiples to show (1 to range)
    int i;        // Loop counter variable (stands for "index" or "iterator")
    
    /*
     * STEP 2: GET INPUT FROM USER
     */
    printf("Enter a number for multiplication table: ");
    scanf("%d", &num);     // Store the number for which we want the table
    
    printf("Enter the range (up to which number): ");
    scanf("%d", &range);   // How many lines of table to show
    
    printf("\n--- Multiplication Table of %d ---\n", num);
    
    /*
     * METHOD 1: USING FOR LOOP
     * for loop is best when you know exactly how many times to repeat
     * Syntax: for(initialization; condition; increment)
     */
    printf("\nUsing for loop:\n");
    
    for(i = 1; i <= range; i++)  // Start i=1, continue while i<=range, increment i each time
    {
        // Loop body - this code runs 'range' number of times
        printf("%d x %d = %d\n", num, i, num * i);
        
        /*
         * What happens each iteration:
         * 1st iteration: i=1, prints "num x 1 = num*1"
         * 2nd iteration: i=2, prints "num x 2 = num*2"
         * ... and so on until i > range
         */
    }
    
    /*
     * METHOD 2: USING WHILE LOOP
     * while loop is good when condition might change during execution
     * You must manually handle initialization and increment
     */
    printf("\nUsing while loop:\n");
    
    i = 1;                    // INITIALIZATION: Start counter at 1
    while(i <= range)         // CONDITION: Continue while i is <= range
    {
        printf("%d x %d = %d\n", num, i, num * i);  // Loop body
        i++;                  // INCREMENT: MUST manually increment i
                              // i++ is same as i = i + 1
        
        /*
         * IMPORTANT: If you forget i++, you get infinite loop!
         * The condition i <= range will always be true
         */
    }
    
    /*
     * METHOD 3: USING DO-WHILE LOOP
     * do-while guarantees the loop body runs at least once
     * Condition is checked AFTER the body executes
     */
    printf("\nUsing do-while loop:\n");
    
    i = 1;                    // INITIALIZATION: Reset counter to 1
    do
    {
        printf("%d x %d = %d\n", num, i, num * i);  // Loop body executes first
        i++;                  // INCREMENT: Increase counter
    } while(i <= range);      // CONDITION: Check condition after body execution
    
    /*
     * DIFFERENCE BETWEEN while AND do-while:
     * - while: checks condition first, might not execute body at all
     * - do-while: executes body first, then checks condition
     * 
     * Example: if range = 0
     * - while loop: won't print anything (condition false from start)
     * - do-while loop: will print one line, then stop
     */
    
    return 0;
    
    /*
     * KEY LEARNING POINTS:
     * 
     * 1. LOOP COMPONENTS:
     *    - Initialization: Set starting value
     *    - Condition: When to continue looping
     *    - Increment/Update: How to change the loop variable
     * 
     * 2. CHOOSING THE RIGHT LOOP:
     *    - for: When you know exact number of iterations
     *    - while: When condition might change during execution
     *    - do-while: When you need to execute at least once
     * 
     * 3. COMMON MISTAKES:
     *    - Forgetting to increment in while/do-while loops (infinite loop)
     *    - Wrong condition (< instead of <=, or vice versa)
     *    - Not initializing loop variable
     * 
     * 4. LOOP VARIABLE (i):
     *    - Usually named i, j, k for nested loops
     *    - Must be initialized before while/do-while
     *    - Gets updated automatically in for loop
     *    - Used to control how many times loop runs
     */
}
