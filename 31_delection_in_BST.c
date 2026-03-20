#include <stdio.h>
#include <malloc.h>

struct node{
    int data;
    struct node * left;
    struct node* right;
};

struct node* createNode(int value){
    struct node* n;
    n=(struct node*)malloc(sizeof(struct node));
    n->data= value;
    n->left= NULL;
    n->right=NULL;
    return n;
}

void inOrder(struct node* root){
    if(root!=NULL){
        inOrder(root->left);
        printf("%d ",root->data);
        inOrder(root->right);
    }
    
}

struct node* inOrderpredessor(struct node* root){ //inOrderpredessor is the right most child in the left sub-tree.
    root=root->left;
    while(root->right!=NULL){
        root=root->right;
    }
    return root;
}

// struct node* delectNode(struct node* root,int key){
//     struct node* ipre;
//     if(root==NULL){
//         return NULL;
//     }
//     //when key found in leaf node
//     if(root->left==NULL && root->right==NULL){ 
//         free(root);
//         return NULL;
//     }
//     //search the node to be delected
//     if(key<root->data){
//         root->left= delectNode(root->left,key);
//     }
//     else if(key>root->data){
//         root->right= delectNode(root->right,key);
//     }
//     //delection streagy when the node is found (key==root->data)
//     else{
//         ipre=inOrderpredessor(root);
//         root->data= ipre->data;
//         root->left= delectNode(root->left,ipre->data); //delect the node of inOrderpredessor which is found on left subtree
//     }
//     return root;
// }
struct node* delectNode(struct node* root,int key){

    if(root==NULL){
        return NULL;
    }

    // Search for key
    if(key < root->data){
        root->left = delectNode(root->left,key);
    }
    else if(key > root->data){
        root->right = delectNode(root->right,key);
    }

    // Node found
    else{

        // Case 1: No child
        if(root->left==NULL && root->right==NULL){
            free(root);
            return NULL;
        }

        // Case 2: One child
        else if(root->left==NULL){
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL){
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        // Case 3: Two children
        else{
            struct node* ipre = inOrderpredessor(root);
            root->data = ipre->data;
            root->left = delectNode(root->left,ipre->data);
        }
    }

    return root;
}

int main(){
    // Finally The tree looks like this:
    //      5
    //     / \
    //    3   6
    //   / \
    //  1   4
    struct node *p=createNode(5);
    struct node *p1=createNode(3);
    struct node *p2=createNode(6);
    struct node *p3=createNode(1);
    struct node *p4=createNode(4);

    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;

    inOrder(p);
    printf("\n");
    delectNode(p,2);
    inOrder(p);

    return 0;
}