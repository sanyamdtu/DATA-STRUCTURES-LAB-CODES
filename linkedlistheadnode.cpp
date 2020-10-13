#include <stdio.h>
#include <stdlib.h>
struct nod
{
    int val;
    struct nod *next;
};
struct h
{
    struct nod *p; //start
    struct nod *end;
};
void InsertAtEnd(struct h *hd, int x)
{
    struct nod *temp;
    temp = (struct nod *)malloc(sizeof(struct nod));
    temp->val = x;
    temp->next = NULL;
    if (hd->p == NULL)
    {
        hd->p = temp;
        hd->end = temp;
    }
    else
        hd->end->next = temp;
}
void insert_start(struct h *hd, int x)
{
    struct nod *temp;
    temp = (struct nod *)malloc(sizeof(struct nod));
    temp->val = x;
    temp->next = NULL;
    if (hd->p == NULL)
    {
        hd->p = temp;
        hd->end = temp;
    }
    else
    {
        temp->next = hd->p;
        hd->p = temp;
    }
}
void InsertAfter(struct h *hd, int x, int a)
{
    struct nod *temp;
    temp = (struct nod *)malloc(sizeof(struct nod));
    temp->val = x;
    temp->next = NULL;
    struct nod *h = hd->p;
    while (h->val != a)
        h = h->next;
    temp->next = h->next;
    h->next = temp;
}
int search(struct h *h, int x)
{
    while (h->p != NULL)
    {
        if (h->p->val == x)
            return 1;
        h->p = h->p->next;
    }
    return 0;
}
void delnod_list(struct h *hd, int x)
{
    if (hd->p == NULL)
    {
        printf("underflow empty \n");
        return;
    }
    struct nod *t = hd->p;
    if (t->val == x)
        hd->p = t->next;
    else
    {
        struct nod *p = t;
        t = t->next;
        while (t && t->val != x)
        {
            t = t->next;
            p = p->next;
        }
        if (t == NULL)
        {
            printf("not deleted not found\n");
            return;
        }
        p->next = t->next;
        printf("deleted \n");
        free(t);
    }
}
int total(struct h h)
{
    int ans = 0;
    while (h.p != NULL)
    {
        h.p = h.p->next;
        ans++;
    }
    return ans;
}
void display(struct nod *s)
{
    struct nod *p = s;
    if (p == NULL)
    {
        printf("nod list is empty.");
        return;
    }
    while (p->next != NULL)
    {
        printf("%d-> ", p->val);
        p = p->next;
    }
    printf("%d", p->val);
}
int main()
{
    struct h hd;
    hd.p = hd.end = NULL;
    int c, x, f;
    while (1)
    {
        printf("\n1. Insert at end\n2. Insert at front\n3. Insert after\n4. Search\n5. Delete\n6. total\n7. Display\n8. Exit");
        printf("\nEnter the choice : ");
        scanf("%d", &c);
        if (c == 1)
        {
            printf("\nEnter the number to be inserted at end.");
            scanf("%d", &x);
            InsertAtEnd(&hd, x);
        }
        if (c == 2)
        {
            printf("\nEnter the number to be inserted at front.");
            scanf("%d", &x);
            insert_start(&hd, x);
        }
        if (c == 3)
        {
            printf("\nEnter the number to after which you want to insert.");
            scanf("%d", &f);
            printf("\nEnter the number to be inserted.");
            scanf("%d", &x);
            InsertAfter(&hd, x, f);
        }
        if (c == 4)
        {
            printf("\nEnter the number to be searched.");
            scanf("%d", &x);
            if (search(&hd, x) > 0)
                printf("Found\n");
            else
                printf("Not Found\n");
        }
        if (c == 5)
        {
            printf("\nEnter the number to be deleted.");
            scanf("%d", &x);
            delnod_list(&hd, x);
        }
        if (c == 6)
        {
            x = total(hd);
            printf("\nThe number of elements present are : %d", x);
        }
        if (c == 7)
        {
            struct nod *p = hd.p;
            display(p);
        }
        if (c == 8)
            return 0;
    }
}