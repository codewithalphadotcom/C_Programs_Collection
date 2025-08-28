/*
 * Program: Pattern Printing with Nested Loops
 * Purpose: This program teaches beginners about:
 *          - Nested loop concepts and applications
 *          - Pattern generation logic and algorithms
 *          - Space and character positioning
 *          - Menu-driven program structure
 *          - Visual programming concepts
 *          - Mathematical relationships in patterns
 * Demonstrates: How nested loops create visual patterns
 * 
 * Pattern Types Covered:
 * 1. Right Triangle: Increasing stars per row
 * 2. Square: Equal stars in all rows
 * 3. Number Triangle: Sequential numbers in triangle form
 * 4. Reverse Triangle: Decreasing stars per row
 * 5. Pyramid: Centered triangle with spaces
 */

#include <stdio.h>

int main()
{
    /*
     * STEP 1: VARIABLE DECLARATIONS
     * We need variables for menu choice, dimensions, and loop counters
     */
    int rows;    // Number of rows in the pattern
    int i, j;    // Loop counter variables (i for rows, j for columns)
    int choice;  // User's menu selection
    
    /*
     * STEP 2: DISPLAY MENU AND GET USER PREFERENCES
     * Menu-driven interface allows users to choose pattern type
     */
    printf("Pattern Printing Program\n");
    printf("=======================\n");
    printf("1. Right Triangle (Stars)\n");   // Increasing pattern: *, **, ***, etc.
    printf("2. Square (Stars)\n");           // Regular grid of stars
    printf("3. Number Triangle\n");          // Numbers instead of stars
    printf("4. Reverse Triangle\n");         // Decreasing pattern
    printf("Enter your choice (1-4): ");
    scanf("%d", &choice);
    
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    /*
     * INPUT CONSIDERATIONS:
     * - rows determines the height of the pattern
     * - Larger values create bigger patterns
     * - Should validate for positive numbers (added later)
     */
    
    /*
     * STEP 3: PATTERN GENERATION USING SWITCH-CASE
     * Each case demonstrates different nested loop patterns
     */
    switch(choice)
    {
        case 1: // RIGHT TRIANGLE PATTERN WITH STARS
            /*
             * Pattern Example (rows = 4):
             * *
             * * *
             * * * *
             * * * * *
             * 
             * Logic: Row i has i stars
             * Row 1: 1 star, Row 2: 2 stars, Row 3: 3 stars, etc.
             */
            printf("\nRight Triangle Pattern:\n");
            
            for(i = 1; i <= rows; i++)  // Outer loop: controls rows (1 to rows)
            {
                /*
                 * OUTER LOOP EXPLANATION:
                 * - i represents current row number
                 * - Runs from 1 to rows (total number of rows)
                 * - Each iteration creates one complete row
                 */
                
                for(j = 1; j <= i; j++)  // Inner loop: prints stars for current row
                {
                    printf("* ");  // Print star followed by space
                    /*
                     * INNER LOOP EXPLANATION:
                     * - j represents current column/position in row
                     * - Runs from 1 to i (current row number)
                     * - Row 1: j goes 1 to 1 (1 star)
                     * - Row 2: j goes 1 to 2 (2 stars)
                     * - Row 3: j goes 1 to 3 (3 stars)
                     * - Pattern: each row has same number of stars as row number
                     */
                }
                printf("\n");  // Move to next line after completing current row
            }
            break;
            
        case 2: // SQUARE PATTERN WITH STARS
            /*
             * Pattern Example (rows = 4):
             * * * * *
             * * * * *
             * * * * *
             * * * * *
             * 
             * Logic: Every row has same number of stars (rows)
             */
            printf("\nSquare Pattern:\n");
            
            for(i = 1; i <= rows; i++)  // Outer loop: controls rows
            {
                for(j = 1; j <= rows; j++)  // Inner loop: always prints 'rows' stars
                {
                    printf("* ");
                    /*
                     * KEY DIFFERENCE FROM TRIANGLE:
                     * - Inner loop condition is j <= rows (not j <= i)
                     * - This means every row prints exactly 'rows' number of stars
                     * - Creates a rectangular/square pattern
                     */
                }
                printf("\n");
            }
            break;
            
        case 3: // NUMBER TRIANGLE PATTERN
            /*
             * Pattern Example (rows = 4):
             * 1
             * 1 2
             * 1 2 3
             * 1 2 3 4
             * 
             * Logic: Same structure as star triangle, but print numbers
             */
            printf("\nNumber Triangle Pattern:\n");
            
            for(i = 1; i <= rows; i++)  // Outer loop: controls rows
            {
                for(j = 1; j <= i; j++)  // Inner loop: prints numbers for current row
                {
                    printf("%d ", j);  // Print current column number
                    /*
                     * PATTERN VARIATION:
                     * - Instead of printing "*", we print the value of j
                     * - j represents position in current row
                     * - Row 1: prints "1"
                     * - Row 2: prints "1 2" 
                     * - Row 3: prints "1 2 3"
                     * - Shows how same loop structure creates different patterns
                     */
                }
                printf("\n");
            }
            break;
            
        case 4: // REVERSE TRIANGLE PATTERN
            /*
             * Pattern Example (rows = 4):
             * * * * *
             * * * *
             * * *
             * *
             * 
             * Logic: Row 1 has 'rows' stars, each subsequent row has one less
             */
            printf("\nReverse Triangle Pattern:\n");
            
            for(i = rows; i >= 1; i--)  // Outer loop: counts DOWN from rows to 1
            {
                /*
                 * REVERSE PATTERN TECHNIQUE:
                 * - Start i from rows and decrement (i--)
                 * - First iteration: i = rows (print rows stars)
                 * - Second iteration: i = rows-1 (print rows-1 stars)
                 * - Last iteration: i = 1 (print 1 star)
                 * - Creates decreasing pattern
                 */
                
                for(j = 1; j <= i; j++)  // Inner loop: prints i stars
                {
                    printf("* ");
                }
                printf("\n");
            }
            break;
            
        default:  // Handle invalid menu choice
            printf("Invalid choice! Please select 1-4.\n");
            return 1;  // Exit with error code
    }
    
    /*
     * BONUS PATTERN: PYRAMID (CENTERED TRIANGLE)
     * This demonstrates more advanced nested loop concepts
     * Pattern Example (rows = 4):
     *    *
     *   ***
     *  *****
     * *******
     * 
     * Logic: Each row has spaces for centering + odd number of stars
     */
    printf("\nBonus - Pyramid Pattern:\n");
    
    for(i = 1; i <= rows; i++)  // Outer loop: controls rows
    {
        /*
         * PYRAMID CONSTRUCTION:
         * Row i needs:
         * 1. (rows - i) spaces for centering
         * 2. (2*i - 1) stars for the actual pattern
         * 
         * Example for rows = 4:
         * Row 1: 3 spaces + 1 star  = "   *"
         * Row 2: 2 spaces + 3 stars = "  ***"
         * Row 3: 1 space  + 5 stars = " *****"
         * Row 4: 0 spaces + 7 stars = "*******"
         */
        
        // FIRST INNER LOOP: Print leading spaces for centering
        for(j = 1; j <= rows - i; j++)
        {
            printf(" ");  // Print space (no newline)
            /*
             * CENTERING LOGIC:
             * - rows - i gives number of spaces needed
             * - As i increases, (rows - i) decreases
             * - This shifts the stars toward the center
             */
        }
        
        // SECOND INNER LOOP: Print stars for current row
        for(j = 1; j <= 2*i - 1; j++)
        {
            printf("*");  // Print star (no space between stars)
            /*
             * STAR COUNT LOGIC:
             * - 2*i - 1 gives odd number of stars
             * - Row 1: 2(1) - 1 = 1 star
             * - Row 2: 2(2) - 1 = 3 stars
             * - Row 3: 2(3) - 1 = 5 stars
             * - Creates symmetric pyramid shape
             */
        }
        
        printf("\n");  // Move to next line after completing row
    }
    
    return 0;  // Program completed successfully
}

/*
 * KEY LEARNING POINTS ABOUT NESTED LOOPS AND PATTERNS:
 * 
 * 1. NESTED LOOP STRUCTURE:
 *    - Outer loop typically controls rows (vertical dimension)
 *    - Inner loop typically controls columns (horizontal dimension)
 *    - Inner loop executes completely for each outer loop iteration
 *    - Pattern: for each row, process all columns
 * 
 * 2. PATTERN GENERATION STRATEGIES:
 *    - Right Triangle: inner loop runs 1 to i (increasing)
 *    - Square: inner loop runs 1 to constant (same width)
 *    - Reverse Triangle: outer loop runs backwards (decreasing)
 *    - Pyramid: two inner loops (spaces + stars)
 * 
 * 3. LOOP VARIABLE RELATIONSHIPS:
 *    - i typically represents row number
 *    - j typically represents column/position number
 *    - Relationship between i and j determines pattern shape
 *    - j <= i creates triangular patterns
 *    - j <= constant creates rectangular patterns
 * 
 * 4. MATHEMATICAL PATTERNS IN CODE:
 *    - Linear relationships: j <= i (straight lines)
 *    - Arithmetic sequences: 2*i - 1 (odd numbers)
 *    - Complementary relationships: rows - i (decreasing as i increases)
 * 
 * 5. VISUAL PROGRAMMING CONCEPTS:
 *    - Each printf("*") represents one "pixel" in the pattern
 *    - Spaces create positioning and alignment
 *    - Newlines create row separation
 *    - Different characters create different visual effects
 * 
 * 6. PATTERN VARIATIONS:
 *    - Change characters: "*" vs "%d" vs "#" vs "@"
 *    - Change spacing: "* " vs "*" vs "  *  "
 *    - Change relationships: j <= i vs j <= 2*i vs j <= i*i
 *    - Change directions: i++ vs i-- vs starting from middle
 * 
 * 7. DEBUGGING PATTERN PROGRAMS:
 *    - Trace through small examples (rows = 3 or 4)
 *    - Check boundary conditions (first row, last row)
 *    - Verify inner loop ranges for each outer loop iteration
 *    - Test with different row counts
 * 
 * 8. REAL-WORLD APPLICATIONS:
 *    - ASCII art and text-based graphics
 *    - Data visualization in console applications
 *    - Creating formatted output tables
 *    - Teaching loop concepts visually
 *    - Game development (text-based games)
 * 
 * 9. ADVANCED PATTERN CONCEPTS:
 *    - Hollow patterns (print stars only on borders)
 *    - Diamond patterns (pyramid + inverted pyramid)
 *    - Number patterns (Pascal's triangle, multiplication tables)
 *    - Character patterns (alphabets, symbols)
 *    - Animated patterns (changing over time)
 */
