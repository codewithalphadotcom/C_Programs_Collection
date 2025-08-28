/*
 * Program: Fibonacci Series Generator
 * Purpose: This program teaches beginners about:
 *          - Mathematical sequences and patterns
 *          - Loop-based sequence generation
 *          - Variable updating and state management
 *          - Input validation techniques
 *          - Multiple output formatting approaches
 * Demonstrates: Famous mathematical sequence implementation
 * 
 * Fibonacci Sequence Background:
 * - Named after Leonardo Fibonacci (Italian mathematician, ~1170-1250)
 * - Each number is the sum of the two preceding numbers
 * - Sequence: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...
 * - Formula: F(n) = F(n-1) + F(n-2), where F(0)=0, F(1)=1
 * - Found everywhere in nature: flower petals, spiral shells, tree branches
 */

#include <stdio.h>

int main()
{
    /*
     * STEP 1: VARIABLE DECLARATIONS
     * We need variables to track the sequence generation process
     */
    int n;         // Number of terms user wants to see
    int i;         // Loop counter variable
    
    // Variables for sequence generation:
    int first = 0;   // First Fibonacci number (F(1) = 0)
    int second = 1;  // Second Fibonacci number (F(2) = 1) 
    int next;        // Variable to calculate and store the next term
    
    /*
     * STEP 2: GET INPUT FROM USER WITH VALIDATION
     */
    printf("Enter the number of terms for Fibonacci series: ");
    scanf("%d", &n);
    
    // INPUT VALIDATION: Check if user entered a valid positive number
    if(n <= 0)
    {
        printf("Please enter a positive number.\n");
        return 1;  // Exit program with error code (non-zero = error)
                   // This prevents the program from continuing with invalid input
    }
    
    /*
     * STEP 3: GENERATE AND DISPLAY FIBONACCI SERIES
     * We handle the first two terms separately because they don't follow 
     * the addition pattern (they are predefined as 0 and 1)
     */
    
    printf("Fibonacci Series: ");
    
    // Display first term if user wants at least 1 term
    if(n >= 1)
    {
        printf("%d ", first);  // Print F(1) = 0
    }
    
    // Display second term if user wants at least 2 terms
    if(n >= 2)
    {
        printf("%d ", second); // Print F(2) = 1
    }
    
    /*
     * STEP 4: GENERATE REMAINING TERMS USING LOOP
     * Starting from the 3rd term, each term is sum of previous two terms
     * This is the core Fibonacci logic: F(n) = F(n-1) + F(n-2)
     */
    for(i = 3; i <= n; i++)  // Start from term 3, go up to n
    {
        next = first + second;    // Calculate next term: sum of previous two
        printf("%d ", next);     // Display the calculated term
        
        /*
         * UPDATE VARIABLES FOR NEXT ITERATION:
         * We need to "shift" the values for the next calculation
         * - first becomes the old second
         * - second becomes the newly calculated next
         * This prepares us for the next iteration
         */
        first = second;   // Move second value to first position
        second = next;    // Move next value to second position
        
        /*
         * ITERATION EXAMPLE:
         * Before loop: first=0, second=1
         * i=3: next=0+1=1, print 1, then first=1, second=1
         * i=4: next=1+1=2, print 2, then first=1, second=2  
         * i=5: next=1+2=3, print 3, then first=2, second=3
         * And so on...
         */
    }
    
    printf("\n");  // New line after the series
    
    /*
     * STEP 5: ALTERNATIVE DISPLAY FORMAT WITH POSITIONS
     * This shows the same series but with explicit position labels
     * Helps users understand the sequence indexing
     */
    printf("\nWith positions:\n");
    
    // Reset variables to initial values for second display
    first = 0;
    second = 1;
    
    // Display with position labels
    if(n >= 1)
        printf("F(1) = %d\n", first);   // F(1) means "1st Fibonacci number"
    
    if(n >= 2)
        printf("F(2) = %d\n", second);  // F(2) means "2nd Fibonacci number"
    
    // Generate remaining terms with position labels
    for(i = 3; i <= n; i++)
    {
        next = first + second;
        printf("F(%d) = %d\n", i, next);  // F(i) = value format
        first = second;
        second = next;
    }
    
    return 0;
}

/*
 * KEY LEARNING POINTS:
 * 
 * 1. MATHEMATICAL SEQUENCES:
 *    - Sequences have patterns that can be expressed as formulas
 *    - Fibonacci: each term = sum of two previous terms
 *    - Many natural phenomena follow Fibonacci patterns
 *    - Understanding the pattern is key to programming it
 * 
 * 2. LOOP-BASED GENERATION:
 *    - Use loops when you need to repeat a calculation
 *    - Each iteration builds on the previous results
 *    - Loop variable (i) often represents position in sequence
 * 
 * 3. VARIABLE STATE MANAGEMENT:
 *    - Keep track of "current state" using variables
 *    - Update variables at end of each iteration
 *    - Order of updates is crucial (first, then second)
 * 
 * 4. INPUT VALIDATION:
 *    - Always check if user input makes sense
 *    - Return error codes for invalid input
 *    - Prevent program from continuing with bad data
 * 
 * 5. SPECIAL CASES HANDLING:
 *    - First two Fibonacci numbers don't follow the general rule
 *    - Handle them separately before starting the loop
 *    - Check boundaries (n>=1, n>=2) before displaying
 * 
 * 6. MULTIPLE OUTPUT FORMATS:
 *    - Same data can be presented in different ways
 *    - Simple series: "0 1 1 2 3 5 8"
 *    - With positions: "F(1)=0, F(2)=1, F(3)=1..."
 *    - Choose format based on user needs
 * 
 * 7. FIBONACCI IN REAL WORLD:
 *    - Nature: flower petals, pinecones, spiral shells
 *    - Art: golden ratio (phi ≈ 1.618) appears in Fibonacci ratios
 *    - Computer science: algorithm analysis, data structures
 *    - Finance: technical analysis, market patterns
 * 
 * 8. ALGORITHM EFFICIENCY:
 *    - This iterative approach is efficient: O(n) time complexity
 *    - Alternative recursive approach is much slower: O(2^n)
 *    - Understanding efficiency helps choose right algorithm
 */
