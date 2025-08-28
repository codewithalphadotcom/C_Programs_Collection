/*
 * Program: Bubble Sort Visualization and Array Utilities
 * Purpose: This program teaches beginners about:
 *          - Sorting algorithms (Bubble Sort)
 *          - Algorithm steps and optimization
 *          - Swapping elements and temporary variables
 *          - Time complexity intuition (O(n^2))
 *          - Early termination optimization using a flag
 *          - Basic linear search in arrays
 * Demonstrates: Step-by-step sorting process with printed passes
 */

#include <stdio.h>

/*
 * Function: printArray
 * Purpose: Utility function to print array contents
 * Parameters:
 *   - arr: the integer array
 *   - size: number of elements in the array
 * Returns: nothing (void)
 * Note: Using a function avoids repeating the same print loop
 */
void printArray(int arr[], int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);  // Print each element followed by a space
    }
    printf("\n");               // Newline after printing the array
}

int main()
{
    /*
     * STEP 1: INPUT PHASE
     * Get number of elements and the elements themselves
     */
    int arr[50];                 // Array with max capacity 50
    int n;                       // Actual number of elements to sort
    int i, j;                    // Loop counters
    int temp;                    // Temporary variable for swapping
    int swapped;                 // Flag to detect if a pass made any swaps
    
    printf("Bubble Sort Program\n");
    printf("Enter the number of elements (max 50): ");
    scanf("%d", &n);
    
    // Validate input size
    if(n <= 0 || n > 50)
    {
        printf("Invalid number of elements!\n");
        return 1;  // Exit with error code
    }
    
    // Input elements
    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++)
    {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    
    printf("\nOriginal array: ");
    printArray(arr, n);
    
    /*
     * STEP 2: BUBBLE SORT ALGORITHM
     * Idea: Repeatedly compare adjacent elements and swap if out of order
     * After the i-th pass, the i-th largest element is in its correct position
     * Visualization: Like bubbles rising to the top (largest moves to the end)
     * Complexity: O(n^2) worst-case time, O(1) extra space
     */
    printf("\nSorting process:\n");
    for(i = 0; i < n - 1; i++)  // Outer loop controls the number of passes
    {
        swapped = 0; // Reset flag; if it remains 0, array is already sorted
        
        printf("Pass %d: ", i + 1);
        for(j = 0; j < n - i - 1; j++)  // Inner loop compares adjacent elements
        {
            if(arr[j] > arr[j + 1])     // If elements are in wrong order
            {
                // Swap elements using a temporary variable
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;            // Mark that a swap occurred in this pass
            }
        }
        
        printArray(arr, n);  // Show array state after each pass
        
        // Optimization: If no swaps occurred, the array is already sorted
        if(swapped == 0)
        {
            printf("Array is now sorted! (Early termination)\n");
            break;  // Exit the loop early
        }
    }
    
    printf("\nFinal sorted array: ");
    printArray(arr, n);
    
    /*
     * STEP 3: LINEAR SEARCH IN SORTED ARRAY
     * Note: For sorted arrays, binary search is more efficient (O(log n))
     * Here we demonstrate simple linear search for clarity
     */
    int search, found = 0, position = -1;
    printf("\nEnter element to search in sorted array: ");
    scanf("%d", &search);
    
    for(i = 0; i < n; i++)
    {
        if(arr[i] == search)
        {
            found = 1;
            position = i;  // 0-based index
            break;         // Exit early when found
        }
    }
    
    if(found)
        printf("Element %d found at position %d (index %d)\n", search, position + 1, position);
    else
        printf("Element %d not found in the array\n", search);
    
    return 0;
}

/*
 * KEY LEARNING POINTS ABOUT BUBBLE SORT:
 * 
 * 1. HOW IT WORKS:
 *    - Repeatedly compare adjacent pairs and swap if out of order
 *    - Largest elements "bubble up" to the end each pass
 *    - After k passes, the last k elements are in correct position
 * 
 * 2. OPTIMIZATION WITH FLAG:
 *    - Track whether any swap happened during a pass
 *    - If no swap occurs, the array is already sorted -> stop early
 *    - Improves performance for nearly-sorted arrays
 * 
 * 3. COMPLEXITY:
 *    - Time: O(n^2) in worst and average cases, O(n) best case (already sorted)
 *    - Space: O(1) extra space (in-place sorting)
 * 
 * 4. SWAPPING ELEMENTS:
 *    - Use a temporary variable to swap two values
 *    - temp = a; a = b; b = temp;
 * 
 * 5. WHEN TO USE BUBBLE SORT:
 *    - Good for teaching sorting concepts
 *    - Simple to implement
 *    - Not efficient for large datasets (use quicksort/mergesort instead)
 * 
 * 6. SEARCHING:
 *    - Linear search checks elements one by one (O(n))
 *    - For sorted arrays, prefer binary search (O(log n))
 */
