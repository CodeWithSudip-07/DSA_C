#include <stdio.h>
#include <stdlib.h>

struct queue{
    int size;
    int front;
    int rear;
    int *arr;
};

int isFull(struct queue *q){
    if(q->rear == q->size-1){
        return 1;
    }
    else{
        return 0;
    }
}

int isEmpty(struct queue *q){
    if(q->rear == q->front){
        return 1;
    }
    else{
        return 0;
    }
}

void enQueue(struct queue* q, int val){
    if(isFull(q)){
        printf("Queue overflow!\n");
    }
    else{
        q->rear= q->rear+1; //q->rear++
        q->arr[q->rear]=val;
        printf("Enqued element: %d\n", val);
    }
}

int deQueue(struct queue *q){
    int x=-1;
    if(isEmpty(q)){
        printf("Queue underflow!\n");
    }
    else{
        q->front++;
        x = q->arr[q->front];
        
    }
    return x;
    
}

// void display(struct queue *q){
//     if(isEmpty(q)){
//         printf("no element in queue\n");
//     }
//     else{
//         int i=q->front+1;
//         while(i!=q->rear+1){
//             printf("%d ",q->arr[i]);
//             i++;
//         }
//         printf("\n");
//     }
// }
void display(struct queue *q){
    if(isEmpty(q)){
        printf("no element in queue\n");
    }
    else{
        int i;
        for(i=q->front+1;i<=q->rear;i++){
            printf("%d ",q->arr[i]);
        }
        
        printf("\n");
    }
}

int main(){
    struct queue *q=(struct queue*)malloc(sizeof(struct queue));
    q->size= 6;
    q->front = q->rear = -1;
    q->arr=(int*)malloc(q->size*sizeof(int));


    
    enQueue(q,4);
    enQueue(q,6);
    enQueue(q,7);
    enQueue(q,14);
    enQueue(q,16);
    enQueue(q,61);
    

    display(q);
    
    printf("deQueue Element: %d\n",deQueue(q));
    printf("deQueue Element: %d\n",deQueue(q));
    // printf("deQueue Element: %d\n",deQueue(q));
    // printf("deQueue Element: %d\n",deQueue(q));
    // enQueue(q,17);
    // enQueue(q,27);
    display(q);

    // if(isEmpty(q)){
    //     printf("queue is empty\n");
    // }
    // if(isFull(q)){
    //     printf("queue is full\n");
    // }

    return 0;
}