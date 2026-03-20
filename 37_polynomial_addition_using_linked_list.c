#include <stdio.h>
#include <stdlib.h>

struct node {
    int coeff;
    int exp;
    struct node* next;
};

// Function to create new node
struct node* createNode(int c, int e) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->coeff = c;
    temp->exp = e;
    temp->next = NULL;
    return temp;
}

// Function to insert in descending order of exponent
//polynomial addition
struct node* insert(struct node* head, int c, int e) {
    struct node* temp = createNode(c, e);
    struct node* p;

    if (head == NULL || head->exp < e) {
        temp->next = head;
        head = temp;
    } else {
        p = head;
        while (p->next != NULL && p->next->exp > e) {
            p = p->next;
        }
        temp->next = p->next;
        p->next = temp;
    }
    return head;
}

// Function to display polynomial
void display(struct node* head) {
    while (head != NULL) {
        printf("%dx^%d", head->coeff, head->exp);
        head = head->next;
        if (head != NULL)
            printf(" + ");
    }
    printf("\n");
}

// Function to add two polynomials
struct node* addPolynomials(struct node* poly1, struct node* poly2) {
    struct node* result = NULL;

    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->exp == poly2->exp) {
            result = insert(result, poly1->coeff + poly2->coeff, poly1->exp);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        else if (poly1->exp > poly2->exp) {
            result = insert(result, poly1->coeff, poly1->exp);
            poly1 = poly1->next;
        }
        else {
            result = insert(result, poly2->coeff, poly2->exp);
            poly2 = poly2->next;
        }
    }

    while (poly1 != NULL) {
        result = insert(result, poly1->coeff, poly1->exp);
        poly1 = poly1->next;
    }

    while (poly2 != NULL) {
        result = insert(result, poly2->coeff, poly2->exp);
        poly2 = poly2->next;
    }

    return result;
}

// Main function
int main() {
    struct node *poly1 = NULL, *poly2 = NULL, *result = NULL;
    int n, i, coeff, exp;

    printf("Enter number of terms in first polynomial: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter coefficient and exponent: ");
        scanf("%d%d", &coeff, &exp);
        poly1 = insert(poly1, coeff, exp);
    }

    printf("Enter number of terms in second polynomial: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter coefficient and exponent: ");
        scanf("%d%d", &coeff, &exp);
        poly2 = insert(poly2, coeff, exp);
    }

    printf("\nFirst Polynomial: ");
    display(poly1);

    printf("Second Polynomial: ");
    display(poly2);

    result = addPolynomials(poly1, poly2);

    printf("Resultant Polynomial after Addition: ");
    display(result);

    return 0;
}