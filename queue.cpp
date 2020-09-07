#include <stdio.h>
#define size 5
struct queue
{
    int arr[size], front, rear;
};
void push(struct queue *q, int d)
{
    if (q->rear == q->front)
    {
        printf("size overflow\n");
        return;
    }
    if (q->front == -1)
        q->front = 0;
    q->arr[q->rear] = d;
    q->rear = (q->rear + 1) % size;
    return;
}
void pop(struct queue *q)
{
    if (q->front == -1)
    {
        printf("queue is empty\n");
        return;
    }
    q->front = (q->front + 1) % size;
    if (q->front == q->rear)
    {
        q->front = -1;
        q->rear = 0;
    }
}
void display(struct queue q)
{
    if (q.front == -1)
    {
        printf("queue is empty\n");
        return;
    }
    int i = q.front;
    while (i != q.rear)
    {
        printf("%d ", q.arr[i]);
        i = i + 1;
        i %= size;
    }
    printf("\n");
}
int main()
{
    struct queue q;
    int w, d;
    q.front = -1;
    q.rear = 0;
    for (int i = 0; i >= 0; ++i)
    {
        printf("insert 1\ndelete 2\nprint 3\nquit 4\n");
        scanf("%d", &w);
        if (w == 1)
        {
            printf("enter the number\n");
            scanf("%d", &d);
            push(&q, d);
        }
        else if (w == 2)
        {
            pop(&q);
            printf("Number deleted\n");
        }
        else if (w == 3)
        {
            printf("The queue is \n");
            display(q);
        }
        else
            break;
    }
}