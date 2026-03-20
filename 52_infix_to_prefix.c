#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
struct stack{
    int size;
    int top;
    char *arr;
};

int isEmpty(struct stack *ptr){
    if(ptr->top == -1){
        return 1;
    }
    else{
        return 0;
    }
}
int isFull(struct stack *ptr){
    if(ptr->top == ptr->size-1){
        return 1;
    }
    else{
        return 0;
    }
}

void push(struct stack *ptr, char value){
    if(isFull(ptr)){
        printf("Stack overflow! the value: %d is not inserted\n",value);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top]= value;
    }
}

char pop(struct stack *ptr){
    if(isEmpty(ptr)){
        printf("Stackunderflow! cannot pop any element\n");
        // return -1;
    }
    else{
        char val= ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

char stackTop(struct stack *sp){
    return sp->arr[sp->top];
}



int precedence(char ch){
    if(ch =='^'){
        return 3;
    }
    else if(ch=='*' || ch=='/'){
        return 2;
    }
    else if(ch=='+' || ch=='-'){
        return 1;
    }
    else{
        return 0;
    }   
}

void reverse(char *infix){
    int i,len;
    len=strlen(infix);
    char temp;
    for(i=0;i<len/2;i++){
        temp=infix[i];
        infix[i]=infix[len-i-1];
        infix[len-i-1]=temp;
    }
}

char* infixToprefix(char *infix){
    struct stack *sp=(struct stack*)malloc(sizeof(struct stack));
    sp->size=100;
    sp->top=-1;
    sp->arr=(char*)malloc(sp->size*sizeof(char));

    int len=strlen(infix);
    char *prefix=(char*)malloc((len+1)*sizeof(char));
    int k=0;

    reverse(infix);
    for(k=0;k<len;k++){
        if(infix[k]=='('){
            infix[k]=')';
        }
        else if(infix[k]==')'){
            infix[k]='(';
        }
    }

    int i=0;
    int j=0;
    while(infix[i]!='\0'){
        if(isalnum(infix[i])){
            prefix[j]=infix[i];
            i++;
            j++;
        }
        else if(infix[i]=='('){
            push(sp,infix[i]);
            i++;
        }
        else if(infix[i]==')'){
            while(!isEmpty(sp) && stackTop(sp)!='('){
                prefix[j]=pop(sp);
                j++;
            }
            pop(sp);
            i++;
        }
        else{
            if(precedence(infix[i])>precedence(stackTop(sp))){
                push(sp,infix[i]);
                i++;
            }
            else{
                prefix[j]=pop(sp);
                j++;
            }
        }
    }
    while(!isEmpty(sp)){
        prefix[j]=pop(sp);
        j++;
    }

    prefix[j]='\0';
    reverse(prefix);
    return prefix;

}

int main(){
    char infix[]="10+((7-5)+10)/2+5*3";

    printf("the prefix: %s\n",infixToprefix(infix));

    return 0;
}