#include <iostream>
#include <stdio.h>
#include <limits.h>
using namespace std;

struct node
{
    int num;
    struct node *next;
};

void display(struct node *head)
{
    if (head == NULL)
    {
        printf("underfflow empty\n");
        return;
    }
    struct node *q = head;
    printf("list is :  ");
    while (q->next != NULL)
    {
        printf("%d-> ", q->num);
        q = q->next;
    }
    printf("%d\n", q->num);
    return;
}

struct node *Insert(struct node *s, int num)
{
    struct node *q = (struct node *)malloc(sizeof(struct node));
    q->num = num;
    q->next = NULL;
    if (s == NULL)
    {
        s = q;
    }
    else
    {
        struct node *p = s;
        struct node *prev = NULL;
        while (p != NULL && p->num < num)
        {
            prev = p;
            p = p->next;
        }
        if (p == s)
        {
            q->next = s;
            s = q;
        }
        else
        {
            prev->next = q;
            q->next = p;
        }
    }
    return s;
}

struct node *Delete(struct node *s, int num)
{
    if (s == NULL)
    {
        printf("underflow\n\n");
    }
    else
    {
        struct node *q = s;
        struct node *p = NULL;
        while (q != NULL && q->num != num)
        {
            p = q;
            q = q->next;
        }
        if (q == NULL)
        {
            printf("number does not exists\n");
        }
        else
        {
            if (q == s)
            {
                s = s->next;
            }
            else
            {
                p->next = q->next;
            }
            free(q);
        }
    }
    return s;
}

void search(struct node *s, int x)
{
    struct node *p = s;
    int pos = 0;
    while (p != NULL && p->num != x)
    {
        pos = pos + 1;
        p = p->next;
    }
    if (p == NULL)
    {
        printf("number does not exists\n");
    }
    else
    {
        printf("number is at %d \n", pos);
    }
    return;
}

int total(struct node *s)
{
    struct node *q = s;
    int total = 0;
    while (q != NULL)
    {
        q = q->next;
        total += 1;
    }
    return total;
}

int FindMin(struct node *s)
{
    if (s == NULL)
    {
        printf("underflow\n\n");
        return INT_MIN;
    }
    return s->num;
}

int FindMax(struct node *s)
{
    if (s == NULL)
    {
        printf("underflow\n\n");
        return INT_MIN;
    }
    struct node *p = s;
    while (p->next != NULL)
    {
        p = p->next;
    }
    return p->num;
}

int main()
{
    struct node *head = NULL;
    while (1)
    {
        printf("1.Insert \n");
        printf("2.Delete\n");
        printf("3.search\n");
        printf("4.display\n");
        printf("5.total\n");
        printf("6.exit\n");
        int o;
        scanf("%d", &o);
        switch (o)
        {
        case 1:
            printf("number: \n ");
            int x;
            scanf("%d", &x);
            head = Insert(head, x);
            break;
        case 2:
            printf("number: \n");
            scanf("%d", &x);
            head = Delete(head, x);
            break;
        case 3:
            printf("number::\n ");
            scanf("%d", &x);
            search(head, x);
            break;
        case 4:
            printf("list is\n ");
            display(head);
            break;
        case 5:
            if (total(head) == 0)
            {
                printf("underflow\n");
            }
            else
            {
                printf("total %d", total(head));
            }
            break;
        case 6:
            exit(0);
            break;
        default:
            printf("wrong choice\n");
            break;
        }
    }
    return 0;
}
