/*
 * Program: Basic Input and Output Demonstration
 * Purpose: This program teaches beginners about:
 *          - Different data types in C
 *          - How to take input from user using scanf()
 *          - How to display output using printf()
 *          - Format specifiers for different data types
 * Author: Beginner C Programming Tutorial
 */

#include <stdio.h>  // This header file contains input/output functions like printf and scanf

int main()  // main() function - execution starts here
{
    /*
     * STEP 1: VARIABLE DECLARATIONS
     * We declare variables to store different types of data
     */
    
    int age;           // 'int' stores whole numbers (integers)
                       // Example: 25, 18, 65
    
    float height;      // 'float' stores decimal numbers (floating point)
                       // Example: 5.8, 6.2, 5.11
    
    char grade;        // 'char' stores a single character
                       // Example: 'A', 'B', 'C'
    
    char name[50];     // This is a string (array of characters)
                       // [50] means it can store up to 49 characters + 1 null terminator
                       // Example: "John", "Alice", "Mohammed"
    
    /*
     * STEP 2: TAKING INPUT FROM USER
     * scanf() function is used to read input from keyboard
     */
    
    printf("Enter your name: ");          // printf() displays message to user
    scanf("%s", name);                   // %s = format specifier for string
                                          // Note: no & before 'name' for strings
    
    printf("Enter your age: ");
    scanf("%d", &age);                   // %d = format specifier for integers
                                          // & = address operator (tells where to store input)
    
    printf("Enter your height (in feet): ");
    scanf("%f", &height);               // %f = format specifier for float numbers
                                          // & is needed for all variables except strings
    
    printf("Enter your grade: ");
    scanf(" %c", &grade);               // %c = format specifier for single character
                                          // IMPORTANT: Space before %c clears any leftover newline
    
    /*
     * STEP 3: DISPLAYING THE STORED DATA
     * We use printf() with format specifiers to show the values
     */
    
    printf("\n--- Your Information ---\n");  // \n = newline character (moves to next line)
    
    printf("Name: %s\n", name);           // %s displays the string value
    printf("Age: %d years\n", age);       // %d displays the integer value
    printf("Height: %.2f feet\n", height); // %.2f displays float with 2 decimal places
    printf("Grade: %c\n", grade);         // %c displays the character value
    
    /*
     * STEP 4: PROGRAM TERMINATION
     * return 0 tells the operating system that program ended successfully
     */
    return 0;
    
    /*
     * KEY LEARNING POINTS:
     * 1. Always include <stdio.h> for input/output functions
     * 2. Use appropriate data types: int for whole numbers, float for decimals
     * 3. scanf() needs & (address operator) for most variables, except strings
     * 4. Format specifiers: %d (int), %f (float), %c (char), %s (string)
     * 5. printf() can mix text with variables using format specifiers
     * 6. \n creates a new line in output
     * 7. Always end main() function with return 0;
     */
}
