#include <stdio.h>
#include <stdlib.h>




struct node{
    int data;
    struct node *next;
};
void linkedListTraversal(struct node *ptr){

    while(ptr!= NULL){
        printf("Element: %d\n",ptr->data);
        ptr = ptr->next;
    }


}
int main(){
    struct node *head;
    struct node *second;
    struct node *third;

    //Allocate memory for nodes in the linked list in heap
    head= (struct node *)malloc(sizeof(struct node));
    second= (struct node *)malloc(sizeof(struct node));
    third= (struct node *)malloc(sizeof(struct node));

    //linked fisrt and second node
    head->data =5;
    head->next = second;
    //linked second and third node
    second->data =56;
    second->next = third;
    //terminal the list at third node
    third->data =415;
    third->next = NULL;


    linkedListTraversal(head);
    return 0;
}