//2. Write a C program to define a student structure with the data members to store name, roll no and grade of the student. Also write the
//required functions to read, display, and sort student information according to the roll number of the student. All the member functions
//will have array of objects as arguments.

#include <stdio.h>

struct Student
{
    char name[50];
    int rollno;
    char grade;
};

void read(struct Student s[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter details of student %d:\n", i + 1);

        printf("Enter name: ");
        scanf(" %[^\n]", s[i].name);

        printf("Enter roll number: ");
        scanf("%d", &s[i].rollno);

        printf("Enter grade: ");
        scanf(" %c", &s[i].grade);
    }
}

void display(struct Student s[], int n)
{
    printf("\nStudent Information:\n");
    printf("Name\tRoll No\tGrade\n");

    for (int i = 0; i < n; i++)
    {
        printf("%s\t%d\t%c\n",s[i].name, s[i].rollno, s[i].grade);
    }
}

void sort(struct Student s[], int n)
{
    struct Student temp;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (s[i].rollno > s[j].rollno)
            {
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
}

int main()
{
    struct Student s[100];
    int n;

    printf("Enter number of students: ");
    scanf("%d", &n);

    read(s, n);

    printf("\nBefore Sorting:");
    display(s, n);

    sort(s, n);

    printf("\nAfter Sorting According to Roll Number:");
    display(s, n);

    return 0;
}
