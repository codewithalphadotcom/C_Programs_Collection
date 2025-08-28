/*
 * Program: Geometric Area Calculator
 * Purpose: This program teaches beginners about:
 *          - Mathematical formulas implementation in programming
 *          - Menu-driven program structure
 *          - Mathematical constants (PI) usage
 *          - Geometric shape properties and calculations
 *          - switch-case statement for multiple options
 *          - Real-world mathematical applications
 * Demonstrates: How programming can solve practical geometry problems
 * 
 * Geometric Formulas Covered:
 * - Rectangle: Area = length × width
 * - Circle: Area = π × radius²
 * - Triangle: Area = (1/2) × base × height
 * - Square: Area = side × side (special case of rectangle)
 */

#include <stdio.h>  // For input/output functions
#include <math.h>   // For mathematical functions (though we use our own PI constant)

int main()
{
    /*
     * STEP 1: VARIABLE DECLARATIONS
     * We need variables for user choice, area result, and shape dimensions
     */
    int choice;        // User's menu selection (1-4)
    float area;        // Calculated area result (float for decimal precision)
    
    // Variables for different shape dimensions:
    float length, width;  // Rectangle dimensions
    float radius;         // Circle radius
    float base, height;   // Triangle dimensions (base and perpendicular height)
    
    /*
     * MATHEMATICAL CONSTANT DECLARATION
     * PI (π) is a mathematical constant ≈ 3.14159265359...
     * Used in circle calculations (circumference, area, etc.)
     * We declare it as 'const' so it cannot be accidentally changed
     */
    const float PI = 3.14159;
    /*
     * Why use 'const'?
     * - Prevents accidental modification of the value
     * - Makes code more readable and self-documenting
     * - Compiler can optimize better with constants
     * - Mathematical constants should never change during execution
     */
    
    /*
     * STEP 2: DISPLAY MENU AND GET USER CHOICE
     * Menu-driven interface makes the program user-friendly
     */
    printf("Area Calculator\n");
    printf("===============\n");  // Visual separator for better presentation
    printf("1. Rectangle\n");       // Option 1: Four-sided figure with opposite sides equal
    printf("2. Circle\n");          // Option 2: Round shape with all points equidistant from center
    printf("3. Triangle\n");        // Option 3: Three-sided polygon
    printf("4. Square\n");          // Option 4: Special rectangle with all sides equal
    printf("Enter your choice (1-4): ");
    scanf("%d", &choice);           // Read user's selection
    
    /*
     * STEP 3: PROCESS USER'S CHOICE USING SWITCH-CASE
     * Each case handles a different geometric shape with its specific formula
     */
    switch(choice)
    {
        case 1: // RECTANGLE AREA CALCULATION
            /*
             * Rectangle Properties:
             * - Has 4 sides with opposite sides equal
             * - All angles are 90 degrees (right angles)
             * - Area formula: length × width
             * - If length = width, it becomes a square
             */
            printf("\n--- Rectangle Area Calculation ---\n");
            printf("Enter length: ");
            scanf("%f", &length);   // Length of rectangle (longer side)
            printf("Enter width: ");
            scanf("%f", &width);    // Width of rectangle (shorter side)
            
            area = length * width;   // Apply the area formula
            /*
             * MATHEMATICAL EXPLANATION:
             * Rectangle area = length × width
             * This gives us the total space inside the rectangle
             * Units: if length is in meters and width is in meters,
             * area will be in square meters (m²)
             */
            
            printf("Area of rectangle = %.2f square units\n", area);
            break;
            
        case 2: // CIRCLE AREA CALCULATION
            /*
             * Circle Properties:
             * - All points on the edge are equidistant from the center
             * - That distance is called the radius
             * - Diameter = 2 × radius
             * - Area formula: π × radius²
             */
            printf("\n--- Circle Area Calculation ---\n");
            printf("Enter radius: ");
            scanf("%f", &radius);   // Distance from center to edge
            
            area = PI * radius * radius;  // Apply the area formula: πr²
            /*
             * MATHEMATICAL EXPLANATION:
             * Circle area = π × radius²
             * - π (pi) ≈ 3.14159 is the ratio of circumference to diameter
             * - radius² means radius multiplied by itself
             * - This formula was discovered by ancient mathematicians
             * - Example: radius = 3, area = 3.14159 × 3 × 3 = 28.27 square units
             */
            
            printf("Area of circle = %.2f square units\n", area);
            break;
            
        case 3: // TRIANGLE AREA CALCULATION
            /*
             * Triangle Properties:
             * - Has 3 sides and 3 angles
             * - Sum of all angles = 180 degrees
             * - Area formula: (1/2) × base × height
             * - Height must be perpendicular to the base
             */
            printf("\n--- Triangle Area Calculation ---\n");
            printf("Enter base: ");
            scanf("%f", &base);     // Length of the triangle's base (bottom side)
            printf("Enter height: ");
            scanf("%f", &height);   // Perpendicular distance from base to opposite vertex
            
            area = 0.5 * base * height;  // Apply the area formula: (1/2) × base × height
            /*
             * MATHEMATICAL EXPLANATION:
             * Triangle area = (1/2) × base × height
             * - We use 0.5 instead of the fraction 1/2 for easier computation
             * - Height must be perpendicular (90°) to the base
             * - This formula works for any triangle (scalene, isosceles, equilateral)
             * - Imagine the triangle as half of a rectangle with same base and height
             */
            
            printf("Area of triangle = %.2f square units\n", area);
            break;
            
        case 4: // SQUARE AREA CALCULATION
            /*
             * Square Properties:
             * - Special type of rectangle where all sides are equal
             * - All angles are 90 degrees
             * - Area formula: side × side = side²
             * - Perimeter = 4 × side
             */
            printf("\n--- Square Area Calculation ---\n");
            printf("Enter side length: ");
            scanf("%f", &length);   // Using 'length' variable to store side length
            
            area = length * length;  // Apply the area formula: side²
            /*
             * MATHEMATICAL EXPLANATION:
             * Square area = side × side = side²
             * - Since all sides are equal, we only need one measurement
             * - This is a special case of the rectangle formula (length = width)
             * - Example: side = 4, area = 4 × 4 = 16 square units
             */
            
            printf("Area of square = %.2f square units\n", area);
            break;
            
        default: // INVALID CHOICE HANDLING
            printf("Invalid choice! Please select a number between 1 and 4.\n");
            /*
             * GOOD PROGRAMMING PRACTICE:
             * Always handle invalid input gracefully
             * Inform user what went wrong and how to fix it
             * Don't let program crash or behave unexpectedly
             */
    }
    
    return 0;  // Program completed successfully
}

/*
 * KEY LEARNING POINTS:
 * 
 * 1. MATHEMATICAL CONSTANTS:
 *    - Use 'const' keyword for values that shouldn't change
 *    - PI is approximately 3.14159 (more precision: 3.14159265359...)
 *    - Mathematical constants make formulas more readable
 *    - Constants are often defined at the top of functions or programs
 * 
 * 2. GEOMETRIC FORMULAS IN PROGRAMMING:
 *    - Rectangle: length × width
 *    - Circle: π × radius² (radius squared)
 *    - Triangle: (1/2) × base × height (height perpendicular to base)
 *    - Square: side × side (special case of rectangle)
 * 
 * 3. REAL-WORLD APPLICATIONS:
 *    - Construction: calculating material needed for floors, walls
 *    - Landscaping: determining grass seed or fertilizer amounts
 *    - Engineering: designing components with specific areas
 *    - Art: planning canvas sizes or material requirements
 * 
 * 4. FLOATING-POINT PRECISION:
 *    - Use float for measurements (can have decimal places)
 *    - %.2f formats output to 2 decimal places for readability
 *    - Real measurements are rarely exact integers
 * 
 * 5. MENU-DRIVEN PROGRAM DESIGN:
 *    - Present clear options to users
 *    - Use meaningful option descriptions
 *    - Handle invalid input gracefully
 *    - Provide visual separators for better presentation
 * 
 * 6. MATHEMATICAL CONCEPTS:
 *    - Area measures space inside a 2D shape
 *    - Units are always "square units" (cm², m², ft², etc.)
 *    - Different shapes require different formulas
 *    - Understanding geometry helps in many fields
 * 
 * 7. PROGRAMMING BEST PRACTICES:
 *    - Use descriptive variable names (radius, not r)
 *    - Include comments explaining mathematical formulas
 *    - Group related calculations together
 *    - Provide meaningful output messages
 * 
 * 8. COMMON MISTAKES TO AVOID:
 *    - Forgetting to square the radius in circle area (radius * radius)
 *    - Using wrong height in triangle (must be perpendicular to base)
 *    - Mixing up length and width (though mathematically it doesn't matter)
 *    - Not handling invalid menu choices
 */
