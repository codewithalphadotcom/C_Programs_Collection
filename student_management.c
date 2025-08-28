/*
 * Program: Student Management System (Structures)
 * Purpose: This program teaches beginners about:
 *          - Structure definition and usage
 *          - Arrays of structures
 *          - Menu-driven programming and modular design
 *          - Functions operating on structs (pass by pointer/value)
 *          - Basic data management in memory
 * Demonstrates: A mini system to add, search, and display students
 */

#include <stdio.h>
#include <string.h>

/*
 * STRUCTURE DEFINITION
 * A structure groups related data under one name
 * Here, a Student has id, name, age, marks (3 subjects), average, and grade
 */
struct Student
{
    int id;           // Unique identifier for student
    char name[50];    // Student name (string as character array)
    int age;          // Age in years
    float marks[3];   // Marks for 3 subjects
    float average;    // Average of the 3 subject marks
    char grade;       // Letter grade based on average
};

/*
 * FUNCTION PROTOTYPES
 */
void inputStudentData(struct Student *s);
void calculateGrade(struct Student *s);
void displayStudent(struct Student s);
void displayAllStudents(struct Student students[], int count);
int findStudent(struct Student students[], int count, int id);

int main()
{
    /*
     * DATA STORAGE: Array of structures
     * This allows us to store up to 10 students in memory
     */
    struct Student students[10];  // Array-based storage (fixed size)
    int choice;                   // Menu choice
    int count = 0;                // Current number of students in system
    int id, index;                // For search by ID
    
    printf("Student Management System\n");
    printf("=========================\n");
    
    do
    {
        // Display menu
        printf("\n1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student by ID\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 1:  // Add a new student
                if(count < 10)  // Check capacity
                {
                    printf("\nEntering data for student %d:\n", count + 1);
                    inputStudentData(&students[count]);  // Pass by pointer to fill data
                    calculateGrade(&students[count]);    // Compute average and grade
                    count++;
                    printf("Student added successfully!\n");
                }
                else
                {
                    printf("Maximum student limit reached!\n");
                }
                break;
                
            case 2:  // Display all students
                if(count > 0)
                {
                    displayAllStudents(students, count);
                }
                else
                {
                    printf("No students in the system!\n");
                }
                break;
                
            case 3:  // Search student by ID
                if(count > 0)
                {
                    printf("Enter student ID to search: ");
                    scanf("%d", &id);
                    index = findStudent(students, count, id);
                    if(index != -1)
                    {
                        printf("\nStudent found:\n");
                        displayStudent(students[index]);
                    }
                    else
                    {
                        printf("Student with ID %d not found!\n", id);
                    }
                }
                else
                {
                    printf("No students in the system!\n");
                }
                break;
                
            case 4:
                printf("Thank you for using Student Management System!\n");
                break;
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while(choice != 4);  // Loop until user chooses to exit
    
    return 0;
}

/*
 * Function: inputStudentData
 * Purpose: Collect data for one student from user
 * Parameter: s -> pointer to Student (so we modify original)
 */
void inputStudentData(struct Student *s)
{
    printf("Enter student ID: ");
    scanf("%d", &s->id);
    
    printf("Enter student name: ");
    scanf("%49s", s->name);  // Limit input to prevent overflow
    
    printf("Enter student age: ");
    scanf("%d", &s->age);
    
    printf("Enter marks for 3 subjects:\n");
    float total = 0;
    for(int i = 0; i < 3; i++)
    {
        printf("Subject %d: ", i + 1);
        scanf("%f", &s->marks[i]);
        total += s->marks[i];
    }
    
    s->average = total / 3.0f;  // Calculate average (use 3.0f as float literal
}

/*
 * Function: calculateGrade
 * Purpose: Determine letter grade based on average marks
 * Parameter: s -> pointer to Student (we update grade inside)
 */
void calculateGrade(struct Student *s)
{
    if(s->average >= 90)
        s->grade = 'A';
    else if(s->average >= 80)
        s->grade = 'B';
    else if(s->average >= 70)
        s->grade = 'C';
    else if(s->average >= 60)
        s->grade = 'D';
    else if(s->average >= 50)
        s->grade = 'E';
    else
        s->grade = 'F';
}

/*
 * Function: displayStudent
 * Purpose: Print all details of a single student
 * Parameter: s -> Student passed by value (read-only copy)
 */
void displayStudent(struct Student s)
{
    printf("\n--- Student Information ---\n");
    printf("ID: %d\n", s.id);
    printf("Name: %s\n", s.name);
    printf("Age: %d\n", s.age);
    printf("Marks: %.2f, %.2f, %.2f\n", s.marks[0], s.marks[1], s.marks[2]);
    printf("Average: %.2f\n", s.average);
    printf("Grade: %c\n", s.grade);
    printf("---------------------------\n");
}

/*
 * Function: displayAllStudents
 * Purpose: Print a table of all students in the system
 * Parameters: students[] -> array of Student, count -> number of students
 */
void displayAllStudents(struct Student students[], int count)
{
    printf("\n=== All Students ===\n");
    printf("ID\tName\t\tAge\tAverage\tGrade\n");
    printf("----------------------------------------\n");
    
    for(int i = 0; i < count; i++)
    {
        printf("%d\t%-15s\t%d\t%.2f\t%c\n", 
               students[i].id, 
               students[i].name, 
               students[i].age, 
               students[i].average, 
               students[i].grade);
    }
}

/*
 * Function: findStudent
 * Purpose: Linear search for a student by ID
 * Returns: index (0-based) if found, -1 otherwise
 */
int findStudent(struct Student students[], int count, int id)
{
    for(int i = 0; i < count; i++)
    {
        if(students[i].id == id)
        {
            return i;  // Found at index i
        }
    }
    return -1; // Not found
}

/*
 * KEY LEARNING POINTS ABOUT STRUCTURES:
 * 
 * 1. STRUCTS GROUP RELATED DATA:
 *    - struct Student groups id, name, age, marks, average, grade
 *    - Makes code more organized than using separate arrays
 * 
 * 2. ARRAYS OF STRUCTS:
 *    - struct Student students[10]; stores 10 Student records
 *    - Access with students[i].field (dot operator)
 * 
 * 3. PASS BY POINTER VS VALUE:
 *    - Functions that modify Student use pointers (struct Student *s)
 *    - Functions that only read can take by value (struct Student s)
 * 
 * 4. MENU-DRIVEN DESIGN:
 *    - do-while loop to repeat until user exits
 *    - switch-case to handle actions
 *    - Input validation (like max 10 students)
 * 
 * 5. BASICS OF DATA MANAGEMENT:
 *    - Add records, search by key (ID), display all
 *    - This is the foundation of bigger systems (databases)
 */
