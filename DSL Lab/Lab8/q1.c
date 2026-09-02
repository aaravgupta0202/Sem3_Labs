//1. Write a C program to simulate a printer queue where tasks arrive randomly and are processed in order.
//i. Tasks (with a document ID and name) arrive at random (simulate using random function or user input).
//ii. Enqueue each print job.
//iii. Dequeue in FIFO order to simulate printing

#include <stdio.h>
#include <string.h>
#define MAX 100

struct PrintJob
{
    int docId;
    char docName[30];
};

struct PrinterQueue
{
    struct PrintJob items[MAX];
    int front, rear;
};

void initQueue(struct PrinterQueue* q)
{
    q->front = -1;
    q->rear = -1;
}

int isEmpty(struct PrinterQueue* q)
{
    return q->front == -1;
}

int isFull(struct PrinterQueue* q)
{
    return (q->rear + 1) % MAX == q->front;
}

void enqueue(struct PrinterQueue* q, int id, char* name)
{
    if (isFull(q))
     {
        printf("Printer Queue is full! Cannot add more jobs.\n");
        return;
    }
    if (isEmpty(q))
    {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % MAX;
    q->items[q->rear].docId = id;
    snprintf(q->items[q->rear].docName, sizeof(q->items[q->rear].docName), "%s", name);
    printf("Print Job Added Successfully: [%d] %s\n", id, name);
}

void dequeue(struct PrinterQueue* q)
{
    if (isEmpty(q))
    {
        printf("No print jobs pending. Printer is idle.\n");
        return;
    }
    printf("Printing Job: [%d] %s\n", q->items[q->front].docId, q->items[q->front].docName);

    if (q->front == q->rear)
    {
        q->front = q->rear = -1;
    }
    else
    {
        q->front = (q->front + 1) % MAX;
    }
}

void display(struct PrinterQueue* q)
{
    if (isEmpty(q))
    {
        printf("Printer Queue is empty.\n");
        return;
    }
    printf("\nCurrent Printer Queue\n");
    int i = q->front;
    while (1)
    {
        printf("ID: %d | Document Name: %s\n", q->items[i].docId, q->items[i].docName);
        if (i == q->rear) break;
        i = (i + 1) % MAX;
    }
    printf("-----------------------------\n");
}

int main()
{
    struct PrinterQueue q;
    initQueue(&q);
    int choice, id;
    char name[30];
    printf("\nPrinter Queue Menu\n");
    printf("1. Add Print Job\n");
    printf("2. Process Print Job\n");
    printf("3. Display Pending Jobs\n");
    printf("4. Exit\n");
    while (1)
     {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter Document ID: ");
                scanf("%d", &id);
                printf("Enter Document Name: ");
                scanf(" %[^\n]", name);
                enqueue(&q, id, name);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                display(&q);
                break;
            case 4:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
