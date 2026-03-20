#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* LinkedListTraverse(struct node *ptr){
    while(ptr!= NULL){
        printf("element: %d\n",ptr->data);
        ptr= ptr->next;
    }
    printf("\n");
}

//case 1: delete the first element of the linked list 
struct node *deleteFirst(struct node *head){
    struct node *ptr=head;
    head= head->next;
    free(ptr);

    return head;
}

//case 2: delect the element in the index number of the linked list
struct node* deleteAtIndex(struct node* head,int index){
    struct node *p= head;
    struct node *q= head->next;
    for(int i=0; i<index-1;i++){
        p =p->next;
        q =q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}

//case 3: delect the last element of the linked list
struct node* deleteLast(struct node* head){
    struct node *p= head;
    struct node *q= head->next;
    while(q->next != NULL){
        p=p->next;
        q=q->next;
    }
    p->next=NULL;
    free(q);

    return head;
}

//case 4: delect the element with a given value in the linked list
struct node* deleteByValue(struct node* head,int value){
    struct node *p= head;
    struct node *q= head->next;
    while(q->data!=value && q->next!=NULL){
        p=p->next;
        q=q->next;
    }
    if(q->data == value){
        p->next=q->next;
        free(q);        
    }
    
    return head;
}

int main(){
    struct node *head=(struct node *)malloc(sizeof(struct node));
    struct node *second=(struct node *)malloc(sizeof(struct node));
    struct node *third=(struct node *)malloc(sizeof(struct node));
    struct node *forth=(struct node *)malloc(sizeof(struct node));

    head->data=5;
    head->next=second;

    second->data=6;
    second->next=third;

    third->data=8;
    third->next=forth;

    forth->data=4;
    forth->next=NULL;


    printf("LinkedList before delection....\n");
    LinkedListTraverse(head);

    //head= deleteFirst(head); //delect the first node in linked list
    head= deleteLast(head);
    head= deleteLast(head);
    head= deleteLast(head);
    head= deleteLast(head);
    // //head= deleteLast(head);
    // head= deleteByValue(head,8);
    printf("LinkedList after delection....\n");
    LinkedListTraverse(head);

    return 0;
}