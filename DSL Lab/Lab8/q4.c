//4. Create a queue of structures (e.g., queue of patients with name, age, and priority).

#include <stdio.h>
#include <string.h>

#define MAX 100

struct Patient {
    char name[30];
    int age;
    int priority;
};

struct PatientQueue {
    struct Patient items[MAX];
    int front, rear;
};

void initialize(struct PatientQueue* q) {
    q->front = -1;
    q->rear = -1;
}

int isEmpty(struct PatientQueue* q) {
    return q->front == -1;
}

int isFull(struct PatientQueue* q) {
    return q->rear == MAX - 1;
}

void enqueue(struct PatientQueue* q, char* name, int age, int priority) {
    if (isFull(q)) {
        printf("Patient Queue is full.\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear++;
    snprintf(q->items[q->rear].name, sizeof(q->items[q->rear].name), "%s", name);
    q->items[q->rear].age = age;
    q->items[q->rear].priority = priority;
    printf("Patient Enqueued: %s (Age: %d, Priority: %d)\n", name, age, priority);
}

void dequeue(struct PatientQueue* q) {
    if (isEmpty(q)) {
        printf("Patient Queue is empty.\n");
        return;
    }
    printf("\n--> Processing Patient:\n");
    printf("Name: %s | Age: %d | Priority: %d\n",
           q->items[q->front].name,
           q->items[q->front].age,
           q->items[q->front].priority);

    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
}

void display(struct PatientQueue* q) {
    if (isEmpty(q)) {
        printf("Patient Queue is empty.\n");
        return;
    }
    printf("\n--- Current Patient Queue ---\n");
    for (int i = q->front; i <= q->rear; i++) {
        printf("[%d] Name: %s | Age: %d | Priority: %d\n",
               i - q->front + 1,
               q->items[i].name,
               q->items[i].age,
               q->items[i].priority);
    }
    printf("-----------------------------\n");
}

int main() {
    struct PatientQueue q;
    initialize(&q);
    int choice, age, priority;
    char name[30];

    while (1) {
        printf("\n=== Patient Queue Menu ===\n");
        printf("1. Register Patient (Enqueue)\n2. Call Next Patient (Dequeue)\n3. Display Waiting List\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Patient Name: ");
                scanf(" %[^\n]", name);
                printf("Enter Patient Age: ");
                scanf("%d", &age);
                printf("Enter Priority (1-High, 2-Medium, 3-Low): ");
                scanf("%d", &priority);
                enqueue(&q, name, age, priority);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                display(&q);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}
