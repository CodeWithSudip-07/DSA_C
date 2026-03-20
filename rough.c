#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

void LinkedListTraversal(struct node* ptr){
    while(ptr!=NULL){
        printf("%d ",ptr->data);
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

struct node* reverse(struct node *head){
    struct node *prev=NULL, *current=head, *next=NULL;

    while(current!=NULL){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    head=prev;
    return head;
}

int main(){
    struct node *head=NULL;
    head=insertAtFirst(head,56);
    head=insertAtFirst(head,16);
    head=insertAtFirst(head,26);
    head=insertAtFirst(head,36);
    head=insertAtFirst(head,46);
    LinkedListTraversal(head);
    head=reverse(head);
    LinkedListTraversal(head);
    

    return 0;
}