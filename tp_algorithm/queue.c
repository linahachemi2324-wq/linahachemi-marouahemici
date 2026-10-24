#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int customerNumber;
    struct node *next;
}node;

typedef struct queue
{
    node *front;
    node *rear;
}queue;

void initqueue(queue *q){
    q->front = NULL;
    q->rear = NULL;
}
int isEmpty(queue *q){
    return q->front == NULL;
}
void enqueue(queue *q, int customerNumber){
    node *temp = (node*)malloc(sizeof(node));
    temp->customerNumber = customerNumber;
    temp->next = NULL;
    if(isEmpty(q)){
        q->front = temp;
        q->rear = temp;
    } else {
        q->rear->next = temp;
        q->rear = temp;
    }
}
int dequeue(queue *q){
    if(isEmpty(q)){
        printf("Queue is empty\n");
        return -1;
    }
    node *temp = q->front;
    int customerNumber = temp->customerNumber;
    q->front = q->front->next;
    free(temp);
    return customerNumber;
}
int peek(queue *q){
    if(isEmpty(q)){
        printf("Queue is empty\n");
        return -1;
    }
    return q->front->customerNumber;
}
int main(){
    queue q;
    initqueue(&q);
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    printf("Front customer number: %d\n", peek(&q));
    printf("Dequeued customer number: %d\n", dequeue(&q));
    printf("Front customer number after dequeue: %d\n", peek(&q));
    return 0;
}