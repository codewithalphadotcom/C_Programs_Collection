#include <stdio.h>

// Function to calculate factorial
long long factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    long long fact = 1;
    for (int i = 1; i <= n; i++)
    {
        fact *= i;
    }
    return fact;
}

// Function to generate Fibonacci series
void fibonacci(int n)
{
    int a = 0, b = 1, c;
    printf("Fibonacci Series up to %d terms: ", n);
    for (int i = 0; i < n; i++)
    {
        printf("%d, ", a);
        c = a + b;
        a = b;
        b = c;
    }
    printf("\n");
}

int main()
{
    int num;

    // Factorial
    printf("Enter a number to find its factorial: ");
    scanf("%d", &num);
    printf("Factorial of %d = %lld\n", num, factorial(num));

    // Fibonacci
    printf("\nEnter the number of terms for Fibonacci series: ");
    scanf("%d", &num);
    fibonacci(num);

    return 0;
}
