#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node *root = NULL;


struct node* createNode(int value) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


struct node* insert(struct node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    } else {
        printf("Duplicate value not allowed!\n");
    }

    return root;
}

void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

/* Postorder Traversal */
void postorder(struct node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

/* Search a value in BST */
int search(struct node* root, int key) {
    if (root == NULL)
        return 0;

    if (root->data == key)
        return 1;

    if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}


int countNodes(struct node* root) {
    if (root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}


int height(struct node* root) {
    if (root == NULL)
        return 0;

    int leftH = height(root->left);
    int rightH = height(root->right);

    return (leftH > rightH ? leftH : rightH) + 1;
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- Binary Search Tree Menu ---\n");
        printf("1. Insert Node\n");
        printf("2. Preorder Traversal\n");
        printf("3. Inorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Search Value\n");
        printf("6. Count Nodes\n");
        printf("7. Height of Tree\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            root = insert(root, value);
            break;

        case 2:
            printf("Preorder: ");
            preorder(root);
            printf("\n");
            break;

        case 3:
            printf("Inorder: ");
            inorder(root);
            printf("\n");
            break;

        case 4:
            printf("Postorder: ");
            postorder(root);
            printf("\n");
            break;

        case 5:
            printf("Enter value to search: ");
            scanf("%d", &value);
            if (search(root, value))
                printf("%d found in tree.\n", value);
            else
                printf("%d NOT found in tree.\n", value);
            break;

        case 6:
            printf("Total nodes = %d\n", countNodes(root));
            break;

        case 7:
            printf("Height of tree = %d\n", height(root));
            break;

        case 8:
            printf("Exiting...\n");
            exit(0);

        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}

