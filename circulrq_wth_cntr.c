#include<stdio.h>
#include<stdlib.h>
#define max 5

typedef struct Circular_Queue{
    int front;
    int rear;
    int count;
    int queue[max];
}CQ;

void Insert(CQ *q, int value){
    if(q->count == max)
    return;
    q->rear = (q->rear+1)%max;
    q->queue[q->rear] = value;
    q->count ++;
}

int Delete(CQ *q){
    if(q->count==0)
    return -99;
    q->front = (q->front+1)%max;
    int temp = q->queue[q->front];
    q->count--;
    return temp;
}
void Display(CQ q)
{
    int i;
    if(q.count==0)
    {
        printf("Queue Underflow!\n\n");
        return;
    }
    else if((q.front+1)>q.rear)
    {
    for(i=q.front+1;i<max;i++)
    printf("%d, ",q.queue[i]);
    for(i=0;i<=q.rear;i++)
    printf("%d, ",q.queue[i]);
    }
    else
    {
        for(i=q.front+1;i<=q.rear;i++)
        printf("%d, ",q.queue[i]);
    }
    printf("\n\n");
}
void main()
{
    CQ q;
    q.front = q.rear = q.count = 0;
    int ch,value;
    while(1)
    {
        printf("Choose one option\n");
        printf("1 for Insertion\n");
        printf("2 for Deletion\n");
        printf("3 for Display\n");
        printf("\n");
        printf("Enter your choice\n");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
            printf("Enter the value you want to Insert\n");
            scanf("%d",&value);
            Insert(&q,value);
            break;
            case 2:
            Delete(&q);
            break;
            case 3:
            Display(q);
            break;
        }
    }
}
