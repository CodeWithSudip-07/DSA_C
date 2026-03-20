#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *prev;
    struct node *next;
};

// Traversal
void LinkedListTraversal(struct node* head){
    struct node* ptr = head;
    while(ptr != NULL){
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

// Case 1: Insert at First
struct node* insertAtFirst(struct node* head, int data){
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->prev = NULL;
    ptr->next = head;

    if(head != NULL)
        head->prev = ptr;

    return ptr;
}

// Case 2: Insert at End
struct node* insertAtEnd(struct node* head, int data){
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    struct node* p = head;

    ptr->data = data;
    ptr->next = NULL;

    if(head == NULL){
        ptr->prev = NULL;
        return ptr;
    }

    while(p->next != NULL){
        p = p->next;
    }

    p->next = ptr;
    ptr->prev = p;

    return head;
}

// Case 3: Insert After Node
struct node* insertAfterNode(struct node* head, struct node* prenode, int data){
    struct node* ptr = (struct node*)malloc(sizeof(struct node));

    ptr->data = data;
    ptr->next = prenode->next;
    ptr->prev = prenode;

    if(prenode->next != NULL)
        prenode->next->prev = ptr;

    prenode->next = ptr;

    return head;
}

// Delete First Node
struct node* deleteFirst(struct node* head){
    if(head == NULL)
        return NULL;

    struct node* ptr = head;
    head = head->next;

    if(head != NULL)
        head->prev = NULL;

    free(ptr);
    return head;
}

// Delete Last Node
struct node* deleteLast(struct node* head){
    if(head == NULL)
        return NULL;

    struct node* p = head;

    while(p->next != NULL){
        p = p->next;
    }

    if(p->prev != NULL)
        p->prev->next = NULL;
    else
        head = NULL;

    free(p);
    return head;
}

// Delete By Value
struct node* deleteByValue(struct node* head, int value){
    struct node* p = head;

    while(p != NULL && p->data != value){
        p = p->next;
    }

    if(p == NULL){
        printf("Value not found\n");
        return head;
    }

    if(p->prev != NULL)
        p->prev->next = p->next;
    else
        head = p->next;

    if(p->next != NULL)
        p->next->prev = p->prev;

    free(p);
    return head;
}

// Search
void search(struct node* head, int key){
    struct node* p = head;
    int pos = 1;

    while(p != NULL){
        if(p->data == key){
            printf("Element %d found at position %d\n\n", key, pos);
            return;
        }
        p = p->next;
        pos++;
    }
    printf("Element not found\n\n");
}

// Reverse Doubly Linked List
struct node* reverse(struct node* head){
    struct node* temp = NULL;
    struct node* current = head;

    while(current != NULL){
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if(temp != NULL)
        head = temp->prev;

    return head;
}

// struct node* reverse(struct node* head){
//     struct node *current=head, *pre=NULL;
//     while(current!=NULL){
//         current->prev=current->next;
//         current->next=pre;
//         pre=current;
//         current=current->prev;
//     }
//     head=pre;
//     return head;
// }
int main(){

    struct node *head = NULL;

    // Creating list
    head = insertAtFirst(head, 45);
    head = insertAtEnd(head, 5);
    head = insertAtEnd(head, 4545);
    head = insertAtEnd(head, 405);

    printf("Original List:\n");
    LinkedListTraversal(head);

    // Insert after second node
    head = insertAfterNode(head, head->next, 500);

    printf("After Insertion:\n");
    LinkedListTraversal(head);

    // Search
    search(head, 4545);

    // Delete
    // head = deleteFirst(head);
    // head = deleteLast(head);
    head = deleteByValue(head, 500);

    printf("After Deletion:\n");
    LinkedListTraversal(head);

    // Reverse
    head = reverse(head);

    printf("After Reversing:\n");
    LinkedListTraversal(head);

    return 0;
}