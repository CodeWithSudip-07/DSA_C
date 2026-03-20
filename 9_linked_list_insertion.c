#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

void LinkedListTraversal(struct node* ptr){
    while(ptr!=NULL){
        printf("Element: %d\n",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}

//case 1
struct node* insertAtFirst(struct node* head, int data){
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    ptr->next=head;
    ptr->data=data;
    return ptr;
}

//case 2
struct node *insertInIndex(struct node* head, int data, int index){
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    struct node* p= head;
    int i=0;
    while(i!= index-1){
        p= p->next;
        i++;
    }
    ptr->data =data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

//case 3
struct node* insertAfterNode(struct node* head, struct node* prenode,int data){
    struct node* ptr=(struct node *)malloc(sizeof(struct node));
    struct node *p=prenode;

    ptr->data= data;
    ptr->next = p->next;
    p->next = ptr;

    return head;

}

//case 4
struct node *insertInEnd(struct node* head,int data){
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    struct node *p =head;

    while(p->next != NULL){
        p= p->next;
        
    }
    ptr->data=data;
    ptr->next=NULL;
    p->next= ptr;

    return head;

}

int main(){
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *fourth;

    head=(struct node*)malloc(sizeof(struct node));
    second=(struct node*)malloc(sizeof(struct node));
    third=(struct node*)malloc(sizeof(struct node));
    fourth=(struct node*)malloc(sizeof(struct node));

    head->data=45;
    head->next=second;

    second->data=5;
    second->next=third;

    third->data=4545;
    third->next=fourth;

    fourth->data=405;
    fourth->next=NULL;
    

    LinkedListTraversal(head);
    //head=insertAtFirst(head,777); //insert at first in likked list
    head=insertInIndex(head,85,0); //insert at between in likked list
    // //head=insertInEnd(head,85); // insert at last in likked list
    // head=insertAfterNode(head,third,500); //insert after a given node
    LinkedListTraversal(head);

    return 0;
}