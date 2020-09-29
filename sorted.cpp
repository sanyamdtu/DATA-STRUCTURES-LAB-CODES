#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
struct node
{
    int value;
    struct node *next;
};

void display(struct node *s)
{
    if (s == NULL)
    {
        printf("Underflow empty\n");
        return;
    }
    struct node *q = s;
    printf("THE LIST IS : ");
    while (q != NULL)
    {
        printf("%d ", q->value);
        q = q->next;
    }
    printf("\n");
    return;
}

struct node *Insert(struct node *s, int val)
{
    struct node *q = (struct node *)malloc(sizeof(struct node));
    q->value = val;
    q->next = NULL;
    if (s == NULL)
    {
        s = q;
    }
    else
    {
        struct node *p = s;
        struct node *prev = NULL;
        while (p != NULL && p->value < val)
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

struct node *Delete(struct node *s, int val)
{
    if (s == NULL)
    {
        printf("Underflow empty\n");
    }
    else
    {
        struct node *q = s;
        struct node *p = NULL;
        while (q != NULL && q->value != val)
        {
            p = q;
            q = q->next;
        }
        if (q == NULL)
        {
            printf("not exist\n");
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
    while (p != NULL && p->value != x)
    {
        pos = pos + 1;
        p = p->next;
    }
    if (p == NULL)
    {
        printf("not exist\n");
    }
    else
    {
        printf("Value found at position : %d", pos);
    }
    return;
}

int count(struct node *s)
{
    struct node *p = s;
    int count = 0;
    while (p != NULL)
    {
        p = p->next;
        count += 1;
    }
    return count;
}

int FindMin(struct node *s)
{
    if (s == NULL)
    {
        printf("Underflow empty\n");
        return INT_MIN;
    }
    return s->value;
}

int FindMax(struct node *s)
{
    if (s == NULL)
    {
        printf("Underflow empty\n");
        return INT_MIN;
    }
    struct node *p = s;
    while (p->next != NULL)
    {
        p = p->next;
    }
    return p->value;
}

void DelAll(struct node *s)
{
    struct node *p = s;
    struct node *q = NULL;
    while (p != NULL)
    {
        q = p;
        p = p->next;
        free(q);
    }
    return;
}

int main()
{
    struct node *s = NULL;
    while (1)
    {
        printf("\nEnnter 1 to Insert n\n Ennter 2 to dele\n\n enter 3 to find\n\n  enter 4 to  print \n\n5. Count\n\n6. Find Min\n\n7. Find Max\n\n8. Exit\n");
        int o;
        scanf("%d", &o);
        switch (o)
        {
        case 1:
            printf("entert the value : ");
            int x;
            scanf("%d", &x);
            s = Insert(s, x);
            display(s);
            break;
        case 2:
            printf("enter the value to be deleted : ");
            scanf("%d", &x);
            s = Delete(s, x);
            display(s);
            break;
        case 3:
            printf("enter the value to search : ");
            scanf("%d", &x);
            search(s, x);
            break;
        case 4:
            display(s);
            break;
        case 5:
            if (count(s) == 0)
            {
                printf("Underflow empty\n");
            }
            else
            {
                printf("count %d", count(s));
            }
            break;
        case 6:
            if (FindMin(s) != -1)
            {
                printf("The Minimum value is : %d", FindMin(s));
            }
            break;
        case 7:
            if (FindMax(s) != -1)
            {
                printf("The Maximum value is : %d", FindMax(s));
            }
            break;
        case 8:
            DelAll(s);
            return 0;
        }
    }
}