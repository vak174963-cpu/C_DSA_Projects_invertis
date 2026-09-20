#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Student structure */
struct Student
{
    int rollNo;
    char name[50];
    float marks;
};

/* Linked List Node */
struct Node
{
    struct Student data;
    struct Node *next;
};

/* Array for storing students */
struct Student students[100];

int studentCount = 0;


/* -------------------------------------------------
   ARRAY FUNCTIONS
   ------------------------------------------------- */

/* Add student using Array */
void addStudentArray()
{
    if (studentCount >= 100)
    {
        printf("\nStudent limit reached!\n");
        return;
    }

    printf("\nEnter Roll Number: ");
    scanf("%d", &students[studentCount].rollNo);

    printf("Enter Name: ");
    scanf(" %[^\n]", students[studentCount].name);

    printf("Enter Marks: ");
    scanf("%f", &students[studentCount].marks);

    studentCount++;

    printf("\nStudent added successfully!\n");
}


/* Display students using Array */
void displayStudentsArray()
{
    int i;

    if (studentCount == 0)
    {
        printf("\nNo students available!\n");
        return;
    }

    printf("\n---------------------------------------------\n");
    printf("Roll No\t\tName\t\tMarks\n");
    printf("---------------------------------------------\n");

    for (i = 0; i < studentCount; i++)
    {
        printf("%d\t\t%s\t\t%.2f\n",
               students[i].rollNo,
               students[i].name,
               students[i].marks);
    }
}


/* Search student using Linear Search */
void searchStudent()
{
    int roll, i;
    int found = 0;

    printf("\nEnter Roll Number to search: ");
    scanf("%d", &roll);

    for (i = 0; i < studentCount; i++)
    {
        if (students[i].rollNo == roll)
        {
            printf("\nStudent Found!\n");

            printf("Roll Number: %d\n",
                   students[i].rollNo);

            printf("Name: %s\n",
                   students[i].name);

            printf("Marks: %.2f\n",
                   students[i].marks);

            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("\nStudent not found!\n");
    }
}


/* Sort students by Marks using Bubble Sort */
void sortStudents()
{
    int i, j;
    struct Student temp;

    if (studentCount == 0)
    {
        printf("\nNo students available for sorting!\n");
        return;
    }

    for (i = 0; i < studentCount - 1; i++)
    {
        for (j = 0; j < studentCount - i - 1; j++)
        {
            if (students[j].marks < students[j + 1].marks)
            {
                temp = students[j];

                students[j] = students[j + 1];

                students[j + 1] = temp;
            }
        }
    }

    printf("\nStudents sorted by marks (Highest to Lowest).\n");
}


/* -------------------------------------------------
   LINKED LIST FUNCTIONS
   ------------------------------------------------- */

struct Node *head = NULL;


/* Add student using Linked List */
void addStudentLinkedList()
{
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("\nMemory allocation failed!\n");
        return;
    }

    printf("\nEnter Roll Number: ");
    scanf("%d", &newNode->data.rollNo);

    printf("Enter Name: ");
    scanf(" %[^\n]", newNode->data.name);

    printf("Enter Marks: ");
    scanf("%f", &newNode->data.marks);

    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        struct Node *temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    printf("\nStudent added to Linked List successfully!\n");
}


/* Display Linked List */
void displayLinkedList()
{
    struct Node *temp = head;

    if (head == NULL)
    {
        printf("\nLinked List is empty!\n");
        return;
    }

    printf("\n---------------------------------------------\n");
    printf("Roll No\t\tName\t\tMarks\n");
    printf("---------------------------------------------\n");

    while (temp != NULL)
    {
        printf("%d\t\t%s\t\t%.2f\n",
               temp->data.rollNo,
               temp->data.name,
               temp->data.marks);

        temp = temp->next;
    }
}


/* -------------------------------------------------
   MAIN FUNCTION
   ------------------------------------------------- */

int main()
{
    int choice;

    do
    {
        printf("\n\n========================================");
        printf("\n       STUDENT MANAGEMENT SYSTEM");
        printf("\n========================================");

        printf("\n\n--- ARRAY OPERATIONS ---");

        printf("\n1. Add Student");
        printf("\n2. Display Students");
        printf("\n3. Search Student");
        printf("\n4. Sort Students by Marks");

        printf("\n\n--- LINKED LIST OPERATIONS ---");

        printf("\n5. Add Student using Linked List");
        printf("\n6. Display Linked List");

        printf("\n\n7. Exit");

        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addStudentArray();
                break;

            case 2:
                displayStudentsArray();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                sortStudents();
                break;

            case 5:
                addStudentLinkedList();
                break;

            case 6:
                displayLinkedList();
                break;

            case 7:
                printf("\nThank you for using Student Management System!\n");
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }

    } while (choice != 7);

    return 0;
}
