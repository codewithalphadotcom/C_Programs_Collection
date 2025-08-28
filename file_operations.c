/*
 * Program: File Operations Demonstration
 * Purpose: This program teaches beginners about:
 *          - File I/O operations (read, write, append)
 *          - Different file opening modes ("r", "w", "a")
 *          - Error handling for file operations
 *          - File statistics (counting lines, words, characters)
 *          - File copying and manipulation
 *          - Working with FILE pointers
 * Demonstrates: Complete file handling workflow in C
 * 
 * File Modes Explained:
 * "r"  - Read mode: opens existing file for reading
 * "w"  - Write mode: creates new file or overwrites existing
 * "a"  - Append mode: opens file to add content at the end
 */

#include <stdio.h>   // For file I/O functions (fopen, fread, fwrite, etc.)
#include <stdlib.h>  // For system functions like exit()
#include <string.h>  // For string functions (strncmp, strlen, etc.)

int main()
{
    /*
     * VARIABLE DECLARATIONS FOR FILE OPERATIONS
     */
    FILE *file;            // FILE pointer - handle to access files
    char filename[100];    // Store filename entered by user
    char content[500];     // Buffer for file content
    char line[200];        // Buffer for reading/writing lines
    int choice;            // Menu selection
    int lineCount = 0, wordCount = 0, charCount = 0;  // File statistics
    char ch;               // For character-by-character file reading
    
    printf("File Operations Program\n");
    printf("=======================\n");
    
    /*
     * MAIN MENU LOOP
     * Continue until user chooses to exit
     */
    do
    {
        printf("\n1. Write to file\n");
        printf("2. Read from file\n");
        printf("3. Append to file\n");
        printf("4. Count lines, words, characters\n");
        printf("5. Copy file\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 1: // WRITE TO FILE (CREATE NEW OR OVERWRITE)
                /*
                 * Writing creates a new file or overwrites existing file
                 * Mode "w" truncates file to zero length if it exists
                 */
                printf("Enter filename: ");
                scanf("%s", filename);
                
                file = fopen(filename, "w");  // Open file in write mode
                /*
                 * fopen() RETURNS:
                 * - Valid FILE pointer if successful
                 * - NULL if file cannot be opened (permissions, disk full, etc.)
                 * Always check for NULL before using the file pointer!
                 */
                if(file == NULL)
                {
                    printf("Error: Could not create file!\n");
                    break;  // Skip to next menu iteration
                }
                
                printf("Enter content to write (end with 'END' on a new line):\n");
                getchar(); // Consume leftover newline from scanf()
                
                /*
                 * WRITE LOOP: Read lines from user and write to file
                 * Continue until user types "END" on a line by itself
                 */
                while(1)
                {
                    fgets(line, sizeof(line), stdin);  // Read line from user
                    /*
                     * fgets() reads a line including the newline character
                     * sizeof(line) ensures we don't overflow the buffer
                     */
                    
                    if(strncmp(line, "END", 3) == 0)  // Check if user wants to stop
                        break;
                    /*
                     * strncmp() compares first 3 characters
                     * This allows "END\n" to match "END"
                     */
                    
                    fputs(line, file);  // Write line to file
                    /*
                     * fputs() writes the string to file
                     * It preserves newlines from fgets()
                     */
                }
                
                fclose(file);  // IMPORTANT: Close file to save changes
                /*
                 * fclose() flushes any buffered data to disk
                 * Always close files when done to prevent data loss
                 */
                printf("File written successfully!\n");
                break;
                
            case 2: // Read from file
                printf("Enter filename to read: ");
                scanf("%s", filename);
                
                file = fopen(filename, "r");
                if(file == NULL)
                {
                    printf("Error: File not found!\n");
                    break;
                }
                
                printf("\n--- File Content ---\n");
                while((ch = fgetc(file)) != EOF)
                {
                    printf("%c", ch);
                }
                printf("\n--- End of File ---\n");
                
                fclose(file);
                break;
                
            case 3: // Append to file
                printf("Enter filename to append: ");
                scanf("%s", filename);
                
                file = fopen(filename, "a");
                if(file == NULL)
                {
                    printf("Error: Could not open file!\n");
                    break;
                }
                
                printf("Enter content to append (end with 'END' on a new line):\n");
                getchar(); // Consume newline
                
                while(1)
                {
                    fgets(line, sizeof(line), stdin);
                    if(strncmp(line, "END", 3) == 0)
                        break;
                    fputs(line, file);
                }
                
                fclose(file);
                printf("Content appended successfully!\n");
                break;
                
            case 4: // Count statistics
                printf("Enter filename to analyze: ");
                scanf("%s", filename);
                
                file = fopen(filename, "r");
                if(file == NULL)
                {
                    printf("Error: File not found!\n");
                    break;
                }
                
                lineCount = 0;
                wordCount = 0;
                charCount = 0;
                int inWord = 0;
                
                while((ch = fgetc(file)) != EOF)
                {
                    charCount++;
                    
                    if(ch == '\n')
                        lineCount++;
                    
                    if(ch == ' ' || ch == '\t' || ch == '\n')
                    {
                        if(inWord)
                        {
                            wordCount++;
                            inWord = 0;
                        }
                    }
                    else
                    {
                        inWord = 1;
                    }
                }
                
                // Count last word if file doesn't end with whitespace
                if(inWord)
                    wordCount++;
                
                fclose(file);
                
                printf("\n--- File Statistics ---\n");
                printf("Filename: %s\n", filename);
                printf("Lines: %d\n", lineCount);
                printf("Words: %d\n", wordCount);
                printf("Characters: %d\n", charCount);
                break;
                
            case 5: // Copy file
                {
                    char sourceFile[100], destFile[100];
                    FILE *source, *dest;
                    
                    printf("Enter source filename: ");
                    scanf("%s", sourceFile);
                    
                    printf("Enter destination filename: ");
                    scanf("%s", destFile);
                    
                    source = fopen(sourceFile, "r");
                    if(source == NULL)
                    {
                        printf("Error: Source file not found!\n");
                        break;
                    }
                    
                    dest = fopen(destFile, "w");
                    if(dest == NULL)
                    {
                        printf("Error: Could not create destination file!\n");
                        fclose(source);
                        break;
                    }
                    
                    // Copy character by character
                    while((ch = fgetc(source)) != EOF)
                    {
                        fputc(ch, dest);
                    }
                    
                    fclose(source);
                    fclose(dest);
                    
                    printf("File copied successfully from %s to %s!\n", sourceFile, destFile);
                }
                break;
                
            case 6:
                printf("Thank you for using File Operations Program!\n");
                break;
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while(choice != 6);
    
    return 0;
}
