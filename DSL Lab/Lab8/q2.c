//2. Write a C program to define a student structure with the data members to store name, roll no and grade of the student. Also write the
//required functions to read, display, and sort student information according to the roll number of the student. All the member functions
//will have array of objects as arguments.

#include <stdio.h>

#define MAX 5  // Small size for easy testing of circular behavior

struct CircularQueue {
    int items[MAX];
    int front, rear;
};

// Initialize the queue
void initialize(struct CircularQueue* q) {
    q->front = -1;
    q->rear = -1;
}

// Check if queue is empty
int isEmpty(struct CircularQueue* q) {
    return q->front == -1;
}

// Check if queue is full
int isFull(struct CircularQueue* q) {
    return (q->rear + 1) % MAX == q->front;
}

// Enqueue operation
void enqueue(struct CircularQueue* q, int value) {
    if (isFull(q)) {
        printf("Circular Queue is full!\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % MAX;
    q->items[q->rear] = value;
    printf("Enqueued: %d\n", value);
}

// Dequeue operation
int dequeue(struct CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Circular Queue is empty!\n");
        return -1;
    }
    int value = q->items[q->front];
    if (q->front == q->rear) {
        // Queue becomes empty after dequeuing the last element
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX;
    }
    return value;
}

// Peek operation
int peek(struct CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Circular Queue is empty!\n");
        return -1;
    }
    return q->items[q->front];
}

// Display elements in the circular queue
void display(struct CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Circular Queue is empty.\n");
        return;
    }
    printf("\n--- Current Circular Queue ---\n");
    int i = q->front;
    while (1) {
        printf("%d ", q->items[i]);
        if (i == q->rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n------------------------------\n");
}

// Main menu-driven function
int main() {
    struct CircularQueue q;
    initialize(&q);
    int choice, value;

    while (1) {
        printf("\n=== Circular Queue Menu ===\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;
            case 2:
                value = dequeue(&q);
                if (value != -1)
                    printf("Dequeued: %d\n", value);
                break;
            case 3:
                value = peek(&q);
                if (value != -1)
                    printf("Front of queue: %d\n", value);
                break;
            case 4:
                display(&q);
                break;
            case 5:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
