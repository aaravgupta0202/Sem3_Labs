//1. Write a menu-driven C program using structures to implement the following operations on a Doubly Linked List.
//➢Insert an element at the rear end of the list (Append a new node to the end of the list)
//➢Delete an element from the rear end of the list (Remove the last node in the list)
//➢Insert an element at a given position in the list (e.g., Insert at position 3. Positioning starts from 1.)
//➢Delete an element from a given position in the list
//➢Insert an element after a node containing a specific value (e.g., Insert 40 after 25)
//➢Insert an element before a node containing a specific value (e.g., Insert 10 before 25)
//➢Traverse the list in forward direction (From head to tail)
//➢Traverse the list in reverse direction (From tail to head – i.e., reverse traversal)

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev, *next;
} Node;

Node *head = NULL, *tail = NULL;

Node *createNode(int value) {
    Node *node = malloc(sizeof(Node));
    if (!node) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    node->data = value;
    node->prev = node->next = NULL;
    return node;
}

void append(int value) {
    Node *node = createNode(value);
    if (!tail)
        head = tail = node;
    else {
        node->prev = tail;
        tail->next = node;
        tail = node;
    }
}

void deleteRear(void) {
    if (!tail) {
        printf("List is empty.\n");
        return;
    }

    Node *temp = tail;
    tail = tail->prev;
    if (tail) tail->next = NULL;
    else head = NULL;
    free(temp);
}

void insertAt(int value, int position) {
    if (position < 1) {
        printf("Invalid position.\n");
        return;
    }
    if (position == 1) {
        Node *node = createNode(value);
        node->next = head;
        if (head) head->prev = node;
        else tail = node;
        head = node;
        return;
    }

    Node *current = head;
    for (int i = 1; current && i < position; i++)
        current = current->next;

    if (!current) {
        int length = 0;
        for (Node *p = head; p; p = p->next) length++;
        if (position == length + 1) append(value);
        else printf("Position out of range.\n");
        return;
    }

    Node *node = createNode(value);
    node->prev = current->prev;
    node->next = current;
    current->prev->next = node;
    current->prev = node;
}

void deleteAt(int position) {
    if (position < 1) {
        printf("Invalid position.\n");
        return;
    }

    Node *current = head;
    for (int i = 1; current && i < position; i++)
        current = current->next;

    if (!current) {
        printf("Position out of range.\n");
        return;
    }

    if (current->prev) current->prev->next = current->next;
    else head = current->next;

    if (current->next) current->next->prev = current->prev;
    else tail = current->prev;

    free(current);
}

void insertByValue(int target, int value, int after) {
    Node *current = head;
    while (current && current->data != target)
        current = current->next;

    if (!current) {
        printf("Value not found.\n");
        return;
    }

    if (after && current == tail) {
        append(value);
        return;
    }
    if (!after && current == head) {
        insertAt(value, 1);
        return;
    }

    Node *node = createNode(value);
    Node *left = after ? current : current->prev;
    Node *right = after ? current->next : current;

    node->prev = left;
    node->next = right;
    left->next = node;
    right->prev = node;
}

void display(void) {
    printf("Forward: ");
    for (Node *p = head; p; p = p->next)
        printf("%d ", p->data);

    printf("\nReverse: ");
    for (Node *p = tail; p; p = p->prev)
        printf("%d ", p->data);

    printf("\n");
}

void freeList(void) {
    while (head) {
        Node *temp = head;
        head = head->next;
        free(temp);
    }
    tail = NULL;
}

int main(void) {
    int choice, value, position, target;

    do {
        printf("\n1.Append  \n2.Delete rear  \n3.Insert at position\n");
        printf("4.Delete at position  \n5.Insert after value\n");
        printf("6.Insert before value  \n7.Display  \n0.Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Value: ");
                scanf("%d", &value);
                append(value);
                break;
            case 2:
                deleteRear();
                break;
            case 3:
                printf("Value and position: ");
                scanf("%d%d", &value, &position);
                insertAt(value, position);
                break;
            case 4:
                printf("Position: ");
                scanf("%d", &position);
                deleteAt(position);
                break;
            case 5:
            case 6:
                printf("Target value and new value: ");
                scanf("%d%d", &target, &value);
                insertByValue(target, value, choice == 5);
                break;
            case 7:
                display();
                break;
            case 0:
                freeList();
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 0);

    return 0;
}
