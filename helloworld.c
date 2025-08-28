/*
 * Program: Hello World - First C Program
 * Purpose: This is the classic "Hello, World!" program that teaches beginners:
 *          - Basic C program structure
 *          - Header file inclusion
 *          - main() function importance
 *          - printf() function usage
 *          - Program termination
 * Learning Objective: Understand the fundamental structure of a C program
 * This is traditionally the first program every programmer writes!
 */

#include <stdio.h>  // Preprocessor directive - includes Standard Input/Output library
                    // This header file contains definitions for printf() and other I/O functions
                    // Without this line, printf() would not be recognized
                    // stdio.h stands for "Standard Input Output Header"

/*
 * main() function - THE HEART OF EVERY C PROGRAM
 * This is where program execution begins and ends
 * Every C program MUST have exactly one main() function
 */
int main()          // Function signature:
                    // 'int' = return type (this function returns an integer)
                    // 'main' = function name (special name recognized by system)
                    // () = parameter list (empty means no parameters)
{
    /*
     * PROGRAM BODY - The actual work happens here
     * Everything between { and } is the function body
     */
    
    printf("Hello, World!\n");  // printf = "print formatted"
                                  // "Hello, World!" = string literal (text in quotes)
                                  // \n = escape sequence for newline (moves cursor to next line)
                                  // ; = statement terminator (REQUIRED after each statement)
    
    /*
     * PROGRAM TERMINATION
     * return 0 tells the operating system that program ended successfully
     * 0 = success, any other number = error code
     */
    return 0;       // This line ends the main() function and the entire program
                    // Control goes back to the operating system
}

/*
 * KEY LEARNING POINTS:
 * 
 * 1. PROGRAM STRUCTURE:
 *    - Every C program starts with #include statements
 *    - main() function is the entry point
 *    - Statements are enclosed in curly braces { }
 *    - Each statement ends with semicolon ;
 * 
 * 2. COMPILATION PROCESS:
 *    - Save this file as filename.c
 *    - Compile: gcc filename.c -o filename
 *    - Run: ./filename (Linux/Mac) or filename.exe (Windows)
 * 
 * 3. OUTPUT:
 *    - This program will display: Hello, World!
 *    - Followed by a new line (cursor moves to next line)
 * 
 * 4. WHY "HELLO, WORLD!"?
 *    - Tradition started by Brian Kernighan and Dennis Ritchie
 *    - Simple way to verify that your programming environment works
 *    - Tests basic output functionality
 * 
 * 5. COMMON MISTAKES FOR BEGINNERS:
 *    - Forgetting #include <stdio.h> (printf won't work)
 *    - Forgetting semicolon after statements
 *    - Misspelling main() function name
 *    - Missing return 0; statement
 *    - Forgetting quotes around "Hello, World!"
 */
