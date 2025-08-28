/*
 * Program: Temperature Converter
 * Purpose: This program teaches beginners about:
 *          - Menu-driven programming structure
 *          - Mathematical formulas implementation
 *          - Floating-point arithmetic operations
 *          - switch-case for multiple options
 *          - Temperature scale relationships
 * Demonstrates: Real-world application of basic programming concepts
 * 
 * Temperature Scales Explained:
 * - Celsius: Water freezes at 0°C, boils at 100°C
 * - Fahrenheit: Water freezes at 32°F, boils at 212°F  
 * - Kelvin: Absolute temperature scale, 0K = -273.15°C
 */

#include <stdio.h>  // Required for input/output functions

int main()
{
    /*
     * STEP 1: VARIABLE DECLARATIONS
     * We need float variables for temperature values because:
     * - Temperatures can have decimal places (like 36.5°C)
     * - Mathematical operations may result in non-whole numbers
     */
    float celsius;     // Variable to store Celsius temperature
    float fahrenheit;  // Variable to store Fahrenheit temperature 
    float kelvin;      // Variable to store Kelvin temperature
    int choice;        // User's menu selection (integers 1, 2, or 3)
    
    /*
     * STEP 2: DISPLAY MENU TO USER
     * Menu-driven programming allows users to choose what they want to do
     * This makes programs more interactive and user-friendly
     */
    printf("Temperature Converter\n");           // Program title
    printf("1. Celsius to Fahrenheit\n");        // Option 1
    printf("2. Fahrenheit to Celsius\n");        // Option 2
    printf("3. Celsius to Kelvin\n");            // Option 3
    printf("Enter your choice (1-3): ");         // Prompt for user input
    scanf("%d", &choice);                       // Read user's choice
    
    /*
     * STEP 3: PROCESS USER'S CHOICE USING SWITCH-CASE
     * switch-case is perfect for menu-driven programs
     * It's cleaner than multiple if-else statements for discrete choices
     */
    switch(choice)  // Check the value of choice variable
    {
        case 1:  // Celsius to Fahrenheit conversion
            printf("Enter temperature in Celsius: ");
            scanf("%f", &celsius);  // Read temperature value
            
            /*
             * CONVERSION FORMULA: F = (C × 9/5) + 32
             * Mathematical explanation:
             * - Multiply by 9/5 (or 1.8) to account for different scale sizes
             * - Add 32 because Fahrenheit zero point is offset from Celsius
             * - We use 9.0/5.0 instead of 9/5 to ensure floating-point division
             */
            fahrenheit = (celsius * 9.0/5.0) + 32;
            
            printf("%.2f°C = %.2f°F\n", celsius, fahrenheit);
            // %.2f displays exactly 2 decimal places for cleaner output
            break;  // Exit switch statement
            
        case 2:  // Fahrenheit to Celsius conversion
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &fahrenheit);
            
            /*
             * CONVERSION FORMULA: C = (F - 32) × 5/9
             * Mathematical explanation:
             * - Subtract 32 first to adjust for the offset
             * - Multiply by 5/9 (or 0.5556) to scale down from Fahrenheit units
             * - This is the reverse of the Celsius to Fahrenheit formula
             */
            celsius = (fahrenheit - 32) * 5.0/9.0;
            
            printf("%.2f°F = %.2f°C\n", fahrenheit, celsius);
            break;
            
        case 3:  // Celsius to Kelvin conversion
            printf("Enter temperature in Celsius: ");
            scanf("%f", &celsius);
            
            /*
             * CONVERSION FORMULA: K = C + 273.15
             * Mathematical explanation:
             * - Kelvin and Celsius have the same scale size (degree increments)
             * - The difference is just the zero point offset
             * - 0°C = 273.15K (absolute zero is -273.15°C)
             */
            kelvin = celsius + 273.15;
            
            printf("%.2f°C = %.2fK\n", celsius, kelvin);
            // Note: Kelvin doesn't use the degree symbol (°)
            break;
            
        default:  // Handle invalid input
            printf("Invalid choice!\n");
            // This executes if user enters anything other than 1, 2, or 3
            // Good programming practice: always handle unexpected input
    }
    
    return 0;  // Program completed successfully
}

/*
 * KEY LEARNING POINTS:
 * 
 * 1. MENU-DRIVEN PROGRAMMING:
 *    - Present clear options to the user
 *    - Use switch-case for multiple discrete choices
 *    - Always include a default case for invalid input
 * 
 * 2. MATHEMATICAL FORMULAS IN PROGRAMMING:
 *    - Break down complex formulas into simple operations
 *    - Use parentheses to ensure correct order of operations
 *    - Use floating-point literals (9.0, 5.0) for decimal calculations
 * 
 * 3. FLOATING-POINT ARITHMETIC:
 *    - Use float for numbers with decimal places
 *    - Be aware that 9/5 = 1 (integer division) but 9.0/5.0 = 1.8
 *    - Format output with %.2f for consistent decimal places
 * 
 * 4. REAL-WORLD APPLICATIONS:
 *    - Programming often involves converting between different units
 *    - Understanding the mathematical relationships is crucial
 *    - User-friendly interfaces make programs more practical
 * 
 * 5. TEMPERATURE SCALE FACTS:
 *    - Celsius: Based on water's freezing (0°) and boiling (100°) points
 *    - Fahrenheit: 0°F = very cold winter day, 100°F = hot summer day
 *    - Kelvin: Absolute temperature scale used in science
 *    - Absolute zero (0K = -273.15°C) is the lowest possible temperature
 */
