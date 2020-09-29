#include <iostream>
#include <stdio.h>
using namespace std;

struct linkedlist
{
    int num;
    struct linkedlist *next;
};
struct linkedlist *first(struct linkedlist *s, int x)
{
    struct linkedlist *q;
    q = (struct linkedlist *)malloc(100 * sizeof(struct linkedlist));
    q->num = x;
    q->next = s;
    s = q;
    return s;
}
struct linkedlist *back(struct linkedlist *s, int x)
{
    struct linkedlist *p, *q;
    q = (struct linkedlist *)malloc(100 * sizeof(struct linkedlist));
    q->num = x;
    q->next = NULL;
    p = s;
    if (s == NULL)
    {
        s = q;
        return s;
    }
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = q;
    return s;
}
struct linkedlist *after(struct linkedlist *s, int x, int y)
{
    struct linkedlist *p, *q;
    q = (struct linkedlist *)malloc(100 * sizeof(struct linkedlist));
    q->num = x;
    p = s;
    if (s == NULL)
    {
        q->next = NULL;
        s = q;
        return s;
    }
    while (p->num != y)
    {
        if (p->next == NULL)
        {
            break;
        }
        p = p->next;
    }
    if (p->next == NULL && p->num != y)
    {
        printf("\nnot found\n");
        return s;
    }
    q->next = p->next;
    p->next = q;
    return s;
}
struct linkedlist *delete_(struct linkedlist *s, int x)
{
    if (s == NULL)
    {
        printf("undrflow\n");
        return s;
    }
    struct linkedlist *p, *q;
    q = s;
    p = NULL;
    while (q != NULL && q->num != x)
    {
        p = q;
        q = q->next;
    }
    if (q != NULL)
    {
        if (q == s)
        {
            s = s->next;
        }
        else
        {
            p->next = q->next;
            free(q);
        }
    }
    else
    {
        printf("\nElemenet not deleted\n");
    }

    return s;
}
void search(struct linkedlist *s, int x)
{
    struct linkedlist *p = s;
    int flag = 0;
    if (s == NULL)
    {
        printf("underflow no node \n");
        return;
    }
    while (p != NULL)
    {
        if (p->num == x)
        {
            flag = 1;
        }
        p = p->next;
    }
    if (flag == 0)
    {
        printf("\nnot found.\n");
    }
    else
    {
        printf("\nfound. \n");
    }
}
void display(struct linkedlist *s)
{
    struct linkedlist *p = s;
    if (p == NULL)
    {
        printf("\nno node\n");
        return;
    }
    while (p->next != NULL)
    {
        printf("%d-> ", p->num);
        p = p->next;
    }
    printf("%d\n", p->num);
}
int count(struct linkedlist *s)
{
    struct linkedlist *p = s;
    int c = 0;
    while (p != NULL)
    {
        c++;
        p = p->next;
    }
    return c;
}
int main()
{
    int x, y;
    struct linkedlist *p = NULL;
    while (1)
    {
        int q;
        printf("1.Insert start\n");
        printf("2.Insert end\n");
        printf("3.Insert after a certain number\n");
        printf("4.Delete\n");
        printf("5.counts\n");
        printf("6.Search\n");
        printf("7.Print\n");
        printf("8.Exit\n");
        scanf("%d", &q);
        if (q == 1)
        {
            printf("Enter the number: ");
            scanf("%d", &x);
            p = first(p, x);
        }
        if (q == 2)
        {
            printf("Enter the number: ");
            scanf("%d", &x);
            p = back(p, x);
        }
        if (q == 3)
        {
            printf("Enter the number after which insertion will take pace : ");
            scanf("%d", &y);
            printf("Enter the number inserted : ");
            scanf("%d", &x);
            p = after(p, x, y);
        }
        if (q == 4)
        {
            printf("Enter the number: ");
            scanf("%d", &x);
            p = delete_(p, x);
        }
        if (q == 5)
        {
            printf("Enter the number  : ");
            scanf("%d", &x);
            search(p, x);
        }
        if (q == 6)
        {
            y = count(p);
            printf("total : %d\n", y);
        }
        if (q == 7)
        {
            display(p);
        }
        if (q == 8)
        {
            break;
        }
    }
    return 0;
}