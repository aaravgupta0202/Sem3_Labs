#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *createNode(int data);
void insertBefore(struct Node **head, int data, int target);
void insertAfter(struct Node **head, int data, int target);
void deleteElement(struct Node **head, int data);
void traverse(struct Node *head);
void reverseList(struct Node **head);
void sortList(struct Node *head);
void deleteAlternate(struct Node **head);
void sortedInsert(struct Node **head, int data);
void freeList(struct Node **head);

struct Node *createNode(int data)
{
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}
void insertBefore(struct Node **head, int data, int target)
{
    struct Node *newNode;
    struct Node *temp;
    struct Node *prev = NULL;

    newNode = createNode(data);

    if (*head == NULL) {
        printf("List is empty. Target element not found.\n");
        free(newNode);
        return;
    }

    if ((*head)->data == target) {
        newNode->next = *head;
        *head = newNode;
        printf("%d inserted before %d.\n", data, target);
        return;
    }

    temp = *head;

    while (temp != NULL && temp->data != target) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Element %d not found.\n", target);
        free(newNode);
        return;
    }

    newNode->next = temp;
    prev->next = newNode;

    printf("%d inserted before %d.\n", data, target);
}

void insertAfter(struct Node **head, int data, int target)
{
    struct Node *temp;
    struct Node *newNode;

    temp = *head;

    while (temp != NULL && temp->data != target) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Element %d not found.\n", target);
        return;
    }

    newNode = createNode(data);

    newNode->next = temp->next;
    temp->next = newNode;

    printf("%d inserted after %d.\n", data, target);
}
void deleteElement(struct Node **head, int data)
{
    struct Node *temp;
    struct Node *prev = NULL;

    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    temp = *head;

    if (temp->data == data) {
        *head = temp->next;
        free(temp);
        printf("Element %d deleted.\n", data);
        return;
    }

    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Element %d not found.\n", data);
        return;
    }

    prev->next = temp->next;
    free(temp);

    printf("Element %d deleted.\n", data);
}

void traverse(struct Node *head)
{
    struct Node *temp = head;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Linked List: ");

    while (temp != NULL) {
        printf("%d", temp->data);

        if (temp->next != NULL)
            printf(" -> ");

        temp = temp->next;
    }

    printf("\n");
}

void reverseList(struct Node **head)
{
    struct Node *prev = NULL;
    struct Node *current = *head;
    struct Node *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;

    printf("List reversed successfully.\n");
}

void sortList(struct Node *head)
{
    struct Node *i;
    struct Node *j;
    int temp;

    if (head == NULL || head->next == NULL) {
        printf("List is already sorted.\n");
        return;
    }

    for (i = head; i != NULL; i = i->next) {
        for (j = head; j->next != NULL; j = j->next) {
            if (j->data > j->next->data) {
                temp = j->data;
                j->data = j->next->data;
                j->next->data = temp;
            }
        }
    }

    printf("List sorted in ascending order.\n");
}

void deleteAlternate(struct Node **head)
{
    struct Node *current;
    struct Node *temp;

    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    current = *head;

    while (current != NULL && current->next != NULL) {
        temp = current->next;

        current->next = temp->next;

        free(temp);

        current = current->next;
    }

    printf("Every alternate node deleted.\n");
}

void sortedInsert(struct Node **head, int data)
{
    struct Node *newNode;
    struct Node *current;

    newNode = createNode(data);

    if (*head == NULL || data <= (*head)->data) {
        newNode->next = *head;
        *head = newNode;

        printf("%d inserted into sorted list.\n", data);
        return;
    }

    current = *head;

    while (current->next != NULL &&
           current->next->data < data) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;

    printf("%d inserted into sorted list.\n", data);
}

void freeList(struct Node **head)
{
    struct Node *temp;

    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

int main()
{
    struct Node *head = NULL;

    int choice;
    int data, target;

    do {
        printf("\n      SINGLY LINKED LIST        \n");
        printf("1.  Insert before an element\n");
        printf("2.  Insert after an element\n");
        printf("3.  Delete an element\n");
        printf("4.  Traverse / Display list\n");
        printf("5.  Reverse the list\n");
        printf("6.  Sort the list\n");
        printf("7.  Delete every alternate node\n");
        printf("8.  Insert into sorted list\n");
        printf("9.  Exit\n");


        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &data);

                printf("Enter element before which to insert: ");
                scanf("%d", &target);

                insertBefore(&head, data, target);
                break;

            case 2:
                printf("Enter element to insert: ");
                scanf("%d", &data);

                printf("Enter element after which to insert: ");
                scanf("%d", &target);

                insertAfter(&head, data, target);
                break;

            case 3:
                printf("Enter element to delete: ");
                scanf("%d", &data);

                deleteElement(&head, data);
                break;

            case 4:
                traverse(head);
                break;

            case 5:
                reverseList(&head);
                break;

            case 6:
                sortList(head);
                break;

            case 7:
                deleteAlternate(&head);
                break;

            case 8:
                printf("Enter element to insert into sorted list: ");
                scanf("%d", &data);

                sortedInsert(&head, data);
                break;

            case 9:
                freeList(&head);
                printf("Memory released. Program terminated.\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 9);

    return 0;
}

