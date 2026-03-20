#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Create new node
struct node* createNode(int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

//////////////////////////////
// Level Order Traversal
//////////////////////////////

void levelOrder(struct node* root) {
    if(root == NULL)
        return;

    struct node* queue[10];   // simple queue
    int front = 0, rear = 0;

    queue[rear++] = root;

    while(front < rear) {
        struct node* temp = queue[front++];
        printf("%d ", temp->data);

        if(temp->left != NULL)
            queue[rear++] = temp->left;

        if(temp->right != NULL)
            queue[rear++] = temp->right;
    }
}

//////////////////////////////
// Count Leaf Nodes
//////////////////////////////

int countLeaf(struct node* root) {
    if(root == NULL){
        return 0;
    }
    if(root->left == NULL && root->right == NULL){
        return 1;
    }
    return countLeaf(root->left) + countLeaf(root->right);
}

//////////////////////////////
// Count Non-Leaf Nodes
//////////////////////////////

int countNonLeaf(struct node* root) {
    if(root == NULL)
        return 0;

    if(root->left == NULL && root->right == NULL)
        return 0;

    return 1 + countNonLeaf(root->left) + countNonLeaf(root->right);
}

//////////////////////////////
// Find Height
//////////////////////////////

int height(struct node* root) {
    if(root == NULL)
        return -1;   // height in terms of edges

    int left = height(root->left);
    int right = height(root->right);

    if(left > right)
        return left + 1;
    else
        return right + 1;
}

//////////////////////////////
// Mirror Tree
//////////////////////////////

void mirror(struct node* root) {
    if(root == NULL)
        return;

    struct node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    mirror(root->left);
    mirror(root->right);
}

//////////////////////////////

int main() {

    /*
          5
         / \
        3   6
       / \
      1   4
    */

    struct node* root = createNode(5);
    root->left = createNode(3);
    root->right = createNode(6);
    root->left->left = createNode(1);
    root->left->right = createNode(4);

    printf("Level Order Traversal: ");
    levelOrder(root);

    printf("\nLeaf Nodes: %d", countLeaf(root));
    printf("\nNon-Leaf Nodes: %d", countNonLeaf(root));
    printf("\nHeight of Tree: %d", height(root));

    printf("\n\nMirror Tree Level Order: ");
    mirror(root);
    levelOrder(root);

    return 0;
}