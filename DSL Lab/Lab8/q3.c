//3. Implement a queue using a singly linked list with enqueue and dequeue operations.

#include <stdio.h>

#define MAX 5

struct Deque {
    int items[MAX];
    int front, rear;
};

// Initialize Deque
void initialize(struct Deque* q) {
    q->front = -1;
    q->rear = -1;
}

// Check if Deque is empty
int isEmpty(struct Deque* q) {
    return q->front == -1;
}

// Check if Deque is full
int isFull(struct Deque* q) {
    return (q->front == 0 && q->rear == MAX - 1) || (q->front == q->rear + 1);
}

// Insert at Front
void insertFront(struct Deque* q, int value) {
    if (isFull(q)) {
        printf("Deque is Full!\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
        q->rear = 0;
    } else if (q->front == 0) {
        q->front = MAX - 1;
    } else {
        q->front--;
    }
    q->items[q->front] = value;
    printf("Inserted %d at Front.\n", value);
}

// Insert at Rear
void insertRear(struct Deque* q, int value) {
    if (isFull(q)) {
        printf("Deque is Full!\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
        q->rear = 0;
    } else if (q->rear == MAX - 1) {
        q->rear = 0;
    } else {
        q->rear++;
    }
    q->items[q->rear] = value;
    printf("Inserted %d at Rear.\n", value);
}

// Delete from Front
void deleteFront(struct Deque* q) {
    if (isEmpty(q)) {
        printf("Deque is Empty!\n");
        return;
    }
    printf("Deleted %d from Front.\n", q->items[q->front]);
    if (q->front == q->rear) {
        q->front = q->rear = -1; // Queue becomes empty
    } else if (q->front == MAX - 1) {
        q->front = 0;
    } else {
        q->front++;
    }
}

// Delete from Rear
void deleteRear(struct Deque* q) {
    if (isEmpty(q)) {
        printf("Deque is Empty!\n");
        return;
    }
    printf("Deleted %d from Rear.\n", q->items[q->rear]);
    if (q->front == q->rear) {
        q->front = q->rear = -1; // Queue becomes empty
    } else if (q->rear == 0) {
        q->rear = MAX - 1;
    } else {
        q->rear--;
    }
}

// Display Deque elements
void display(struct Deque* q) {
    if (isEmpty(q)) {
        printf("Deque is empty.\n");
        return;
    }
    printf("\n--- Current Deque ---\n");
    int i = q->front;
    while (1) {
        printf("%d ", q->items[i]);
        if (i == q->rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n---------------------\n");
}

int main() {
    struct Deque q;
    initialize(&q);
    int choice, value;

    while (1) {
        printf("\n=== Double-Ended Queue (Deque) Menu ===\n");
        printf("1. Insert at Front\n2. Insert at Rear\n3. Delete from Front\n4. Delete from Rear\n5. Display\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at front: ");
                scanf("%d", &value);
                insertFront(&q, value);
                break;
            case 2:
                printf("Enter value to insert at rear: ");
                scanf("%d", &value);
                insertRear(&q, value);
                break;
            case 3:
                deleteFront(&q);
                break;
            case 4:
                deleteRear(&q);
                break;
            case 5:
                display(&q);
                break;
            case 6:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}
