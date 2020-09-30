#include <stdio.h>
#include <stdio.h>
void backinsertion(struct node *s, int p, struct node *e)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->num = p;
    temp->next = NULL;
    if (s == NULL)
    {
        s = temp;
        e = temp;
    }
    else
    {
        e->next = temp;
        e = temp;
    }
}

struct node *SetUnion(struct node *S1, struct node *S2)
{
    struct node *new_nod = NULL;
    struct node *end = NULL;
    struct node *p = S1;
    struct node *q = S2;

    while (s1 != NULL && s2 != NULL)
    {
        if (s1->num <= s2->num)
        {
            backinsertion(&new_nod, s1->data, &end);
            s1 = s1->next;
        }
        else
        {
            backinsertion(&new_nod, s2->data, &end);
            s2 = s2->next;
        }
    }
    while (s1 != NULL)
    {
        backinsertion(&new_nod, s1->data, end);
        s1 = s1->next;
    }
    while (s2 != NULL)
    {
        backinsertion(&new_nod, s2->data, &end);
        s2 = s2->next;
    }
    return new_nod;
};
struct node *SetDifference(struct node *S1, struct node *S2)
{
    struct node *p = S1;
    struct node *q = S2;
    struct node *temp = NULL;
    struct node *back = NULL;
    while (p != NULL && q != NULL)
    {
        if (p->num < q->num)
        {
            backinsertion(&temp, p->num, &back);
            p = p->next;
        }
        else if (p->num == q->num)
        {
            p = p->next;
            q = q->next;
        }
        else
        {
            q = q->next;
        }
    }
    while (p != NULL)
    {
        backinsertion(&temp, p->num, &end);
        p = p->next;
    }
    return temp;
};
struct node *SetIntersection(struct node *S1, struct node *S2)
{
    struct node *temp = NULL;
    struct node *end = NULL;
    struct node *p = S1;
    struct node *q = S2;
   
    while (p != NULL && q != NULL)
    {
        if (p->num == q->num)
        {
            InsertAtEnd(&temp, p->num, &end);
            p = p->next;
            q = q->next;
        }
        else if (p->num < q->num)
        {
            p = p->next;
        }
        else
            q = q->next;
    }
    return temp;
};
int member(struct node *s, int x)
{
    struct node *temp = NULL;
    temp = s;
    while (temp != NULL)
    {
        if (temp->num > x)
            return 0;
        if (temp->num == x)
            return 1;
        temp = temp->next;
    }
    return 0;
}