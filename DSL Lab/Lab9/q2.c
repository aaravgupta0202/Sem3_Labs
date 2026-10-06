//2. Write a recursive function to:
//i) Create a binary tree 
//ii) Print the binary tree (in traversal order, typically level-order)

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *createTree(void) {
    int value;

    printf("Enter value (-1 for no node): ");
    if (scanf("%d", &value) != 1)
        return NULL;

    if (value == -1)
        return NULL;

    Node *node = malloc(sizeof(*node));
    if (!node) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    node->data = value;
    printf("Enter left child of %d:\n", value);
    node->left = createTree();

    printf("Enter right child of %d:\n", value);
    node->right = createTree();

    return node;
}

/* Recursive helper: print nodes at a specified depth. */
void printLevel(Node *root, int level) {
    if (!root)
        return;

    if (level == 0) {
        printf("%d ", root->data);
        return;
    }

    printLevel(root->left, level - 1);
    printLevel(root->right, level - 1);
}

/* Recursive level-order traversal. */
void printLevelOrder(Node *root) {
    if (!root) {
        printf("(empty)\n");
        return;
    }

    /* Compute height recursively. */
    int height = 0;
    Node *nodes[1000];
    int front = 0, rear = 0;
    nodes[rear++] = root;

    while (front < rear) {
        int levelSize = rear - front;
        height++;
        while (levelSize-- > 0) {
            Node *node = nodes[front++];
            if (node->left)  nodes[rear++] = node->left;
            if (node->right) nodes[rear++] = node->right;
        }
    }

    for (int level = 0; level < height; level++)
        printLevel(root, level);

    printf("\n");
}

int main(void) {
    printf("Create the tree in preorder. Use -1 for a missing node.\n");
    Node *root = createTree();

    printf("Level-order traversal: ");
    printLevelOrder(root);
    return 0;
}
