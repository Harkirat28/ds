#include <stdio.h>
#include <stdlib.h>

// Structure for a node
struct node {
    int data;
    struct node *left, *right;
};

// Function to create a new node
struct node* createNode(int value) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->left = newnode->right = NULL;
    return newnode;
}

// Insert a node in BST
struct node* insert(struct node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    else
        printf("Duplicate value %d not inserted!\n", value);

    return root;
}

// Search for a key in BST
struct node* search(struct node* root, int key) {
    if (root == NULL || root->data == key)
        return root;

    if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

// Find the node with the smallest value (used for deletion)
struct node* findMin(struct node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

// Delete a node from BST
struct node* deleteNode(struct node* root, int key) {
    if (root == NULL)
        return root;

    // Search for the node
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        // Found the node to be deleted

        // Case 1 & 2: Node with 0 or 1 child
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        // Case 3: Node with 2 children
        struct node* temp = findMin(root->right);
        root->data = temp->data;  // copy inorder successor
        root->right = deleteNode(root->right, temp->data); // delete duplicate
    }
    return root;
}

// Inorder Traversal (Left, Root, Right)
void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Preorder Traversal (Root, Left, Right)
void preorder(struct node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Postorder Traversal (Left, Right, Root)
void postorder(struct node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// Main function
int main() {
    struct node* root = NULL;
    int n, value, key, choice;

    printf("How many nodes do you want to insert initially? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);
        root = insert(root, value);
    }

    while (1) {
        printf("\n\n===== BST OPERATIONS =====\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Traversals\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;

            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                break;

            case 3:
                printf("Enter value to search: ");
                scanf("%d", &key);
                if (search(root, key))
                    printf("✅ %d found in BST.\n", key);
                else
                    printf("❌ %d not found in BST.\n", key);
                break;

            case 4:
                printf("\nInorder   : ");
                inorder(root);
                printf("\nPreorder  : ");
                preorder(root);
                printf("\nPostorder : ");
                postorder(root);
                printf("\n");
                break;

            case 5:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
int main(){
    struct node*root;
    root=NULL;
    root=insert(root,45);
    root=insert(root,56);
    root=insert(root,67);
    root=insert (root,87);
      root=insert(root,16);
      root=insert(root,76);
          root=insert(root,16);
            root=insert(root,26);
              root=insert(root,36);
                root=insert(root,46);
 printf("enter the inorder trversal \n");
 inorder(root);
 printf("searching  the keys \n");
 if( search(root,46))
     printf("hence found\n");
 
 else
     printf("not found\n");
root=deletenode(root,26);
 
 printf("inorder tranersal \n");
 inorder(root);
 return 0;
}



