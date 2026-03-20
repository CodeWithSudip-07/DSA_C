#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void ClinkedlistTraversal(struct node* head){
    struct node* ptr= head;
    do{
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }while(ptr!=head);
    printf("\n");
}

//case 1: insertion at first
struct node* insertAtFirst(struct node* head,int value){
    struct node* ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data=value;
    struct node* q=head->next;
    while(q->next!=head){
        q= q->next;
    }
    // At this point q points to the last node of this circular linked list
    q->next=ptr;
    ptr->next=head;
    head=ptr;
    return head;

}

struct node* insertAtEnd(struct node* head,int val){
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=val;
    struct node* p=head->next;
    while(p->next!=head){
        p=p->next;
    }
    p->next=ptr;
    ptr->next=head;
    return head;

}

struct node* deleteAtFirst(struct node* head){
    struct node* p=head;
    struct node* q=head->next;
    while(q->next!=head){
        q=q->next;
    }
    head=head->next;
    q->next=head;
    free(p);
    return head;

}
struct node* deleteAtEnd(struct node* head){
    struct node* p=head;
    struct node* q=head->next;
    while(q->next!=head){
        p=p->next;
        q=q->next;
    }
    p->next=head;
    free(q);
    return head;

}

struct node* deleteByValue(struct node* head,int key){
    struct node* p=head;
    struct node* q=head->next;
    while(q->data!=key && q->next!=head){
        p=p->next;
        q=q->next;
    }
    if(q->data==key){
        p->next=q->next;
        free(q);
    }
    return head;

}
struct node* deleteInIndex(struct node* head,int index){
    struct node* p=head;
    struct node* q=head->next;
    for(int i=0;i<index-1;i++){
        p=p->next;
        q=q->next;
    }
    p->next=q->next;
    free(q);
    return head;

}


int main(){
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *fourth;

    head=(struct node *)malloc(sizeof(struct node));
    second=(struct node *)malloc(sizeof(struct node));
    third=(struct node *)malloc(sizeof(struct node));
    fourth=(struct node *)malloc(sizeof(struct node));

    head->data=4;
    head->next=second;

    second->data=3;
    second->next=third;

    third->data=6;
    third->next=fourth;

    fourth->data=1;
    fourth->next=head;

    ClinkedlistTraversal(head);
    head=insertAtFirst(head,40);
    head=insertAtFirst(head,41);
    head=insertAtFirst(head,42);
    ClinkedlistTraversal(head);


    return 0;
}