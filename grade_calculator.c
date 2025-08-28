/*
 * Program: Grade Calculator and Classification System
 * Purpose: This program teaches beginners about:
 *          - if-else ladder (chain of conditions)
 *          - Range-based conditional logic
 *          - Input validation techniques
 *          - Character variables and assignment
 *          - Grading system implementation
 *          - User-friendly output formatting
 * Demonstrates: Real-world application of conditional statements
 * 
 * Grading Scale Used:
 * A (90-100): Excellent performance
 * B (80-89):  Very Good performance  
 * C (70-79):  Good performance
 * D (60-69):  Average performance
 * E (50-59):  Below Average performance
 * F (0-49):   Failing performance
 */

#include <stdio.h>

int main()
{
    /*
     * STEP 1: VARIABLE DECLARATIONS
     */
    float marks;  // Student's marks (float to allow decimal grades like 85.5)
    char grade;   // Letter grade (A, B, C, D, E, or F)
    
    /*
     * STEP 2: GET INPUT FROM USER
     */
    printf("Grade Calculator\n");
    printf("===============\n");
    printf("Enter your marks (0-100): ");
    scanf("%f", &marks);
    /*
     * WHY USE FLOAT FOR MARKS?
     * - Allows decimal scores like 87.5, 92.3
     * - More precise than integer for academic grading
     * - Real grading systems often use decimal points
     */
    
    /*
     * STEP 3: INPUT VALIDATION
     * Always validate user input before processing
     * Marks should be between 0 and 100 (inclusive)
     */
    if(marks < 0 || marks > 100)
    {
        printf("Invalid marks! Please enter marks between 0 and 100.\n");
        return 1;  // Exit program with error code
        /*
         * INPUT VALIDATION IMPORTANCE:
         * - Prevents invalid data from causing incorrect results
         * - Provides clear error messages to users
         * - return 1 indicates program ended with an error
         * - Good programming practice: validate before processing
         */
    }
    
    /*
     * STEP 4: GRADE CALCULATION USING IF-ELSE LADDER
     * This is a chain of if-else conditions that checks ranges
     * The order is CRUCIAL: we check from highest to lowest
     */
    
    if(marks >= 90)  // Check for A grade first (90-100)
    {
        grade = 'A';
        printf("\n--- Grade Report ---\n");
        printf("Marks: %.2f\n", marks);
        printf("Grade: %c (Excellent)\n", grade);
        /*
         * WHY CHECK >= 90 FIRST?
         * - If marks = 95, it satisfies >= 90, >= 80, >= 70, etc.
         * - By checking highest range first, we ensure correct classification
         * - if-else ladder stops at first true condition
         */
    }
    else if(marks >= 80)  // Check for B grade (80-89)
    {
        grade = 'B';
        printf("\n--- Grade Report ---\n");
        printf("Marks: %.2f\n", marks);
        printf("Grade: %c (Very Good)\n", grade);
        /*
         * RANGE LOGIC:
         * - This executes only if marks < 90 (first condition was false)
         * - So marks is in range: 80 <= marks < 90
         * - This gives us the B grade range automatically
         */
    }
    else if(marks >= 70)  // Check for C grade (70-79)
    {
        grade = 'C';
        printf("\n--- Grade Report ---\n");
        printf("Marks: %.2f\n", marks);
        printf("Grade: %c (Good)\n", grade);
        /*
         * CONTINUING THE PATTERN:
         * - marks < 90 AND marks < 80 (previous conditions false)
         * - marks >= 70 (current condition true)
         * - Result: 70 <= marks < 80 (C grade range)
         */
    }
    else if(marks >= 60)  // Check for D grade (60-69)
    {
        grade = 'D';
        printf("\n--- Grade Report ---\n");
        printf("Marks: %.2f\n", marks);
        printf("Grade: %c (Average)\n", grade);
        /*
         * PATTERN CONTINUES:
         * - All previous conditions false: marks < 70
         * - Current condition true: marks >= 60
         * - Result: 60 <= marks < 70 (D grade range)
         */
    }
    else if(marks >= 50)  // Check for E grade (50-59)
    {
        grade = 'E';
        printf("\n--- Grade Report ---\n");
        printf("Marks: %.2f\n", marks);
        printf("Grade: %c (Below Average)\n", grade);
        /*
         * NEAR-FAILING GRADE:
         * - marks < 60 (from previous conditions)
         * - marks >= 50 (current condition)
         * - Result: 50 <= marks < 60 (E grade range)
         * - Still passing but needs improvement
         */
    }
    else  // All other cases: marks < 50 (F grade)
    {
        grade = 'F';
        printf("\n--- Grade Report ---\n");
        printf("Marks: %.2f\n", marks);
        printf("Grade: %c (Fail)\n", grade);
        /*
         * FINAL ELSE CLAUSE:
         * - Catches all remaining cases (marks < 50)
         * - No condition needed - if we reach here, student failed
         * - Range: 0 <= marks < 50 (F grade range)
         */
    }
    
    /*
     * STEP 5: ADDITIONAL FEEDBACK BASED ON PERFORMANCE
     * Provide encouraging or motivational messages
     */
    printf("\n--- Feedback ---\n");
    
    if(grade == 'F')  // Special message for failing students
    {
        printf("You need to work harder!\n");
        printf("Don't give up - seek help from teachers or tutors.\n");
        /*
         * CONSTRUCTIVE FEEDBACK:
         * - Acknowledges the failure honestly
         * - Provides encouragement and actionable advice
         * - Maintains positive tone despite poor performance
         */
    }
    else  // Message for all passing students
    {
        printf("Congratulations! You passed.\n");
        
        // Additional specific feedback based on grade level
        if(grade == 'A')
        {
            printf("Outstanding performance! Keep up the excellent work!\n");
        }
        else if(grade == 'B')
        {
            printf("Very good work! You're doing great!\n");
        }
        else if(grade == 'C')
        {
            printf("Good job! There's room for improvement.\n");
        }
        else  // Grades D and E
        {
            printf("You passed, but consider studying more for better grades.\n");
        }
    }
    
    /*
     * STEP 6: DISPLAY GRADE BOUNDARIES FOR REFERENCE
     */
    printf("\n--- Grade Scale Reference ---\n");
    printf("A: 90-100 (Excellent)\n");
    printf("B: 80-89  (Very Good)\n");
    printf("C: 70-79  (Good)\n");
    printf("D: 60-69  (Average)\n");
    printf("E: 50-59  (Below Average)\n");
    printf("F: 0-49   (Fail)\n");
    
    return 0;  // Program completed successfully
}

/*
 * KEY LEARNING POINTS:
 * 
 * 1. IF-ELSE LADDER PATTERN:
 *    - Chain of conditions checked from top to bottom
 *    - First true condition executes, rest are skipped
 *    - Order matters: check most restrictive conditions first
 *    - Final 'else' catches all remaining cases
 * 
 * 2. RANGE-BASED CONDITIONS:
 *    - Use >= for lower bounds of ranges
 *    - Upper bounds are implicit (from previous failed conditions)
 *    - Example: marks >= 80 with marks < 90 gives range 80-89
 *    - This technique works for any range-based classification
 * 
 * 3. INPUT VALIDATION:
 *    - Always check if input is within expected range
 *    - Use logical operators (|| for OR, && for AND)
 *    - Provide clear error messages
 *    - Exit gracefully with error codes (return 1)
 * 
 * 4. CHARACTER VARIABLES:
 *    - char stores single characters ('A', 'B', 'C', etc.)
 *    - Use single quotes for character literals
 *    - Characters can be compared with == operator
 *    - Useful for categories, codes, and classifications
 * 
 * 5. FLOATING-POINT PRECISION:
 *    - Use float for decimal values like grades
 *    - %.2f formats output to 2 decimal places
 *    - Be aware of floating-point comparison issues
 *    - Consider rounding for display purposes
 * 
 * 6. USER EXPERIENCE DESIGN:
 *    - Provide clear input prompts
 *    - Format output professionally
 *    - Give constructive feedback
 *    - Include reference information (grade scale)
 * 
 * 7. REAL-WORLD APPLICATIONS:
 *    - Academic grading systems
 *    - Performance evaluation systems
 *    - Quality rating systems
 *    - Risk assessment categories
 *    - Any classification based on numeric ranges
 * 
 * 8. COMMON MISTAKES TO AVOID:
 *    - Wrong order in if-else ladder (check highest first)
 *    - Using > instead of >= (excludes boundary values)
 *    - Forgetting input validation
 *    - Not handling edge cases (exactly 90, 80, etc.)
 *    - Inconsistent or confusing feedback messages
 * 
 * 9. TESTING STRATEGY:
 *    - Test boundary values: 90, 89.9, 80, 79.9, etc.
 *    - Test invalid inputs: -10, 150
 *    - Test decimal inputs: 85.5, 92.7
 *    - Test each grade range at least once
 */
