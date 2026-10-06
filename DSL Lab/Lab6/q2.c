//2. Add Two Polynomials Represented as Doubly Linked Lists
//i) Represent each polynomial using a doubly linked list, where each node contains the coefficient and exponent of a term.
//ii) Write a function to add two polynomials by merging terms with equal exponents. The resulting polynomial should be stored in a new doubly linked list, maintaining the order of terms in descending powers of exponents.
//iii) Display all three polynomials: the two input polynomials and their sum.
//Ensure dynamic memory allocation is used for all node operations and that both prev and next pointers are maintained correctly.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int coefficient;
    int exponent;
    struct Node *prev;
    struct Node *next;
} Node;

Node *createNode(int coefficient, int exponent) {
    Node *node = malloc(sizeof(Node));
    if (!node) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    node->coefficient = coefficient;
    node->exponent = exponent;
    node->prev = node->next = NULL;
    return node;
}

void appendTerm(Node **head, Node **tail, int coefficient, int exponent) {
    if (coefficient == 0)
        return;

    Node *node = createNode(coefficient, exponent);
    if (*tail) {
        (*tail)->next = node;
        node->prev = *tail;
    } else {
        *head = node;
    }
    *tail = node;
}

void readPolynomial(Node **head, Node **tail) {
    int terms, coefficient, exponent;

    printf("Number of terms: ");
    scanf("%d", &terms);

    for (int i = 0; i < terms; i++) {
        printf("Enter coefficient and exponent: ");
        scanf("%d%d", &coefficient, &exponent);
        appendTerm(head, tail, coefficient, exponent);
    }
}

Node *addPolynomials(Node *a, Node *b) {
    Node *sum = NULL, *tail = NULL;

    while (a && b) {
        if (a->exponent > b->exponent) {
            appendTerm(&sum, &tail, a->coefficient, a->exponent);
            a = a->next;
        } else if (b->exponent > a->exponent) {
            appendTerm(&sum, &tail, b->coefficient, b->exponent);
            b = b->next;
        } else {
            appendTerm(&sum, &tail, a->coefficient + b->coefficient,
                       a->exponent);
            a = a->next;
            b = b->next;
        }
    }

    while (a) {
        appendTerm(&sum, &tail, a->coefficient, a->exponent);
        a = a->next;
    }
    while (b) {
        appendTerm(&sum, &tail, b->coefficient, b->exponent);
        b = b->next;
    }

    return sum;
}

void displayPolynomial(Node *head) {
    if (!head) {
        printf("0\n");
        return;
    }

    for (Node *p = head; p; p = p->next) {
        if (p != head && p->coefficient > 0)
            printf("+");
        printf("%dx^%d", p->coefficient, p->exponent);
        if (p->next)
            printf(" ");
    }
    printf("\n");
}

void freePolynomial(Node *head) {
    while (head) {
        Node *next = head->next;
        free(head);
        head = next;
    }
}

int main(void) {
    Node *poly1 = NULL, *tail1 = NULL;
    Node *poly2 = NULL, *tail2 = NULL;

    printf("Enter first polynomial in descending exponent order:\n");
    readPolynomial(&poly1, &tail1);

    printf("Enter second polynomial in descending exponent order:\n");
    readPolynomial(&poly2, &tail2);

    Node *sum = addPolynomials(poly1, poly2);

    printf("\nFirst polynomial:  ");
    displayPolynomial(poly1);
    printf("Second polynomial: ");
    displayPolynomial(poly2);
    printf("Sum:               ");
    displayPolynomial(sum);

    freePolynomial(poly1);
    freePolynomial(poly2);
    freePolynomial(sum);
    return 0;
}
