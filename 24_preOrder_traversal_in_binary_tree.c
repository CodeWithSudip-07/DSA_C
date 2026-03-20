#include <stdio.h>
#include <malloc.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createnode(int value){
    struct node *n; // creating a node pointer
    n = (struct node *) malloc(sizeof(struct node)); // Allocating memory in the heap
    n->data = value; // Setting the data
    n->left = NULL; // Setting the left and right children to NULL
    n->right = NULL; // Setting the left and right children to NULL
    return n; // Finally returning the created node
}

void preOrder(struct node* root){
    if(root!=NULL){
        printf("%d ",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void iterativePreOrder(struct node* root){
    if(root == NULL) return;
    struct node* stack[100];
    int top = -1;
    stack[++top] = root;
    while(top != -1){
        struct node* temp = stack[top--];
        printf("%d ", temp->data);
        if(temp->right != NULL)
            stack[++top] = temp->right;
        if(temp->left != NULL)
            stack[++top] = temp->left;
    }
}
void iterativeInOrder(struct node* root){
    struct node* stack[100];
    int top = -1;
    struct node* current = root;
    while(current != NULL || top != -1){
            while(current != NULL){
            stack[++top] = current;
            current = current->left;
        }
        current = stack[top--];
        printf("%d ", current->data);
        current = current->right;
    }
}
void iterativePostOrder(struct node* root){
    if(root == NULL) return;
    struct node* stack1[100];
    struct node* stack2[100];
    int top1 = -1, top2 = -1;
    stack1[++top1] = root;
    while(top1 != -1){
        struct node* temp = stack1[top1--];
        stack2[++top2] = temp;
        if(temp->left != NULL)
            stack1[++top1] = temp->left;
        if(temp->right != NULL)
            stack1[++top1] = temp->right;
    }
    while(top2 != -1){
        printf("%d ", stack2[top2--]->data);
    }
}

int main(){
    //construction the root node---using functions(recomanded)
    struct node* p =createnode(4);
    struct node* p1 =createnode(1);
    struct node* p2 =createnode(6);
    struct node* p3 =createnode(5);
    struct node* p4 =createnode(2);

    // Finally The tree looks like this:
    //      4
    //     / \
    //    1   6
    //   / \
    //  5   2  


    //likking the root node to the children
    p->left= p1;
    p->right= p2;
    p1->left= p3;
    p1->right= p4;

    iterativePostOrder(p);

    return 0;
}