#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* head = NULL;

// Insert at end
void insert(int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

// Display list
void display() {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Reverse linked list
void reverse() {
    struct node *prev = NULL, *current = head, *next = NULL;

    while (current != NULL) {
        next = current->next;   // Store next node
        current->next = prev;   // Reverse link
        prev = current;         // Move prev forward
        current = next;         // Move current forward
    }

    head = prev;  // Update head
}

int main() {
    int n, value, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter values:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        insert(value);
    }

    printf("\nOriginal Linked List:\n");
    display();

    reverse();

    printf("Reversed Linked List:\n");
    display();

    return 0;
}