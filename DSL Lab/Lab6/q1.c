//1.Write a C program to implement a Circular Singly Linked List using First and Last pointers.
//Implement the following operations:
//i.Insertion at the end of the list using First and Last pointers.
//ii.Deletion from the beginning or end using First and Last pointers.
//iii.Display the list after each operation.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *first = NULL;
Node *last = NULL;

void display(void) {
    if (first == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node *current = first;
    printf("List: ");
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != first);
    printf("\n");
}

void insertEnd(int value) {
    Node *node = malloc(sizeof(Node));
    if (node == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    node->data = value;

    if (first == NULL) {
        first = last = node;
        node->next = first;
    } else {
        node->next = first;
        last->next = node;
        last = node;
    }

    display();
}

void deleteBeginning(void) {
    if (first == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node *temp = first;
    if (first == last) {
        first = last = NULL;
    } else {
        first = first->next;
        last->next = first;
    }

    free(temp);
    display();
}

void deleteEnd(void) {
    if (first == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (first == last) {
        free(first);
        first = last = NULL;
    } else {
        Node *current = first;
        while (current->next != last)
            current = current->next;

        free(last);
        last = current;
        last->next = first;
    }

    display();
}

int main(void) {
    int choice, value;

    do {
        printf("\n1. Insert at end\n");
        printf("2. Delete from beginning\n");
        printf("3. Delete from end\n");
        printf("4. Display\n");
        printf("0. Exit\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1)
            break;

        switch (choice) {
            case 1:
                printf("Enter value: ");
                if (scanf("%d", &value) == 1)
                    insertEnd(value);
                break;
            case 2:
                deleteBeginning();
                break;
            case 3:
                deleteEnd();
                break;
            case 4:
                display();
                break;
            case 0:
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 0);

    while (first != NULL)
        deleteBeginning();

    return 0;
}
