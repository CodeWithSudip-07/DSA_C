#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
struct stack
{
    int size;
    int top;
    char *arr;
};
 
int stackTop(struct stack* sp){
    return sp->arr[sp->top];
}
 
int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
 
int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
 
void push(struct stack* ptr, char val){
    if(isFull(ptr)){
        printf("Stack Overflow! Cannot push %d to the stack\n", val);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}
 
char pop(struct stack* ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    }
    else{
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
int precedence(char ch){
    if(ch == '*' || ch=='/')
        return 3;
    else if(ch == '+' || ch=='-')
        return 2; 
    else
        return 0;
}
 
int isOperator(char ch){
    if(ch=='+' || ch=='-' ||ch=='*' || ch=='/') 
        return 1;
    else
        return 0;
}

// Reverse a string
void reverse(char* exp){
    int len = strlen(exp);
    for(int i=0; i<len/2; i++){
        char temp = exp[i];
        exp[i] = exp[len-i-1];
        exp[len-i-1] = temp;
    }
}

char* infixToPostfix(char* infix){
    struct stack * sp = (struct stack *) malloc(sizeof(struct stack));
    sp->size = 100; 
    sp->top = -1;
    sp->arr = (char *) malloc(sp->size * sizeof(char));
    char * postfix = (char *) malloc((strlen(infix)+1) * sizeof(char));
    int i=0; // Track infix traversal
    int j = 0; // Track postfix addition 

    // reverse(infix);
    
    // // Step 2: Change brackets if any
    // for(int i=0; i<infix[i]!='\0'; i++){
    //     if(infix[i]=='(')
    //         infix[i]=')';
    //     else if(infix[i]==')')
    //         infix[i]='(';
    // }

    while (infix[i]!='\0')
    {
        
        if(isalnum(infix[i])){
            postfix[j] = infix[i];
            j++;
            i++;
        }
        // If '(' → push to stack
        else if(infix[i] == '('){
            push(sp, infix[i++]);
        }

        // If ')' → pop until '('
        else if(infix[i] == ')'){
            while(!isEmpty(sp) && stackTop(sp) != '('){
                postfix[j] = pop(sp);
                j++;
            }
            pop(sp);  // remove '('
            i++;
        }
        else{
            if(precedence(infix[i])> precedence(stackTop(sp))){
                push(sp, infix[i]);
                i++;
            }
            else{
                postfix[j] = pop(sp);
                j++;
            }
        }

    }
    while (!isEmpty(sp))    
    {
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0';
    // reverse(postfix);
    return postfix;
}
int main()
{
    char  infix[] = "(x-y/z)*(k-d)";
    printf("postfix is %s:", infixToPostfix(infix));
    return 0;
}
