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

void postOrder(struct node* root){
    if(root!=NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ",root->data);
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

    postOrder(p);

    return 0;
}