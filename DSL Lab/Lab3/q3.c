//3. Define a structure Student with the following members:
//char name [50] – to store student name as a string
//int roll_no – to store roll number
//float marks – to store marks
//Write a C program that:
//i.Reads the details of ‘n’ students using a function that uses pointer to structure as an argument.
//ii.Displays the details of all students using a separate function.
//iii.Finds and displays the student with the highest marks using pointer-based access.

#include <stdio.h>

struct Student
{
    char name[50];
    int rollno;
    float marks;
};

void read(struct Student *s, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter details of student %d:\n", i + 1);

        printf("Enter name: ");
        scanf(" %[^\n]", (s + i)->name);

        printf("Enter roll number: ");
        scanf("%d", &(s + i)->rollno);

        printf("Enter marks: ");
        scanf("%f", &(s + i)->marks);
    }
}

void display(struct Student s[], int n)
{
    printf("\nStudent Information:\n");
    printf("Name\tRoll No\tMarks\n");

    for (int i = 0; i < n; i++)
    {
        printf("%s\t%d\t%.2f\n",s[i].name, s[i].rollno, s[i].marks);
    }
}

void highestMarks(struct Student *s, int n)
{
    int highest = 0;

    for (int i = 1; i < n; i++)
    {
        if ((s + i)->marks > (s + highest)->marks)
        {
            highest = i;
        }
    }

    printf("\nStudent with Highest Marks:\n");
    printf("Name    : %s\n", (s + highest)->name);
    printf("Roll No : %d\n", (s + highest)->rollno);
    printf("Marks   : %.2f\n", (s + highest)->marks);
}

int main()
{
    struct Student s[100];
    int n;

    printf("Enter number of students: ");
    scanf("%d", &n);

    read(s, n);

    display(s, n);

    highestMarks(s, n);

    return 0;
}
