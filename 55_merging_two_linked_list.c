#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

// Display Linked List
void display(struct node *ptr){
    while(ptr != NULL){
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

// Insert at End
struct node* insertEnd(struct node* head, int data){
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = NULL;

    if(head == NULL){
        return ptr;
    }

    struct node* p = head;
    while(p->next != NULL){
        p = p->next;
    }

    p->next = ptr;
    return head;
}

// Merge Two Lists
struct node* mergeList(struct node* head1, struct node* head2){
    
    if(head1 == NULL)
        return head2;

    struct node* p = head1;

    while(p->next != NULL){
        p = p->next;
    }

    p->next = head2;

    return head1;
}

int main(){

    struct node *head1 = NULL;
    struct node *head2 = NULL;
    struct node *merged = NULL;

    int n1,n2,x;

    printf("Enter number of nodes in List 1: ");
    scanf("%d",&n1);

    for(int i=0;i<n1;i++){
        printf("Enter element: ");
        scanf("%d",&x);
        head1 = insertEnd(head1,x);
    }

    printf("Enter number of nodes in List 2: ");
    scanf("%d",&n2);

    for(int i=0;i<n2;i++){
        printf("Enter element: ");
        scanf("%d",&x);
        head2 = insertEnd(head2,x);
    }

    printf("\nList 1:\n");
    display(head1);

    printf("\nList 2:\n");
    display(head2);

    merged = mergeList(head1, head2);

    printf("\nMerged List:\n");
    display(merged);

    return 0;
}