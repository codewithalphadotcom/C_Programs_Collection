
#include <stdio.h>
#include <string.h>

/*
 * This program demonstrates how to use pointers with structures in C.
 * Pointers are commonly used with structures to avoid copying large amounts of data
 * when passing them to functions. It also shows the two main ways to access
 * structure members through a pointer: the arrow operator (->) and the dereference
 * operator (*).
 */

// Define a simple structure for a Student.
struct Student {
    int id;
    char name[50];
    float gpa;
};

// Function prototype to print student details using a pointer to the structure.
void printStudent(const struct Student *s_ptr);

int main() {
    // Declare a structure variable and initialize it.
    struct Student s1 = {101, "Alice", 3.8};

    // Declare a pointer to a Student structure.
    struct Student *p_student;

    // Assign the address of the structure variable 's1' to the pointer.
    p_student = &s1;

    printf("--- Accessing Struct Members via Pointer ---\n\n");

    // --- Method 1: The Arrow Operator (->) ---
    // This is the most common and readable way.
    // The '->' operator automatically dereferences the pointer and accesses the member.
    printf("Using the arrow operator (->):\n");
    printf("ID:   %d\n", p_student->id);
    printf("Name: %s\n", p_student->name);
    printf("GPA:  %.2f\n\n", p_student->gpa);

    // --- Method 2: The Dereference Operator (*) ---
    // This method is less common but demonstrates what the arrow operator does.
    // 1. Dereference the pointer (*p_student) to get the actual structure.
    // 2. Use the dot operator (.) to access the member.
    // Parentheses are required due to operator precedence (* has lower precedence than .).
    printf("Using the dereference operator (*):\n");
    printf("ID:   %d\n", (*p_student).id);
    printf("Name: %s\n", (*p_student).name);
    printf("GPA:  %.2f\n\n", (*p_student).gpa);
    
    printf("--- Passing a Struct Pointer to a Function ---\n\n");

    // Call the function, passing the address of the structure.
    printStudent(&s1);

    return 0;
}

/*
 * Prints the details of a Student structure.
 * @param s_ptr A constant pointer to a Student structure. 'const' ensures the function
 *              cannot modify the original structure.
 */
void printStudent(const struct Student *s_ptr) {
    printf("Printing from within the function:\n");
    printf("Student ID: %d, Name: %s, GPA: %.2f\n", s_ptr->id, s_ptr->name, s_ptr->gpa);
}

