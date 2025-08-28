/*
 * Program: String Operations Demonstration
 * Purpose: This program teaches beginners about:
 *          - String handling and manipulation in C
 *          - Character arrays vs strings
 *          - String input methods (fgets vs scanf)
 *          - Character classification and conversion
 *          - String algorithms (length, reverse, palindrome)
 *          - String comparison techniques
 * Demonstrates: Comprehensive string processing operations
 * 
 * String Concepts in C:
 * - Strings are arrays of characters ending with '\0' (null terminator)
 * - "Hello" is stored as ['H','e','l','l','o','\0'] (6 bytes total)
 * - String length doesn't include the null terminator
 * - Always allocate one extra byte for the null terminator
 */

#include <stdio.h>   // For input/output functions (printf, scanf, fgets)
#include <string.h>  // For string functions (strlen, strcmp, strcspn)
#include <ctype.h>   // For character classification (isalpha, tolower, toupper)

int main()
{
    /*
     * STEP 1: VARIABLE DECLARATIONS
     * Arrays for string storage and variables for analysis
     */
    
    char str[100];      // Primary string (99 characters + 1 null terminator)
    char str2[100];     // Second string for comparison operations
    char reversed[100]; // Array to store reversed string
    
    int length;         // Length of the string (number of characters)
    int i, j;           // Loop counter variables
    int vowels = 0;     // Counter for vowel characters (a,e,i,o,u)
    int consonants = 0; // Counter for consonant characters
    int isPalindrome = 1; // Flag: 1 = palindrome, 0 = not palindrome
                          // We assume it's palindrome until proven otherwise
    
    /*
     * STEP 2: GET STRING INPUT FROM USER
     * Using fgets() instead of scanf() for safer string input
     */
    printf("String Operations Program\n");
    printf("Enter a string: ");
    
    /*
     * fgets() vs scanf() for string input:
     * - fgets() reads entire line including spaces
     * - scanf("%s") stops at first space
     * - fgets() is safer (prevents buffer overflow)
     * - fgets() includes newline character which we need to remove
     */
    fgets(str, sizeof(str), stdin);
    // fgets(destination, max_size, input_source)
    // sizeof(str) ensures we don't exceed array bounds
    
    /*
     * REMOVE NEWLINE CHARACTER FROM FGETS INPUT
     * fgets() includes the '\n' character when user presses Enter
     * We need to remove it for proper string processing
     */
    str[strcspn(str, "\n")] = 0;
    /*
     * strcspn() explained:
     * - strcspn(str, "\n") finds position of first '\n' character
     * - We replace that '\n' with '\0' (null terminator)
     * - This effectively removes the newline from our string
     */
    
    /*
     * STEP 3: CALCULATE STRING LENGTH MANUALLY
     * This demonstrates how to find string length without using strlen()
     * Understanding this helps grasp how strings work internally
     */
    length = 0;                    // Initialize counter to 0
    while(str[length] != '\0')     // Continue until null terminator
    {
        length++;                  // Increment counter for each character
    }
    /*
     * Alternative: You could use strlen() function: length = strlen(str);
     * But doing it manually shows how strings are null-terminated
     */
    
    /*
     * STEP 4: DISPLAY BASIC STRING INFORMATION
     */
    printf("\n--- String Analysis ---\n");
    printf("Original string: \"%s\"\n", str);     // Quotes show string boundaries
    printf("Length: %d characters\n", length);
    
    /*
     * STEP 5: CASE CONVERSION DEMONSTRATION
     * Show string in uppercase and lowercase formats
     */
    printf("Uppercase: ");
    for(i = 0; i < length; i++)    // Loop through each character
    {
        printf("%c", toupper(str[i])); // toupper() converts to uppercase
        /*
         * toupper() from <ctype.h>:
         * - Converts lowercase to uppercase
         * - Leaves uppercase and non-letters unchanged
         * - 'a' becomes 'A', 'z' becomes 'Z', '5' stays '5'
         */
    }
    printf("\n");
    
    printf("Lowercase: ");
    for(i = 0; i < length; i++)
    {
        printf("%c", tolower(str[i])); // tolower() converts to lowercase
        /*
         * tolower() from <ctype.h>:
         * - Converts uppercase to lowercase
         * - Leaves lowercase and non-letters unchanged
         * - 'A' becomes 'a', 'Z' becomes 'z', '5' stays '5'
         */
    }
    printf("\n");
    
    /*
     * STEP 6: COUNT VOWELS AND CONSONANTS
     * Analyze the alphabetic composition of the string
     */
    for(i = 0; i < length; i++)
    {
        char ch = tolower(str[i]);     // Convert to lowercase for easier checking
        
        if(isalpha(ch))                // Check if character is a letter
        {
            /*
             * isalpha() from <ctype.h>:
             * - Returns true if character is a letter (A-Z, a-z)
             * - Returns false for numbers, spaces, punctuation
             * - We only count letters, not spaces or symbols
             */
            
            // Check if the letter is a vowel
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
                vowels++;              // Increment vowel counter
            else
                consonants++;          // If it's a letter but not vowel, it's consonant
        }
        // Non-alphabetic characters (spaces, numbers, punctuation) are ignored
    }
    
    printf("Vowels: %d\n", vowels);
    printf("Consonants: %d\n", consonants);
    
    /*
     * STEP 7: REVERSE THE STRING
     * Create a reversed copy of the original string
     */
    for(i = 0; i < length; i++)
    {
        reversed[i] = str[length - 1 - i]; // Copy characters in reverse order
        /*
         * REVERSE LOGIC EXPLANATION:
         * - When i=0, copy str[length-1] (last character)
         * - When i=1, copy str[length-2] (second last character)
         * - When i=length-1, copy str[0] (first character)
         * 
         * Example for "Hello" (length=5):
         * i=0: reversed[0] = str[4] = 'o'
         * i=1: reversed[1] = str[3] = 'l' 
         * i=2: reversed[2] = str[2] = 'l'
         * i=3: reversed[3] = str[1] = 'e'
         * i=4: reversed[4] = str[0] = 'H'
         * Result: "olleH"
         */
    }
    reversed[length] = '\0';  // Don't forget the null terminator!
    
    printf("Reversed string: \"%s\"\n", reversed);
    
    /*
     * STEP 8: PALINDROME CHECK
     * A palindrome reads the same forwards and backwards
     * Examples: "racecar", "madam", "A man a plan a canal Panama"
     */
    for(i = 0; i < length/2; i++)  // Only need to check half the string
    {
        /*
         * PALINDROME ALGORITHM:
         * - Compare first character with last character
         * - Compare second character with second-last character
         * - Continue until we reach the middle
         * - If any pair doesn't match, it's not a palindrome
         */
        
        if(tolower(str[i]) != tolower(str[length - 1 - i]))
        {
            /*
             * We use tolower() to make comparison case-insensitive
             * "Racecar" should be considered a palindrome even though
             * 'R' != 'r' in ASCII values
             */
            isPalindrome = 0;  // Set flag to false
            break;             // No need to check further
        }
    }
    
    if(isPalindrome)
        printf("The string is a palindrome.\n");
    else
        printf("The string is not a palindrome.\n");
    
    /*
     * STEP 9: STRING COMPARISON
     * Compare two strings alphabetically using strcmp()
     */
    printf("\nEnter another string for comparison: ");
    fgets(str2, sizeof(str2), stdin);     // Get second string
    str2[strcspn(str2, "\n")] = 0;        // Remove newline
    
    /*
     * strcmp() FUNCTION EXPLANATION:
     * - Compares strings character by character
     * - Returns 0 if strings are identical
     * - Returns negative if first string comes before second alphabetically  
     * - Returns positive if first string comes after second alphabetically
     * - Comparison is based on ASCII values
     */
    if(strcmp(str, str2) == 0)
        printf("Both strings are identical.\n");
    else if(strcmp(str, str2) < 0)
        printf("First string comes before second string alphabetically.\n");
    else
        printf("First string comes after second string alphabetically.\n");
    
    return 0;
}

/*
 * KEY LEARNING POINTS ABOUT STRINGS:
 * 
 * 1. STRING FUNDAMENTALS:
 *    - Strings are arrays of characters ending with '\0'
 *    - Always allocate one extra byte for null terminator
 *    - String length doesn't include the null terminator
 *    - "Hello" needs 6 bytes: ['H','e','l','l','o','\0']
 * 
 * 2. STRING INPUT METHODS:
 *    - fgets(): Safer, reads entire line including spaces
 *    - scanf("%s"): Stops at whitespace, risk of buffer overflow
 *    - Always remove newline from fgets() input
 * 
 * 3. CHARACTER CLASSIFICATION (<ctype.h>):
 *    - isalpha(): Check if character is a letter
 *    - toupper(): Convert to uppercase
 *    - tolower(): Convert to lowercase
 *    - These functions work with individual characters, not strings
 * 
 * 4. STRING PROCESSING ALGORITHMS:
 *    - Length calculation: Count until '\0'
 *    - Reversal: Copy characters in reverse order
 *    - Palindrome: Compare characters from both ends
 *    - Character counting: Classify each character
 * 
 * 5. STRING LIBRARY FUNCTIONS (<string.h>):
 *    - strlen(): Calculate string length
 *    - strcmp(): Compare strings alphabetically
 *    - strcpy(): Copy strings
 *    - strcat(): Concatenate strings
 *    - strcspn(): Find first occurrence of character set
 * 
 * 6. COMMON STRING MISTAKES:
 *    - Forgetting null terminator when creating strings manually
 *    - Buffer overflow (writing beyond array bounds)
 *    - Not removing newline from fgets() input
 *    - Comparing strings with == instead of strcmp()
 * 
 * 7. MEMORY CONSIDERATIONS:
 *    - Strings use contiguous memory
 *    - Larger arrays use more memory
 *    - Always consider maximum expected input length
 *    - Static arrays (char str[100]) vs dynamic allocation
 */
