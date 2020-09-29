#include <stdio.h>
#include <stdlib.h>
#define MAX 50
void insert();
void delete ();
void display();
int queue_array[MAX];
int rear = -1;
int front = -1;
int main()
{
    int q;
    while (1)
    {
        printf("1 Inser \n");
        printf("2 delete \n");
        printf("3 display \n");
        printf("4 quit \n");
        printf("Enter your choice : \n");
        scanf("%d", &q);
        if (q == 1)
            insert();
        else if (q == 2)
            delete ();
        else if (q == 3)
            display();
        else
            break;
    };
    void insert()
    {
        int item;
        if (rear == MAX - 1)
            printf("size overflow \n");
        else
        {
            if (front == -1)
                front = 0;
            printf("inser element \n");
            scanf("%d", &item);
            rear = rear + 1;
            queue_array[rear] = item;
        }
    }
    void delete ()
    {
        if (front == -1 || front > rear)
        {
            printf("Queue Underflow n");
            return;
        }
        else
        {
            printf("Element deleted from queue is : %dn", queue_array[front]);
            front = front + 1;
        }
    }
    void display()
    {
        int i;
        if (front == -1)
            printf("Queue is empty n");
        else
        {
            printf("Queue is : n");
            for (i = front; i <= rear; i++)
                printf("%d ", queue_array[i]);
            printf("n");
        }
    }