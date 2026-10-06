//1. Write user-defined functions to perform the following operations on binary trees:
//i) Inorder traversal (Iterative) 
//ii) Postorder traversal (Iterative) 
//iii) Preorder traversal (Iterative) 
//iv) Print the parent of a given element 
//v) Print the depth (or height) of the tree 
//vi) Print the ancestors of a given element 
//vii) Count the number of leaf nodes in a binary tree

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *createNode(int data) {
    Node *node = malloc(sizeof(*node));
    if (!node) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

/* Iterative preorder: root, left, right */
void preorder(Node *root) {
    if (!root) {
        printf("(empty)\n");
        return;
    }

    Node **stack = malloc(sizeof(*stack) * 1000);
    if (!stack) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    int top = 0;
    stack[top++] = root;

    while (top > 0) {
        Node *current = stack[--top];
        printf("%d ", current->data);

        if (current->right) stack[top++] = current->right;
        if (current->left)  stack[top++] = current->left;
    }
    printf("\n");
    free(stack);
}

/* Iterative inorder: left, root, right */
void inorder(Node *root) {
    Node **stack = malloc(sizeof(*stack) * 1000);
    if (!stack) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    int top = 0;
    Node *current = root;

    while (current || top > 0) {
        while (current) {
            stack[top++] = current;
            current = current->left;
        }

        current = stack[--top];
        printf("%d ", current->data);
        current = current->right;
    }

    if (!root) printf("(empty)");
    printf("\n");
    free(stack);
}

/* Iterative postorder using two stacks */
void postorder(Node *root) {
    if (!root) {
        printf("(empty)\n");
        return;
    }

    Node **stack1 = malloc(sizeof(*stack1) * 1000);
    Node **stack2 = malloc(sizeof(*stack2) * 1000);
    if (!stack1 || !stack2) {
        perror("malloc");
        free(stack1);
        free(stack2);
        exit(EXIT_FAILURE);
    }

    int top1 = 0, top2 = 0;
    stack1[top1++] = root;

    while (top1 > 0) {
        Node *current = stack1[--top1];
        stack2[top2++] = current;

        if (current->left)  stack1[top1++] = current->left;
        if (current->right) stack1[top1++] = current->right;
    }

    while (top2 > 0)
        printf("%d ", stack2[--top2]->data);

    printf("\n");
    free(stack1);
    free(stack2);
}

/* Returns the parent of target, or NULL if target is root/not found. */
Node *findParent(Node *root, int target) {
    if (!root || root->data == target)
        return NULL;

    Node **stack = malloc(sizeof(*stack) * 1000);
    if (!stack) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    int top = 0;
    stack[top++] = root;

    while (top > 0) {
        Node *current = stack[--top];

        if ((current->left && current->left->data == target) ||
            (current->right && current->right->data == target)) {
            free(stack);
            return current;
        }

        if (current->right) stack[top++] = current->right;
        if (current->left)  stack[top++] = current->left;
    }

    free(stack);
    return NULL;
}

/* Height measured in nodes: empty tree = 0, leaf = 1. */
int treeHeight(Node *root) {
    if (!root) return 0;

    int leftHeight = treeHeight(root->left);
    int rightHeight = treeHeight(root->right);
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

/* Prints ancestors from root to the target's parent. */
int printAncestors(Node *root, int target) {
    if (!root) return 0;

    if (root->data == target)
        return 1;

    if (printAncestors(root->left, target) ||
        printAncestors(root->right, target)) {
        printf("%d ", root->data);
        return 1;
    }

    return 0;
}

int countLeaves(Node *root) {
    if (!root) return 0;
    if (!root->left && !root->right) return 1;
    return countLeaves(root->left) + countLeaves(root->right);
}

int main(void) {
    Node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->right = createNode(6);

    printf("Inorder:   ");
    inorder(root);
    printf("Preorder:  ");
    preorder(root);
    printf("Postorder: ");
    postorder(root);

    int target = 5;
    Node *parent = findParent(root, target);
    if (parent)
        printf("Parent of %d: %d\n", target, parent->data);
    else
        printf("Parent of %d: not found (or element is the root)\n", target);

    printf("Tree height (in nodes): %d\n", treeHeight(root));

    printf("Ancestors of %d: ", target);
    if (printAncestors(root, target))
        printf("\n");
    else
        printf("not found\n");

    printf("Leaf count: %d\n", countLeaves(root));
    return 0;
}
