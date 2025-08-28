/*
 * Program: Recursion Examples and Techniques
 * Purpose: This program teaches beginners about:
 *          - Recursive functions and base cases
 *          - Thinking in terms of smaller subproblems
 *          - Stack frames and function calls
 *          - Differences between iterative and recursive approaches
 *          - Common recursive algorithms (factorial, Fibonacci, GCD)
 *          - When recursion is appropriate (and when not)
 * Demonstrates: Multiple classic recursion examples with menu
 */

#include <stdio.h>

/*
 * FUNCTION PROTOTYPES
 * Declare recursive functions before main()
 */
int factorialRecursive(int n);        // n! = n × (n-1)!
int fibonacciRecursive(int n);        // F(n) = F(n-1) + F(n-2), F(1)=0, F(2)=1
int gcdRecursive(int a, int b);       // Euclidean Algorithm: gcd(a,b) = gcd(b, a%b)
void printNumbers(int n);             // Print 1 to n recursively
int sumOfDigits(int n);               // Sum digits: 123 -> 1+2+3
int power(int base, int exp);         // base^exp via repeated multiplication

int main()
{
    /*
     * MENU-DRIVEN INTERFACE
     */
    int choice, n, a, b, base, exp, result;
    
    printf("Recursion Examples Program\n");
    printf("1. Factorial (Recursive)\n");
    printf("2. Fibonacci number (Recursive)\n");
    printf("3. GCD of two numbers (Recursive)\n");
    printf("4. Print numbers 1 to n (Recursive)\n");
    printf("5. Sum of digits (Recursive)\n");
    printf("6. Power calculation (Recursive)\n");
    printf("Enter your choice (1-6): ");
    scanf("%d", &choice);
    
    switch(choice)
    {
        case 1:
            printf("Enter a number: ");
            scanf("%d", &n);
            if(n < 0)
            {
                printf("Factorial is not defined for negative numbers.\n");
            }
            else
            {
                result = factorialRecursive(n);
                printf("Factorial of %d = %d\n", n, result);
            }
            break;
            
        case 2:
            printf("Enter position in Fibonacci series: ");
            scanf("%d", &n);
            if(n <= 0)
            {
                printf("Please enter a positive number.\n");
            }
            else
            {
                result = fibonacciRecursive(n);
                printf("Fibonacci number at position %d = %d\n", n, result);
            }
            break;
            
        case 3:
            printf("Enter two numbers: ");
            scanf("%d %d", &a, &b);
            result = gcdRecursive(a, b);
            printf("GCD of %d and %d = %d\n", a, b, result);
            break;
            
        case 4:
            printf("Enter a number: ");
            scanf("%d", &n);
            printf("Numbers from 1 to %d:\n", n);
            printNumbers(n);
            printf("\n");
            break;
            
        case 5:
            printf("Enter a number: ");
            scanf("%d", &n);
            result = sumOfDigits(n);
            printf("Sum of digits of %d = %d\n", n, result);
            break;
            
        case 6:
            printf("Enter base and exponent: ");
            scanf("%d %d", &base, &exp);
            if(exp < 0)
            {
                printf("This program handles non-negative exponents only.\n");
            }
            else
            {
                result = power(base, exp);
                printf("%d^%d = %d\n", base, exp, result);
            }
            break;
            
        default:
            printf("Invalid choice!\n");
    }
    
    return 0;
}

/*
 * RECURSIVE FUNCTION DEFINITIONS
 */

// Recursive function to calculate factorial
// Definition: n! = n × (n-1)! with 0! = 1 and 1! = 1
int factorialRecursive(int n)
{
    // Base case(s): smallest input for which we know the answer directly
    if(n == 0 || n == 1)
        return 1;  // 0! = 1, 1! = 1 (by definition)
    
    // Recursive case: reduce the problem size and call function again
    return n * factorialRecursive(n - 1);  // Multiply n by factorial of (n-1)
}

// Recursive function to calculate Fibonacci number
// Definition:
// F(1) = 0, F(2) = 1, for n>2 -> F(n) = F(n-1) + F(n-2)
int fibonacciRecursive(int n)
{
    // Base cases: directly known values
    if(n == 1)
        return 0;
    if(n == 2)
        return 1;
    
    // Recursive case: sum of previous two Fibonacci numbers
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
    /*
     * WARNING: This implementation has exponential time complexity O(2^n)
     * due to repeated calculations. It's for teaching purposes only.
     * Use iterative or memoized approaches for efficiency.
     */
}

// Recursive function to find GCD using Euclidean algorithm
// gcd(a, b) = gcd(b, a % b) with gcd(a, 0) = a
int gcdRecursive(int a, int b)
{
    // Base case: when second number becomes 0
    if(b == 0)
        return a;
    
    // Recursive case: reduce the problem by taking remainder
    return gcdRecursive(b, a % b);
}

// Recursive function to print numbers from 1 to n in increasing order
void printNumbers(int n)
{
    // Base case: stop when n <= 0 (nothing to print)
    if(n <= 0)
        return;
    
    // Recursive case - print smaller numbers first, then current
    printNumbers(n - 1);   // This prints 1..(n-1)
    printf("%d ", n);     // Then we print n
}

// Recursive function to calculate sum of digits of a non-negative integer
int sumOfDigits(int n)
{
    // Base case: when n becomes 0, sum is 0
    if(n == 0)
        return 0;
    
    // Recursive case: last digit + sum of remaining digits
    return (n % 10) + sumOfDigits(n / 10);
}

// Recursive function to calculate power (base^exp) for non-negative exp
int power(int base, int exp)
{
    // Base case: any number to the power 0 is 1
    if(exp == 0)
        return 1;
    
    // Recursive case: base^exp = base × base^(exp-1)
    return base * power(base, exp - 1);
}
