/*
 * Program: Array Operations Demonstration
 * Purpose: This program teaches beginners about:
 *          - Array declaration and initialization
 *          - Array indexing (0-based indexing)
 *          - Traversing arrays using loops
 *          - Basic array algorithms (sum, average, max, min, search)
 *          - Input validation and error handling
 * Demonstrates: Complete array manipulation with statistical operations
 */

#include <stdio.h>

int main()
{
    /*
     * STEP 1: ARRAY DECLARATION AND VARIABLE SETUP
     */
    
    int arr[50];     // Declare an integer array that can hold 50 elements
                     // Array elements are: arr[0], arr[1], arr[2], ..., arr[49]
                     // IMPORTANT: Array indexing starts from 0, not 1!
    
    int n;           // Number of elements user wants to enter (actual size used)
    int i;           // Loop counter variable for traversing array
    int sum = 0;     // Variable to store sum of all elements (initialized to 0)
    int max, min;    // Variables to store maximum and minimum values
    float average;   // Average of all elements (float to handle decimal results)
    
    /*
     * STEP 2: GET ARRAY SIZE FROM USER WITH VALIDATION
     */
    printf("Array Operations Program\n");
    printf("Enter the number of elements (max 50): ");
    scanf("%d", &n);
    
    // INPUT VALIDATION: Check if n is within valid range
    if(n <= 0 || n > 50)
    {
        printf("Invalid number of elements!\n");
        return 1;  // Exit program with error code 1 (non-zero means error)
    }
    
    /*
     * STEP 3: INPUT ELEMENTS INTO ARRAY
     * We use a for loop to fill the array with user input
     */
    printf("Enter %d elements:\n", n);
    
    for(i = 0; i < n; i++)  // Loop from index 0 to n-1
    {
        printf("Element %d: ", i + 1);  // Display position as 1-based for user friendliness
        scanf("%d", &arr[i]);          // Store input in arr[i] (i-th position)
        
        sum += arr[i];  // Add current element to sum
                        // This is same as: sum = sum + arr[i]
                        // We calculate sum while inputting to be efficient
    }
    
    /*
     * STEP 4: DISPLAY ALL ARRAY ELEMENTS
     * Traverse the array and print each element
     */
    printf("\nArray elements: ");
    for(i = 0; i < n; i++)  // Loop through all valid indices
    {
        printf("%d ", arr[i]);  // Print element at index i
    }
    printf("\n");  // New line after displaying all elements
    
    /*
     * STEP 5: FIND MAXIMUM AND MINIMUM ELEMENTS
     * Algorithm: Assume first element is both max and min, then compare with others
     */
    max = min = arr[0];  // Initialize both max and min to first element
                         // This is same as: max = arr[0]; min = arr[0];
    
    for(i = 1; i < n; i++)  // Start from index 1 (since we already used arr[0])
    {
        if(arr[i] > max)     // If current element is greater than max
            max = arr[i];    // Update max to current element
            
        if(arr[i] < min)     // If current element is smaller than min
            min = arr[i];    // Update min to current element
    }
    
    /*
     * STEP 6: CALCULATE AVERAGE
     * Average = Sum of all elements / Number of elements
     */
    average = (float)sum / n;  // (float) is type casting - converts int to float
                               // This ensures decimal division instead of integer division
                               // Without (float): 5/2 = 2 (integer division)
                               // With (float): 5/2 = 2.5 (floating point division)
    
    /*
     * STEP 7: DISPLAY STATISTICAL RESULTS
     */
    printf("\n--- Array Statistics ---\n");
    printf("Sum of elements: %d\n", sum);
    printf("Average: %.2f\n", average);      // %.2f shows 2 decimal places
    printf("Maximum element: %d\n", max);
    printf("Minimum element: %d\n", min);
    
    /*
     * STEP 8: SEARCH FOR A SPECIFIC ELEMENT
     * This is called Linear Search - we check each element one by one
     */
    int search;      // Element to search for
    int found = 0;   // Flag variable: 0 = not found, 1 = found
    int position = -1; // Position where element is found (-1 means not found)
    
    printf("\nEnter element to search: ");
    scanf("%d", &search);
    
    // LINEAR SEARCH ALGORITHM
    for(i = 0; i < n; i++)  // Check each element
    {
        if(arr[i] == search)  // If current element matches what we're looking for
        {
            found = 1;        // Set flag to indicate element found
            position = i;     // Store the index where we found it
            break;            // Exit loop early (no need to continue searching)
        }
    }
    
    /*
     * STEP 9: DISPLAY SEARCH RESULTS
     * Check the flag variable to see if element was found
     */
    if(found)  // If found == 1 (true)
    {
        // Display both position (1-based for user) and index (0-based for programmers)
        printf("Element %d found at position %d (index %d)\n", search, position + 1, position);
    }
    else  // If found == 0 (false)
    {
        printf("Element %d not found in the array\n", search);
    }
    
    return 0;  // Program ended successfully
    
    /*
     * KEY LEARNING POINTS ABOUT ARRAYS:
     * 
     * 1. ARRAY BASICS:
     *    - Arrays store multiple values of same data type
     *    - Array size is fixed at declaration time
     *    - Elements are stored in contiguous memory locations
     * 
     * 2. ARRAY INDEXING:
     *    - Arrays use 0-based indexing (first element is arr[0])
     *    - For array of size n, valid indices are 0 to n-1
     *    - arr[n] is invalid and causes undefined behavior
     * 
     * 3. ARRAY TRAVERSAL:
     *    - Use for loop with counter from 0 to n-1
     *    - Can process elements during input or in separate loop
     * 
     * 4. COMMON ARRAY ALGORITHMS:
     *    - Sum: Add all elements using loop
     *    - Average: Sum divided by number of elements
     *    - Max/Min: Compare each element with current max/min
     *    - Search: Check each element until found or end reached
     * 
     * 5. IMPORTANT CONCEPTS:
     *    - Type casting: (float) converts int to float for decimal division
     *    - Flag variables: Used to track status (found/not found)
     *    - Early exit: Use break to stop loop when task is complete
     *    - Input validation: Always check if user input is valid
     */
}
